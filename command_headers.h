
// Copyright 2022 Bogdan Dumitrescu

#ifndef COMMAND_HEADERS_H_
#define COMMAND_HEADERS_H_

#include "declarations.h"

ds_list *two_param_header(ds_list *list_of_decks, char *p, int *index1,
                          int *index2, ds_node **deck_node);

ds_list *one_index_operations(ds_list *list_of_decks, char *p, int *index);

#endif  // COMMAND_HEADERS_H_
