#!/bin/bash
echo "enter a"
read a
echo "enter b"
read b

echo "a is $a and b is $b"

if [$a -gt $b ]
then echo "a is greter than b"
elif [$a -eq $b]
then echo "a is equal to b"
else echo "good bye"
fi
echo "we need fi to close stetement of if"

echo "check is string is empty or not"
read NAME
if[ -z $NAME ]
then echo "string has zero lenght"
else echo "the string has non zero lenght"
fi
