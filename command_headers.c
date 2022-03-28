// Copyright 2022 Bogdan Dumitrescu

#include <stdio.h>
#include "command_headers.h"
#include "conditions_check.h"
#include "operations.h"
#include "errors.h"

ds_list *two_param_header(ds_list *list_of_decks, char *p,
                          int *index1, int *index2, ds_node **deck_node)
{
    int ok = 0;
    check_two_params(p, index1, index2, &ok);
    if (ok)
        return NULL;
    if (*index1 >= list_of_decks->size || *index1 < 0)
    {
        PRINT_DECK_INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    *deck_node = goto_node(list_of_decks, *index1);
    ds_list *deck_elements = (ds_list *)(*deck_node)->data;
    if (*index2 >= deck_elements->size || *index2 < 0)
    {
        PRINT_CARD_INDEX_OUT_OF_BOUNDS(*index1);
        return NULL;
    }
    return deck_elements;
}

ds_list *one_index_operations(ds_list *list_of_decks, char *p, int *index)
{
    int ok = 0;
    check_one_param(p, index, &ok);
    if (ok)
        return NULL;
    if (*index >= list_of_decks->size || *index < 0)
    {
        PRINT_DECK_INDEX_OUT_OF_BOUNDS;
        return NULL;
    }
    ds_node *deck_node = goto_node(list_of_decks, *index);
    ds_list *deck_elements = (ds_list *)deck_node->data;

    return deck_elements;
}
