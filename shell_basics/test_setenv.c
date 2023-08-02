#include "main.h"


int main(void)
{

  printf("Setting environment variable MY_VAR to Hello with overwrite=0...\n");
    _setenv("MY_VAR", "Hello", 0);

    printf("Setting environment variable NEW_VAR to World with overwrite=1...\n");
    _setenv("NEW_VAR", "World", 1);

    printf("Setting environment variable MY_VAR to Hola with overwrite=1...\n");
    _setenv("MY_VAR", "Hola", 1); 

    return (0);
}
