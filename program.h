#ifndef PROGRAM_H
#define PROGRAM_H

#include "programtypes.h"
#include "token.h"

extern struct Program *Program_new();
extern void Program_destroy();
extern void Program_norun();
extern void Program_store();
extern void Program_delete();
extern void Program_addScope();
extern struct Pc *Program_goLine();
extern struct Pc *Program_fromLine();
extern struct Pc *Program_toLine();
extern int Program_scopeCheck();
extern struct Pc *Program_dataLine();
extern struct Pc *Program_imageLine();
extern long int Program_lineNumber();
extern struct Pc *Program_beginning();
extern struct Pc *Program_end();
extern struct Pc *Program_nextLine();
extern int Program_skipEOL();
extern void Program_trace();
extern void Program_PCtoError();
extern struct Value *Program_merge();
extern int Program_lineNumberWidth();
extern struct Value *Program_list();
extern struct Value *Program_analyse();
extern void Program_renum();
extern void Program_unnum();
extern int Program_setname();
extern void Program_xref();

#endif
