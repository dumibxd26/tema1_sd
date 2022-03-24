#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_to_lists.h"
#include "declarations.h"
#include "conditions_check.h"
#include "print_cards.h"
#include "operations.h"

int main(void)
{

     ds_deck_list *deck_list = create_deck_list();
     char *command = malloc(sizeof(char) * BUFF_SIZE), *p;

     while(1)
     {    
          fgets(command, BUFF_SIZE, stdin);

          command[strlen(command) - 1] = '\0';

          p = strtok(command, " ");

          if (!strcmp(p, "ADD_DECK")) {

               int number_of_cards;
               check_one_param(p, &number_of_cards);

               if(number_of_cards == -1)
                    continue;
               
               ADD_DECK(deck_list, CREATE_DECK(number_of_cards));

          } else if (!strcmp(p, "DEL_DECK")) {

          } else if (!strcmp(p, "DEL_CARD")) {

          } else if (!strcmp(p, "ADD_CARDS")) {

          } else if (!strcmp(p, "DECK_NUMBER")) {

          } else if (!strcmp(p, "DECK_LEN")) {

          } else if (!strcmp(p, "SHUFFLE_DECK")) {

          } else if (!strcmp(p, "MERGE_DECKS")) {

          } else if (!strcmp(p, "SPLIT_DECK")) {

          } else if (!strcmp(p, "REVERSE_DECK")) {

          } else if (!strcmp(p, "SHOW_DECK")) {

               int deck_number;
               check_one_param(p, &deck_number);

               if(deck_number == -1)
                    continue;
               
               if(deck_number > deck_list->total_decks) {

                    PRINT_DECK_INDEX_OUT_OF_BOUNDS;
                    continue;
               }

               SHOW_DECK(goto_deck(deck_list, deck_number), deck_number);

          } else if (!strcmp(p, "SHOW_ALL")) {

           if(check_no_params()) 
               SHOW_ALL(deck_list);
           else 
               continue;
          } else if (!strcmp(p, "EXIT")) {

               break;
          } else {
               PRINT_INVALID_COMMAND;
          }

     }



     return 0;

}