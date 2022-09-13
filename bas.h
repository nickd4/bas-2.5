#ifndef BAS_H
#define BAS_H

#define STDCHANNEL 0
#define LPCHANNEL 32

extern int bas_argc;
extern char *bas_argv0;
extern char **bas_argv;
extern int bas_end;

extern void bas_init();
extern void bas_runFile();
extern void bas_runLine();
extern void bas_interpreter();
extern void bas_exit();

#endif
