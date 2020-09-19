#!bin/bash
echo "enter a"
read a
echo "enter b"
read b
multi = `expr $a \* $b`
echo "the product is $multi"
