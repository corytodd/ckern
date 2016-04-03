#!/bin/sh
# Rename OS

set -e

old="$1"
new="$2"
echo "Replacing $old with $new"...

count=0

for file in $(find . -name '*.c' -or -name '*.h' -or -name '*.sh' \
								 -or -name '*.s' -or -name 'Makefile'); do 
	if [ -f $file ] && [ -w $file ] && grep -q "$old" "$file" ; then	
	echo "Updating $file"
	sed -i -- "s/$old/$new/g" "$file"
	count=$((count+1))
	fi

done

echo "Updated $count files"
