#include <stdio.h>
#include <stdlib.h>
#include "add_to_lists.h"

int main(void)
{

     ds_deck_list *list = create_deck_list();
     char *command = malloc(sizeof(char) * BUFF_SIZE), *p;

     while(1)
     {

          p = strtok(command, " ");

          if (strcmp(p, "ADD_DECK")) {

          } else if (strcmp(p, "DEL_DECK")) {

          } else if (strcmp(p, "DEL_CARD")) {

          } else if (strcmp(p, "ADD_CARDS")) {

          } else if (strcmp(p, "DECK_NUMBER")) {

          } else if (strcmp(p, "DECK_LEN")) {

          } else if (strcmp(p, "SHUFFLE_DECK")) {

          } else if (strcmp(p, "MERGE_DECKS")) {

          } else if (strcmp(p, "SPLIT_DECK")) {

          } else if (strcmp(p, "REVERSE_DECK")) {

          } else if (strcmp(p, "SHOW_DECK")) {

          } else if (strcmp(p, "SHOW_ALL")) {

          } else if (strcmp(p, "EXIT")) {

               break;
          } else {
               PRINT_INVALID_COMMAND;
          }

     }



     return 0;

}