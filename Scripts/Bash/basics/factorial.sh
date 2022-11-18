#! /bin/bash

#This script will show us how to find the factorial of a given number 

echo "Enter a number:"
read a

i=a
fact=1
while [[ $i -gt 1 ]] ; do
	((fact *= i ))
	((i -= 1))
done

echo "$a factorial is $fact"
