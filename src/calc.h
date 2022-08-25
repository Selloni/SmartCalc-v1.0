#pragma once
#include <stdio.h>


// структура элемента списка
typedef struct Node {
    int data; // по этому указателю мы храним какие-то данные
    struct Node *next; // это у нас ссылка на следующий указатель
    // struct list_item *prev; // это у нас ссылка на предыдущий указатель
}Node;
// typedef struct Node Node;


// // Общая структура списка
// typedef struct list {
//     int count; // информация о размере списка
//     list_item *head; // это ссылка на головной элемент
//     list_item *tail; // это у нас ссылка на последний элемент (хвост списка)
// } list;
