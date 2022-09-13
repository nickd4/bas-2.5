#ifndef STR_H
#define STR_H

#include <sys/types.h>

struct String
{
  size_t length;
  char *character;
  struct StringField *field;
};

struct StringField
{
  struct String **refStrings;
  int refCount;
};

#if __STDC__
#define PARAMS(s) s
#else
#define PARAMS(s) ()
#endif

/* str.c */
int cistrcmp PARAMS((/*const*/ char *s, const char *r));
struct String *String_new PARAMS((struct String *this));
void String_destroy PARAMS((struct String *this));
int String_joinField PARAMS((struct String *this, struct StringField *field, char *character, size_t length));
void String_leaveField PARAMS((struct String *this));
struct String *String_clone PARAMS((struct String *this, /*const*/ struct String *original));
int String_size PARAMS((struct String *this, size_t length));
int String_appendString PARAMS((struct String *this, /*const*/ struct String *app));
int String_appendChar PARAMS((struct String *this, int/*char*/ ch));
int String_appendChars PARAMS((struct String *this, /*const*/ char *ch));
int String_appendPrintf PARAMS((struct String *this, /*const*/ char *fmt, ...));
int String_insertChar PARAMS((struct String *this, size_t where, int/*char*/ ch));
int String_delete PARAMS((struct String *this, size_t where, size_t len));
void String_ucase PARAMS((struct String *this));
void String_lcase PARAMS((struct String *this));
int String_cmp PARAMS((/*const*/ struct String *this, const struct String *s));
int String_quote PARAMS((struct String *this));
void String_lset PARAMS((struct String *this, /*const*/ struct String *s));
void String_rset PARAMS((struct String *this, /*const*/ struct String *s));
void String_set PARAMS((struct String *this, size_t pos, /*const*/ struct String *s, size_t length));
struct StringField *StringField_new PARAMS((struct StringField *this));
void StringField_destroy PARAMS((struct StringField *this));

/*#undef PARAMS*/

#endif
