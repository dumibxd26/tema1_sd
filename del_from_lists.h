// Copyright 2022 Bogdan Dumitrescu

#ifndef DEL_FROM_LISTS_H_
#define DEL_FROM_LISTS_H_

#include "declarations.h"

void delete_deck_cards(ds_list *deck);

void DEL_DECK(ds_list *deck_list, int pos, int command_type);

void DEL_CARD(ds_list *deck_list, ds_list *deck_elements,
              int deck_index, int card_index);

#endif  // DEL_FROM_LISTS_H_

