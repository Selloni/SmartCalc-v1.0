#include "s21_calc.h"

int calc();

int pull_stack(char *value, Node **list, Node **s_lst) {
    int err_flag = 0;  //  раскрыть флаг 
    int num_flag = 0;
    Data num;
    int i = 0;
    int j = 0;
    char *trg = "mdcosintaqrlg";
    char str[256] = {'\0'};  //  есть ли не обходимось создавать статический масив
    int len = strlen(value);
    len +=1;
    // len = len + 1;
    while (i != len) {
        if (value[0] == '-') {
            push(list, 0, 0, 0);
            push(s_lst, 0, minus, 1);
            i++;
        }
        if(value[i] > 47 && value[i] < 58 || value[i] == '.') {
            str[j] = value[i];
            num_flag = 1;
            j++;
            // printf(".-%s-.", str);
         /////////// заупстить тригонометрическую функцию 
         } else {  //  не цифры
            j = 0;  //////// касяк  
            int have_trg = 0;
            if (num_flag) {
                num = atoi(str);
                push(list, num, 0, 0);
                printf("num-%d\n", num);
                // printf("d-%d ", *list->data);
                // printf("p-%d ", list->prioritet);
                // printf("o-%d ", list->operator);
            }
            num_flag = 0;
            memset(str, '\0', 256);
            if (value[i] > 96 && value[i] < 123 ) {  // alphabet
                for(int l = 0; trg[l]; l++) {  // смотрим наш масиф тригонометрический и проверям ввод пользователья\
                запсисывваем в строку с которой в дальнейшем будем работать
                str[i] = value[i];
                if (value[i] == trg[l]) str[l] = trg[l];
                    have_trg = 1;  //   думал реализовать флаг, для контроля входа в цикл
                }
            } else if (!trigonometr(s_lst, str) && (have_trg)) {  //  проверить чательнее 
                printf("err_trigonmetri");
                break;
            } else {
                // printf("в стк%s ", str);  ///////// 
                pars_sing(s_lst, value[i]);
                printf("end\n");
            }
        }
        i++;
        // j++;
    }
    print(*list);  ////  если поставить тут обычнй фор все работает, выносить в функцию все крашется
   ////// если передавать аддрес все крашеться
    return (err_flag);
}

int pars_sing(Node **s_lst, char val) {
    int oper = 0;
    printf("вхождение в поиск знака");
    if(val == '+') {
        push(s_lst, 0, plus, 1);
        oper = plus;
        // printf("sd-%d ", s_lst->operator);
        // printf("prior%d ", s_lst->prioritet);
    // } else if (val == '-') {
    //     push(&s_lst, 0, minus, 1);
    //     oper = minus;
    //     // printf("sd-%d ", s_lst->operator);
    //     // printf("prior%d ", s_lst->prioritet);
    // } else if (val == '/') {
    //     push(&s_lst, 0, division, 2);
    //     oper = division;
    //     // printf("sd-%d ", s_lst->operator);
    //     // printf("prior%d ", s_lst->prioritet);
    // } else if (val == '*') {
    //     push(&s_lst, 0, mult, 2);
    //     oper = mult;
    //     // printf("sd-%d ", s_lst->operator);
    //     // printf("prior%d ", s_lst->prioritet);
    // } else if (val == '^') {
    //     push(&s_lst, 0, exp, 5);
    //     oper = exp;
    //     // printf("sd-%d ", s_lst->operator);
    //     // printf("prior%d ", s_lst->prioritet);
    // } else if (val == '(') {
    //     push(&s_lst, 0, brack_op, 5);
    //     oper = brack_op;
    //     // printf("sd-%d ", s_lst->operator);
    //     // printf("prior%d ", s_lst->prioritet);
    // } else if (val == '(') {
    //     push(&s_lst, 0, brack_cl, 5);
    //     oper = brack_cl;
    //     // printf("sd-%d ", s_lst->operator);
    //     // printf("prior%d ", s_lst->prioritet);
    }
    printf("\n");
    // for (Node **p = s_lst; p != NULL; *p = (**p).next) {
    //     printf("so %d ", (**p).operator);
    //     printf("sp %d ", (**p).prioritet);
    // }
    // printf("sd-%d ", s_lst->operator);
    return oper;
}

int trigonometr(Node **s_lst, char *str) {
    int err = 0;
    if (str == "cos") {
        err = 1;
        push(s_lst, 0, cos, 4);
    } else if (str == "sin") {
        err = 1;
        push(s_lst, 0, sin, 4);
    } else if (str == "tan") {
        err = 1;
        push(s_lst, 0, tan, 4);
    } else if (str == "acos") {
        err = 1;
        push(s_lst, 0, acos, 4);
    } else if (str == "asin") {
        err = 1;
        push(s_lst, 0, asin, 4);
    } else if (str == "atan") {
        err = 1;
        push(s_lst, 0, atan, 4);
    } else if (str == "sqrt") {
        err = 1;
        push(s_lst, 0, sqrt, 4);
    } else if (str == "ln") {
        err = 1;
        push(s_lst, 0, ln, 4);
    } else if (str == "log") {
        err = 1;
        push(s_lst, 0, log, 4);
    } else if (str == "mod") {
        err = 1;
        push(s_lst, 0, mod, 2);
    }
    return (err);
}

