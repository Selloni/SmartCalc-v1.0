#include "s21_calc.h"

int calc(Node **list, Node **s_lst, int next_prior, char oper) {
    if(*s_lst != NULL) {
        // printf("xx%p\n", *s_lst);
    // if (s_lst->prioritet > 0 && s_lst->prioritet < 6) {
        Data var1 = 0;
        Data var2 = 0;
        Data sum = 0;
        char stek_oper = (**s_lst).operator;
        int stek_prior = (**s_lst).prioritet;
        printf("в стеке приоритет %d|символ(%c)\n", (**s_lst).prioritet, (**s_lst).operator);
            //передаю инвентированную строку 
        if (next_prior > (**s_lst).prioritet || /*oper == ')' ||*/ oper == '(') {
            push(s_lst, 0, oper, next_prior);
            printf("op%c|pr%d\n", oper, next_prior);
        } else {  //  рекурсия или цикл что бы постоянно проверял условие
            var1 = pop(list);
            printf("1var%f\n", var1);
            var2 = pop(list);
            printf("2var%f\n", var2);
            printf("какое действие выполняет%c\n", oper);
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
            //     push(s_lst, 0, oper, next_prior);
            // } else if (stek_oper == ')') {
            }
            printf("sum%f\n", sum);
            // push(list, sum, '0', 0);
        }
    } else {
        push(s_lst, 0, oper, next_prior);
        printf("пушим знак(%c)\n", oper);
        print(*s_lst);
        // printf("ll%p\n", s_lst);
    }
    return 0;
}

Data total(Node **list, Node **s_lst) {
    Data var1 = 0;
    Data var2 = 0;
    char sign;
    // printf("hj%p\n", s_lst);
    printf ("totol sign%c\n", (**s_lst).operator);
    while(*s_lst != NULL) {
        Data sum = 0;
        var2 = pop(list);
        var1 = pop(list);
        sign = pop_s(s_lst);
        if (sign == '+') {
            sum = var2 + var1;  
        } else if (sign == '-') {
            sum = var2 - var1;
        } else if (sign == '/') {
            sum = var2 / var1;
        } else if (sign == '*') {
            sum = var2 * var1;
        } else if (sign == '^') {
            sum = pow(var2, var1);
        }
        printf("sum%f\n", sum);
        push(list, sum, '0', 0);
    }
    Data total = pop(list);
    printf("итого%f", total);
    return(total);
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
    return prior;
}


  
