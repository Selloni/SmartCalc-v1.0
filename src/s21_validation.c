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
            value[i+1] > 41 && value[i+1] < 47 || value[i+1] == 94 ) {  //  //  )*+,-./^
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
            }
            // printf("%d", i);
            i++;
            if (i == len) err_flag = 0;
        }
    }
    return(err_flag);  // 0 not error
}
