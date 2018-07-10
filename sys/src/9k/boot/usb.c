/* usb support */

#include <u.h>
#include <libc.h>
#include <auth.h>
#include <fcall.h>
#include "../boot/boot.h"

#define PARTSRV "partfs.sdXX"

enum {
	Dontpost,
	Post,
};

static char usbdisk0[] = "/dev/sdU0.0";
static char sdxxctl[]  = "/dev/sdXX/ctl";

/*
 * run argv[0] (short name is name) and wait awhile for file to appear.
 * file must be generated by running argv[0]; if it already exists, we're done.
 */
static int
start(char *name, char **argv, char *file)
{
	int cnt;

	if(access(file, AEXIST) >= 0)
		return 0;
	if(access(argv[0], AEXIST) < 0) {
		fprint(2, "no %s...", argv[0]);
		return -1;
	}

	dprint("%s...", name);
	runv(argv);
	for(cnt = 10; cnt > 0 && access(file, AEXIST) < 0; cnt--)
		sleep(100);
	if (cnt <= 0) {
		dprint("no %s...", file);
		return -1;
	}
	return 0;
}

int
chmod(char *file, int mode)
{
	Dir *dir;

	dir = dirstat(file);
	if (dir == nil) {
		dprint("can't stat %s: %r\n", file);
		return -1;
	}
	dir->mode &= ~0777;
	dir->mode |= mode & 0777;
	dirwstat("/srv/" PARTSRV, dir);
	free(dir);
	return 0;
}

/* start partfs on first usb disk, if any.  optionally post partfs in /srv. */
static int
startpartfs(int post)
{
	int r, i;
	char *parts;
	char *partfsv[32];

	if(access(usbdisk0, AEXIST) < 0)
		return -1;	/* can't run partfs until usbd is mounted */

	if (post)
		remove("/srv/" PARTSRV);

	i = 0;
	partfsv[i++] = "/boot/partfs";
	/*
	 * hack for booting from usb: if /env/sdB0part (from 9load) exists,
	 * pass it to partfs for sdXX.
	 */
	parts = getenv("sdB0part");
	if (parts != nil) {
		partfsv[i++] = "-p";
		partfsv[i++] = parts;
	}
	if (post) {
		partfsv[i++] = "-s";
		partfsv[i++] = PARTSRV;
	}
	partfsv[i++] = usbdisk0;
	partfsv[i] = nil;
	r = start("partfs", partfsv, sdxxctl);

	if (post)
		chmod("/srv/" PARTSRV, 0666);
	return r;
}

static int
mountusb(void)
{
	int fd;

	dprint("mount usbd...");
	fd = open("/srv/usb", ORDWR);
	if(fd < 0)
		dprint("can't open /srv/usb");
	else if(mount(fd, -1, "/dev", MBEFORE, "") < 0) {
		warning("mount -a /srv/usb /dev");
		close(fd);
	} else
		return 0;		/* mount closed fd */
	return -1;
}

int
mountusbparts(void)
{
	mountusb();
	return startpartfs(Post);
}

/*
 *  start usbd, which mounts itself on /dev.
 *  start partfs on first disk, if any, to permit nvram on usb.
 */
void
usbinit(int post)
{
	int cnt;
	static char *usbdv[] = { "/boot/usbd", nil };

	if(access("#u/usb/ctl", AEXIST) < 0 || bind("#u", "/dev", MAFTER) < 0)
		return;
	dprint("usbinit...");
	start("usbd", usbdv, "/srv/usb");

	/* allow a little time for usbd's device discovery */
	for(cnt = 20; cnt > 0 && access(usbdisk0, AEXIST) < 0; cnt--)
		sleep(100);
	if(cnt > 0)
		startpartfs(post);
	else
		dprint("no usb disk...");
}
