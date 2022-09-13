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

extern /*const*/ char *FS_errmsg;
extern /*volatile*/ int FS_intr;

#if __STDC__
#define PARAMS(s) s
#else
#define PARAMS(s) ()
#endif

/* fs.c */
int FS_opendev PARAMS((int chn, int infd, int outfd));
int FS_openin PARAMS((/*const*/ char *name));
int FS_openinChn PARAMS((int chn, /*const*/ char *name, int mode));
int FS_openout PARAMS((/*const*/ char *name));
int FS_openoutChn PARAMS((int chn, /*const*/ char *name, int mode, int append));
int FS_openrandomChn PARAMS((int chn, /*const*/ char *name, int mode, int recLength));
int FS_openbinaryChn PARAMS((int chn, /*const*/ char *name, int mode));
int FS_freechn PARAMS((void));
int FS_flush PARAMS((int dev));
int FS_close PARAMS((int dev));
int FS_istty PARAMS((int chn));
int FS_lock PARAMS((int chn, off_t offset, off_t length, int mode, int w));
int FS_truncate PARAMS((int chn));
void FS_shellmode PARAMS((int dev));
void FS_fsmode PARAMS((int chn));
void FS_xonxoff PARAMS((int chn, int on));
int FS_put PARAMS((int chn));
int FS_putChar PARAMS((int dev, int/*char*/ ch));
int FS_putChars PARAMS((int dev, /*const*/ char *chars));
int FS_putString PARAMS((int dev, /*const*/ struct String *s));
int FS_putItem PARAMS((int dev, /*const*/ struct String *s));
int FS_putbinaryString PARAMS((int chn, /*const*/ struct String *s));
int FS_putbinaryInteger PARAMS((int chn, long int x));
int FS_putbinaryReal PARAMS((int chn, double x));
int FS_getbinaryString PARAMS((int chn, struct String *s));
int FS_getbinaryInteger PARAMS((int chn, long int *x));
int FS_getbinaryReal PARAMS((int chn, double *x));
int FS_nextcol PARAMS((int dev));
int FS_nextline PARAMS((int dev));
int FS_tab PARAMS((int dev, int position));
int FS_width PARAMS((int dev, int width));
int FS_zone PARAMS((int dev, int zone));
int FS_cls PARAMS((int chn));
int FS_locate PARAMS((int chn, int line, int column));
int FS_colour PARAMS((int chn, int foreground, int background));
int FS_getChar PARAMS((int dev));
int FS_get PARAMS((int chn));
int FS_inkeyChar PARAMS((int dev, int ms));
void FS_sleep PARAMS((double s));
int FS_eof PARAMS((int chn));
long int FS_loc PARAMS((int chn));
long int FS_lof PARAMS((int chn));
long int FS_recLength PARAMS((int chn));
void FS_field PARAMS((int chn, struct String *s, long int position, long int length));
int FS_seek PARAMS((int chn, long int record));
int FS_appendToString PARAMS((int chn, struct String *s, int output_nl));
void FS_closefiles PARAMS((void));
int FS_charpos PARAMS((int chn));
int FS_copy PARAMS((/*const*/ char *from, const char *to));
int FS_portInput PARAMS((int address));
int FS_memInput PARAMS((int address));
int FS_portOutput PARAMS((int address, int value));
int FS_memOutput PARAMS((int address, int value));
void FS_allowIntr PARAMS((int on));

/*#undef PARAMS*/

#endif
