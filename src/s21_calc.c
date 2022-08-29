#include "s21_calc.h"


int validation(char *value) {
    int err_flag = 1;
    int i = 0;
    if (value[0] == 94 && value[0] == 46 && value[0] == 47 && value[0] == 42) {  //   ^./*
        printf("err 1");
    } else {
        int len = strlen(value);
        while (value[i] != '\0') {
            // int err_flag = 0;
            int point = 0;
            int bracket = 0;
            // char *sing = '=+-()/*^';
            char *cos = "cosintaqrlg";
            if ((value[i] > 41 && value[i] < 47 || value[i] == 94) &&\
            value[i++] > 41 && value[i+1] < 47 || value[i+1] == 94 ) {  //  //  )*+,-./^
                printf("err 2 %d---", i);
                break;
            } else if (value[0] == 94 && value[0] == 45) {  // ^.
                printf("err 3");
                break;
            } else if (value[i] == 46 && point == 0) {  // .
                point++;
                if (point > 1) {
                    bracket;
                    printf("err_point4");
                }
            } else if (value[i] == '(') {  // (
                bracket++;
            } else if (value[i] == ')') {  // )
                if (bracket < 0) {
                    break;
                    printf("err_bracket5");
                } else {
                    bracket--;
                }
            } else if (value[i] < 47 || value[i] > 58) {  //   cos, sin, tg /// переделать проверу на тангенс
                int flag_stop = 0;
                for(int a = 0; cos[a] != '\0'; a++) {
                    if (value[i] != cos[a])
                    flag_stop = 1;
                    printf("err 6 i=%d---", i);
                    break;
                }
                if (flag_stop > 0) printf("err 7 %d---", i); break;
            }
            // printf("%d", i);
            i++;
            if (i == len) err_flag = 0;
        }
    }
    return(err_flag);  // 0 not error
}


int pars_sing(Node *s_lst, char val) {
    int oper = 0;
    if(val == '+') {
        push(&s_lst, 0, plus, 1);
        oper = plus;
    } else if (val == '-') {
        push(&s_lst, 0, minus, 1);
        oper = minus;
    } else if (val == '/') {
        push(&s_lst, 0, division, 2);
        oper = division;
    } else if (val == '*') {
        push(&s_lst, 0, mult, 2);
        oper = mult;
    } else if (val == '^') {
        push(&s_lst, 0, exp, 5);
        oper = exp;
    } else if (val == '(') {
        push(&s_lst, 0, brack_op, 5);
        oper = brack_op;
    } else if (val == '(') {
        push(&s_lst, 0, brack_cl, 5);
        oper = brack_cl;
    }
    return oper;
}

int pull_stack(char *value, Node *list, Node *s_lst) {
    int err_flag = 0;  //  раскрыть флаг 
    int num_flag = 0;
    double num;
    int i = 0;
    int j = 0;
    char *trg = "mdcosintaqrlg";
    char str[256] = {'\0'};  //  есть ли не обходимось создавать статический масив
    int len = strlen(value);
    len +=1;
    // len = len + 1;
    while (i != len) {
        if (value[0] == '-') {
            push(&list, 0, 0, 0);
            push(&s_lst, 0, minus, 1);
            i++;
        }
        if(value[i] > 47 && value[i] < 58 || value[i] == '.') {
            str[j] = value[i];
            num_flag = 1;
            j++;
            printf(".-%s-.", str);
         /////////// заупстить тригонометрическую функцию 
         } else {  //  не цифры
            j = 0;  //////// касяк  
            int have_trg = 0;
            if (num_flag) {
                num = atof(str);
                push(&list, num, 0, 0);
                printf("num-%f\n", num);
            }
            num_flag = 0;
            memset(str, '\0', 256);
            if (value[i] > 96 && value[i] < 123 ) {  // alphabet
                for(int l = 0; trg[l]; l++) {  // смотрим наш масиф тригонометрический и проверям ввод пользователья\
                запсисывваем в строку с которой в дальнейшем будем работать
                if (value[i] = trg[l]) str[l] = trg[l];
                    have_trg = 1;  //   думал реализовать флаг, для контроля входа в цикл
                }
            } else if (!trigonometr(s_lst, str) && (have_trg)) {  //  проверить чательнее 
                printf("err_trigonmetri");
                break;
            } else {
                // printf("в стк%s ", str);  ///////// 
                int g = pars_sing(s_lst, value[i]);
                // printf("%d",g);
            }
        }
        i++;
        // j++;
    }
    return (err_flag);
}


int trigonometr(Node *s_lst, char *str) {
    int err = 0;
    if (str == "cos") {
        err = 1;
        push(&s_lst, 0, cos, 4);
    } else if (str == "sin") {
        err = 1;
        push(&s_lst, 0, sin, 4);
    } else if (str == "tan") {
        err = 1;
        push(&s_lst, 0, tan, 4);
    } else if (str == "acos") {
        err = 1;
        push(&s_lst, 0, acos, 4);
    } else if (str == "asin") {
        err = 1;
        push(&s_lst, 0, asin, 4);
    } else if (str == "atan") {
        err = 1;
        push(&s_lst, 0, atan, 4);
    } else if (str == "sqrt") {
        err = 1;
        push(&s_lst, 0, sqrt, 4);
    } else if (str == "ln") {
        err = 1;
        push(&s_lst, 0, ln, 4);
    } else if (str == "log") {
        err = 1;
        push(&s_lst, 0, log, 4);
    } else if (str == "mod") {
        err = 1;
        push(&s_lst, 0, mod, 2);
    }
    return (err);
}

