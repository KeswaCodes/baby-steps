#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
/**
 *main- get the PPID
 *Return: Always 0
 */

int main(void)
{
  pid_t ppid;

  ppid = getppid();
  printf("%u\n", ppid);

  return (0);

}
