#include "s21_calc.h"

int main () {
    Node *list = NULL;
    Node *s_lst = NULL;
    // s_lst->prioritet = 0;
    // s_lst->operator = '\0';
    char *str = "2+17-9";
//  реализовать запись строки в обратную сторону 
    // int len = strlen(str);
    // char invert[--len];
    // int i = 0;
    // while (len >= 0) {
    //     invert[i] = str[len]; 
    //     i++;
    //     len--;
    // }  для этого способа, нужно разить числа на лик-семы
//  реализовал запись строки в обратную сторону
    int err;
    err = validation(str);
    if(validation(str)) {
        printf("\n%dvalid\n", err);
    } else {
        // printf("invert%s\n",str);
        pull_stack(str, &list, &s_lst);
    }
    print(list);
    print(s_lst);

}

void print(Node *list) {
    printf("-\n");
    for(Node *p = list; p != NULL; p = p->next) {
        printf("int%f ", p->data);
        printf("sign%c  ", p->operator); 
        printf("prior%d\n", p->prioritet); 
        
    }
    printf("-\n");
}