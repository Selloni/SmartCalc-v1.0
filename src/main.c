#include "s21_calc.h"

int main () {
    Node *list = NULL;
    Node *s_lst = NULL;
    // char *str = "(0.25+17)*8.6";
    char *str = "25+17*86";
    int err;
    err = validation(str);
    if(validation(str)) {
        printf("\n%dvalid\n", err);
    } else {
        pull_stack(str, &list, &s_lst);
    }
    // for (Node *p = list; p != NULL; p = p->next) {
    //     printf("l %d ", p->data);
    // }
    // print(&list);
    printf("%p ", list);
    printf ("\n");
    printf("kostya");
    // for (Node *p = s_lst; p != NULL; p = p->next) {    
    //     printf("s %d ", p->operator);
    //     printf("s %d ", p->prioritet);
    // }
    // printf("asa");

    
    // typedef struct list_item Node;
//     int  *test = {3, 18, 65};
//     Node *list = NULL;
//     for(size_t i = 0; i < sizeof(test)/sizeof(test[0]); i++) {
//         push(&list, test[i], 0);
//         // printf(&list);
//     }

    for (Node *p = list; p != NULL; p = p->next){
        printf("%d ", p->data);
    }
    
//     // while (! is_emty(list)) {
//     //     int d = pop(&list);
//     //     printf(pop(is_emty));
//     // }
}
