#include <stdio.h>

/**
 *main- reads a line using getline() functions
 *Return: number of lines read
 */

int main(void)
{
char *lineptr = NULL;
size_t n = 0;
ssize_t result;
 
  printf("$ ");
  result = getline(&lineptr, &n, stdin);
  printf("%s", lineptr);

  return (result);
}
