#define nil		((void*)0)
typedef	unsigned short	ushort;
typedef	unsigned char	uchar;
typedef	unsigned long	ulong;
typedef	unsigned int	uint;
typedef	signed char	schar;
typedef	long long	vlong;
typedef	unsigned long long uvlong;
typedef	ushort		Rune;
typedef 	union FPdbleword FPdbleword;
typedef long	jmp_buf[2];
#define	JMPBUFSP	0
#define	JMPBUFPC	1
#define	JMPBUFDPC	(-8)
typedef unsigned int	mpdigit;	/* for /sys/include/mp.h */
typedef unsigned int	u32int;

/* FCR */
#define	FPINEX	(1<<23)
#define	FPOVFL	(1<<26)
#define	FPUNFL	(1<<25)
#define	FPZDIV	(1<<24)
#define	FPRNR	(0<<30)
#define	FPRZ	(1<<30)
#define	FPINVAL	(1<<27)
#define	FPRPINF	(2<<30)
#define	FPRNINF	(3<<30)
#define	FPRMASK	(3<<30)
#define	FPPEXT	0
#define	FPPSGL	0
#define	FPPDBL	0
#define	FPPMASK	0
/* FSR */
#define	FPAINEX	(1<<5)
#define	FPAZDIV	(1<<6)
#define	FPAUNFL	(1<<7)
#define	FPAOVFL	(1<<8)
#define	FPAINVAL	(1<<9)
union FPdbleword
{
	double	x;
	struct {	/* big endian */
		long hi;
		long lo;
	};
};

typedef	char*	va_list;
#define va_start(list, start) list = (char*)&start + 4
#define va_end(list)
#define va_arg(list, mode)\
	(sizeof(mode)==1?\
		((mode*)(list += 4))[-4]:\
	sizeof(mode)==2?\
		((mode*)(list += 4))[-2]:\
		((mode*)(list += sizeof(mode)))[-1])
