#ifndef GLOBAL_H
#define GLOBAL_H

#include "token.h"
#include "value.h"
#include "var.h"

#define GLOBAL_HASHSIZE 31

struct GlobalFunctionChain
{
  struct Pc begin,end;
  struct GlobalFunctionChain *next;
};

struct Global
{
  struct String command;
  struct Symbol *table[GLOBAL_HASHSIZE];
  struct GlobalFunctionChain *chain;
};

#if __STDC__
#define PARAMS(s) s
#else
#define PARAMS(s) ()
#endif

/* global.c */
struct Global *Global_new PARAMS((struct Global *this));
int Global_find PARAMS((struct Global *this, struct Identifier *ident, int oparen));
int Global_variable PARAMS((struct Global *this, struct Identifier *ident, enum ValueType type, enum SymbolType symbolType, int redeclare));
int Global_function PARAMS((struct Global *this, struct Identifier *ident, enum ValueType type, struct Pc *deffn, struct Pc *begin, int argLength, enum ValueType *argTypes));
void Global_endfunction PARAMS((struct Global *this, struct Identifier *ident, struct Pc *end));
void Global_clear PARAMS((struct Global *this));
void Global_clearFunctions PARAMS((struct Global *this));
void Global_destroy PARAMS((struct Global *this));

#undef PARAMS

#endif
