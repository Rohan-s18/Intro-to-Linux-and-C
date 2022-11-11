#! /bin/bash

#This code will calculate the factorial of a given input using a while loop

#Getting the frist user input
counter=$1

factorial=1

#Looping while the counter is greater than 0
while [ $counter -gt 0 ]
do
	factorial = $(( $factorial * $counter ))
	counter = $(( $counter - 1 ))
done

echo the factorial of $1 is $factorial
