#ifndef AUTO_H
#define AUTO_H

#include "programtypes.h"
#include "var.h"

struct Auto
{
  long int stackPointer;
  long int stackCapacity;
  long int framePointer;
  long int frameSize;
  struct Pc onerror;
  union AutoSlot *slot;
  long int erl;
  struct Pc erpc;
  struct Value err;
  struct Value lastdet;
  struct Pc begindata;
  int resumeable;
  struct Symbol *cur,*all; /* should be hung off the funcs/procs */
};

struct AutoFrameSlot
{
  long int framePointer;
  long int frameSize;
  struct Pc pc;
};

struct AutoExceptionSlot
{
  struct Pc onerror;
  int resumeable;
};

union AutoSlot
{
  struct AutoFrameSlot retFrame;
  struct AutoExceptionSlot retException;
  struct Var var;
};

#include "token.h"

#if __STDC__
#define PARAMS(s) s
#else
#define PARAMS(s) ()
#endif

/* auto.c */
struct Auto *Auto_new PARAMS((struct Auto *this));
void Auto_destroy PARAMS((struct Auto *this));
struct Var *Auto_pushArg PARAMS((struct Auto *this));
void Auto_pushFuncRet PARAMS((struct Auto *this, int firstarg, struct Pc *pc));
void Auto_pushGosubRet PARAMS((struct Auto *this, struct Pc *pc));
struct Var *Auto_local PARAMS((struct Auto *this, int l));
int Auto_funcReturn PARAMS((struct Auto *this, struct Pc *pc));
int Auto_gosubReturn PARAMS((struct Auto *this, struct Pc *pc));
void Auto_frameToError PARAMS((struct Auto *this, struct Program *program, struct Value *v));
void Auto_setError PARAMS((struct Auto *this, long int line, struct Pc *pc, struct Value *v));
int Auto_find PARAMS((struct Auto *this, struct Identifier *ident));
int Auto_variable PARAMS((struct Auto *this, /*const*/ struct Identifier *ident));
enum ValueType Auto_argType PARAMS((/*const*/ struct Auto *this, int l));
enum ValueType Auto_varType PARAMS((/*const*/ struct Auto *this, struct Symbol *sym));
void Auto_funcEnd PARAMS((struct Auto *this));

/*#undef PARAMS*/

#endif
