#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_to_lists.h"
#include "declarations.h"
#include "del_from_lists.h"
#include "conditions_check.h"
#include "print_cards.h"
#include "operations.h"
#include "print_messages.h"


int main(void)
{

     ds_list *list_of_decks = create_list();
     char *command = malloc(sizeof(char) * BUFF_SIZE), *p;

     while(1)
     {    
          fgets(command, BUFF_SIZE, stdin);

          command[strlen(command) - 1] = '\0';

          p = strtok(command, " ");

          if (!strcmp(p, "ADD_DECK")) {

               int number_of_cards, ok = 0;
               check_one_param(p, &number_of_cards, &ok);

               if(ok)
                    continue;
               
               ds_node *deck_node = create_node(CREATE_DECK(number_of_cards));

               add_to_list(list_of_decks, deck_node);

               printf("The deck was successfully created with %d cards.\n", number_of_cards);

          } else if (!strcmp(p, "DEL_DECK")) {

               int deck_index, ok = 0;
               check_one_param(p, &deck_index, &ok);

               if(ok)
                    continue;
               
               if(deck_index >= list_of_decks->size || deck_index < 0)
               {
                    PRINT_DECK_INDEX_OUT_OF_BOUNDS;
                    continue;
               }

               DEL_DECK(list_of_decks, deck_index, 1);

               printf("The deck %d was successfully deleted.\n", deck_index);

          } else if (!strcmp(p, "DEL_CARD")) {

               int deck_index, card_index, ok = 0;

               check_two_params(p, &deck_index, &card_index, &ok);

               if(ok)
                    continue;

               if(deck_index >= list_of_decks->size || deck_index < 0)
               {
                    PRINT_DECK_INDEX_OUT_OF_BOUNDS;
                    continue;
               }

               ds_node *deck_node = goto_node(list_of_decks, deck_index);
               ds_list *deck_elements = (ds_list *)deck_node->data;

               if(card_index >= deck_elements->size || card_index < 0)
               {
                    PRINT_CARD_INDEX_OUT_OF_BOUNDS(deck_index);
                    continue;
               }    

               DEL_CARD(list_of_decks, deck_elements, deck_index, card_index);

               printf("The card was successfully deleted from deck %d.\n", deck_index);
               
          } else if (!strcmp(p, "ADD_CARDS")) {

               int deck_index, number_of_cards, ok = 0;

               check_two_params(p, &deck_index, &number_of_cards, &ok);

               if(ok)
                    continue;
               
               if(deck_index >= list_of_decks->size || deck_index < 0)
               {
                    PRINT_DECK_INDEX_OUT_OF_BOUNDS;
                    continue;
               }

              ds_list *deck_add = CREATE_DECK(number_of_cards);
               
              ADD_CARDS(goto_deck(list_of_decks, deck_index), deck_add);

              free(deck_add);

              printf("The cards were successfully added to deck %d.\n", deck_index); 
               
          } else if (!strcmp(p, "DECK_NUMBER")) {
               if(check_no_params()) 
               printf("The number of decks is %d.\n", list_of_decks->size);
               else
               continue;

          } else if (!strcmp(p, "DECK_LEN")) {

               int deck_index, ok = 0;
               check_one_param(p, &deck_index, &ok);

               if(ok)
                    continue;
               
               if(deck_index >= list_of_decks->size || deck_index < 0)
               {
                    PRINT_DECK_INDEX_OUT_OF_BOUNDS;
                    continue;
               }

               ds_node *deck_node = goto_node(list_of_decks, deck_index);
               ds_list *deck_elements = (ds_list *)deck_node->data;
               printf("The length of deck %d is %d.\n", deck_index, deck_elements->size);

          } else if (!strcmp(p, "SHUFFLE_DECK")) {

               int deck_index, ok = 0;
               check_one_param(p, &deck_index, &ok);

               if(ok)
                    continue;
               
               if(deck_index >= list_of_decks->size || deck_index < 0)
               {
                    PRINT_DECK_INDEX_OUT_OF_BOUNDS;
                    continue;
               }

              
               ds_node *deck_node = goto_node(list_of_decks, deck_index);
               ds_list *deck_elements = (ds_list *)deck_node->data;

               shuffle_deck(deck_elements);

               printf("The deck %d was successfully shuffled.\n", deck_index);
               
          } else if (!strcmp(p, "MERGE_DECKS")) {
               
               int deck_index1, deck_index2, ok = 0;

               check_two_params(p, &deck_index1, &deck_index2, &ok);

               if(ok)
                    continue;
               
               if(deck_index1 >= list_of_decks->size || deck_index2 >= list_of_decks->size ||
                  deck_index1 < 0                    ||  deck_index2 < 0)
               {
                    PRINT_DECK_INDEX_OUT_OF_BOUNDS;
                    continue;
               }

               ds_list *deck_elements_index1, *deck_elements_index2;     

               deck_elements_index1 = goto_deck_elements(list_of_decks, deck_index1);
               deck_elements_index2 = goto_deck_elements(list_of_decks, deck_index2);

               ds_node *deck_node = malloc(sizeof(ds_node));
               deck_node->data = merge_decks(deck_elements_index1, deck_elements_index2);
               deck_node->next = deck_node->prev = NULL;

               add_to_list(list_of_decks, deck_node);

               if(deck_index1 > deck_index2)
               {
                    DEL_DECK(list_of_decks, deck_index1, 1);
                    DEL_DECK(list_of_decks, deck_index2, 1);
               }
               else
               {
                    DEL_DECK(list_of_decks, deck_index2, 1);
                    DEL_DECK(list_of_decks, deck_index1, 1);
               }
              
               printf("The deck %d and the deck %d were successfully merged.\n", deck_index1, deck_index2);

          } else if (!strcmp(p, "SPLIT_DECK")) {

               int deck_index, split_index, ok = 0;

               check_two_params(p, &deck_index, &split_index, &ok);

               if(ok)
                    continue;

               if(deck_index >= list_of_decks->size || deck_index < 0)
               {
                    PRINT_DECK_INDEX_OUT_OF_BOUNDS;
                    continue;
               }

               ds_node *deck_node = goto_node(list_of_decks, deck_index);
               ds_list *deck_elements = (ds_list *)deck_node->data;

               if(split_index >= deck_elements->size || split_index < 0)
               {
                    PRINT_CARD_INDEX_OUT_OF_BOUNDS(deck_index);
                    continue;
               }    
               if(split_index)
               {
                   ds_node *split_node = goto_node(deck_elements, split_index - 1);
                   
                    ds_list *next_deck = create_list(); 

                    next_deck->tail = deck_elements->tail;
                    deck_elements->tail = split_node;
                    next_deck->head = split_node->next;
                    split_node->next->prev = NULL;
                    split_node->next = NULL;

                    next_deck->size = deck_elements->size - split_index;
                    deck_elements->size = split_index;

                    ds_node *new_node = create_node(next_deck);

                    if(deck_index == list_of_decks->size - 1)
                         add_to_list(list_of_decks, new_node);
                    else
                    {
                         (list_of_decks->size)++;
                         deck_node->next->prev = new_node;
                         new_node->next = deck_node->next;
                         deck_node->next = new_node;
                         new_node->prev = deck_node;
                         
                    }
                   
               }
          
               printf("The deck %d was successfully split by index %d.\n", deck_index, split_index);

          } else if (!strcmp(p, "REVERSE_DECK")) {
               
               int deck_index, ok = 0;
               check_one_param(p, &deck_index, &ok);

               if(ok)
                    continue;

               if(deck_index >= list_of_decks->size || deck_index < 0)
               {
                    PRINT_DECK_INDEX_OUT_OF_BOUNDS;
                    continue;
               }

               ds_node *deck_node = goto_node(list_of_decks, deck_index);
               ds_list *deck_elements = (ds_list *)deck_node->data;

               REVERSE_LIST(deck_elements);

               printf("The deck %d was successfully reversed.\n", deck_index);

          } else if(!strcmp(p, "SORT_DECK")) {
               
               int deck_index, ok = 0;
               check_one_param(p, &deck_index, &ok);

               if(ok)
                    continue;
               
               if(deck_index >= list_of_decks->size || deck_index < 0)
               {
                    PRINT_DECK_INDEX_OUT_OF_BOUNDS;
                    continue;
               }

               ds_node *deck_node = goto_node(list_of_decks, deck_index);
               ds_list *deck_elements = (ds_list *)deck_node->data;

               sort_list(deck_elements);

               printf("The deck %d was successfully sorted.\n", deck_index);

          } else if (!strcmp(p, "SHOW_DECK")) {

               int deck_index, ok = 0;
               check_one_param(p, &deck_index, &ok);

               if(ok)
                    continue;

               if(deck_index >= list_of_decks->size || deck_index < 0) {

                    PRINT_DECK_INDEX_OUT_OF_BOUNDS;
                    continue;
               }

               SHOW_DECK(goto_deck(list_of_decks, deck_index), deck_index);
          } else if (!strcmp(p, "SHOW_ALL")) {

           if(check_no_params()) 
               SHOW_ALL(list_of_decks);
           else 
               continue;
          } 
          else if (!strcmp(p, "EXIT")) {
               if(check_no_params()) 
               {EXIT(&list_of_decks);
               free(command);
           break;}
           else continue;
          } else {
               PRINT_INVALID_COMMAND;
          }

     }



     return 0;

}