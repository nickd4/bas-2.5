#!/bin/sh
mv getopt.c getopt.c1
sed -e 's/^# *include </\/\/AAA&/' -i *.[ch]
sed -e 's/^#include "dmalloc\.h"/\/\/AAA&/' -i *.[ch]
sed -e 's/\/\/AAA#include <sys\/types\.h>/#include "mytypes.h"&/' -i *.[ch]
sed -e 's/^_(/\/\/AAA&/' -i value.c
for i in *.c
do
  echo "========== $i ==========" >&2
  cproto -C "int f(a, b)" -F "int f(a, b)" -m -M PARAMS -t $i >$i.proto
done
sed -e 's/^.*\/\/AAA//' -i *.[ch]
mv getopt.c1 getopt.c
