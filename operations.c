#include <stdlib.h>
#include "operations.h"
#include "del_from_lists.h"
#include "add_to_lists.h"

ds_list *goto_deck(ds_list *deck, int pos)
{
    ds_node *node_aux = deck->head;

    while(pos--)
        node_aux = node_aux->next;

    return (ds_list *)node_aux->data;
}

ds_node *goto_node(ds_list *deck, int pos)
{
    ds_node *node_aux = deck->head;

    while(pos--)
        node_aux = node_aux->next;

    return node_aux;
}

ds_list *goto_deck_elements(ds_list *list_of_decks, int deck_index)
{

    ds_node *deck_node = goto_node(list_of_decks, deck_index);
    ds_list *deck_elements = (ds_list *)deck_node->data;

    return deck_elements;
}

int list_size(ds_list *deck_list)
{
    return deck_list->size;
}

void swap_links(ds_node *node)
{
    ds_node *aux = node->prev;
    node->prev = node->next;
    node->next = aux;
}

void REVERSE_LIST(ds_list *list)
{
    
    ds_node *prev, *current;
    
    prev = NULL;
    
    list->tail = list->head;
    prev = list->head;
    current = list->head->next;

    while(current)
    {
         swap_links(prev);
         prev = current;
         current = current->next;
    }
    swap_links(prev);

    list->head = prev;
}

int cmp(ds_card_data *a, ds_card_data *b)
{
    if(a->val < b->val)
        return -1;
    if(a->val > b->val)
        return 1;
    
    if(a->sym_conversion < b->sym_conversion)
        return -1;
    if(a->sym_conversion > b->sym_conversion)
        return 1;
    
    return 0;
}

void sort_list(ds_list *list)
{

    ds_node *aux_i, *aux_j;
    ds_card_data *data_i, *data_j;

    aux_i = list->head;

    while(aux_i->next)
    {
        aux_j = aux_i->next;
        while(aux_j)
        {  
            data_i = (ds_card_data*)aux_i->data;
            data_j = (ds_card_data*)aux_j->data;

            if(cmp(data_i, data_j) > 0)
            {
                 ds_card_data *aux = aux_i->data;
                 aux_i->data = aux_j->data;
                 aux_j->data = aux;
            }

            aux_j = aux_j->next;
        }
        
        aux_i = aux_i->next;
    }
}

void shuffle_deck(ds_list *deck)
{

    if(deck->size == 1)
        return;

    int half = deck->size / 2;
    ds_node *node = deck->head;

    while(--half)
        node = node->next;
    
    node->next->prev = NULL;

    deck->tail->next = deck->head;
    deck->head->prev = deck->tail;
    deck->head = node->next;
    deck->tail = node;
    deck->head->prev = NULL;
    node->next = NULL;

}

ds_list *merge_decks(ds_list *first_deck, ds_list *second_deck)
{
    ds_list *merged = create_list();

    ds_node *aux1 = first_deck->head;
    ds_node *aux2 = second_deck->head;
    
    int k = 1;

    while(aux1 && aux2)
    {
        ds_card_data *data1 = (ds_card_data *)aux1->data;
        ds_card_data *data2 = (ds_card_data *)aux2->data;
        ds_node *node = NULL;

        if(k)
        {
            node = create_node(create_card(data1->sym_conversion, data1->val));
            aux1 = aux1->next;
            k = 0;
        }
        else
        {
            node = create_node(create_card(data2->sym_conversion, data2->val));
            aux2 = aux2->next;
            k = 1;
        }
        add_to_list(merged, node);
    }

    while(aux1)
    {
        ds_card_data *data1 = (ds_card_data *)aux1->data;
        ds_node *node = create_node(create_card(data1->sym_conversion, data1->val));
        add_to_list(merged, node);
        aux1 = aux1->next;
    }

    while(aux2)
    {
        ds_card_data *data2 = (ds_card_data *)aux2->data;
        ds_node *node = create_node(create_card(data2->sym_conversion, data2->val));
        add_to_list(merged, node);
        aux2 = aux2->next;
    }

    return merged;

}
#include "stdio.h"
void EXIT(ds_list **list_of_decks)
{
    while((*list_of_decks)->size)
        DEL_DECK(*list_of_decks, 0, 1);

    free(*list_of_decks);
}