void		_assert(char*);
void		accounttime(void);
void		addbootfile(char*, uchar*, ulong);
Timer*		addclock0link(void (*)(void), int);
int		addconsdev(Queue*, void (*fn)(char*,int), int, int);
int		addkbdq(Queue*, int);
int		addphysseg(Physseg*);
void		adduser(char*, char*, int, char**);
void		addwatchdog(Watchdog*);
int		adec(int*);
Block*		adjustblock(Block*, int);
int		ainc(int*);
void		alarmkproc(void*);
Block*		allocb(int);
Block*	allocbalign(int, int);
int		anyhigher(void);
int		anyready(void);
Image*		attachimage(Chan*);
Block*		bl2mem(uchar*, Block*, int);
int		blocklen(Block*);
void		bootlinks(void);
Bpool*		bpoolcreate(uint, uint, uintmem, uintmem, void* (*)(usize, int));
uintmem		bpoolalloc(Bpool*, usize);
void		bpoolfree(Bpool*, uintmem, usize);
void		bpoolallocrange(Bpool*, usize*, usize*);
void		bpoolinitfree(Bpool*, uintmem, uintmem);
void		bpooldump(Bpool*);
void		callwithureg(void (*)(Ureg*));
char*		chanpath(Chan*);
int		canlock(Lock*);
int		canqlock(QLock*);
int		canrlock(RWlock*);
Chan*		cclone(Chan*);
void		cclose(Chan*);
void		ccloseq(Chan*);
void		(*consdebug)(void);
void		(*consputs)(char*, int);
void		chanfree(Chan*);
void		checkalarms(void);
void		checkb(Block*, char*);
void		checkflushmmu(void);
void		checkmmu(uintptr, uintmem);
void		checkpages(void);
void		cinit(void);
void		closeegrp(Egrp*);
void		closefgrp(Fgrp*);
void		closepgrp(Pgrp*);
void		closergrp(Rgrp*);
void		cmderror(Cmdbuf*, char*);
int		cmount(Chan**, Chan*, int, char*);
#define	commonerror() (up->errstr)
#define	commonuser() (up->user)
Block*		concatblock(Block*);
int		consactive(void);
void		copen(Chan*);
Block*		copyblock(Block*, int);
void		copypage(Page*, Page*);
int		cread(Chan*, uchar*, int, vlong);
void		cunmount(Chan*, Chan*);
void		cupdate(Chan*, uchar*, int, vlong);
void		cwrite(Chan*, uchar*, int, vlong);
uintptr		dbgpc(Proc*);
int		decref(Ref*);
int		decrypt(void*, void*, int);
void		delay(int);
void		delconsdevs(void);
int		deluser(char*);
Proc*		dequeueproc(Schedq*, Proc*);
Chan*		devattach(int, char*);
Block*		devbread(Chan*, long, vlong);
long		devbwrite(Chan*, Block*, vlong);
Dev*		devbyname(char*);
Chan*		devclone(Chan*);
int		devconfig(int, char *, DevConf *);
void		devcreate(Chan*, char*, int, int);
void		devdir(Chan*, Qid, char*, vlong, char*, long, Dir*);
long		devdirread(Chan*, char*, long, Dirtab*, int, Devgen*);
Devgen		devgen;
void		devinit(void);
Chan*		devopen(Chan*, int, Dirtab*, int, Devgen*);
void		devpermcheck(char*, int, int);
void		devpower(int);
long		devreadv(Chan*, IOchunk*, long, long, vlong);
void		devremove(Chan*);
void		devreset(void);
void		devshutdown(void);
long		devstat(Chan*, uchar*, long, Dirtab*, int, Devgen*);
Dev*		devtabget(int, int);
void		devtabinit(void);
long		devtabread(Chan*, void*, long, vlong);
void		devtabreset(void);
void		devtabshutdown(void);
long		devwritev(Chan*, IOchunk*, long, long, vlong);
long		devwstat(Chan*, uchar*, long);
Walkqid*	devwalk(Chan*, Chan*, char**, int, Dirtab*, int, Devgen*);
void		drawactive(int);
void		drawcmap(void);
void		dumpaproc(Proc*);
void		dumpregs(Ureg*);
void		dumpstack(void);
Fgrp*		dupfgrp(Fgrp*);
void		duppages(Pages*, Pages*);
void		edfinit(Proc*);
char*		edfadmit(Proc*);
int		edfready(Proc*);
void		edfrecord(Proc*);
void		edfrun(Proc*, int);
void		edfstop(Proc*);
void		edfyield(void);
int		emptystr(char*);
int		encrypt(void*, void*, int);
void		envcpy(Egrp*, Egrp*);
int		eqchanddq(Chan*, int, uint, Qid, int);
int		eqqid(Qid, Qid);
void		error(char*);
void		errorf(char*, ...);
void		exhausted(char*);
void		exit(int);
uvlong		fastticks(uvlong*);
uvlong		fastticks2us(uvlong);
uvlong		fastticks2ns(uvlong);
int		fault(uintptr, int);
void		fdclose(int, int);
Chan*		fdtochan(int, int, int, int);
int		findmount(Chan**, Mhead**, int, uint, Qid);
int		fixfault(Segment*, uintptr, int, int);
void		fmtinit(void);
void		forceclosefgrp(void);
void		free(void*);
void		freeb(Block*);
void		freeblist(Block*);
void		freepagelist(Page*);
void		freepages(Pages*);
int		freebroken(void);
Pages*	growpages(Pages*, uintptr);
void		freepte(void (*)(Page*), Pte*);
void		getcolor(ulong, ulong*, ulong*, ulong*);
void		gotolabel(Label*);
char*		getconfenv(void);
int		haswaitq(void*);
long		hostdomainwrite(char*, long);
long		hostownerwrite(char*, long);
void		hzsched(void);
Block*		iallocb(int);
void		ialloclimit(ulong);
void		iallocsummary(void);
void		ilock(Lock*);
void		iunlock(Lock*);
Page*	imagepage(Image*, int, uintptr, uintptr);
int		incref(Ref*);
int		ingroup(char*, char*);
void		initimage(void);
int		iprint(char*, ...);
void		isdir(Chan*);
int		iseve(void);
int		isevegroup(void);
int		islo(void);
#define	islocked(l)	((l)->key != 0)
Segment*	isoverlap(Proc*, uintptr, usize);
int		ispages(void*);
int		isphysseg(char*);
int		isrmapped(RMap*, uintmem, uintmem*);
void		ixsummary(void);
int		kbdcr2nl(Queue*, int);
int		kbdgetmap(int, int*, int*, Rune*);
int		kbdputc(Queue*, int);
void		kbdputmap(ushort, ushort, Rune);
void		kickpager(void);
void		killbig(char*);
void		kproc(char*, void(*)(void*), void*);
void		kprocchild(Proc*, void (*)(void*), void*);
void		(*kproftimer)(uintptr);
void		ksetenv(char*, char*, int);
void		kstrcpy(char*, char*, int);
void		kstrdup(char**, char*);
int			labtrap(char*);
long		latin1(Rune*, int);
int		leadsgroup(char*, char*);
int		lock(Lock*);
uintptr	lockgetpc(Lock*);
void		locksetpc(Lock*, uintptr);
void		logopen(Log*);
void		logclose(Log*);
char*		logctl(Log*, int, char**, Logflag*);
void		logn(Log*, int, void*, int);
long		logread(Log*, void*, ulong, long);
void		log(Log*, int, char*, ...);
Cmdtab*		lookupcmd(Cmdbuf*, Cmdtab*, int);
Page*		lookpage(Image*, ulong);
#define		MS2NS(n) (((vlong)(n))*1000000LL)
void		mallocinit(void);
int			malloclocked(void);
long		mallocreadsummary(Chan*, void*, long, long);
void		mallocsummary(void);
Block*		mem2bl(uchar*, int);
Page*	mfreepages(Pages*, uintptr, usize);
void		mfreeseg(Segment*, uintptr, uintptr);
void		microdelay(int);
uvlong		mk64fract(uvlong, uvlong);
void		mkqid(Qid*, vlong, ulong, int);
void		mmuflush(void);
void		mmuput(uintptr, uintmem, Page*);
void		mmurelease(Proc*);
void		mmuswitch(Proc*);
Chan*		mntauth(Chan*, char*);
usize		mntversion(Chan*, u32int, char*, usize);
void		mountfree(Mount*);
int		mregfmt(Fmt*);
ulong		ms2tk(ulong);
uvlong		ms2fastticks(ulong);
void		mul64fract(uvlong*, uvlong, uvlong);
void		muxclose(Mnt*);
Chan*		namec(char*, int, int, int);
void		nameerror(char*, char*);
Chan*		newchan(void);
int		newfd(Chan*);
Mhead*		newmhead(Chan*);
Mount*		newmount(Mhead*, Chan*, int, char*);
Page*		newpage(int, uint, RWlock*);
Pages*		newpages(int, uintptr, void (*f)(Page*));
Path*		newpath(char*);
Pgrp*		newpgrp(void);
Rgrp*		newrgrp(void);
Proc*		newproc(void);
Section*		newsection(uintptr, ulong, ulong);
void		nexterror(void);
void		noteallow(void);
void		notedefer(void);
int		nrand(int);
uvlong		ns2fastticks(uvlong);
int		okaddr(uintptr, long, int);
int		openmode(int);
int		ownlock(Lock*);
Block*		packblock(Block*);
Block*		padblock(Block*, int);
void		pageinit(void);
void		pageflush(Page*, uint);
void		pagesflush(Pages*, uintptr, uintptr);
ulong		pagenumber(Page*);
void	pagereclaim(int, int);
void	pagewake(void);
void		panic(char*, ...);
Cmdbuf*		parsecmd(char *a, int n);
void		pathclose(Path*);
ulong		perfticks(void);
void		pexit(char*, int);
void		pgrpcpy(Pgrp*, Pgrp*);
void		pgrpnote(ulong, char*, long, int);
void		physdump(void);
void		physinit(uintmem);
void		physinitfree(uintmem, uintmem);
uintmem	physalloc(usize);
void		physdump(void);
int		physmemavail(uintptr);
int		psindex(int);
#define		poperror()		up->nerrlab--
int		postnote(Proc*, int, char*, int);
void	priqlock(QLock*);
void		prockill(Proc*, int, char*);
int		pprint(char*, ...);
int		preempted(void);
void		prflush(void);
void		printinit(void);
void		printpages(Pages*);
void		psinit(int);
ulong		procalarm(ulong);
void		procctl(Proc*);
ulong	procdatasize(Proc*, int);
void		procdump(void);
int		procfdprint(Chan*, int, int, char*, int);
void		procflushseg(Segment*);
void		procpriority(Proc*, int, int);
void		procrestore(Proc*);
void		procsave(Proc*);
Proc*		psincref(int);
void		psdecref(Proc*);
void		(*proctrace)(Proc*, int, vlong, vlong);
void		procwired(Proc*, int);
Pte*		ptealloc(void);
Pte*		ptecpy(Pte*);
void		pteflush(Pte*, int, int);
int		pullblock(Block**, int);
Block*		pullupblock(Block*, int);
Block*		pullupqueue(Queue*, int);
void		putimage(Image*);
void		putmhead(Mhead*);
void		putpage(Page*);
void		putseg(Segment*);
void		putstrn(char*, int);
int		pwait(Waitmsg*);
void		qaddlist(Queue*, Block*);
int		qblen(Queue*);
Block*		qbread(Queue*, int);
long		qbwrite(Queue*, Block*);
Queue*		qbypass(void (*)(void*, Block*), void*);
int		qcanread(Queue*);
void		qclose(Queue*);
int		qconsume(Queue*, void*, int);
Block*		qcopy(Queue*, int, ulong);
int		qdiscard(Queue*, int);
void		qflush(Queue*);
void		qfree(Queue*);
int		qfull(Queue*);
Block*		qget(Queue*);
void		qhangup(Queue*, char*);
int		qisclosed(Queue*);
int		qiwrite(Queue*, void*, int);
int		qlen(Queue*);
void		qlock(QLock*);
Queue*		qopen(int, int, void (*)(void*), void*);
int		qpass(Queue*, Block*);
int		qpassnolim(Queue*, Block*);
int		qproduce(Queue*, void*, int);
void		qputback(Queue*, Block*);
long		qread(Queue*, void*, int);
Block*		qremove(Queue*);
void		qreopen(Queue*);
void		qsetbypass(Queue*, void (*)(void*, Block*), void*);
void		qsetlimit(Queue*, int);
void		qsleep(Queue*);
void		qunlock(QLock*);
int		qwindow(Queue*);
int		qwrite(Queue*, void*, int);
void		qnoblock(Queue*, int);
int		rand(void);
void		randominit(void);
ulong		randomread(void*, ulong);
void		rdb(void);
int		readnum(ulong, char*, ulong, ulong, int);
long		readstr(long, char*, long, char*);
void		ready(Proc*);
void		rebootcmd(int, char**);
void		reboot(void*, void*, long);
void		relocatepages(Pages*, uintptr);
void		relocateseg(Segment*, uintptr);
void		renameuser(char*, char*);
void		resched(char*);
void		resrcwait(char*, char*);
int		return0(void*);
void		rlock(RWlock*);
void		rmapinit(RMap*, char*, RMapel* (*)(void));
uintmem	rmapalloc(RMap*, uintmem, uintmem, uint);
int		rmapfirst(RMap*, uintmem, uintmem*, uintmem*);
void		rmapfree(RMap*, uintmem, uintmem);
void		rmapgaps(RMap*, RMap*);
void		rmapprint(RMap*);
uintmem	rmapsize(RMap*);
long		rtctime(void);
void		runlock(RWlock*);
Proc*		runproc(void);
void		sched(void);
void		scheddump(void);
void		schedinit(void);
long		seconds(void);
void		segclock(uintptr);
void		addpage(Pages*, uintptr, Page*);
Page*	va2page(Pages*, uintptr);
Page*	segva2page(Segment*, uintptr);
char*	seprintbpoolstats(Bpool*, char*, char*);
char*	seprintphysstats(char*, char*);
char*	seprintpagestats(char*, char*);
int		setcolor(ulong, ulong, ulong, ulong);
void		setkernur(Ureg*, Proc*);
int		setlabel(Label*);
void		setregisters(Ureg*, char*, char*, int);
char*		skipslash(char*);
void		sleep(Rendez*, int (*)(void*), void*);
void*		smalloc(ulong);
char*		srvname(Chan*);
char*	syscallfmt(int, uintptr, va_list list);
char*	sysretfmt(int, va_list, Ar0*, uvlong, uvlong);
void		sysrforkchild(Proc*, Proc*);
#define	tickscmp(a, b)  ((long)((a)-(b)))
void		timeradd(Timer*);
void		timerdel(Timer*);
void		timersinit(void);
void		timerintr(Ureg*, void*);
void		timerset(uvlong);
ulong		tk2ms(ulong);
#define		TK2MS(x) ((x)*(1000/HZ))
uvlong		tod2fastticks(vlong);
vlong		todget(vlong*);
void		todsetfreq(vlong);
void		todinit(void);
void		todset(vlong, vlong, int);
void		tsleep(Rendez*, int (*)(void*), void*, long);
Block*		trimblock(Block*, int, int);
Segment*	txt2data(Proc*, Segment*);
Uart*		uartconsole(int, char*);
int		uartctl(Uart*, char*);
int		uartgetc(void);
void		uartkick(void*);
void		uartputc(int);
void		uartputs(char*, int);
void		uartrecv(Uart*, char);
int		uartstageoutput(Uart*);
void		unbreak(Proc*);
void		unlock(Lock*);
void		userinit(void);
uintptr		userpc(Ureg*);
char*	usersread(void);
long		userswrite(void*, long);
long		userwrite(char*, long);
void*		validaddr(void*, long, int);
void		validname(char*, int);
char*		validnamedup(char*, int);
void		validstat(uchar*, usize);
void*		vmemchr(void*, int, int);
Proc*		wakeup(Rendez*);
int		walk(Chan**, char**, int, int, int*);
void		wlock(RWlock*);
void		wunlock(RWlock*);
void		yield(void);
Segment*	data2txt(Segment*);
Segment*	dupseg(Segment**, int, int);
Segment*	newseg(int, uintptr, uintptr, Image*, int);
Segment*	seg(Proc*, uintptr, void(*)(RWlock*));
void		hnputv(void*, uvlong);
void		hnputl(void*, uint);
void		hnputs(void*, ushort);
uvlong		nhgetv(void*);
uint		nhgetl(void*);
ushort		nhgets(void*);
ulong		µs(void);

#pragma varargck 	argpos 	errorf 		1
#pragma varargck	argpos	iprint		1
#pragma varargck	argpos	panic		1
#pragma varargck	argpos	pprint		1

void*	xchgm(void*, void*);
#define ALIGNED(h, a)	((((uintptr)(h)) & (a-1)) == 0)
