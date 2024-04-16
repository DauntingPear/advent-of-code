#include <stdio.h>
#include <stdlib.h>

int main() {
  char *filename = "input.txt";
  FILE *fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Error: could not open file %s", filename);
    return 1;
  }

  const unsigned MAX_LENGTH = 256;
  char buffer[MAX_LENGTH];

  while (fgets(buffer, MAX_LENGTH, fp)) {
    printf("%s", buffer);
  }

  fclose(fp);

  return 0;
}
