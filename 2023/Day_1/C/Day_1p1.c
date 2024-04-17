#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *filename = "../input_part1.txt";
  FILE *fp = fopen(filename, "r");

  if (fp == NULL) {
    // printf("Error: could not open file %s", filename);
    return 1;
  }

  int character;
  char first_num;
  char last_num;
  bool nl = true;
  char num[2];
  int total = 0;

  // Need to iterate over current line
  // get first and last number characters
  // and concat them. Then, convert those numbers into
  // an integer. Add that number to some total variable.
  // Print that variable at end of program for result.
  while ((character = fgetc(fp)) != EOF) {
    // printf("Character: %c, %d | %d\n", character, character, nl);
    if (character == '\n') {
      total += num[0];
      total += num[1];
      // printf("Num: %d%d\n", num[0] / 10, num[1]);
      num[0] = 0;
      num[1] = 0;
      // printf("<<Newline>>\n");
      nl = true;
      continue;
    }
    switch (character) {
    case 48 ... 57:
      if (nl == true) {
        nl = false;
        num[1] = character - 48;
        num[0] = num[1] * 10;
      } else {
        num[1] = character - 48;
      }
      nl = false;
      break;
    default:
      break;
    }
  }

  printf("Input file -> %s\n", filename);
  printf("Total: %d\n", total);
  fclose(fp);
  return 0;
}
