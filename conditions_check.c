#include "declarations.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int check_is_number(char *str)
{
    int sz = strlen(str);
    int d = 0;
    if(str[0] == '-')
        d = 1;
    for(int i = d; i < sz; i++)
        if(str[i] < '0' || str[i] > '9')
            return 0;

    return 1;
}

int check_no_params()
{
    if(strtok(NULL, " "))
    {
        PRINT_INVALID_COMMAND;
        return 0;
    }

    return 1;
}


void check_one_param(char *p, int *first_param, int *ok)
{
    p = strtok(NULL, " ");

    if(!p)
    {
        *ok = 1;
        PRINT_INVALID_COMMAND;
        return;
    }

    if(check_is_number(p) && !strtok(NULL, " ")) {
        *first_param = atoi(p);
    } else {
        *ok = 1;
        PRINT_INVALID_COMMAND;
    }  
        

}

void check_two_params(char *p, int *first_param, int *second_param, int *ok)
{
    p = strtok(NULL, " ");

    if(!p)
    {
        *ok = 1;
        PRINT_INVALID_COMMAND;
        return;
    }

    if(check_is_number(p)) {
        *first_param = atoi(p);
    } else {
        *first_param = -1;
        PRINT_INVALID_COMMAND;
        return ;
    }

    p = strtok(NULL, " ");

    if(!p)
    {
        *ok = 1;
        PRINT_INVALID_COMMAND;
        return;
    }

    if(check_is_number(p) && !strtok(NULL, " ")) {
        *second_param = atoi(p);
    } else {
        *ok = 1;
        PRINT_INVALID_COMMAND;
    }
     

}
