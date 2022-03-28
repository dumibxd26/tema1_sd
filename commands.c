// Copyright 2022 Bogdan Dumitrescu

#include <stdlib.h>
#include "commands.h"
#include "operations.h"
#include "del_from_lists.h"
#include "add_to_lists.h"

void merge_lists_command(ds_list **list_of_decks, int deck_index1,
                         int deck_index2)
{
    ds_list *deck_elements_index1, *deck_elements_index2;

    deck_elements_index1 = goto_deck_elements(*list_of_decks, deck_index1);
    deck_elements_index2 = goto_deck_elements(*list_of_decks, deck_index2);

    ds_node *deck_node = malloc(sizeof(ds_node));
    deck_node->data = merge_lists(deck_elements_index1, deck_elements_index2);
    deck_node->next = deck_node->prev = NULL;

    add_to_list(*list_of_decks, deck_node);

    // We do this to avoid deck removal index issues
    if (deck_index1 > deck_index2)
    {
        DEL_DECK(*list_of_decks, deck_index1, 1);
        DEL_DECK(*list_of_decks, deck_index2, 1);
    }
    else
    {
        DEL_DECK(*list_of_decks, deck_index2, 1);
        DEL_DECK(*list_of_decks, deck_index1, 1);
    }
}

void split_deck_command(ds_list *list_of_decks, ds_node *deck_node,
                        ds_list *deck_elements, int deck_index, int split_index)
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

    if (deck_index == list_of_decks->size - 1)
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
