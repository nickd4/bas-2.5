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

extern int cistrcmp();

extern struct String *String_new();
extern void String_destroy();
extern int String_joinField();
extern void String_leaveField();
extern struct String *String_clone();
extern int String_appendString();
extern int String_appendChar();
extern int String_appendChars();
extern int String_appendPrintf();
extern int String_insertChar();
extern int String_delete();
extern void String_ucase();
extern void String_lcase();
extern int String_size();
extern int String_cmp();
extern int String_quote();
extern void String_lset();
extern void String_rset();
extern void String_set();

extern struct StringField *StringField_new();
extern void StringField_destroy();

#endif
