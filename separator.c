/* program allows you to enter a comma separated list and user will get back parsed list */
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#define STRING_LEN 40 /*Assumed char array len */


struct		Word
{
char*		textPtr_;
struct Word*	nextPtr_;
};

struct Word* head; //global var
char *part;  //global

struct Word* obtainCommaSeparatedList (const char* string)
{
    int tracker = 0;

    while ( *string != '\0')
    {
      while (string[0] != ',' && string[0] != '\0')
      {
        tracker++;
        string++;
      }
        part = (char*) malloc(tracker+1);
        strncpy(part, string-tracker, tracker);
        part[tracker] = '\0';

        struct Word *temp = (struct Word*)malloc(sizeof(struct Word));
        temp->textPtr_ = part;
        temp->nextPtr_ = NULL;

          //if node is empty, create node and point head to node
          if (head == NULL)
          {
          head = temp;
          }
          //if not empty put it at the end
          else
          {
            struct Word* temp1 = head;
            while ( temp1->nextPtr_ != NULL )
            {
              temp1 = temp1->nextPtr_;
            }
            temp1->nextPtr_ = temp;
          }
        string+= 1;
        tracker=0;
      }
    return head;
}

void printCommaSeparatedList (const struct Word* list)
{
  if (list == NULL) return;

  //print with recursion
  printf("\"%s\"\n", list->textPtr_ );
  printCommaSeparatedList (list->nextPtr_);
}

void freeCommaSeparatedList (struct Word* list)
{
  struct Word* temp=head;

   while (head != NULL)
    {
       temp = head;
       head = head->nextPtr_;
       free(temp);
    }
}

void getText (char* nPtr)
{
  printf("Please enter a line of text:  ");
  fgets(nPtr,STRING_LEN,stdin);
}

int	main	()
{
  struct Word* head = NULL; //empty list

  char text[STRING_LEN];

  getText(text);
  char*		cPtr	= strchr(text,'\n');

  if  (cPtr != NULL)
    *cPtr = '\0';

  //build the linked list function call
  struct Word *lst = obtainCommaSeparatedList(text);

  //call print function
  printCommaSeparatedList(lst);

  //free parsed string
  free(part);

  //free linked list
  freeCommaSeparatedList(lst);

  return(EXIT_SUCCESS);
}
