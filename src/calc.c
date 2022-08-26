#include "calc.h"


int validation(char *value) {
    int err_flag = 1;
    int i = 0;
    if (value[0] == '94' && value[0] == '46' && value[0] == '47' && value[0] == '42') {
        printf("err 1");
    } else {
        int len = strlen(value);
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
            } else if (value[i] > '47' && value[i] < '58') {  //   cos, sin, tg /// переделать проверу на тангенс
                int flag_stop = 0;
                for(int a = 0; cos[a] != '\0'; a++) {
                    if (value[i] != cos[a])
                    flag_stop = 1;
                    break;
                }
                if (flag_stop > 0) break;
            }
            i++;
            if (i = len) err_flag = 0;
        }
    }
    return(err_flag);  // 0 not error
}

void push(Node **plist, Data value, int import) {
    Node *p = malloc(sizeof(Node));
    p->data = value; 
    p->next = *plist;
    p->prioritet = import;
    *plist = p;
}

int is_emty(Node *list) {
    return (list == NULL) ? 0 : 1;
}

Data pop(Node **plist) {
    Node *p = *plist;
    Data res = p->data;
    *plist = p->next; 
    free (p);
    return res;
}

int pars_sign(val) {
    int priora;
    if(val == '+' || val == '-'){
        priora = plus;
    } else if (val == '/' || val == '*'){
        priora = div;
    } else if (val == '^'){
        priora = exp;
    }
    return priora;
}

int pull_stack(char *value) {
    int err_flag = 0;  //  раскрыть флаг 
    Node *list = NULL;
    sing *s_lst = NULL;
    int i = 0;
    int j = 0;
    char *str;
    while (value[i] != '\0') {
        if(value[i] > '47' && value[i] < '57') {
            str[j] = value[i];
        }
        else if (value[i] < '47' && value[i] > '57') {
            int num;
            num = str - '0';
            printf('%s', str);  ///////// 
            push(&list ,num, 0);
            push(&s_lst, value[i], pars_sing(value[i])); 
        }
    }
    return (err_flag);
}

int liksema () {

}