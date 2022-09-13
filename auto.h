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

extern struct Auto *Auto_new();
extern void Auto_destroy();
extern struct Var *Auto_pushArg();
extern void Auto_pushFuncRet();
extern void Auto_pushGosubRet();
extern struct Var *Auto_local();
extern int Auto_funcReturn();
extern int Auto_gosubReturn();
extern void Auto_frameToError();
extern void Auto_setError();

extern int Auto_find();
extern int Auto_variable();
extern enum ValueType Auto_argType();
extern enum ValueType Auto_varType();
extern void Auto_funcEnd();

#endif
