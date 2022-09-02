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
    // printf("addres%p\n", list);
    print(list);
    // printf("\n");
    print(s_lst);
    // while (!is_emty(list)) {
    //     // printf("opop");
    //     pop(&list);
    //     print(list);
    // }
}
