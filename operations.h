#include "declarations.h"

ds_list *goto_deck(ds_list *deck, int pos);

ds_node *goto_node(ds_list *deck, int pos);

ds_list *goto_deck_elements(ds_list *list_of_decks, int deck_index);

int cmp(ds_card_data *a, ds_card_data *b);

void REVERSE_LIST(ds_list *list);

void sort_list(ds_list *list);

void shuffle_deck(ds_list *deck);

ds_list *merge_decks(ds_list *first_deck, ds_list *second_deck);

void swap_links(ds_node *node);

void EXIT(ds_list **list_of_decks);