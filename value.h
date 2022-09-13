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

#if __STDC__
#define PARAMS(s) s
#else
#define PARAMS(s) ()
#endif

/* value.c */
#ifndef HAVE_LRINT
long int lrint PARAMS((double d));
#endif
double Value_trunc PARAMS((double d));
double Value_round PARAMS((double d));
long int Value_toi PARAMS((double d, int *overflow));
long int Value_vali PARAMS((const char *s, char **end, int *overflow));
double Value_vald PARAMS((const char *s, char **end, int *overflow));
struct Value *Value_new_NIL PARAMS((struct Value *this));
struct Value *Value_new_ERROR PARAMS((struct Value *this, int code, const char *error, ...));
struct Value *Value_new_INTEGER PARAMS((struct Value *this, long n));
struct Value *Value_new_REAL PARAMS((struct Value *this, double n));
struct Value *Value_new_STRING PARAMS((struct Value *this));
struct Value *Value_new_VOID PARAMS((struct Value *this));
struct Value *Value_new_null PARAMS((struct Value *this, enum ValueType type));
int Value_isNull PARAMS((const struct Value *this));
void Value_destroy PARAMS((struct Value *this));
struct Value *Value_clone PARAMS((struct Value *this, const struct Value *original));
struct Value *Value_uplus PARAMS((struct Value *this, int calc));
struct Value *Value_uneg PARAMS((struct Value *this, int calc));
struct Value *Value_unot PARAMS((struct Value *this, int calc));
struct Value *Value_add PARAMS((struct Value *this, struct Value *x, int calc));
struct Value *Value_sub PARAMS((struct Value *this, struct Value *x, int calc));
struct Value *Value_mult PARAMS((struct Value *this, struct Value *x, int calc));
struct Value *Value_div PARAMS((struct Value *this, struct Value *x, int calc));
struct Value *Value_idiv PARAMS((struct Value *this, struct Value *x, int calc));
struct Value *Value_mod PARAMS((struct Value *this, struct Value *x, int calc));
struct Value *Value_pow PARAMS((struct Value *this, struct Value *x, int calc));
struct Value *Value_and PARAMS((struct Value *this, struct Value *x, int calc));
struct Value *Value_or PARAMS((struct Value *this, struct Value *x, int calc));
struct Value *Value_xor PARAMS((struct Value *this, struct Value *x, int calc));
struct Value *Value_eqv PARAMS((struct Value *this, struct Value *x, int calc));
struct Value *Value_imp PARAMS((struct Value *this, struct Value *x, int calc));
struct Value *Value_lt PARAMS((struct Value *this, struct Value *x, int calc));
struct Value *Value_le PARAMS((struct Value *this, struct Value *x, int calc));
struct Value *Value_eq PARAMS((struct Value *this, struct Value *x, int calc));
struct Value *Value_ge PARAMS((struct Value *this, struct Value *x, int calc));
struct Value *Value_gt PARAMS((struct Value *this, struct Value *x, int calc));
struct Value *Value_ne PARAMS((struct Value *this, struct Value *x, int calc));
int Value_exitFor PARAMS((struct Value *this, struct Value *limit, struct Value *step));
void Value_errorPrefix PARAMS((struct Value *this, const char *prefix));
void Value_errorSuffix PARAMS((struct Value *this, const char *suffix));
struct Value *Value_new_typeError PARAMS((struct Value *this, enum ValueType t1, enum ValueType t2));
struct Value *Value_retype PARAMS((struct Value *this, enum ValueType type));
struct String *Value_toString PARAMS((struct Value *this, struct String *s, char pad, int headingsign, size_t width, int commas, int dollar, int dollarleft, int precision, int exponent, int trailingsign));
struct Value *Value_toStringUsing PARAMS((struct Value *this, struct String *s, struct String *using, size_t *usingpos));
struct String *Value_toWrite PARAMS((struct Value *this, struct String *s));
struct Value *Value_nullValue PARAMS((enum ValueType type));

#undef PARAMS

#endif
