#!/bin/bash

myFun()
{
	echo "this is my first shell script function"
	return
}

function secondFun
{
 echo "my seconf shell script funcion"
 return
}
echo -n "print first functon: "
myFun
echo -n "print second functon: "
secondFun

function sumFun
{
 echo "lets add numbers"
 sum=`expr $1 + $2`
 echo "sum is $sum"
}
sumFun 1 2

function payMe
{
 echo "what is your name"
 read name
 echo "$name here is your $1"
 return 8
}
#payMe 300
#returnedArg=$?
#echo "you returned $returnedArg"

function spendMoney
{
 echo "how much money can you give"
  payMe 300
}
spendMoney

function multiArg
{
 echo "you called us with : $@"
 x=2
}
multiArg 9 5 9 9 4 2 0 5 7 0
echo "also the x was $x"

