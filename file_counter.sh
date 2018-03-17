#!/bin/bash
find . -type d -print0 | while read -d '' -r dir; do
       files=("$dir"/*)
       printf "%5d files in directory %s\n" "${#files[@]}" "$dir"
done
printf 'number of README:'
find -name *README | wc -l
printf 'number of Kconfig files:'
find -name *Kconfig | wc -l
printf 'number of Kbuild files:'
find -name *Kbuild | wc -l
printf 'number of Makefiles:'
find -name *Makefile | wc -l
printf 'number of C files:'
find -name *.c | wc -l
printf 'number of H files:'
find -name *.h | wc -l
printf 'number of PL files:'
find -name *.pl | wc -l
for file in $(find . -type f);do
       if grep -q "#include <linux/module.h>" $file
       then
       buscarLibreria=$((buscarLibreria+1))
       fi
done
printf 'Archivos que contienen #include <linux/module.h>: %d' "$buscarLibreria"
mkdir -p C_FILES
mkdir -p H_FILES
for fh in $(find -name *.h); do cp $fh H_FILES; done;
for fc in $(find -name *.c); do cp $fc C_FILES; done;
cd H_FILES
printf 'number of H files:'
find -name *.h | wc -l
cd ..
cd C_FILES
printf 'number of C files:'
find -name *.c | wc -l
