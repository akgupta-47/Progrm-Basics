#!/bin/bash
echo "the name of file is $0"
echo "the first arg is $1"
echo "the second arg is $2"
echo " all args 9+ in {} so 10th is ${10}"
echo "the process id is $$"
echo "arg using \$@ are $@"
echo $*
echo "num of args $#"
