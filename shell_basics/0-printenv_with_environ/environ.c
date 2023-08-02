#include "main.h"

/**
 *main- prints the environmental variable using environ
 *Return: 0 - success
 */

extern char **environ;

int main(void)
{

  int i = 0, j = 0;
  
  while (environ[i] != NULL)
    {
      j = 0;
      while (environ[i][j] != '\0')
	{
	  if (printchar(environ[i][j]))
	    j++;
	  else
	    perror("Error printing variable");
	}
      printchar('\n');
      i++;

	}
    return (0);
}
