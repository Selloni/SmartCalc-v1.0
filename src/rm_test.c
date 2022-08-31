#include <stdlib.h>
#include <stdio.h>

typedef int Data;

typedef struct Nod {
    Data data;  // что бы ввести строку нужно запсиать ее в переменную, выделить ей память и стркопии записать в нвый выдленный масиф 
    struct Nod *next; 
}Nod;

void print (Nod *list) {
    for(Nod *p = list; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");
}

void push (Nod **list, Data val) {
    Nod *tmp = malloc(sizeof(Nod));
    tmp->data = val;
    tmp->next = *list;
    *list = tmp;
    // free(*tmp);
}



int main () {

    // char str[5] = "32.2h";
    // float num;
    // num = atof(str);
    // printf("%f", num);
    Nod *list = NULL;
    int test[] = {13 , 14, 11, 4};
    // Data *str= "32";
    // Data *str2 = "+";
    // Data *str3 = "11";
    // push(&list, str);
    // push(&list, str2);
    // push(&list, str3);
    for (int i = 0; i < 4; i ++){
        push(&list, test[i]);
    }
    print(list);
    return 0;
}
