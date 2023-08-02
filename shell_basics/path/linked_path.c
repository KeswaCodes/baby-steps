#include "main.h"

/**
 *main- builds a linked list for PATH env variable
 *Return: 0 - success, -1 otherwise
 */

int main(void)
{

  int result;
  size_t i, k;
  char *path, *token;
  struct node *new_node, *head = NULL, *temp;
  
  path = _getenv("PATH");

  token = strtok(path, ":");

    /*create new node*/
      new_node = malloc(sizeof(struct node));
      if (new_node == NULL)
	return (-1);
      /*allocate space for data stored inside node*/
      for (i = 0; token[i] != '\0'; i++)
	;
      i++;
      new_node->data = malloc(i);
      if (new_node->data == NULL)
	return (-1);

      for (k = 0; k < i; k++)
result = printchar(new_node->data[k] = token[k]);

      if (result == 1)
result = printchar(new_node->data[k] = '\0');
      
            if (result == 1)
      printchar('\n');

      if (head == NULL)
	head = new_node;

      temp = head;
      token = strtok(NULL, ":");      
  while (token != NULL)
    {
      /*create new node*/
      new_node = malloc(sizeof(struct node));
      if (new_node == NULL)
	return (-1);
      /*allocate space for data stored inside node*/
      for (i = 0; token[i] != '\0'; i++)
	;
      i++;
      new_node->data = malloc(i);
      if (new_node->data == NULL)
	return (-1);

      for (k = 0; k < i; k++)
result = printchar(new_node->data[k] = token[k]);
      if (result == 1)
result = printchar(new_node->data[k] = '\0');
      

      if (result == 1)
      printchar('\n');

	          temp->next = new_node;
  token = strtok(NULL, ":");
    }
  temp->next = NULL;

  for (temp = head; temp->next != NULL; temp = temp->next)
    {
      temp = head->next;
  free(head);
  head = temp;
}
  free(head);
  return (0);
}
