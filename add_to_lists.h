#include "declarations.h"

void CREATE_DECK(int size);

void ADD_DECK(ds_deck_list *deck_list, ds_deck *deck_add);

void ADD_CARDS(ds_deck *deck, ds_deck **deck_add, int pos);