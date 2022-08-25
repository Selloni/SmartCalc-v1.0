#include "calc.h"


int validation(char *value) {
    int i = 0;
    if (value[0] == '94' && value[0] == '46' && value[0] == '47' && value[0] == '42') {
        printf("err 1");
    } else {
        while (value[i] != '\0') {
            int err_flag = 0;
            int point = 0;
            int bracket = 0;
            // char *sing = '=+-()/*^';
            char *cos = "cosintaqrlg";
            if ((value[i] > '41' && value[i] < '47' || value[i] == '94') &&\
            value[i++] > '41' && value[i++] < '47' || value[i++] == '94' || value[i++] == '\0') {
                printf("err 1");
                break;
            } else if (value[0] == '94' && value[0] == '45') {  // ^.
                printf("err 1");
                break;
            } else if (value[i] == '46' && point == 0) {  // .
                point++;
                if (point > 1) {
                    bracket;
                    printf('err_point');
                }
            } else if (value[i] == '40') {  // (
                bracket++;
            } else if (value[i] == '41') {  // )
                if (bracket == 0) {
                    break;
                    printf('err_bracket');
                } else {
                    bracket--;
                }
            } else if (value[i] > '47' && value[i] < '58') {  //   cos, sin, tg
                int flag_stop = 0;
                for(int a = 0; cos[a] != '\0'; a++) {
                    if (value[i] != cos[a])
                    flag_stop = 1;
                    break;
                }
                if (flag_stop > 0) break;
            }
            i++;
        }
    }
    // return(err_flag);
}

push(int value) {

}

pop() {

}

int pull_stack() {

}

