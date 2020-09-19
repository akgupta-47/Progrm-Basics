#!/bin/bash
echo "enter your password"
read passW
sum=0
len="${#passW}"

if [ $len -ge 8 ] then
echo "$passW" | grep -q [0-9]
if [ $? -eq 0 ] then
echo "$passW" | grep -q [A-Z]
if [ $? -eq 0 ] then
echo "$passW" | grep -q [a-z]   
if [ $? -eq 0 ] 
then
echo "Strong password"
else 
then
echo "weak password include lower case chars"
fi
else
echo "weak password include capital chars" 
fi
else
echo "please include the numbers in password it is weak password"   
fi
else
echo "password lenght should be greater than or equal 8 hence weak password"
fi
