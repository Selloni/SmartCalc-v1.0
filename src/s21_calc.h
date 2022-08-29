#pragma once

// #ifndef SRC_S21_CALC_H_
// #define SRC_S21_CALC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <math.h>

#define tgr m || d || c || o || s || i || n || t || a || q || r || l || g  //  вместо перебора в цикле
typedef int Data;


enum operator {
    // score = 0.
    plus = 1,
    minus = 2,
    mult = 3,
    division = 4,
    exp = 5,
    mod = 6,
    cos = 7,
    sin = 8,
    tan = 9,
    acos = 10,
    asin = 11,
    atan = 12,
    sqrt = 13,
    ln = 14,
    log = 15,
    brack_op = 16,
    brack_cl = 17,

};




// структура элемента списка
typedef struct Node {
    Data data; // по этому указателю мы храним какие-то данные
    struct Node *next; // это у нас ссылка на следующий указатель
    char operator;
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



void push(Node **plist, Data value, int operator, int prior);
int is_emty(Node *list);
int pop(Node **plist);
int pull_stack(char *value, Node *list, Node *s_lst);
int trigonometr(Node *s_lst, char *str);
int validation(char *value);
int pars_sing(Node *s_lst, char val);

// #endif