#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Data;

enum prioritet {
    // score = 0
    plus = 1,
    minus = 1,
    mult = 3,
    div = 3,
    exp = 4,
    mod = 1,
};



// структура элемента списка
typedef struct Node {
    Data data; // по этому указателю мы храним какие-то данные
    struct Node *next; // это у нас ссылка на следующий указатель
    int prioritet;// struct list_item *prev; // это у нас ссылка на предыдущий указатель
}Node;
// typedef struct Node Node;


// // Общая структура списка
// typedef struct list {
//     int count; // информация о размере списка
//     list_item *head; // это ссылка на головной элемент
//     list_item *tail; // это у нас ссылка на последний элемент (хвост списка)
// } list;

void push(Node **plist, Data value, int import);
int is_emty(Node *list);
int pop(Node **plist);
