#include <stdio.h>
#include <assert.h>
#include "defs.h"
#include "data.h"

#define INTSIZE 2
#define BYTEOFF 0

header()
{
    outstr(";\tSmall C AVR\n;");
    FEvers();
    nl ();
}

nl(){ outbyte (EOL); }

initmac(){}

galign(t)
int t;
{
    return (t);
}

intsize(){ return(INTSIZE); }

byteoff(){ return(BYTEOFF); }

olprfix(){ outstr("L"); }

col(){ outstr (":\n"); }

comment(){ outbyte (';'); }

prefix(){ outbyte ('\0'); }

trailer(){ ol (".end");  }

prologue(){}

gtext(){ ol (".text"); }

gdata(){ ol (".data"); }

ppubext(scptr)
char *scptr; 
{
    if (scptr[STORAGE] == STATIC) return;
    ot (".global\t");
    prefix ();
    outstr (scptr);
    nl();
}

fpubext(scptr)
char *scptr;
{
    ppubext(scptr);
}

onum(num)
int num; 
{
    outdec(num);
}

getmem(sym)
char *sym;
{
    assert(0);
}

getloc (sym)
char    *sym;
{
    if (sym[STORAGE] == LSTATIC)
    {
        assert(0);
        immed(0);
        printlabel(glint(sym));
        nl();
    }
    else
    {
        immed (glint(sym));
        nl();
    }
}

putmem (sym)
char    *sym;
{
    assert(0);
}

putstk (typeobj)
char    typeobj;
{
    ol("in\tr28, 0x3d");
    ol("in\tr29, 0x3e");
    ol("adiw\tr28, 1");
    ol("ld\tr27, Y+");
    ol("ld\t26, Y");
    ol("st\tX, r31");
    ol("st\t-X, r30");
    nl();
}

indirect (typeobj)
char    typeobj;
{
    ol("ld\tr27, Z");
    ol("ld\tr26, -Z");
    ol("movw\tr30, r26");
    nl();
}

swap ()
{
    assert(0);
}

immed (addr)
int addr;
{
    ot("ldi\tr30, ");
    onum(addr & 0xFF);
    nl();
    ot("ldi\tr31, ");
    onum((addr >> 8) & 0xFF);
}

gpush ()
{
    ol("push\tr30");
    ol("push\tr31");
    nl();

    stkp = stkp - INTSIZE*2;
}

gpop ()
{
    ol ("pop\tr27");
    ol ("pop\tr26");
    nl();

    stkp = stkp + INTSIZE;
}

swapstk ()
{
    assert(0);
}

gcall(sname)
char* sname;
{
    ot ("call\t");
    outstr( sname );
    nl();
}

gret()
{
    ol("ret");
    nl();
}

callstk ()
{
    assert(0);
}

jump (label)
int     label;
{
    ot ("jmp\t");
    olprfix();
    outdec( label );
    nl();
}

testjump (label, ft)
int label, ft;
{
    assert(0);
}

defbyte ()
{
    ot (".byte\t");
}

defstorage ()
{
    assert(0);
}

defword ()
{
    ot (".word\t");
}

modstk(newstkp)
int newstkp;
{
    ot("ldi\tr16, ");
    onum(newstkp & 0xFF);
    nl();
    ol("out\t0x3d, r16");
    ot("ldi\tr17, ");
    onum((newstkp >> 8) & 0xFF);
    nl();
    ol("out\t0x3e, r17");
    nl();

    return newstkp;
}

gaslint()
{
    assert(0);
}

gasrint()
{
    assert(0);
}

gjcase()
{
    assert(0);
}

gadd (lval, lval2)
int *lval, *lval2;
{
    if(dbltest (lval2, lval))
    {
        assert(0);
    }
    gpop();
    ol("add\tr30, r26");
    ol("adc\tr31, r27");
    stkp = stkp + INTSIZE;
}

gsub ()
{
    assert(0);
}

gmult ()
{
    assert(0);
}

gdiv ()
{
    assert(0);
}

gmod ()
{
    assert(0);
}

gor ()
{
    assert(0);
}

gxor ()
{
    assert(0);
}

gand ()
{
    assert(0);
}

gasr ()
{
    assert(0);
}

gasl ()
{
    assert(0);
}

gneg ()
{
    assert(0);
}

glneg ()
{
    assert(0);
}

gcom ()
{
    assert(0);
}

gbool ()
{
    assert(0);
}

ginc (lval) int lval[];
{
    ol("adiw\tr30, 1");
}


gdec (lval) int lval[];
{
    ol("sbiw\tr30, 1");
}

geq ()
{
    assert(0);
}

gne ()
{
    assert(0);
}

glt ()
{
    assert(0);
}

gle ()
{
    assert(0);
}

ggt ()
{
    assert(0);
}

gge ()
{
    assert(0);
}

gult ()
{
    assert(0);
}

gule ()
{
    assert(0);
}

gugt ()
{
    assert(0);
}

guge ()
{
    assert(0);
}

inclib()
{
    return("");
}

gnargs(d)int d;{}

assemble(s)char *s;{ return(0); }

link(){ return(0); }

