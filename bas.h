#ifndef BAS_H
#define BAS_H

#define STDCHANNEL 0
#define LPCHANNEL 32

extern int bas_argc;
extern char *bas_argv0;
extern char **bas_argv;
extern int bas_end;

#if __STDC__
#define PARAMS(s) s
#else
#define PARAMS(s) ()
#endif

/* bas.c */
void bas_init PARAMS((int backslash_colon, int restricted, int uppercase, int lpfd));
void bas_runFile PARAMS((/*const*/ char *runFile));
void bas_runLine PARAMS((/*const*/ char *runLine));
void bas_interpreter PARAMS((void));
void bas_exit PARAMS((void));

#endif
