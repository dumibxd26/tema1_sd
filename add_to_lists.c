
ds_deck CREATE_DECK(int size)
{
    for(size_t i = 0; i < size;)
    {
        scanf("%d")
    }
}

void ADD_DECK(ds_deck_list *deck_list, ds_deck *deck_add)
{
    deck_list->deck_tail->next = deck_add;
    deck_add->prev = deck_list->deck_tail;
    deck_list->deck_tail = deck_add;
}

void ADD_CARDS(ds_deck_list *deck_list, ds_deck **deck_add, int pos) //refac
{
    ds_deck *deck = deck_list->deck_head;

    for(size_t i = 0; i < pos; i++)
        deck = deck->next;
    
    deck->card_tail->next = (*deck_add)->deck_head;
    (*deck_add)->deck_head = deck->card_tail;
    deck->card_tail = (*deck_add)->card_tail;
    deck->deck_size += (*deck_add)->deck_size;

    free(*deck_add);

}