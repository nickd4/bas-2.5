/* Dyanamic strings. */
/* #includes */ /*{{{C}}}*//*{{{*/
#include "config.h"

#include <assert.h>
#include <ctype.h>
#ifdef __STDC__
#include <stdarg.h>
#include <stddef.h>
#else
#include <varargs.h>
#endif
#include <stdio.h>
#ifdef __STDC__
#include <stdlib.h>
#else
void *realloc();
#endif
#include <string.h>

#include "str.h"

#ifdef USE_DMALLOC
#include "dmalloc.h"
#endif
/*}}}*/

int cistrcmp(s, r)
/*const*/ char *s;
/*const*/ char *r; /*{{{*/
{
  assert(s!=(char*)0);
  assert(r!=(char*)0);
  while (*s && tolower(*s)==tolower(*r)) { ++s; ++r; };
  return ((tolower(*s)-tolower(*r)));
}
/*}}}*/

struct String *String_new(this)
struct String *this; /*{{{*/
{
  assert(this!=(struct String*)0);
  this->length=0;
  this->character=(char*)0;
  this->field=(struct StringField*)0;
  return this;
}
/*}}}*/
void String_destroy(this)
struct String *this; /*{{{*/
{
  assert(this!=(struct String*)0);
  if (this->field) String_leaveField(this);
  if (this->length) free(this->character);
}
/*}}}*/
int String_joinField(this, field, character, length)
struct String *this;
struct StringField *field;
char *character;
size_t length; /*{{{*/
{
  struct String **n;

  assert(this!=(struct String*)0);
  if (this->field) String_leaveField(this);
  this->field=field;
  if ((n=(struct String**)realloc(field->refStrings,sizeof(struct String*)*(field->refCount+1)))==(struct String**)0) return -1;
  field->refStrings=n;
  field->refStrings[field->refCount]=this;
  ++field->refCount;
  if (this->length) free(this->character);
  this->character=character;
  this->length=length;
  return 0;
}
/*}}}*/
void String_leaveField(this)
struct String *this; /*{{{*/
{
  struct StringField *field;
  int i;
  struct String **ref;

  assert(this!=(struct String*)0);
  field=this->field;
  assert(field!=(struct StringField*)0);
  for (i=0,ref=field->refStrings; i<field->refCount; ++i,++ref)
  {
    if (*ref==this)
    {
      int further=--field->refCount-i;

      if (further) memmove(ref,ref+1,further*sizeof(struct String**));
      this->character=(char*)0;
      this->length=0;
      this->field=(struct StringField*)0;
      return;
    }
  }
  assert(0);
}
/*}}}*/
struct String *String_clone(this, original)
struct String *this;
/*const*/ struct String *original; /*{{{*/
{
  assert(this!=(struct String*)0);
  String_new(this);
  String_appendString(this,original);
  return this;
}
/*}}}*/
int String_size(this, length)
struct String *this;
size_t length; /*{{{*/
{
  char *n;

  assert(this!=(struct String*)0);
  if (this->field) String_leaveField(this);
  if (length)
  {
    if (length>this->length)
    {
      if ((n=realloc(this->character,length+1))==(char*)0) return -1;
      this->character=n;
    }
    this->character[length]='\0';
  }
  else
  {
    if (this->length) free(this->character);
    this->character=(char*)0;
  }
  this->length=length;
  return 0;
}
/*}}}*/
int String_appendString(this, app)
struct String *this;
/*const*/ struct String *app; /*{{{*/
{
  size_t oldlength=this->length;

  if (this->field) String_leaveField(this);
  if (app->length==0) return 0;
  if (String_size(this,this->length+app->length)==-1) return -1;
  memcpy(this->character+oldlength,app->character,app->length);
  return 0;
}
/*}}}*/
int String_appendChar(this, ch)
struct String *this;
int/*char*/ ch; /*{{{*/
{
  size_t oldlength=this->length;

  if (this->field) String_leaveField(this);
  if (String_size(this,this->length+1)==-1) return -1;
  this->character[oldlength]=ch;
  return 0;
}
/*}}}*/
int String_appendChars(this, ch)
struct String *this;
/*const*/ char *ch; /*{{{*/
{
  size_t oldlength=this->length;
  size_t chlen=strlen(ch);

  if (this->field) String_leaveField(this);
  if (String_size(this,this->length+chlen)==-1) return -1;
  memcpy(this->character+oldlength,ch,chlen);
  return 0;
}
/*}}}*/
#ifdef __STDC__
int String_appendPrintf(
  struct String *this,
  /*const*/ char *fmt,
  ...
)
#else
int String_appendPrintf(this, fmt, va_alist)
struct String *this;
/*const*/ char *fmt;
va_dcl
#endif
/*{{{*/
{
  char buf[1024];
  size_t l,j;
  va_list ap;

  if (this->field) String_leaveField(this);
#ifdef __STDC__
   va_start(ap, fmt);
#else
  va_start(ap);
#endif
  l=vsprintf(buf,fmt,ap);
  va_end(ap);
  j=this->length;
  if (String_size(this,j+l)==-1) return -1;
  memcpy(this->character+j,buf,l);
  return 0;
}
/*}}}*/
int String_insertChar(this, where, ch)
struct String *this;
size_t where;
int/*char*/ ch; /*{{{*/
{
  size_t oldlength=this->length;

  if (this->field) String_leaveField(this);
  assert(where<=oldlength);
  if (String_size(this,this->length+1)==-1) return -1;
  memmove(this->character+where+1,this->character+where,oldlength-where);
  this->character[where]=ch;
  return 0;
}
/*}}}*/
int String_delete(this, where, len)
struct String *this;
size_t where;
size_t len; /*{{{*/
{
  size_t oldlength=this->length;

  if (this->field) String_leaveField(this);
  assert(where<oldlength);
  assert(len>0);
  if ((where+len)<oldlength) memmove(this->character+where,this->character+where+len,oldlength-where-len);
  this->character[this->length-=len]='\0';
  return 0;
}
/*}}}*/
void String_ucase(this)
struct String *this; /*{{{*/
{
  size_t i;

  for (i=0; i<this->length; ++i) this->character[i]=toupper(this->character[i]);
}
/*}}}*/
void String_lcase(this)
struct String *this; /*{{{*/
{
  size_t i;

  for (i=0; i<this->length; ++i) this->character[i]=tolower(this->character[i]);
}
/*}}}*/
int String_cmp(this, s)
/*const*/ struct String *this;
/*const*/ struct String *s; /*{{{*/
{
  size_t pos;
  int res;
  /*const*/ char *thisch,*sch;

  for (pos=0,thisch=this->character,sch=s->character; pos<this->length && pos<s->length; ++pos,++thisch,++sch)
  {
    if ((res=(*thisch-*sch))) return res;
  }
  return (this->length-s->length);
}
/*}}}*/
int String_quote(this)
struct String *this; /*{{{*/
{
  size_t i;

  for (i=0; i<this->length; ++i)
  {
    int ch;

    ch=this->character[i];
    if (!isalpha(ch) && !isdigit(ch) && ch!='*' && ch!='?' && ch!='[' && ch!=']')
    {
      if (String_insertChar(this, i, '\\')==-1) return -1;
      ++i;
    }
  }
  return 0;
}
/*}}}*/
void String_lset(this, s)
struct String *this;
/*const*/ struct String *s; /*{{{*/
{
  size_t copy;

  copy=(this->length<s->length ? this->length : s->length);
  if (copy) memcpy(this->character,s->character,copy);
  if (copy<this->length) memset(this->character+copy,' ',this->length-copy);
}
/*}}}*/
void String_rset(this, s)
struct String *this;
/*const*/ struct String *s; /*{{{*/
{
  size_t copy;

  copy=(this->length<s->length ? this->length : s->length);
  if (copy) memcpy(this->character+this->length-copy,s->character,copy);
  if (copy<this->length) memset(this->character,' ',this->length-copy);
}
/*}}}*/
void String_set(this, pos, s, length)
struct String *this;
size_t pos;
/*const*/ struct String *s;
size_t length; /*{{{*/
{
  if (this->length>=pos)
  {
    if (this->length<(pos+length)) length=this->length-pos;
    if (length) memcpy(this->character+pos,s->character,length);
  }
}
/*}}}*/

struct StringField *StringField_new(this)
struct StringField *this; /*{{{*/
{
  this->refStrings=(struct String**)0;
  this->refCount=0;
  return this;
}
/*}}}*/
void StringField_destroy(this)
struct StringField *this; /*{{{*/
{
  int i;

  for (i=this->refCount; i>0; ) String_leaveField(this->refStrings[--i]);
  this->refCount=-1;
  free(this->refStrings);
}
/*}}}*/
