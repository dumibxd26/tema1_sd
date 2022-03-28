#ifndef declarations
#define declarations

#define BUFF_SIZE 100

#include "errors.h"
#include "stddef.h"

typedef struct ds_card_data ds_card_data;
typedef struct ds_list ds_list;
typedef struct ds_node ds_node;

struct ds_card_data {

    char val, sym_conversion;
};

struct ds_node {
    void *data;
    ds_node *next, *prev;
};

struct ds_list {

    ds_node *head, *tail;
    int size;
};

#endif