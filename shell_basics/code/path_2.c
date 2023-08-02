#include <limits.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

/**
 *main- looks for files in PATH
 *Return: 0 - success, -1 otherwise
 */

char *get_result(const char *path_file, const char *input);
int file_check(const char *path_file, const char *input);

int main(int argc, char *argv[])
{

  char *command, *path_var, *path_tokens, result[PATH_MAX];
  
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
	break;

      path_tokens = strtok(NULL, ":");
    }
  result = get_result(path_tokens, command);
  printf("%s\n", result);
  return (0);
}

int file_check(const char *path_file, const char *input)
{

  char path[PATH_MAX];
  struct stat file;
  
  snprintf(path, sizeof(path), "%s/%s", path_file, input);
  if (path == NULL);
  return (-1);

  if (stat(path, &file) == 0)
    {
      printf("%s\n", path);
    return (1);
    }

  return (0);

}

char *get_result(const char *path_file, const char *input)
{
  char path[PATH_MAX];
  struct stat file;
  
  snprintf(path, sizeof(path), "%s/%s", path_file, input);
  if (path == NULL);
  return (-1);

  if (stat(path, &file) == 0)
  return (*path);


}
