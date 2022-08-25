#include "calc.h"

int main () {
    // typedef struct list_item Node;
    Node *list = NULL;
    Node a = {3};
    Node b = {5};
    Node c = {15};
    list = &a;
    a.next = &b;
    b.next = &c; 
    c.next = NULL;

    for (Node *p = list; p != NULL; p = p->next){
        printf("%d ", p->data);
    }
    // prinf("%d", p -> data); p = p -> next;
    // prinf("%d", p -> data); p = p -> next;
    // prinf("%d", p -> data); p = p -> next;
}