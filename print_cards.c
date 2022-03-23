

void SHOW_DECK(ds_deck *deck)
{
    ds_card *aux = deck->head;

    for(size_t i = 0; i < deck->deck_size; i++)
    {   
        printf("\t%hhu %s\n", aux->val, aux->symbol);
        aux = aux->next;
    }
    
}

void SHOW_ALL(ds_deck_list *deck_list)
{
    ds_deck *deck_aux = deck_list->head;

    for(size_t i = 0; i < deck_list->total_decks; i++)
    {
        printf("Deck %d\n", deck_aux->deck_size);
        ds_card *card_aux = deck_aux->head;

        for(size_t j = 0; j < deck_aux->deck_size; i++)
        {
            printf("\t%hhu %s\n", card_aux->data.val, card_aux->data->symbol);
            card_aux = card_aux->next;
        }
          
        deck_aux = deck_aux->next;
    }
}
