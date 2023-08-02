#include <limits.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#define PATH_SIZE 1024

/**
 *main- looks for files in PATH
 *Return: 0 - success, -1 otherwise
 */

int file_check(const char *path_file, const char *input);

int main(int argc, char *argv[])
{

const char *command, *path_tokens;
  char *path_var;
  
  if (argc < 2)
    return (-1);

  command = argv[1];
  path_var = getenv("PATH");

  if (path_var == NULL)
    return (-1);

  path_tokens = strtok(path_var, ":");


  while(path_tokens != NULL)
    {
       
      if (file_check(path_tokens, command))
	{

	printf("%s/%s\n", path_tokens, command);
	break;
	}

      else
	path_tokens = strtok(NULL, ":");
    }
  return (0);
}

int file_check(const char *path_file, const char *input)
{

  char path[PATH_MAX];
  struct stat file;
  
  snprintf(path, sizeof(path), "%s/%s", path_file, input);

  if (stat(path, &file) == 0 && S_ISREG(file.st_mode))
    return (1);


  return (0);

}


