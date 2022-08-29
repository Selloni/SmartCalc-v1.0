#include "s21_calc.h"

void push(Node **plist, Data value, int operator, int prior) {
    Node *p = malloc(sizeof(Node));
    p->data = value; 
    p->next = *plist;
    p->prioritet = prior;
    p->operator = operator;
    *plist = p;
}

// int is_emty(Node *list) {
//     return (list == NULL) ? 0 : 1;
// }

Data pop(Node **plist) {
    Node *p = *plist;
    Data res = p->data;
    *plist = p->next; 
    free (p);
    return res;
}
