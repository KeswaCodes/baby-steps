#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 *main- simple shell by zinksw@gmail.com
 *Return: 1 - success, -1 failure
 */

extern char **environ;

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{

  int i, status, process, j = 0;
  ssize_t input;
  size_t n = 0;
  char *lineptr = NULL, *tokens, *data = "$ " , **args;


  for (i = 0; ; i++)
    {
      write(STDOUT_FILENO, data, 3);
      input = getline(&lineptr, &n, stdin);
      if (input == -1)
	return (-1);

      if (lineptr[input - 1] == '\n')
	lineptr[input - 1] = '\0';
      
      process = fork();
      if (process == 0)
	{
	  if (lineptr == NULL)
	    continue;
	  /*malloc the space for the arguments*/
	  args = malloc(sizeof(char *) * n);
	  if (args == NULL)
	    return (-1);

	  /*tokenize arguments*/
	  tokens = strtok(lineptr, " ");
	  while(tokens != NULL)
	    {
	      args[j] = tokens;
	      tokens = strtok(NULL, " ");
	      j++;
	    }

	  args[j] = NULL;

	  execve(args[0], args, environ);
	  if (execve(args[0], args, environ) == -1)
	    continue;

	  else
	    wait(&status);


	}

      else if (process > 0)
      wait(&status);


      else
	return (-1);
    }

  free(args);
  free(lineptr);
  return (0);
}
