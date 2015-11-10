#!/bin/sh

while read first; do
  while read last; do
    age=`expr $RANDOM % 25 + 20`
    printf "$first:$last:$age\n" >> names.txt
  done < last.txt
done < first.txt
