#include <stdio.h>
#include <string.h>
/**
 *main- splits a string and returns an array of each word of the string
 *Return: each word of the string
 */

int main(void)
{
  char str[] = "Hi World, I am Zinhle, an ALX Student!";
  char delim[] = " ,!";
    char *result;

result = strtok(str, delim);
while (result != NULL)
  {
    printf("%s\n", result);
    result = strtok(NULL, delim);
  }
  return (0);
}
