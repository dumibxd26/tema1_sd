#include "declarations.h"

int is_in_the_list(char *symbol);

char symbol_conversion(char *symbol);

ds_list *create_list();

void add_to_list(ds_list *list, ds_node *node);

ds_card_data *create_card(char symbol_conversed, char val);

ds_list *CREATE_DECK(int size);

ds_node *create_node(void *data);

void ADD_CARDS(ds_list *deck, ds_list *deck_add);

