#!/bin/bash
<<'comment*'
this brings multi line
comment
comment*

echo "enter name"
read name
case $name in
"dhondhu")
echo "$name beta just chill"
;;
"binod" | "ambani")
echo "$name is rich"
;;
"bablu")
echo "$name will be the next meme"
;;
esac
