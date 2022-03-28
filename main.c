// Copyright 2022 Bogdan Dumitrescu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_to_lists.h"
#include "declarations.h"
#include "del_from_lists.h"
#include "conditions_check.h"
#include "print_cards.h"
#include "operations.h"
#include "print_command_messages.h"
#include "command_headers.h"
#include "commands.h"

int main(void)
{
     ds_list *list_of_decks = create_list();
     char *command = malloc(sizeof(char) * BUFF_SIZE), *p;

     while (1)
     {
          fgets(command, BUFF_SIZE, stdin);
          command[strlen(command) - 1] = '\0';
          p = strtok(command, " ");

          if (!strcmp(p, "ADD_DECK"))
          {
               int number_of_cards, ok = 0;
               check_one_param(p, &number_of_cards, &ok);
               if (ok)
                    continue;

               ds_node *deck_node = create_node(CREATE_DECK(number_of_cards));

               add_to_list(list_of_decks, deck_node);

               PRINT_ADD_DECK(number_of_cards);
          }
          else if (!strcmp(p, "DEL_DECK"))
          {
               int deck_index, ok = 0;
               check_one_param(p, &deck_index, &ok);
               if (ok)
                    continue;
               if (deck_index >= list_of_decks->size || deck_index < 0)
               {
                    PRINT_DECK_INDEX_OUT_OF_BOUNDS;
                    continue;
               }

               DEL_DECK(list_of_decks, deck_index, 1);

               PRINT_DEL_DECK(deck_index);
          }
          else if (!strcmp(p, "DEL_CARD"))
          {
               int deck_index, card_index;
               ds_list *deck_elements;
               ds_node *deck_node;
               deck_elements = two_param_header(list_of_decks, p, &deck_index,
                                                &card_index, &deck_node);
               if (!deck_elements)
                    continue;

               DEL_CARD(list_of_decks, deck_elements, deck_index, card_index);

               PRINT_DEL_CARD(deck_index);
          }
          else if (!strcmp(p, "ADD_CARDS"))
          {
               int deck_index, number_of_cards, ok = 0;

               check_two_params(p, &deck_index, &number_of_cards, &ok);

               if (ok)
                    continue;

               if (deck_index >= list_of_decks->size || deck_index < 0)
               {
                    PRINT_DECK_INDEX_OUT_OF_BOUNDS;
                    continue;
               }

               ds_list *deck_add = CREATE_DECK(number_of_cards);

               ADD_CARDS(goto_deck(list_of_decks, deck_index), deck_add);

               free(deck_add);

               PRINT_ADD_CARDS(deck_index);
          }
          else if (!strcmp(p, "DECK_NUMBER"))
          {
               if (check_no_params())
                    PRINT_DECK_NUMBER(list_of_decks->size)
               else
                    continue;
          }
          else if (!strcmp(p, "DECK_LEN"))
          {
               int deck_index;
               ds_list *deck_elements;
               deck_elements = one_index_operations(list_of_decks,
                                                    p, &deck_index);

               if (!deck_elements)
                    continue;

               PRINT_DECK_LEN(deck_index, deck_elements->size);
          }
          else if (!strcmp(p, "SHUFFLE_DECK"))
          {
               int deck_index;
               ds_list *deck_elements;
               deck_elements = one_index_operations(list_of_decks,
                                                    p, &deck_index);

               if (!deck_elements)
                    continue;

               shuffle_deck(deck_elements);

               PRINT_SHUFFLE_DECK(deck_index);
          }
          else if (!strcmp(p, "MERGE_DECKS"))
          {
               int deck_index1, deck_index2, ok = 0;
               check_two_params(p, &deck_index1, &deck_index2, &ok);
               if (ok)
                    continue;
               if (deck_index1 >= list_of_decks->size ||
                   deck_index2 >= list_of_decks->size ||
                   deck_index1 < 0 || deck_index2 < 0)
               {
                    PRINT_DECK_INDEX_OUT_OF_BOUNDS;
                    continue;
               }

               merge_lists_command(&list_of_decks, deck_index1, deck_index2);

               PRINT_MERGE_DECKS(deck_index1, deck_index2);
          }
          else if (!strcmp(p, "SPLIT_DECK"))
          {
               int deck_index, split_index;

               ds_list *deck_elements;
               ds_node *deck_node;
               deck_elements = two_param_header(list_of_decks, p, &deck_index,
                                                &split_index, &deck_node);
               if (!deck_elements)
                    continue;

               if (split_index)
                    split_deck_command(list_of_decks, deck_node,
                                       deck_elements, deck_index, split_index);

               PRINT_SPLIT_DECK(deck_index, split_index);
          }
          else if (!strcmp(p, "REVERSE_DECK"))
          {
               int deck_index;
               ds_list *deck_elements;
               deck_elements = one_index_operations(list_of_decks,
                                                    p, &deck_index);

               if (!deck_elements)
                    continue;

               REVERSE_LIST(deck_elements);

               PRINT_REVERSE_DECK(deck_index);
          }
          else if (!strcmp(p, "SORT_DECK"))
          {
               int deck_index;
               ds_list *deck_elements;
               deck_elements = one_index_operations(list_of_decks,
                                                    p, &deck_index);

               if (!deck_elements)
                    continue;

               sort_list(deck_elements);

               PRINT_SORT_DECK(deck_index);
          }
          else if (!strcmp(p, "SHOW_DECK"))
          {
               int deck_index, ok = 0;
               check_one_param(p, &deck_index, &ok);
               if (ok)
                    continue;
               if (deck_index >= list_of_decks->size || deck_index < 0)
               {
                    PRINT_DECK_INDEX_OUT_OF_BOUNDS;
                    continue;
               }

               SHOW_DECK(goto_deck(list_of_decks, deck_index), deck_index);
          }
          else if (!strcmp(p, "SHOW_ALL"))
          {
               if (check_no_params())
                    SHOW_ALL(list_of_decks);
               else
                    continue;
          }
          else if (!strcmp(p, "EXIT"))
          {
               if (check_no_params())
               {
                    EXIT(&list_of_decks);
                    free(command);
                    break;
               }
               else
                    continue;
          }
          else
          {
               PRINT_INVALID_COMMAND;
          }
     }

     return 0;
}
