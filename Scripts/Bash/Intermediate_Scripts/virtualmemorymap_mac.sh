#! /bin/bash

#This file will print out the virtual memory map of this bash process to the given file

vmmap $$ > $1

echo Tranfer Completed!
