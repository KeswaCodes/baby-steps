#include "main.h"
/**
 *printchar- prints character
 *Return: 0 - success, -1 otherwise
 */

int printchar(char z)
{
int result = write(1, &z, 1);

 if (result == 1)
   return (1);

 return (-1);


}
