// Copyright 2022 Bogdan Dumitrescu

#include <stdio.h>
#include <stdlib.h>
#include "print_cards.h"

const char symbol_value[4][8] = {"HEART", "SPADE", "DIAMOND", "CLUB"};

void SHOW_DECK(ds_list *deck, int deck_index)
{
    printf("Deck %d:\n", deck_index);

    ds_node *aux = deck->head;

    for (int i = 0; i < deck->size; i++)
    {
        printf("\t%hhu %s\n", ((ds_card_data *)aux->data)->val,
               symbol_value[(int)((ds_card_data *)aux->data)->sym_conversion]);
        aux = aux->next;
    }
}

void SHOW_ALL(ds_list *deck_list)
{
    ds_node *aux_head = deck_list->head;

    for (int i = 0; i < deck_list->size; i++)
    {
        SHOW_DECK((ds_list *)(aux_head->data), i);
        aux_head = aux_head->next;
    }
}
