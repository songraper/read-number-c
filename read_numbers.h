#ifndef DEF_READ_NUMBERS
#define DEF_READ_NUMBERS

char *read_per_unit(char a);
char *read_hundreds(char a[], int mod);
void split_string(char temp[], char blank[], int a, int b);
void padding_0(char s[], char temp[]);
char *read(char s[]);

void read_per_unit_test();
void read_hundreds_test();
void split_string_test();
void read_test();

#endif
