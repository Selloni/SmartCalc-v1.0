#include <stdlib.h>
#include <stdio.h>

typedef struct Nod {
    int data;
    struct Nod *next;
}Nod;

void print (Nod *list);
void push (Nod **list, int val);




int main () {

    char str[5] = "32.2h";
    float num;
    num = atof(str);
    printf("%f", num);
    // Nod *list = NULL;
    // int test[] = {13 , 14, 11, 4};
    // for (int i = 0; i < 4; i ++){
    //     push(&list, test[i]);
    // }
    // print(list);
    return 0;
}

void print (Nod *list) {
    for(Nod *p = list; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");
}

void push (Nod **list, int val) {
    Nod *tmp = malloc(sizeof(Nod));
    tmp->data = val;
    tmp->next = *list;
    *list = tmp;
    // free(*tmp);
}
