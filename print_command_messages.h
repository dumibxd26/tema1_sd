// Copyright 2022 Bogdan Dumitrescu

#ifndef PRINT_COMMAND_MESSAGES_H_
#define PRINT_COMMAND_MESSAGES_H_

#define PRINT_ADD_DECK(info)\
printf("The deck was successfully created with %d cards.\n", info);

#define PRINT_DEL_DECK(info)\
printf("The deck %d was successfully deleted.\n", info);

#define PRINT_DEL_CARD(info)\
printf("The card was successfully deleted from deck %d.\n", info);

#define PRINT_ADD_CARDS(info)\
printf("The cards were successfully added to deck %d.\n", info);

#define PRINT_DECK_NUMBER(info)\
printf("The number of decks is %d.\n", info);

#define PRINT_DECK_LEN(info1, info2)\
printf("The length of deck %d is %d.\n", info1, info2);

#define PRINT_SHUFFLE_DECK(info)\
printf("The deck %d was successfully shuffled.\n", info);

#define PRINT_MERGE_DECKS(info1, info2)\
printf("The deck %d and the deck %d were successfully merged.\n", info1, info2);

#define PRINT_SPLIT_DECK(info1, info2)\
printf("The deck %d was successfully split by index %d.\n", info1, info2);

#define PRINT_REVERSE_DECK(info)\
printf("The deck %d was successfully reversed.\n", info);

#define PRINT_SORT_DECK(info)\
printf("The deck %d was successfully sorted.\n", info);

#endif  // PRINT_COMMAND_MESSAGES_H_
