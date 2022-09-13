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

extern struct Var *Var_new();
extern struct Var *Var_new_scalar();
extern void Var_destroy();
extern void Var_retype();
extern struct Value *Var_value();
extern void Var_clear();
extern struct Value *Var_mat_assign();
extern struct Value *Var_mat_addsub();
extern struct Value *Var_mat_mult();
extern struct Value *Var_mat_scalarMult();
extern void Var_mat_transpose();
extern struct Value *Var_mat_invert();
extern struct Value *Var_mat_redim();

#endif
