#pragma once

// #ifndef SRC_S21_CALC_H_
// #define SRC_S21_CALC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef double Data;


// структура элемента списка
typedef struct Node {
    Data data; // по этому указателю мы храним какие-то данные
    struct Node *next; // это у нас ссылка на следующий указатель
    char oper;
    int prioritet;// struct list_item *prev; // это у нас ссылка на предыдущий указатель
}Node;
// typedef struct Node Node;

// typedef struct sing {
//     char data; // по этому указателю мы храним какие-то данные
//     struct sing *next; // это у нас ссылка на следующий указатель
//     int operator;
//     int prioritet;// struct list_item *prev; // это у нас ссылка на предыдущий указатель
// }sing;
// // Общая структура списка
// typedef struct list {
//     int count; // информация о размере списка
//     list_item *head; // это ссылка на головной элемент
//     list_item *tail; // это у нас ссылка на последний элемент (хвост списка)
// } list;



void push(Node **plist, Data value, char oper, int prior);
int is_emty(Node **list);
Data pop(Node **plist);
char pop_s(Node **plist);
double pull_stack(char *value, Data value_x);
int trigonometr(Node **s_lst, char *str);
int validation(char *value);
int pars_sing(char val);
int calc(Node **list, Node **s_list, int next_prior, char oper);
void print(Node *list);
Data total(Node **list, Node **s_lst);
Node *revers_steack(Node **list);
Node *revers_steack_s(Node **list);
Data calc_triginimetr(Data var, char stek_oper);
// #endif