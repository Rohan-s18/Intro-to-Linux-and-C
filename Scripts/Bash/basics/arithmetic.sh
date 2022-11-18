#! /bin/bash

#Numerical Expressins have to be stored in the following format into variables
#var=$((expression))

#In this script, we will take user input in terms of numbers and returns the sum of the 2 numbers

echo "Enter a number"
read a

echo "Enter another number"
read b

sum=$((a+b))
echo "The sum is: $sum"


