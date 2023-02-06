#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main() {
  char line[MAX_LINE_LENGTH];
  
  while (fgets(line, MAX_LINE_LENGTH, stdin)) {
    if (strncmp(line, "PRINT", 5) == 0) {
      printf("printf(\"%s\");\n", line + 6);
    }
  }
  
  return 0;
}

