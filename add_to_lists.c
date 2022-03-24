#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_to_lists.h"

int is_in_the_list(char *symbol)
{
    return !strcmp(symbol, "HEART") || 
           !strcmp(symbol, "CLUB") || 
           !strcmp(symbol, "DIAMOND") || 
           !strcmp(symbol, "SPADE");
}

char symbol_conversion(char *symbol)
{
    if(strcmp(symbol, "HREAT"))
        return 1;
    if(strcmp(symbol, "CLUB"))
        return 2;
    if(strcmp(symbol, "DIAMOND"))
        return 3;
    if(strcmp(symbol, "SPADE"))
        return 4; 

    return 69;   
}

ds_deck_list *create_deck_list()
{
     ds_deck_list *list = malloc(sizeof(ds_deck_list));
     list->total_decks = 0;
     list->deck_head = list->deck_tail = NULL;

     return list;
}

ds_card *create_card(char *symbol, char val)
{
    ds_card *card = malloc(sizeof(ds_card));
    card->next = card->prev = NULL;
    card->data = malloc(sizeof(ds_card_data));
    card->data->val = val;
    card->data->sym_conversion = symbol_conversion(symbol);
    card->data->symbol = malloc(strlen(symbol) + 1);
    strcpy(card->data->symbol, symbol);

    return card;
}

void add_cards(ds_deck *deck, char *symbol, char val)
{

    ds_card *card = create_card(symbol, val);
    
    (deck->deck_size)++;

    if(deck->deck_size == 1)
    {
        deck->card_head = deck->card_tail = card;
        return ;
    }

    card->prev = deck->card_tail;
    deck->card_tail->next = card;
    deck->card_tail = card;
    
}

ds_deck *CREATE_DECK(int size)
{
    
    char *line = malloc(sizeof(char) * BUFF_SIZE), *p;

    int card_value;

    ds_deck *deck = malloc(sizeof(ds_deck));

    deck->deck_size = 0;
    deck->card_head = deck->card_tail = NULL;

   // create_add_cards(deck);
   
    while(size && fgets(line, BUFF_SIZE, stdin))
    {
        line[strlen(line) -1] = '\0';

        p = strtok(line, " ");

        card_value = atoi(p);

        if(card_value < 1 || card_value > 14)
        {
            PRINT_INVALID_CARD; 
            continue;
        }

        p = strtok(NULL, " ");

        // if(p)
        // {
        //     card_symbol = malloc(strlen(p) + 1);
        //     strcpy(card_symbol, p);

        // }
        
       if(!p || !is_in_the_list(p) || strtok(NULL, " "))
       {
           PRINT_INVALID_CARD;
           continue;
       }
    
       add_cards(deck, p, card_value);
       size--;
    }
    free(line);
    

    // ds_card *card = deck->card_head;

    // while(card->next)
    // {
    //     printf("%d %s\n", card->data->val, card->data->symbol);
    //     card = card->next;
    //     free(card->prev->data->symbol);
    //     free(card->prev->data);
    //     free(card->prev);
    // }
    // free(card->data->symbol); 
    // free(card->prev->data);
    // free(card->prev);

    // free(deck);

    return deck;
}

void ADD_DECK(ds_deck_list *deck_list, ds_deck *deck_add)
{

    deck_list->total_decks++;
    if(deck_list->total_decks == 1)
    {
        deck_list->deck_head = deck_add;
        return ;
    }
 
    deck_add->prev = deck_list->deck_tail;
    deck_list->deck_tail->next = deck_add;
    deck_list->deck_tail = deck_add;

    // deck_list->deck_tail->next = deck_add;
    // deck_add->prev = deck_list->deck_tail;
    // deck_list->deck_tail = deck_add;
}

void ADD_CARDS(ds_deck *deck, ds_deck **deck_add) 
{
    deck->card_tail = (*deck_add)->card_head;
    (*deck_add)->card_head->prev = deck->card_tail;
    deck->card_tail = (*deck_add)->card_tail;

}