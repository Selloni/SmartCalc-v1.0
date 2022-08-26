#include "calc.h"

int main (int argc, char **argv) {
    // typedef struct list_item Node;
    int test[] = {3, 15 ,6};
    Node *list = NULL;
    for(size_t i = 0; i < sizeof(test)/sizeof(test[0]); i++) {
        push(&list, test[i], 0);
        // printf(&list);
    }

    for (Node *p = list; p != NULL; p = p->next){
        printf("%d ", p->data);
    }
    
    // while (! is_emty(list)) {
    //     int d = pop(&list);
    //     printf(pop(is_emty));
    // }
}


