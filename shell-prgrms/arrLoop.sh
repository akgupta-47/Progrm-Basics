#!/bin/bash
echo "--for--"
name=(dhondhu binod bablu)
for i in ${name[@]}
do
echo $i
done

echo "--while--"
arr=(1 2 3 4 5)
i=0
while [$i -lt ${#arr[@]} ]
do
echo $i
done
