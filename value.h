#ifndef VALUE_H
#define VALUE_H

#include "str.h"

enum ValueType
{
  V_ERROR=1,
  V_INTEGER,
  V_NIL,
  V_REAL,
  V_STRING,
  V_VOID
};

struct Value
{
  enum ValueType type;
  union
  {
    /* V_ERROR   */ struct { char *msg; long int code; } error;
    /* V_INTEGER */ long int integer;
    /* V_NIL     */
    /* V_REAL    */ double real;
    /* V_STRING  */ struct String string;
    /* V_VOID    */
  } u;
};

extern const enum ValueType Value_commonType[V_VOID+1][V_VOID+1];

#define VALUE_NEW_INTEGER(this,n) ((this)->type=V_INTEGER,(this)->u.integer=(n))
#define VALUE_NEW_REAL(this,n) ((this)->type=V_REAL,(this)->u.real=(n))
#define VALUE_RETYPE(v,t) ((v)->type==(t) ? (v) : Value_retype(v,t))
#define VALUE_DESTROY(this) assert((this)!=(struct Value*)0); \
  switch ((this)->type) \
  { \
    case V_ERROR: free((this)->u.error.msg); break; \
    case V_INTEGER: break; \
    case V_NIL: break; \
    case V_REAL: break; \
    case V_STRING: String_destroy(&(this)->u.string); break; \
    case V_VOID: break; \
    default: assert(0); \
  } \
  (this)->type=0;


#ifndef HAVE_LRINT
extern long int lrint();
#endif
extern double Value_trunc();
extern double Value_round();
extern long int Value_toi();
extern long int Value_vali();
extern double Value_vald();

extern struct Value *Value_new_NIL();
extern struct Value *Value_new_ERROR();
extern struct Value *Value_new_INTEGER();
extern struct Value *Value_new_REAL();
extern struct Value *Value_new_STRING();
extern struct Value *Value_new_VOID();
extern struct Value *Value_new_null();
extern int Value_isNull();
extern void Value_destroy();
extern void Value_errorPrefix();
extern void Value_errorSuffix();
extern struct Value *Value_new_typeError();
extern struct Value *Value_retype();
extern struct Value *Value_clone();
extern struct Value *Value_uplus();
extern struct Value *Value_uneg();
extern struct Value *Value_unot();
extern struct Value *Value_add();
extern struct Value *Value_sub();
extern struct Value *Value_mult();
extern struct Value *Value_div();
extern struct Value *Value_idiv();
extern struct Value *Value_mod();
extern struct Value *Value_pow();
extern struct Value *Value_and();
extern struct Value *Value_or();
extern struct Value *Value_xor();
extern struct Value *Value_eqv();
extern struct Value *Value_imp();
extern struct Value *Value_lt();
extern struct Value *Value_le();
extern struct Value *Value_eq();
extern struct Value *Value_ge();
extern struct Value *Value_gt();
extern struct Value *Value_ne();
extern int Value_exitFor();
extern struct String *Value_toString();
extern struct Value *Value_toStringUsing();
extern struct String *Value_toWrite();
extern struct Value *Value_nullValue();

#endif
