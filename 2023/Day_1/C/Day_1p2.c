#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int parse_calibration_buffer(char *buf) {
  int i = 0;
  while (buf[i] != 0) {
    printf("%c", buf[i]);
    i++;
  }
  printf("\n");
  return 0;
}

int main() {
  char *filename = "../test_part2.txt";
  FILE *fp = fopen(filename, "r");

  if (fp == NULL) {
    // printf("Error: could not open file %s", filename);
    return 1;
  }

  int character;
  char buf[256];
  int i = 0;

  // Need to iterate over current line

  while (character != EOF) {
    character = fgetc(fp);
    if (character == '\n') {
      i = 0;
      // pass buffer to function to handle and return value of that line
      i = parse_calibration_buffer(buf);
    } else {
      buf[i] = character;
    }
    i++;
  }

  fclose(fp);
  return 0;
}
