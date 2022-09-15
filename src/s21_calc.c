#include "s21_calc.h"

int calc(Node **list, Node **s_lst, int next_prior, char oper) {
    if(*s_lst != NULL) {
        Data var1 = 0;
        Data var2 = 0;
        Data sum = 0;
        char stek_oper = (**s_lst).operator;
        int stek_prior = (**s_lst).prioritet;
        printf("в стеке приоритет %d|символ(%c)-|-текущий приоритет %d: символ(%c)\n ",\
         (**s_lst).prioritet, (**s_lst).operator, next_prior, oper);
        if(oper == ')') {
            sum = total(list, s_lst);
        } else if (next_prior > (**s_lst).prioritet || /*oper == ')' ||*/ oper == '(') { // если в стеке приоритет меньше \
        чем текущий, кладем знак в стек 
            push(s_lst, 0, oper, next_prior);
            printf("op%c|pr%d\n", oper, next_prior);
        } else {  //  рекурсия или цикл что бы постоянно проверял условие
            while (*s_lst != NULL && next_prior <= (**s_lst).prioritet /*|| oper == ')' || oper == '('*/) {
                print(*s_lst);
                stek_oper = pop_s(s_lst);
                var1 = pop(list);
                printf("1var%f\n", var1);
                var2 = pop(list);
                printf("2var%f\n", var2);
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
                push(list, sum, '0', 0);
                // printf("cycle%p\n", *s_lst);
                // print(*s_lst);
            }
            printf("какой знак пушим%c\n", oper);
            push(s_lst, 0, oper, next_prior);    
        }
    } else {
        push(s_lst, 0, oper, next_prior);
        printf("пушим знак(%c)\n", oper);
        print(*s_lst);
    }
    return 0;
}

Data total(Node **list, Node **s_lst) {
    Data var1 = 0;
    Data var2 = 0;
    char sign;    
    while(*s_lst != NULL) {
        printf ("totol sign%c\n", (**s_lst).operator);
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
        } else if (sign == '(') {
            // printf("sum%f\n", sum);
            // push(list, sum, '0', 0);
            // break;
        }
        /// не пушит сумму 
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
        prior = 2;
    } else if (val == '-') {
        prior = 2;
    } else if (val == '/') {
        prior = 3;          
    } else if (val == '*') {
        prior = 3;          
    } else if (val == '^') {
        prior = 5;       
    } else if (val == '(') {
        prior = -1;    
    } else if (val == ')') {
        prior = -1;
    }
    return prior;
}


  
