// Copyright 2022 Bogdan Dumitrescu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_to_lists.h"

int is_in_the_list(char *symbol)
{
    return !strcmp(symbol, "HEART") ||
           !strcmp(symbol, "SPADE") ||
           !strcmp(symbol, "DIAMOND") ||
           !strcmp(symbol, "CLUB");
}

char symbol_conversion(char *symbol)
{
    if (!strcmp(symbol, "HEART"))
        return 0;
    if (!strcmp(symbol, "SPADE"))
        return 1;
    if (!strcmp(symbol, "DIAMOND"))
        return 2;
    if (!strcmp(symbol, "CLUB"))
        return 3;

    return -1;
}

ds_list *create_list()
{
    ds_list *list = malloc(sizeof(ds_list));
    list->head = list->tail = NULL;
    list->size = 0;

    return list;
}

ds_card_data *create_card(char symbol_conversed, char val)
{
    ds_card_data *data = malloc(sizeof(data));
    data->val = val;
    data->sym_conversion = symbol_conversed;

    return data;
}

ds_node *create_node(void *data)
{
    ds_node *node = malloc(sizeof(ds_node));
    node->next = node->prev = NULL;
    node->data = data;

    return node;
}

void add_to_list(ds_list *list, ds_node *node)
{
    list->size++;

    if (list->size == 1)
    {
        list->head = list->tail = node;
        return;
    }

    node->prev = list->tail;
    list->tail->next = node;
    list->tail = node;
}

ds_list *CREATE_DECK(int size)
{
    char *line = malloc(sizeof(char) * BUFF_SIZE), *p;

    int card_value;

    ds_list *deck = create_list();

    while (size && fgets(line, BUFF_SIZE, stdin))
    {
        line[strlen(line) - 1] = '\0';

        p = strtok(line, " ");

        card_value = atoi(p);

        if (card_value < 1 || card_value > 14)
        {
            PRINT_INVALID_CARD;
            continue;
        }

        p = strtok(NULL, " ");

        if (!p || !is_in_the_list(p) || strtok(NULL, " "))
        {
            PRINT_INVALID_CARD;
            continue;
        }

        ds_card_data *data = create_card(symbol_conversion(p), card_value);

        ds_node *card = create_node(data);

        add_to_list(deck, card);

        size--;
    }
    free(line);

    return deck;
}

void ADD_CARDS(ds_list *deck, ds_list *deck_add)
{
    deck->size += deck_add->size;

    deck->tail->next = deck_add->head;
    deck_add->head->prev = deck->tail;
    deck->tail = deck_add->tail;
}
