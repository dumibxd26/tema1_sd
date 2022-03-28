// Copyright 2022 Bogdan Dumitrescu

#ifndef ERRORS_H_
#define ERRORS_H_

#define PRINT_INVALID_COMMAND\
    printf("Invalid command. Please try again.\n");

#define PRINT_DECK_INDEX_OUT_OF_BOUNDS\
    printf("The provided index is out of bounds for the deck list.\n");

#define PRINT_CARD_INDEX_OUT_OF_BOUNDS(deck_index)\
    printf("The provided index is out of bounds for deck %d.\n", deck_index);

#define PRINT_INVALID_CARD\
    printf("The provided card is not a valid one.\n");

#endif  // ERRORS_H_
