#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_numbers.h"

int main(int argc, char const *argv[])
{
  char str[100] = "\0";

  printf("Enter your numbers :\n");
  fgets(str, 100, stdin);

  printf("%s\n", read(str));

  return 0;
}
