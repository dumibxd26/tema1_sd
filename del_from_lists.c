// Copyright 2022 Bogdan Dumitrescu

#include <stdlib.h>
#include <stdio.h>
#include "declarations.h"
#include "operations.h"

void delete_deck_cards(ds_list *deck)
{
    ds_node *deck_head_aux = deck->head;

    for (int i = 0; i < deck->size - 1; i++)
    {
        free(deck_head_aux->data);
        deck_head_aux = deck_head_aux->next;
        free(deck_head_aux->prev);
    }
    free(deck_head_aux->data);
    free(deck_head_aux);
}

void DEL_DECK(ds_list *deck_list, int pos, int command_type)
{
    ds_node *deck_node = goto_node(deck_list, pos);

    if (command_type)
        delete_deck_cards((ds_list *)deck_node->data);

    if (!pos)
    {
        ds_node *aux = deck_list->head;
        deck_list->head = deck_list->head->next;
        if (deck_list->head)
            deck_list->head->prev = NULL;

        free(aux->data);
        free(aux);
        deck_list->size--;
        return;
    }

    deck_node->prev->next = deck_node->next;
    if (pos != deck_list->size - 1)
        deck_node->next->prev = deck_node->prev;
    else
        deck_list->tail = deck_list->tail->prev;

    free(deck_node->data);
    free(deck_node);

    deck_list->size--;
}

void DEL_CARD(ds_list *deck_list, ds_list *deck_elements,
              int deck_index, int card_index)
{
    DEL_DECK(deck_elements, card_index, 0);

    if (!deck_elements->size)
        DEL_DECK(deck_list, deck_index, 0);
}
