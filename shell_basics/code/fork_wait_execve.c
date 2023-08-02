#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

/**
 *main- executes a command for a child process 5 times
 *Return: 0 - success, 1 - failure
 */

char *const *environ;

int main(void)
{

  int status, cp[5], i = 1;
  char *const args[] = {"ls", "-l", "/tmp", NULL};
  const char *pathname = "/usr/bin/ls";

  while (i < 6)
    {
      cp[i] = fork();

  if (cp[i] == 0)
    {
      execve(pathname, args, environ);
      sleep(1);
    }
  else if (cp[i]> 0)
	   
    {
      wait(&status);

      if (WIFEXITED(status))
	printf("Child process %d complete with exit status: %d\n", i, WEXITSTATUS(status));
	
    }
  else
    perror("Error\n");
  i++;
}
  return (0);
}
