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

extern struct Global *Global_new();
extern void Global_destroy();
extern void Global_clear();
extern void Global_clearFunctions();
extern int Global_find();
extern int Global_function();
extern void Global_endfunction();
extern int Global_variable();

#endif
