#include "main.h"
/**
 *setenv- changes or adds env variable
 *Return: 0 - success, -1 failure
 */

int _setenv(const char *name, const char *value, int overwrite)
{

  char *variable, *result = NULL;
  int i, j, m, k;
  
if (name == NULL)
    return (-1);

 /*get length of variable name*/
 for (i = 0; name[i] != '\0'; i++)
{
  /*check whether name is in uppercase*/
  if (!(name[i] >= 'A' && name[i] <= 'Z'))
    return (-1);
}
 if (value == NULL)
   return (-1);
  printf("%s\n", result);
 for (j = 0; value[j] != '\0'; j++)
   ;
 /*allocate space for env var name & value*/
 result = malloc(j + i + 1);
 if (result == NULL)
   return (-1);
 /*copy var name into malloc'd string*/
 for (k = 0; k < i; k++)
   result[k] = name[k];

 result[k] = '=';
 /*copy value into string*/
 for (m = 0; m < (j + k); m++)
     result[k + m] = value[m];

 result[k + m] = '\0';

 /*check if variable exists*/
  variable = _getenv(name);
  if (variable == NULL || overwrite == 1)
    putenv(result);



  return (0);
}

int main(void)
{

  int res = _setenv("PATH", "HELLO", 0);
  if (res == -1)
    return (-1);
  return (0);
  
}
