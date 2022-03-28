// Copyright 2022 Bogdan Dumitrescu

#ifndef CONDITIONS_CHECK_H_
#define CONDITIONS_CHECK_H_

int check_is_number(char *str);

int check_no_params();

void check_one_param(char *p, int *first_param, int *ok);

void check_two_params(char *p, int *first_param, int *second_param, int *ok);

#endif  // CONDITIONS_CHECK_H_
