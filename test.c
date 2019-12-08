#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_numbers.h"

int main(int argc, char const *argv[])
{
  read_per_unit_test();
  read_hundreds_test();
  split_string_test();
  read_test();
  return 0;
}

void read_per_unit_test()
{
  char test_data[5] = "15034";
  char result[5][7] = {"Mot ", "Nam ", "Khong ", "Ba ", "Bon "};

  for (int i = 0; i < 5; i++)
  {
    if (strcmp(result[i], read_per_unit(test_data[i])) == 0)
    {
      printf("Right \n");
    }
    else
    {
      printf("Wrong %c -> %s \n", test_data[i], result[i]);
    }
  }
}

void read_hundreds_test()
{
  char test_data[5][4] = {"012", "203", "256", "415", "400"};
  char result[5][50] = {"Muoi` Hai ", "Hai Tram Le Ba ", "Hai Tram Nam Muoi Sau ", "Bon Tram Muoi` Lam ", "Bon Tram "};

  for (int i = 0; i < 5; i++)
  {
    if (strcmp(result[i], read_hundreds(test_data[i], 0)) == 0)
    {
      printf("Right \n");
    }
    else
    {
      printf("Wrong %s -> %s \n", read_hundreds(test_data[i], 0), result[i]);
    }
  }
}

void split_string_test()
{
  char test_data[5][7] = {"012", "20345", "251236", "417695", "40220"};
  char temp[5][4] = {"", "", "", "", ""};
  char result[5][4] = {"012", "203", "251", "417", "402"};

  for (int i = 0; i < 5; i++)
  {
    split_string(test_data[i], temp[i], 0, 2);
    if (strcmp(result[i], temp[i]) == 0)
    {
      printf("Right \n");
    }
    else
    {
      printf("Wrong %s -> %s \n", test_data[i], result[i]);
    }
  }
}

void read_test()
{
  char test_data[5][30] = {"012\n", "12203\n", "256\n", "1000415\n", "6000000000\n"};
  char result[5][300] = {"Muoi` Hai Dong\n", "Muoi` Hai Nghin Hai Tram Le Ba Dong\n", "Hai Tram Nam Muoi Sau Dong\n", "Mot Trieu Bon Tram Muoi` Lam Dong\n", "Sau Ty Dong\n"};

  for (int i = 0; i < 5; i++)
  {
    if (strcmp(result[i], read(test_data[i])) == 0)
    {
      printf("Right \n");
    }
    else
    {
      printf("Wrong %s -> %s \n", read(test_data[i]), result[i]);
    }
  }
}
