#include "declarations.h"

int is_in_the_list(char *symbol);

char symbol_conversion(char *symbol);

ds_deck_list *create_deck_list();

ds_card *create_card(char *symbol, char val);

void add_cards(ds_deck *deck, char *symbol, char val);

ds_deck *CREATE_DECK(int size);

void ADD_DECK(ds_deck_list *deck_list, ds_deck *deck_add);

void ADD_CARDS(ds_deck *deck, ds_deck **deck_add);

