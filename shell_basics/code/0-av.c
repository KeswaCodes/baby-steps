#include <stdio.h>
/**
 *main- prints all arguments without using ac
 *
 *Return: 0 - success
 */

int main(int ac, char **av)
{
  int i;
  (void)ac;


      for (i = 0; av[i] != NULL; i++)
	  printf("%s ", av[i]);

      printf("\n");
      return (0);

}
