// #include "declarations.h"

// int DECK_NUMBER(ds_deck_list *deck_list)
// {
//     return deck_list->total_decks;
// }

// int DECK_LEN(ds_deck *deck)
// {
//     return deck->deck_size;
// }

// void REVERSE_DECK(ds_deck *deck)
// {
    
//     ds_card *prev, *next, *current;

//     current = deck->card_head;

//     while(current)
//     {
//         next = current->next;
//         current->next = prev;
//         current = next;
//     }

// }

// void SHUFFLE_DECK(ds_deck *deck)
// {
//     int mid = deck->deck_size / 2;

//     ds_card *card = deck->card_head;

//     for(size_t i = 0; i < mid; i++)
//         card = card->next;

//     ///aici

// }

// void SORT_DECK(ds_deck *deck)
// {
//     ds_card *aux_i = deck->card_head, *aux_j;

//     while(aux_i->next)
//     {
//         aux_j = aux_i->next;
//         while(aux_j)
//         {
//             if(aux_i->data.val > aux_j->data.val || 
//                aux_i->data.val == aux_j->data.val &&
//                aux_i->data.sym_conversion > aux_j->data.sym_conversion)
//             {
//                 ds_card_data *aux_swap;
//                 aux_swap = aux_i->data;
//                 aux_i->data = aux_j->data;
//                 aux_j->data = aux_swap;
//             }
//           aux_j = aux_j->next;
//         }
//     }

// }

// void EXIT(ds_deck_list **deck_list)
// {
//     ds_deck_list *deck_aux = *deck_list;

//     while(DECK_LEN(*deck_list, 0, 0)) // Delete every first node untill we delete all lists
//        DEL_CARD(*deck_list, 0, 0);    

//     free(*deck_list);

// }