// Copyright 2022 Bogdan Dumitrescu

#ifndef COMMANDS_H_
#define COMMANDS_H_


#include "declarations.h"

void merge_lists_command(ds_list **list_of_decks,
                         int deck_index1, int deck_index2);

void split_deck_command(ds_list *list_of_decks, ds_node *deck_node,
                        ds_list *deck_elements, int deck_index,
                        int split_index);

#endif  // COMMANDS_H_
