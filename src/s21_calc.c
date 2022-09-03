#include "s21_calc.h"

int calc(Node *list, Node *s_list, int next_prior, char oper) {
    if(s_list != NULL) {
    // if (s_list->prioritet > 0 && s_list->prioritet < 6) {
        Data var1 = 0;
        Data var2 = 0;
        Data sum = 0;
        char stek_oper = s_list->operator;
        int stek_prior = s_list->prioritet;
        printf("в стеке приоритет %d|символ(%c)\n", s_list->prioritet, s_list->operator);
            //передаю инвентированную строку 
        if (next_prior > s_list->prioritet || /*oper == ')' ||*/ oper == '(') {
            push(&s_list, 0, oper, next_prior);
            printf("op%c|pr%d\n", oper, next_prior);
        } else {  //  рекурсия или цикл что бы постоянно проверял условие
            // var1 = pop(&list);
            // printf("1var%f\n", var1);
            // var2 = pop(&list);
            // printf("2var%f\n", var2);
            printf("c%cc", oper);
            if (stek_oper == '+') {
                sum = var2 + var1;  
            } else if (stek_oper == '-') {
                sum = var2 - var1;
            } else if (stek_oper == '/') {
                sum = var2 / var1;
            } else if (stek_oper == '*') {
                sum = var2 * var1;
            } else if (stek_oper == '^') {
                sum = pow(var2, var1);
            // } else if (stek_oper == '(') {
            //     push(s_list, 0, oper, next_prior);
            // } else if (stek_oper == ')') {
            }
            printf("sum%f\n", sum);
            // push(list, sum, '0', 0);
        }
    } else {
        push(&s_list, 0, oper, next_prior);
        printf("esle%c\n", oper);
        print(s_list);
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
        // prior = 0;    
    } else if (val == ')') {
        // prior = 0;
    }
    // printf("%cexit%d\n", val, prior);
    return prior;
}


  
