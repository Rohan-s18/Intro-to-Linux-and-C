//
// Created by Rohan Singh on 3/15/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main() {
  char *mystring;
  char *laststring;
  char *lastlaststring;
  long long unfreed=0;
  mystring = malloc(sizeof(char));
  laststring = malloc(sizeof(char));
  lastlaststring = malloc(sizeof(char));
  for (int i=1; i<=100000; i++) {
    lastlaststring = laststring;
    laststring = mystring;
    // printf("%d\n",rand());
    if (rand() < .5*RAND_MAX) { if (0) printf("FREEING %d,%x\n",i,lastlaststring); if (lastlaststring) free(lastlaststring); unfreed -= (i-2)*sizeof(char); }
    mystring = malloc(i*sizeof(char)); unfreed += i*sizeof(char);
    for (int j=0; j<i; j++) *(mystring+j) = 'a';
    printf("\tALLOCATING %d,%x\n",i,mystring);
  }
  printf("\nUNFREED=%lld\n",unfreed);
  system("sleep 500");

}
