#include "s21_calc.h"
/// могу ли яне передаввать адрес 

  //  нужно добавить if-х, после разбора qt 
int pull_stack(char *value) {
    Node *list = NULL;
    Node *s_lst = NULL;
    int err_flag = 0;  //  раскрыть флаг 
    int num_flag = 0;
    Data num;
    int i = 0;
    int j = 0;
    int k = 0;  //  нужно придумать что то элегантнее 
    char *trg = "mdcosintaqrlg";
    char str[256] = {'\0'};  //  есть ли не обходимось создавать статический масив
    int len = strlen(value);
    len +=1;
    if (value[0] == '-') {
        push(&list, 0, 0, 0);
        push(&s_lst, 0, '-', 1);
        i++;
    }
    // printf("hj%p\n", s_lst);
    while (i != len) {
        if (value[i] > 47 && value[i] < 58 || value[i] == '.') {
            str[j] = value[i];
            num_flag = 1;
            j++;
         /////////// заупстить тригонометрическую функцию 
        //  } else if (value[i] == 'X') {  //   передовать переменную , которой пользователь будет присваивать х
         } else {  //  не цифры
            j = 0;  //////// касяк  
            int have_trg = 0;
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
            } else if (!trigonometr(s_lst, str) && (have_trg)) {  //  проверить чательнее 
                printf("err_trigonmetri");
                break;
            } else {
                if (value[i] != '\0') {
                int prior = pars_sing(value[i]);
                // push(&s_lst, 0, value[i], prior);
                // print(s_lst);
                calc(&list, &s_lst, prior, value[i]);
                // printf("qq%p\n", s_lst);
                print(s_lst);
                } else {
                    break;
                }
            }
        }
        i++;
    }
    print(s_lst);
    print(list);
    printf("oo%p\n", s_lst);
    total(&list, &s_lst);
    return (err_flag);
    
    // printf("sign %c\n",s_lst->operator);
    
}

// int pars_sing(Node **s_lst, char val) {
//     int oper = 0;
//     if(val == '+') {
//         push(s_lst, 0, plus_s, 1);
//         oper = plus_s;
//     } else if (val == '-') {
//         push(s_lst, 0, minus_s, 1);
//         oper = minus_s;
              
//     } else if (val == '/') {
//         push(s_lst, 0, division_s, 2);
//         oper = division_s;
              
//     } else if (val == '*') {
//         push(s_lst, 0, mult_s, 2);
//         oper = mult_s;
              
//     } else if (val == '^') {
//         push(s_lst, 0, exp_s, 5);
//         oper = exp_s;
              
//     } else if (val == '(') {
//         push(s_lst, 0, brack_op_s, 5);
//         oper = brack_op_s;
              
//     } else if (val == '(') {
//         push(s_lst, 0, brack_cl_s, 5);
//         oper = brack_cl_s;
//     }
//     printf("\n");
//     return oper;
// }

int trigonometr(Node *s_lst, char *word) {
    char str[5];
    int err = 0;
    char tmp0[] = "cos";
    char tmp1[] = "sin";
    char tmp2[] = "tan";
    char tmp3[] = "acos";
    char tmp4[] = "asin";
    char tmp5[] = "atan";
    char tmp7[] = "sqrt";
    char tmp8[] = "ln";
    char tmp9[] = "log";
    char tmp10[] = "mod";
    for(int i = 0; word[i] != '\0'; i++){  //  отстой, спросить рекомендации как сдлеать лучше 
        // printf("%s\n", word);
        str[i] = word[i];
    }
    if (!strcmp(str, tmp0)) {
        err = 1;
        push(&s_lst, 0, cos_s, 4);
    } else if (!strcmp(str, tmp1)) {
        err = 1;
        push(&s_lst, 0, sin_s, 4);
    } else if (!strcmp(str, tmp1)) {
        err = 1;
        push(&s_lst, 0, tan_s, 4);
    } else if (!strcmp(str, tmp2)) {
        err = 1;
        push(&s_lst, 0, acos_s, 4);
    } else if (!strcmp(str, tmp3)) {
        err = 1;
        push(&s_lst, 0, asin_s, 4);
    } else if (!strcmp(str, tmp4)) {
        err = 1;
        push(&s_lst, 0, atan_s, 4);
    } else if (!strcmp(str, tmp5)) {
        err = 1;
        push(&s_lst, 0, sqrt_s, 4);
    } else if (!strcmp(str, tmp8)) {
        err = 1;
        push(&s_lst, 0, ln_s, 4);
    } else if (!strcmp(str, tmp9)) {
        err = 1;
        push(&s_lst, 0, log_s, 4);
    } else if (!strcmp(str, tmp10)) {
        err = 1;
        push(&s_lst, 0, mod_s, 2);
    }
    return (err);

}

void push(Node **plist, Data value, char operator, int prior) {
    Node *p = malloc(sizeof(Node));
    p->data = value;
    p->operator = operator;
    p->next = *plist;
    p->prioritet = prior;
    *plist = p;
}

void print(Node *list) {
    printf("-\n");
    for(Node *p = list; p != NULL; p = p->next) {
        printf("int%f ", p->data);
        printf("sign%d\n ", p->operator); 
    }
    printf("-\n");
}

int is_emty(Node *list) {
    return (list == NULL);
}

int pop(Node **plist) {
    Node *p = *plist;
    Data res = p->data;
    // printf("int pop%d\n", res);
    *plist = p->next; 
    free (p);
    return res;
}

char pop_s(Node **plist) {
    Node *p = *plist;
    char res = p->operator;
    *plist = p->next; 
    free (p);
    return res;
}
