#! /usr/bin/bash

#printing the virtual memory map of this bash process and sending it to the command line argument file

cat /proc/$$/maps > $1

echo Tranfer Completed!
