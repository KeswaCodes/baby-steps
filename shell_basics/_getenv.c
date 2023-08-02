#include "main.h"
#include <stddef.h>
#include <stdlib.h>

extern char **environ;

char *_getenv(const char *name)
{
  int i, j = 0, k;
  size_t len = 0;
  char *var;
  
  if (name == NULL)
        return NULL;

    for (i = 0; environ[i] != NULL; i++)
    {
        
      while (name[j] != '\0' && name[j] == environ[i][j])
	j++;
      
if (name[j] == '\0' && environ[i][j] == '=')
        {

            while (environ[i][j + 1 + len] != '\0')
                len++;

            var = (char *)malloc(len + 1);
            if (var == NULL)
	      return (NULL);

            for (k = 0; k < len; k++)
                var[k] = environ[i][j + 1 + k];

            var[len] = '\0';
            return (var);
        }
	  
                
    }

    return (NULL);
}
