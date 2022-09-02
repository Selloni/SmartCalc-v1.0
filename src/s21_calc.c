#include "s21_calc.h"

int calc(Node *list, Node *s_list, int prior, char oper) {
    if (list->next != NULL) {
        Data var1;
        Data var2;
        Data sum = 0;
        // char stek_oper = s_list->operator;
            //передаю инвентированную строку 
        if (prior >= s_list->prioritet || oper == ')' || oper == '(') {
            push(s_list, 0, oper, prior);
        } else {
            var1 = pop(&list);
            printf("1var%f\n", var1);
            var2 = pop(&list);
            printf("2var%f\n", var2);
            printf("c%cc", oper);
            if (oper == '+') {
                sum = var2 + var1;  
            } else if (oper == '-') {
                sum = var2 - var1;
            } else if (oper == '/') {
                sum = var2 / var1;
            } else if (oper == '*') {
                sum = var2 * var1;
            } else if (oper == '^') {
                sum = pow(var2, var1);
            } else if (oper == '(') {
                push(s_list, 0, oper, prior);
            } else if (oper == ')') {
                
            }
            printf("sum%f\n", sum);
        }
    } else {
        push(s_list, 0, oper, prior);
    }
    return 0;
}

int pars_sing(char val) {
    int prior = 0;
    if(val == '+') {
        prior = 1;
    } else if (val == '-') {
        prior = 1;
    } else if (val == '/') {
        prior = 2;          
    } else if (val == '*') {
        prior = 2;          
    } else if (val == '^') {
        prior = 5;       
    } else if (val == '(') {
        prior = 0;     
    } else if (val == ')') {
        prior = 0;
    }
    printf("\n");
    return prior;
}


  
