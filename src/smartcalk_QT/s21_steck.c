#include "s21_calc.h"
//  нужно добавить if-х, после разбора qt
double pull_stack(char *value) {
    Node *list = NULL;
    Node *s_lst = NULL;
    Data err_flag = 0;  //  раскрыть флаг
    int num_flag = 0;
    int have_trg = 0;
    Data num;
    int i = 0;
    int j = 0;
    int k = 0;  //  нужно придумать что то элегантнее
    char str[256] = {'\0'};  //  есть ли не обходимось создавать статический масив
    int len = strlen(value);
    len +=1;
    if (value[0] == '-') {
        push(&list, 0, 0, 0);
        push(&s_lst, 0, '-', 1);
        i++;
    }
    while (i != len) {
        if (value[i] > 47 && value[i] < 58 || value[i] == '.') {
            str[j] = value[i];
            num_flag = 1;
            j++;
         /////////// заупстить тригонометрическую функцию
        //  } else if (value[i] == 'X') {  //   передовать переменную , которой пользователь будет присваивать х
         } else {  //  не цифры
            j = 0;  //////// касяк
            if (num_flag) {
                num = atof(str);
                push(&list, num, '0', 0);
                memset(&str, '\0', 256);  //  зачистить статическую строку
            }
            num_flag = 0;
            if (value[i] > 96 && value[i] < 123) {  // alphabet
                str[k] = value[i];
                have_trg = 1;  //   думал реализовать флаг, для контроля входа в цикл
                k++;
            } else if (have_trg) {  //заходит в фунцию тригонометрия выполняет функцию, но не заходит в устловие if
                trigonometr(&s_lst, str);
                have_trg = 0;
                push(&s_lst, 0, '(', -1);  //  сразу после тригонометрии пушу скобку
                memset(&str, '\0', 256);  //  зачистить статическую строку
                // printf("err_trigonmetri");
                // break;
            } else {
                if (value[i] != '\0') { // костыль
                int prior = pars_sing(value[i]);
                printf("списаок занков");
                print(s_lst);
                calc(&list, &s_lst, prior, value[i]);
                } else {
                    break;
                }
            }
        }
        i++;
    }
    print(s_lst);
    print(list);
    // list = revers_steack(&list);
    // s_lst = revers_steack_s(&s_lst);
    print(s_lst);
    print(list);
    err_flag = total(&list, &s_lst);
    return (err_flag);
}

int trigonometr(Node **s_lst, char *word) {
    char str[5] = {'\0'};
    int err = 0;
    char tmp0[] = "cos";
    char tmp1[] = "sin";
    char tmp2[] = "tan";
    char tmp3[] = "acos";
    char tmp4[] = "asin";
    char tmp5[] = "atan";
    char tmp6[] = "sqrt";
    char tmp7[] = "ln";
    char tmp8[] = "log";
    char tmp9[] = "mod";
    for(int i = 0; word[i] != '\0'; i++){  //  отстой, спросить рекомендации как сдлеать лучше
        str[i] = word[i];
    }
    if (!strcmp(str, tmp0)) {  //cos
        err = 1;
        push(s_lst, 0, 'B', 4);
    } else if (!strcmp(str, tmp1)) {  //sin
        err = 1;
        push(s_lst, 0, 'C', 4);
    } else if (!strcmp(str, tmp2)) {  // tan
        err = 1;
        push(s_lst, 0, 'D', 4);
    } else if (!strcmp(str, tmp3)) {  //acos
        err = 1;
        push(s_lst, 0, 'E', 4);
    } else if (!strcmp(str, tmp4)) {  //asin
        err = 1;
        push(s_lst, 0, 'F', 4);
    } else if (!strcmp(str, tmp5)) {   //atan
        err = 1;
        push(s_lst, 0, 'G', 4);
    } else if (!strcmp(str, tmp6)) {  //sqrt
        err = 1;
        push(s_lst, 0, 'H', 4);
    } else if (!strcmp(str, tmp7)) {  //ln
        err = 1;
        push(s_lst, 0, 'I', 4);
    } else if (!strcmp(str, tmp8)) {  //log
        err = 1;
        push(s_lst, 0, 'J', 4);
    } else if (!strcmp(str, tmp9)) {  //mod
        err = 1;
        push(s_lst, 0, 'A', 2);
    }
    return (err);
}

Node *revers_steack(Node **list) {
    Node *revers_list = NULL;
    while (*list != NULL) {
        Data data = pop(list);
        push(&revers_list, data, '0', 0);
    }
    return revers_list;
}

Node *revers_steack_s(Node **list) {
    Node *revers_list = NULL;
    while (*list != NULL) {
        char data = pop_s(list);
        push(&revers_list, 0, data, 0);
    }
    return revers_list;
}

Data pop(Node **plist) {
    Node *p = *plist;
    Data res = p->data;
    *plist = p->next;
    free (p);
    return res;
}

void push(Node **plist, Data value, char oper, int prior) {
    Node *p = malloc(sizeof(Node));
    p->data = value;
    p->oper = oper;
    p->next = *plist;
    p->prioritet = prior;
    *plist = p;
}

void print(Node *list) {
    printf("-\n");
    for(Node *p = list; p != NULL; p = p->next) {
        printf("int%f ", p->data);
        printf("sign%c\n ", p->oper);
    }
    printf("-\n");
}

int is_emty(Node **list) {
    return (list == NULL);
}

char pop_s(Node **plist) {
    Node *p = *plist;
    char res = p->oper;
    *plist = p->next;
    free (p);
    return res;
}
