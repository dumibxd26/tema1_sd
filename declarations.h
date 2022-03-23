
#include "errors.h"

typedef struct ds_card_data ds_card_data;
typedef struct ds_card ds_card;
typedef struct ds_deck ds_deck;
typedef struct ds_deck_list ds_deck_list;

ds_card_data {

    char *symbol, val, sym_conversion;
};

ds_card {

    ds_card_data *data; 
    ds_card *next, *prev;
};

ds_deck {

    ds_card *card_head, *card_tail;
    int deck_size;
    ds_deck *next, *prev;
};

ds_deck_list {

    ds_deck *deck_head, *deck_tail;
    int total_decks;
};

