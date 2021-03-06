/*
  JTSK-320112
  a3_p1.c
  Fezile Manana
  f.manana@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

struct list
  {
    char letter;
    struct list *next;
  };

struct list* push_back(struct list* my_list, char elem)
{
  struct list *cursor, *new;
  cursor = my_list;
  new = (struct list *) malloc(sizeof(struct list));
  if(new == NULL)
    return my_list;

  new->letter = elem;
  new->next = NULL;
  if(my_list == NULL)
    return new;
  while(cursor->next != NULL)
    cursor = cursor->next;
  cursor->next = new;
  return my_list;
}

struct list* push_front(struct list* my_list, char elem)
{
  struct list *new;
  new = (struct list *) malloc(sizeof(struct list));
  if(new == NULL)
    {
      return my_list;
    }
  new->letter = elem;
  new->next = my_list;
  return new;
}

void empty_list(struct list* my_list)
{
  struct list *next_elem;
  while(my_list != NULL)
    {
      next_elem = my_list->next;
      free(my_list);
      my_list = next_elem;
    }
}

struct list* rm_first(struct list* my_list)
{
  struct list *cursor;
  if(my_list == NULL)
    return my_list;
  cursor = my_list->next;
  free(my_list);
  my_list = cursor;
  return cursor;
}

void print(struct list *my_list)
{
  struct list *ptr;
  for(ptr = my_list; ptr; ptr = ptr->next)
    {
      printf("%c ", ptr->letter);
    }
  printf("\n");
}
int main()
{
    
  struct list *my_list = NULL;
  int input;
  char elem;
  scanf("%d", &input);
  
  while(input != 5)
  { 
    switch(input)
    {
      case 1 :
	getchar();
	scanf("%c", &elem);
	my_list = push_back(my_list, elem);
	break;
     case 2 :
       getchar();
       scanf("%c", &elem);
       my_list = push_front(my_list, elem);
       break;
     case 3 :
       getchar();
       my_list = rm_first(my_list);
       break;
     case 4 :
       print(my_list);
       break;
     case 5 :
       empty_list(my_list);
       break;
    }
    scanf("%d", &input);
  }	      
  return 0;
}