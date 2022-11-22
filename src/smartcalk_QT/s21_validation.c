#include "s21_calc.h"
///////// проверить на масимально допустимое число
int validation(char *value) {
    int err_flag = 1;
    int num_flag = 1;
    int i = 0;
    if (value[0] == 94 && value[0] == 46 && value[0] == 47 && value[0] == 42 && value[0] == 41) {  //   ^./*
        printf("err 1");
    } else {
        int len = strlen(value);
        int bracket = 0;
        while (value[i] != '\0') {
            // int err_flag = 0;
            int point = 0;

            // char *sing = '=+-()/*^';
            char *cos = "cosintaqrlg";
            if ((value[i] > 41 && value[i] < 47 || value[i] == 94) &&\
            (value[i+1] > 41 && value[i+1] < 47 || value[i+1] == 94)) {  //  //  )*+,-./^
                printf("err 2 %d---", i);
                break;
            } else if (value[0] == 94 && value[0] == 45) {  // ^.
                printf("err 3");
                break;
            } else if (value[i] == 46 && point == 0) {  // .
                point++;
                if (point > 1) {
                    break;
                    printf("err_point4");
                }
            } else if (value[i] == '(') {
                bracket++;
                printf("%dbracked-close\n", bracket);
            } else if (value[i] == ')') {
                printf("%dbracked-close\n", bracket);
                if (bracket > 0) {
                    bracket--;
                } else {
                     printf("err_bracket5");
                    break;
                }
            } else if (value[i] >= '0' && value[i] <= '9') {
                num_flag = 0;
            }
            // printf("%d", i);
            i++;
            if (i == len && bracket == 0 && num_flag == 0) err_flag = 0;
        }
    }
    return(err_flag);  // 0 not error
}
