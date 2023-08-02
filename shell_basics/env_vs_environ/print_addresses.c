#include "main.h"
/**
 *main- prints the addresses of env & environ 
 *Return: 0 - sucess
 */

extern char **environ;

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)), char **env)
{


  printf("The address of environ is: %p and the address of env is: %p\n", (void *)environ, (void *)env);

  return (0);
  
}
