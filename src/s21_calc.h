#pragma once

// #ifndef SRC_S21_CALC_H_
// #define SRC_S21_CALC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define tgr m || d || c || o || s || i || n || t || a || q || r || l || g  //  вместо перебора в цикле
typedef double Data;


enum operator {
    // score = 0.
    plus_s = 1,
    minus_s = 2,
    mult_s = 3,
    division_s = 4,
    exp_s = 5,
    mod_s = 6,
    cos_s = 7,
    sin_s = 8,
    tan_s = 9,
    acos_s = 10,
    asin_s = 11,
    atan_s = 12,
    sqrt_s = 13,
    ln_s = 14,
    log_s = 15,
    brack_op_s = 16,
    brack_cl_s = 17,

};




// структура элемента списка
typedef struct Node {
    Data data; // по этому указателю мы храним какие-то данные
    struct Node *next; // это у нас ссылка на следующий указатель
    int operator;
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



void push(Node **plist, Data value, char operator, int prior);
int is_emty(Node *list);
int pop(Node **plist);
int pull_stack(char *value, Node **list, Node **s_lst);
int trigonometr(Node **s_lst, char *str);
int validation(char *value);
// int pars_sing(Node **s_lst, char val);
void print(Node *list);

// #endif