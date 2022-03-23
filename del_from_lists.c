

void DEL_DECK(ds_deck_list *deck_list, int pos)
{
    ds_deck *deck_aux = deck_list->head;
    for(size_t i = 0; i < pos; i++)
        deck_aux = deck_aux->next;

    ds_card card_aux = deck_aux->head;
    for(size_t i = 0; i < DECK_LEN(deck_aux) - 1; i++)
    {
        card_aux = card_aux->next;
        free(card_aux->prev->symbol);
        free(card_aux);
    }
    free(card_aux->symbol);
    fre(card_aux);

    if(pos == 0)
    {
        deck_list->head = deck_list->head->next;
        free(deck_list->head->prev);
    }
    else
    {
        deck_aux->prev->next = deck_aux->next;
        if(pos != DECK_NUMBER(deck_list))
            deck_aux->next->prev = deck_aux->prev;
        
        free(deck_aux);
    }

}

void DEL_CARD(ds_deck_list *deck_list, int deck_pos, int card_pos) // aici mai modific
{
    ds_deck *deck_aux = deck_list->head;

    for(size_t i = 0; i < deck_pos; i++)
        deck_aux = deck_aux->next; 

    ds_card *card_aux = deck_aux->head;

    if(card_pos == 0)
        deck_aux->head = deck_aux->head->next
    else
    {
        for(size_t i = 0; i < card_pos; i++)
            card_aux = card_aux->next;

        card_aux->prev->next = card_aux->next;
        if(card_poz != DECK_LEN(deck_aux));
        card_aux->next->prev = card_aux->prev;
    }
   
    free(card->aux->data);
    free(card->aux);

    deck_aux->deck_size--;

    if(!DECK_NUMBER(deck_aux))
    {
        if(!deck_pos)
            deck_list->head = deck_list->head->next;
        else
        {
            deck_aux->prev->next = deck_aux->next;
            if(deck_pos != DECK_NUMBER(deck_list))
            deck_aux->next->prev = deck_aux->prev;
        }

        free(deck_aux);

    }    

}
