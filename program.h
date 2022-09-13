#ifndef PROGRAM_H
#define PROGRAM_H

#include "programtypes.h"
#include "token.h"

#if __STDC__
#define PARAMS(s) s
#else
#define PARAMS(s) ()
#endif

/* program.c */
struct Program *Program_new PARAMS((struct Program *this));
void Program_destroy PARAMS((struct Program *this));
void Program_norun PARAMS((struct Program *this));
void Program_store PARAMS((struct Program *this, struct Token *line, long int where));
void Program_delete PARAMS((struct Program *this, const struct Pc *from, const struct Pc *to));
void Program_addScope PARAMS((struct Program *this, struct Scope *scope));
struct Pc *Program_goLine PARAMS((struct Program *this, long int line, struct Pc *pc));
struct Pc *Program_fromLine PARAMS((struct Program *this, long int line, struct Pc *pc));
struct Pc *Program_toLine PARAMS((struct Program *this, long int line, struct Pc *pc));
int Program_scopeCheck PARAMS((struct Program *this, struct Pc *pc, struct Pc *fn));
struct Pc *Program_dataLine PARAMS((struct Program *this, long int line, struct Pc *pc));
struct Pc *Program_imageLine PARAMS((struct Program *this, long int line, struct Pc *pc));
long int Program_lineNumber PARAMS((const struct Program *this, const struct Pc *pc));
struct Pc *Program_beginning PARAMS((struct Program *this, struct Pc *pc));
struct Pc *Program_end PARAMS((struct Program *this, struct Pc *pc));
struct Pc *Program_nextLine PARAMS((struct Program *this, struct Pc *pc));
int Program_skipEOL PARAMS((struct Program *this, struct Pc *pc, int dev, int tr));
void Program_trace PARAMS((struct Program *this, struct Pc *pc, int dev, int tr));
void Program_PCtoError PARAMS((struct Program *this, struct Pc *pc, struct Value *v));
struct Value *Program_merge PARAMS((struct Program *this, int dev, struct Value *value));
int Program_lineNumberWidth PARAMS((struct Program *this));
struct Value *Program_list PARAMS((struct Program *this, int dev, int watchIntr, struct Pc *from, struct Pc *to, struct Value *value));
struct Value *Program_analyse PARAMS((struct Program *this, struct Pc *pc, struct Value *value));
void Program_renum PARAMS((struct Program *this, int first, int inc));
void Program_unnum PARAMS((struct Program *this));
int Program_setname PARAMS((struct Program *this, const char *filename));
void Program_xref PARAMS((struct Program *this, int chn));

#undef PARAMS

#endif
