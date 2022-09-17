#include "s21_calc.h"
 //// почти готово, если тригонометрия есть проблема то что раньше заканчиватеься цикл, если двойной квадрат верно не отрабатывает\
 , првоерить отрабатывает ли минус в переди числа ! так же нужно написать тесты
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
            while (*s_lst != NULL && next_prior <= (**s_lst).prioritet) {
                print(*s_lst);
                print(*list);
                stek_oper = pop_s(s_lst);
                if(stek_oper < 75 && stek_oper > 65) {
                    var1 = pop(list);
                    sum = calc_triginimetr(var1, stek_oper);
                    printf("summ-trigonometr%f\n", sum);
                    push(list, sum, '0', 0);
                } else {
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
                    }
                    printf("sum%f\n", sum);
                    push(list, sum, '0', 0);
                }
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
    Data sum = 0;
    Data total;
    char sign;
    int flag = 0;   
    while(*s_lst != NULL) {
        sign = pop_s(s_lst);
        // printf ("totol sign%c\n", (**s_lst).operator);
        if (sign == '(') {
            flag = 1;
            printf("'('sum%f\n", sum);
            break;
        } 
        if (sign > 65 && sign < 75) {
            sum = calc_triginimetr(pop(list),sign);
        } else {
            var1 = pop(list);
            var2 = pop(list);
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
            } else if (sign == 'A') {
                sum = fmod(var2, var1);
            }
            printf("sum%f\n", sum);
        }
        push(list, sum, '0', 0);
    }
    if (flag == 1) {
        total = sum;
        // printf("итого%f", total);
    } else {
        total = pop(list);
    }
    return(total);
}

Data calc_triginimetr(Data var, char stek_oper) {
    Data res = 0;
    if (stek_oper == 'B') {
        res = cos(var);
    } else if (stek_oper == 'C') {
        res = sin(var);
    } else if (stek_oper == 'D') {
        res = tan(var);
    } else if (stek_oper == 'E') {
        res = acos(var);
    } else if (stek_oper == 'F') {
        res = asin(var);
    } else if (stek_oper == 'G') {
        res = atan(var);
    } else if (stek_oper == 'H') {
        res = sqrt(var);
    // } else if (stek_oper == 'I') {
    //     res = ln(var);
    } else if (stek_oper == 'J') {
        res = log(var);
    }
    return res;

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


  
