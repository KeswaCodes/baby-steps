#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define ARG_MAX 20
/**
 *main- simple shell
 *Return: 0
 */
void sigquit_handler(int signum);

char *const *environ;

int main(void)
{

  size_t n = 0;
  ssize_t input;
  int status, cp, i;
  const char *cwd = getcwd(NULL, 0);
  char *lineptr = NULL, *tokenized, *args[ARG_MAX] = {NULL};


  
for (i = 0; ; i++)
{
printf("$ ");
input = getline(&lineptr, &n, stdin);
 if (input == -1)
   return (-1);
signal(SIGINT, sigquit_handler);

    cp = fork();
    if (cp == 0)
      {
	tokenized = strtok(lineptr, " .,/!");
	while (tokenized != NULL)
	  {
	    args[i] = malloc(strlen(tokenized) + 1);
	    strcpy(args[i], tokenized);
	    i++;
	    tokenized = strtok(NULL, " .,/!");
	  }
	printf("%s ", *args);
	execve(cwd, args, environ);
      }
    else if (cp > 0)
      wait(&status);
 }

  return (0);
}


void sigquit_handler(int signum)
{
  if (signum == SIGQUIT)
    printf("ERR: SIGQUIT\nTerminating shell session...\n");
  exit (0);

}
