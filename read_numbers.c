#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_numbers.h"
char *read_per_unit(char a)
{
  char *read_unit = malloc(5 * sizeof(char));
  char string[10][7] = {"Khong ", "Mot ", "Hai ", "Ba ", "Bon ", "Nam ", "Sau ", "Bay ", "Tam ", "Chin "};

  switch (a)
  {
  case '0':
  {
    strcpy(read_unit, string[0]);
    break;
  }
  case '1':
  {
    strcpy(read_unit, string[1]);
    break;
  }
  case '2':
  {
    strcpy(read_unit, string[2]);
    break;
  }
  case '3':
  {
    strcpy(read_unit, string[3]);
    break;
  }
  case '4':
  {
    strcpy(read_unit, string[4]);
    break;
  }
  case '5':
  {
    strcpy(read_unit, string[5]);
    break;
  }
  case '6':
  {
    strcpy(read_unit, string[6]);
    break;
  }
  case '7':
  {
    strcpy(read_unit, string[7]);
    break;
  }
  case '8':
  {
    strcpy(read_unit, string[8]);
    break;
  }
  case '9':
  {
    strcpy(read_unit, string[9]);
    break;
  }
  }

  return read_unit;
}

char *read_hundreds(char a[], int mod)
{
  char *str = malloc(500 * sizeof(char));
  char read_tram[] = "Tram ";

  if (mod == 0)
  {
    if (a[0] != '0')
    {
      strcat(str, read_per_unit(a[0]));
      strcat(str, read_tram);
    }
  }
  else if (mod == 1)
  {
    if (a[1] != '0' || a[2] != '0')
    {
      strcat(str, read_per_unit(a[0]));
      strcat(str, read_tram);
    }
  }
  if (a[1] == '0')
  {
    if (a[0] != '0' && a[2] != '0' || a[2] != '0' && mod == 1)
    {
      char read_le[] = "Le ";
      strcat(str, read_le);
    }
  }
  else if (a[1] == '1')
  {
    char read_1[] = "Muoi` ";
    strcat(str, read_1);
  }
  else
  {
    char read_muoi[] = "Muoi ";
    strcat(str, read_per_unit(a[1]));
    strcat(str, read_muoi);
  }

  if (a[2] == '5')
  {
    char read_lam[] = "Lam ";
    if (a[1] != '0')
    {
      strcat(str, read_lam);
    }
    else
    {
      strcat(str, read_per_unit(a[2]));
    }
  }

  else if (a[2] != '0')
  {
    strcat(str, read_per_unit(a[2]));
  }

  return str;
}

void split_string(char temp[], char blank[], int a, int b)
{
  int j = 0;

  for (int i = a; i <= b; i++)
  {
    blank[j] = temp[i];
    j++;
  }
  blank[j] = '\0';
}

void padding_0(char s[], char temp[])
{
  int n = strlen(s) - 1;

  printf("++ %d\n", n);
  if (n % 3 == 0)
  {
    strcpy(temp, s);
  }

  else
  {
    for (int i = 0; i < (3 - (n % 3)); i++)
    {
      temp[i] = '0';
    }
    for (int k = 0; k < n; k++)
    {
      temp[k + (3 - (n % 3))] = s[k];
    }

    temp[n + (3 - (n % 3))] = '\0';
  }
}

char *read(char s[])
{
  char *str = malloc(300 * sizeof(char));
  char temp[300] = "\0", blank[3] = "\0";

  padding_0(s, temp);

  int m = strlen(temp);

  printf("==> %d\n", m);
  int loop = m / 3;
  printf("%d\n", loop);


  int a = 0, b = 2, k = loop;

  for (int i = 0; i < loop; i++)
  {
    if (i == 0)
    {
      split_string(temp, blank, a, b);
      strcat(str, read_hundreds(blank, 0));
    }
    else
    {
      split_string(temp, blank, a, b);
      strcat(str, read_hundreds(blank, 1));
    }

    if (k > 4)
    {
      if (blank[0] != '0' || blank[1] != '0' || blank[2] != '0')
      {
        switch (k)
        {
        case 7:
        {
          char read_ty_ty[] = "Ty Ty ";
          strcat(str, read_ty_ty);
          break;
        }
        case 6:
        {
          char read_trieu_ty[] = "Trieu Ty ";
          strcat(str, read_trieu_ty);
          break;
        }
        case 5:
        {
          char read_nghin_ty[] = "Nghin Ty ";
          strcat(str, read_nghin_ty);
          break;
        }
        }
      }
    }
    else
    {
      if (i == loop - 1)
      {
        char read_dong[] = "Dong ";
        strcat(str, read_dong);
      }
      else if (blank[0] != '0' || blank[1] != '0' || blank[2] != '0')
      {
        switch(k)
        {
          case 4:
          {
            char read_ty[] = "Ty ";
            strcat(str, read_ty);
            break;
          }
          case 3:
          {
            char read_trieu[] = "Trieu ";
            strcat(str, read_trieu);
            break;
          }
          case 2:
          {
            char read_nghin[] = "Nghin ";
            strcat(str, read_nghin);
            break;
          }
        }
      }
    }

    a += 3;
    b += 3;
    k--;
  }

  return str;
}
