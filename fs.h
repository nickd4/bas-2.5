#ifndef FILE_H
#define FILE_H

#include "str.h"

struct FileStream
{
  int dev,tty;
  int recLength;

  int infd;
  char inBuf[1024];
  size_t inSize,inCapacity;

  int outfd;
  int outPos;
  int outLineWidth;
  int outColWidth;
  char outBuf[1024];
  size_t outSize,outCapacity;
  int outforeground,outbackground;

  int randomfd;
  int recPos;
  char *recBuf;
  struct StringField field;

  int binaryfd;
};

#define FS_COLOUR_BLACK         0
#define FS_COLOUR_BLUE          1
#define FS_COLOUR_GREEN         2
#define FS_COLOUR_CYAN          3
#define FS_COLOUR_RED           4
#define FS_COLOUR_MAGENTA       5
#define FS_COLOUR_BROWN         6
#define FS_COLOUR_WHITE         7
#define FS_COLOUR_GREY          8
#define FS_COLOUR_LIGHTBLUE     9
#define FS_COLOUR_LIGHTGREEN    10
#define FS_COLOUR_LIGHTCYAN     11
#define FS_COLOUR_LIGHTRED      12
#define FS_COLOUR_LIGHTMAGENTA  13
#define FS_COLOUR_YELLOW        14
#define FS_COLOUR_BRIGHTWHITE   15

#define FS_ACCESS_NONE          0
#define FS_ACCESS_READ          1
#define FS_ACCESS_WRITE         2
#define FS_ACCESS_READWRITE     3

#define FS_LOCK_NONE            0
#define FS_LOCK_SHARED          1
#define FS_LOCK_EXCLUSIVE       2

extern const char *FS_errmsg;
extern volatile int FS_intr;

extern int FS_opendev();
extern int FS_openin();
extern int FS_openinChn();
extern int FS_openout();
extern int FS_openoutChn();
extern int FS_openrandomChn();
extern int FS_openbinaryChn();
extern int FS_freechn();
extern int FS_flush();
extern int FS_close();
extern int FS_istty();
extern int FS_lock();
extern int FS_truncate();
extern void FS_shellmode();
extern void FS_fsmode();
extern void FS_xonxoff();
extern int FS_put();
extern int FS_putChar();
extern int FS_putChars();
extern int FS_putString();
extern int FS_putItem();
extern int FS_putbinaryString();
extern int FS_putbinaryInteger();
extern int FS_putbinaryReal();
extern int FS_getbinaryString();
extern int FS_getbinaryInteger();
extern int FS_getbinaryReal();
extern int FS_nextcol();
extern int FS_nextline();
extern int FS_tab();
extern int FS_cls();
extern int FS_locate();
extern int FS_colour();
extern int FS_get();
extern int FS_getChar();
extern int FS_eof();
extern long int FS_loc();
extern long int FS_lof();
extern int FS_width();
extern int FS_zone();
extern long int FS_recLength();
extern void FS_field();
extern int FS_appendToString();
extern int FS_inkeyChar();
extern void FS_sleep();
extern int FS_seek();
extern void FS_closefiles();
extern int FS_charpos();
extern int FS_copy();
extern int FS_portInput();
extern int FS_memInput();
extern int FS_portOutput();
extern int FS_memOutput();
extern void FS_allowIntr();

#endif
