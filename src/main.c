#include "s21_calc.h"

int main () {
    Node *list = NULL;
    Node *s_lst = NULL;
    char *str = "-2.5+17+86+sin(45)";
//  реализовать запись строки в обратную сторону 
    int len = strlen(str);
    char invert[len];
    int i = 0;
    while (len != 0) {
        invert[i] = str[len]; 
        i++;
        len--;
    }
//  реализовал запись строки в обратную сторону
    int err;
    err = validation(str);
    if(validation(str)) {
        printf("\n%dvalid\n", err);
    } else {
        pull_stack(str, &list, &s_lst);
    }
    printf("%p ", list);
    print(list);
    printf ("\n");
    print(s_lst);
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

    // for (Node *p = list; p != NULL; p = p->next){
    //     printf("%d ", p->data);
    // }
    
    
//     // while (! is_emty(list)) {
//     //     int d = pop(&list);
//     //     printf(pop(is_emty));
//     // }
}
