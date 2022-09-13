#ifndef VAR_H
#define VAR_H

#include "value.h"

struct Var
{
  unsigned int dim;
  unsigned int *geometry;
  struct Value *value;
  unsigned int size;
  enum ValueType type;
  long int base;
};

#define VAR_SCALAR_VALUE(this) ((this)->value)

#if __STDC__
#define PARAMS(s) s
#else
#define PARAMS(s) ()
#endif

/* var.c */
struct Var *Var_new PARAMS((struct Var *this, enum ValueType type, unsigned int dim, /*const*/ unsigned int *geometry, int base));
struct Var *Var_new_scalar PARAMS((struct Var *this));
void Var_destroy PARAMS((struct Var *this));
void Var_retype PARAMS((struct Var *this, enum ValueType type));
struct Value *Var_value PARAMS((struct Var *this, unsigned int dim, int idx[], struct Value *value));
void Var_clear PARAMS((struct Var *this));
struct Value *Var_mat_assign PARAMS((struct Var *this, struct Var *x, struct Value *err, int work));
struct Value *Var_mat_addsub PARAMS((struct Var *this, struct Var *x, struct Var *y, int add, struct Value *err, int work));
struct Value *Var_mat_mult PARAMS((struct Var *this, struct Var *x, struct Var *y, struct Value *err, int work));
struct Value *Var_mat_scalarMult PARAMS((struct Var *this, struct Value *factor, struct Var *x, int work));
void Var_mat_transpose PARAMS((struct Var *this, struct Var *x));
struct Value *Var_mat_invert PARAMS((struct Var *this, struct Var *x, struct Value *det, struct Value *err));
struct Value *Var_mat_redim PARAMS((struct Var *this, unsigned int dim, /*const*/ unsigned int *geometry, struct Value *err));

/*#undef PARAMS*/

#endif
