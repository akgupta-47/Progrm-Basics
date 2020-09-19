#!/bin/bash
students=(daniel tom jack ryan)
echo "the values are ${students[@]}"
echo "the values are ${students[*]}"
echo "the values at 2nd index ${students[2]}"
echo "print all values starting from index ${students[@]:1}"

roll[0]=1
roll[1]=2
roll[2]=3
roll[3]=4
roll[4]=5
echo "the values are ${roll[@]}"

