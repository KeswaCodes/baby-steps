#include "main.h"
/**
 *main- test cases for _getenv
 *Return: 0 - success
 */

int main(void) {

    char *result;

    result = _getenv("PATH");
    if (result != NULL) {
        printf("Environment variable PATH found. Value: %s\n", result);
    } else {
        printf("Environment variable PATH not found.\n");
    }

    result = _getenv("HOME");
    if (result != NULL) {
        printf("Environment variable HOME found. Value: %s\n", result);
    } else {
        printf("Environment variable HOME not found.\n");
    }


    result = _getenv("SOME_OTHER_VARIABLE");
    if (result != NULL) {
        printf("Environment variable SOME_OTHER_VARIABLE found. Value: %s\n", result);
    } else {
        printf("Environment variable SOME_OTHER_VARIABLE not found.\n");
    }


    result = _getenv(NULL);
    if (result != NULL) {
        printf("Environment variable (NULL) found. Value: %s\n", result);
    } else {
        printf("Environment variable (NULL) not found.\n");
    }

    return 0;
}
