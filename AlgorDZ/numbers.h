#ifndef _NUMBERS_
#define _NUMBERS_

#include <stdio.h>
#define STR_SIZE 100

typedef struct Mnoj{
    int _size;
    int* _data;
}Mnoj;

int checkbin(int k);
Mnoj* startw();
void input(Mnoj* A);
void output(Mnoj* A);
int tobinary(int k);
int pow(int a, int n);
#endif