#!/bin/bash

#until
echo "give value"
a=20
until [	$a -gt 30 ]
do
	echo $a
	a=`expr $a + 1`
done

#while loops
<<"while"
echo "--while--"
a=10
while [ $a -lt 20 ]
do
 echo $a
a=`expr $a + 1`
done

echo "----------------"
a=20
while [ $a -gt 0 -a $a -lt 25 ]
do
 echo $a
a=`expr $a + 1`
done
while

<<"for"
echo "--for--"
for i in 1 2 3 4 5 6
do 
echo `expr $i+1`
done
echo "-----------------"
for name in dhondhu binod bablu
do 
echo $name
done
echo "-----------------"
for file in $HOME/*.sh
do 
echo $file
done
for



