#pragma once

// #ifndef SRC_S21_CALC_H_
// #define SRC_S21_CALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef double Data;

// структура элемента списка
typedef struct Node {
  Data data;  //  цифры
  struct Node *next;  // это у нас ссылка на следующий указатель
  char oper;  //  знаки
  int prioritet;  //  приоритет, у цифр = 0
} Node;
// typedef struct Node Node;

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
int graf_validation(double xMax, double xMin, double yMin, double yMax);

// #endif
