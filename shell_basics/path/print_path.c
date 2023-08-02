#include "main.h"
/**
 *main- prints each directory in the variable PATH
 *each directory on a new line
 *Return: 0 - success, -1 otherwise
 */

int main(void)
{
  char *path, *token;
  int j;
  
  path = _getenv("PATH");

  if (path == NULL)
    return (-1);

 token = strtok(path, ":");
 while (token != NULL)
   {
     for (j = 0; token[j] != '\0'; j++)
       {
printchar(token[j]);

       }
     
     printchar('\n');
     token = strtok(NULL, ":");
   }

 return (0);
}
