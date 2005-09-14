void		accounttime(void);
Timer*		addclock0link(void (*)(void), int);
int		addphysseg(Physseg*);
void		addbootfile(char*, uchar*, ulong);
void		addwatchdog(Watchdog*);
Block*		adjustblock(Block*, int);
void		alarmkproc(void*);
Block*		allocb(int);
int		anyhigher(void);
int		anyready(void);
#define		assert(x)	if(x){}else _assert("assert(x) failed")
void		_assert(char*);
Image*		attachimage(int, Chan*, ulong, ulong);
Page*		auxpage(void);
Block*		bl2mem(uchar*, Block*, int);
int		blocklen(Block*);
void		bootlinks(void);
void		cachedel(Image*, ulong);
void		cachepage(Page*, Image*);
void		callwithureg(void(*)(Ureg*));
char*		chanpath(Chan*);
int		canlock(Lock*);
int		canpage(Proc*);
int		canqlock(QLock*);
int		canrlock(RWlock*);
void		chandevinit(void);
void		chandevreset(void);
void		chandevshutdown(void);
void		chanfree(Chan*);
void		checkalarms(void);
void		checkb(Block*, char*);
void		cinit(void);
Chan*		cclone(Chan*);
void		cclose(Chan*);
void		closeegrp(Egrp*);
void		closefgrp(Fgrp*);
void		closepgrp(Pgrp*);
void		closergrp(Rgrp*);
long		clrfpintr(void);
void		cmderror(Cmdbuf*, char*);
int		cmount(Chan**, Chan*, int, char*);
void		confinit(void);
int		consactive(void);
void		(*consdebug)(void);
void		copen(Chan*);
Block*		concatblock(Block*);
Block*		copyblock(Block*, int);
void		copypage(Page*, Page*);
int		cread(Chan*, uchar*, int, vlong);
void		cunmount(Chan*, Chan*);
void		cupdate(Chan*, uchar*, int, vlong);
void		cwrite(Chan*, uchar*, int, vlong);
ulong		dbgpc(Proc*);
long		decref(Ref*);
int		decrypt(void*, void*, int);
void		delay(int);
Proc*		dequeueproc(Schedq*, Proc*);
Chan*		devattach(int, char*);
Block*		devbread(Chan*, long, ulong);
long		devbwrite(Chan*, Block*, ulong);
Chan*		devclone(Chan*);
int		devconfig(int, char *, DevConf *);
void		devcreate(Chan*, char*, int, ulong);
void		devdir(Chan*, Qid, char*, vlong, char*, long, Dir*);
long		devdirread(Chan*, char*, long, Dirtab*, int, Devgen*);
Devgen		devgen;
void		devinit(void);
int		devno(int, int);
Chan*		devopen(Chan*, int, Dirtab*, int, Devgen*);
void		devpermcheck(char*, ulong, int);
void		devpower(int);
void		devremove(Chan*);
void		devreset(void);
void		devshutdown(void);
int		devstat(Chan*, uchar*, int, Dirtab*, int, Devgen*);
Walkqid*	devwalk(Chan*, Chan*, char**, int, Dirtab*, int, Devgen*);
int		devwstat(Chan*, uchar*, int);
void		drawactive(int);
void		drawcmap(void);
void		dumpaproc(Proc*);
void		dumpregs(Ureg*);
void		dumpstack(void);
Fgrp*		dupfgrp(Fgrp*);
int		duppage(Page*);
void		dupswap(Page*);
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
int		eqchan(Chan*, Chan*, int);
int		eqchantdqid(Chan*, int, int, Qid, int);
int		eqqid(Qid, Qid);
void		error(char*);
long		execregs(ulong, ulong, ulong);
void		exhausted(char*);
void		exit(int);
uvlong		fastticks(uvlong*);
uvlong		fastticks2ns(uvlong);
int		fault(ulong, int);
void		fdclose(int, int);
Chan*		fdtochan(int, int, int, int);
int		findmount(Chan**, Mhead**, int, int, Qid);
int		fixfault(Segment*, ulong, int, int);
void		flushmmu(void);
void		forkchild(Proc*, Ureg*);
void		forkret(void);
void		free(void*);
void		freeb(Block*);
void		freeblist(Block*);
int		freebroken(void);
void		freepte(Segment*, Pte*);
void		getcolor(ulong, ulong*, ulong*, ulong*);
ulong		getmalloctag(void*);
ulong		getrealloctag(void*);
void		gotolabel(Label*);
char*		getconfenv(void);
int		haswaitq(void*);
long		hostdomainwrite(char*, int);
long		hostownerwrite(char*, int);
void		hzsched(void);
Block*		iallocb(int);
void		iallocsummary(void);
long		ibrk(ulong, int);
void		ilock(Lock*);
void		iunlock(Lock*);
long		incref(Ref*);
void		initseg(void);
int		iprint(char*, ...);
void		isdir(Chan*);
int		iseve(void);
int		islo(void);
Segment*	isoverlap(Proc*, ulong, int);
int		ispages(void*);
int		isphysseg(char*);
void		ixsummary(void);
int		kbdcr2nl(Queue*, int);
int		kbdgetmap(int, int*, int*, Rune*);
int		kbdputc(Queue*, int);
void		kbdputmap(ushort, ushort, Rune);
void		kickpager(void);
void		killbig(void);
void		kproc(char*, void(*)(void*), void*);
void		kprocchild(Proc*, void (*)(void*), void*);
void		(*kproftimer)(ulong);
void		ksetenv(char*, char*, int);
void		kstrcpy(char*, char*, int);
void		kstrdup(char**, char*);
long		latin1(Rune*, int);
int		lock(Lock*);
void		logopen(Log*);
void		logclose(Log*);
char*		logctl(Log*, int, char**, Logflag*);
void		logn(Log*, int, void*, int);
long		logread(Log*, void*, ulong, long);
void		log(Log*, int, char*, ...);
Cmdtab*		lookupcmd(Cmdbuf*, Cmdtab*, int);
Page*		lookpage(Image*, ulong);
#define		MS2NS(n) (((vlong)(n))*1000000LL)
void		machinit(void);
void*		mallocz(ulong, int);
void*		malloc(ulong);
void*		mallocalign(ulong, ulong, long, ulong);
void		mallocsummary(void);
Block*		mem2bl(uchar*, int);
void		mfreeseg(Segment*, ulong, int);
void		microdelay(int);
uvlong		mk64fract(uvlong, uvlong);
void		mkqid(Qid*, vlong, ulong, int);
void		mmurelease(Proc*);
void		mmuswitch(Proc*);
Chan*		mntauth(Chan*, char*);
long		mntversion(Chan*, char*, int, int);
void		mountfree(Mount*);
ulong		ms2tk(ulong);
ulong		msize(void*);
ulong		ms2tk(ulong);
uvlong		ms2fastticks(ulong);
void		mul64fract(uvlong*, uvlong, uvlong);
void		muxclose(Mnt*);
Chan*		namec(char*, int, int, ulong);
void		nameerror(char*, char*);
#define		nelem(x)	(sizeof(x)/sizeof(x[0]))
Chan*		newchan(void);
int		newfd(Chan*);
Mhead*		newmhead(Chan*);
Mount*		newmount(Mhead*, Chan*, int, char*);
Page*		newpage(int, Segment **, ulong);
Path*		newpath(char*);
Pgrp*		newpgrp(void);
Rgrp*		newrgrp(void);
Proc*		newproc(void);
void		nexterror(void);
int		notify(Ureg*);
int		nrand(int);
uvlong		ns2fastticks(uvlong);
int		okaddr(ulong, ulong, int);
int		openmode(ulong);
Block*		packblock(Block*);
Block*		padblock(Block*, int);
void		pagechainhead(Page*);
void		pageinit(void);
void		pagersummary(void);
void		panic(char*, ...);
Cmdbuf*		parsecmd(char *a, int n);
void		pathclose(Path*);
ulong		perfticks(void);
void		pexit(char*, int);
int		preempted(void);
void		printinit(void);
int		procindex(ulong);
void		pgrpcpy(Pgrp*, Pgrp*);
void		pgrpnote(ulong, char*, long, int);
void		pio(Segment *, ulong, ulong, Page **);
#define		poperror()		up->nerrlab--
int		postnote(Proc*, int, char*, int);
int		pprint(char*, ...);
void		prflush(void);
ulong		procalarm(ulong);
void		procctl(Proc*);
void		procdump(void);
int		procfdprint(Chan*, int, int, char*, int);
void		procinit0(void);
void		procflushseg(Segment*);
void		procpriority(Proc*, int, int);
Proc*		proctab(int);
extern void	(*proctrace)(Proc*, int, vlong); 
void		procwired(Proc*, int);
Pte*		ptealloc(void);
Pte*		ptecpy(Pte*);
int		pullblock(Block**, int);
Block*		pullupblock(Block*, int);
Block*		pullupqueue(Queue*, int);
void		putimage(Image*);
void		putmhead(Mhead*);
void		putmmu(ulong, ulong, Page*);
void		putpage(Page*);
void		putseg(Segment*);
void		putstrn(char*, int);
void		putswap(Page*);
ulong		pwait(Waitmsg*);
void		qaddlist(Queue*, Block*);
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
void		qsetlimit(Queue*, int);
void		qunlock(QLock*);
int		qwindow(Queue*);
int		qwrite(Queue*, void*, int);
void		qnoblock(Queue*, int);
int		rand(void);
void		randominit(void);
ulong		randomread(void*, ulong);
void		rdb(void);
int		readnum(ulong, char*, ulong, ulong, int);
int		readstr(ulong, char*, ulong, char*);
void		ready(Proc*);
void		rebootcmd(int, char**);
void		reboot(void*, void*, ulong);
void		relocateseg(Segment*, ulong);
void		renameuser(char*, char*);
void		resched(char*);
void		resrcwait(char*);
int		return0(void*);
void		rlock(RWlock*);
long		rtctime(void);
void		runlock(RWlock*);
Proc*		runproc(void);
void		savefpregs(FPsave*);
void		sched(void);
void		scheddump(void);
void		schedinit(void);
void		(*screenputs)(char*, int);
long		seconds(void);
ulong		segattach(Proc*, ulong, char *, ulong, ulong);
void		segclock(ulong);
void		segpage(Segment*, Page*);
int		setcolor(ulong, ulong, ulong, ulong);
void		setkernur(Ureg*, Proc*);
int		setlabel(Label*);
void		setmalloctag(void*, ulong);
void		setrealloctag(void*, ulong);
void		setregisters(Ureg*, char*, char*, int);
void		setswapchan(Chan*);
char*		skipslash(char*);
void		sleep(Rendez*, int(*)(void*), void*);
void*		smalloc(ulong);
int		splhi(void);
int		spllo(void);
void		splx(int);
void		splxpc(int);
char*		srvname(Chan*);
int		swapcount(ulong);
int		swapfull(void);
void		swapinit(void);
void		timeradd(Timer*);
void		timerdel(Timer*);
void		timersinit(void);
void		timerintr(Ureg*, uvlong);
void		timerset(uvlong);
ulong		tk2ms(ulong);
#define		TK2MS(x) ((x)*(1000/HZ))
uvlong		tod2fastticks(vlong);
vlong		todget(vlong*);
void		todfix(void);
void		todsetfreq(vlong);
void		todinit(void);
void		todset(vlong, vlong, int);
Block*		trimblock(Block*, int, int);
void		tnsleep(Rendez*, int (*)(void*), void*, vlong);
void		tsleep(Rendez*, int (*)(void*), void*, ulong);
int		uartctl(Uart*, char*);
int		uartgetc(void);
void		uartkick(void*);
void		uartmouse(Uart*, int (*)(Queue*, int), int);
void		uartsetmouseputc(Uart*, int (*)(Queue*, int));
void		uartputc(int);
void		uartputs(char*, int);
void		uartrecv(Uart*, char);
int		uartstageoutput(Uart*);
void		unbreak(Proc*);
void		uncachepage(Page*);
long		unionread(Chan*, void*, long);
void		unlock(Lock*);
void		userinit(void);
ulong		userpc(void);
long		userwrite(char*, int);
void		validaddr(ulong, ulong, int);
void		validname(char*, int);
char*		validnamedup(char*, int);
void		validstat(uchar*, int);
void*		vmemchr(void*, int, int);
Proc*		wakeup(Rendez*);
int		walk(Chan**, char**, int, int, int*);
void		wlock(RWlock*);
void		wunlock(RWlock*);
void*		xalloc(ulong);
void*		xallocz(ulong, int);
void		xfree(void*);
void		xhole(ulong, ulong);
void		xinit(void);
int		xmerge(void*, void*);
void*		xspanalloc(ulong, int, ulong);
void		xsummary(void);
void		yield(void);
Segment*	data2txt(Segment*);
Segment*	dupseg(Segment**, int, int);
Segment*	newseg(int, ulong, ulong);
Segment*	seg(Proc*, ulong, int);
void		hnputv(void*, vlong);
void		hnputl(void*, ulong);
void		hnputs(void*, ushort);
vlong		nhgetv(void*);
ulong		nhgetl(void*);
ushort		nhgets(void*);
void		_xinc(long*);
long		_xdec(long*);

#pragma varargck argpos iprint 1
