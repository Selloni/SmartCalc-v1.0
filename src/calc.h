#pragma once

#include <stdio.h>
#define 
typedef struct s_stack{
    double a;
    struct stack *next // стремная штука ???????????????
    type_t type
} stack;

// структура элемента списка
typedef struct list_item {
    void *data; // по этому указателю мы храним какие-то данные
    struct list_item *next; // это у нас ссылка на следующий указатель
    struct list_item *prev; // это у нас ссылка на предыдущий указатель
} list_item;


// Общая структура списка
typedef struct list {
    int count; // информация о размере списка
    list_item *head; // это ссылка на головной элемент
    list_item *tail; // это у нас ссылка на последний элемент (хвост списка)
} list;
