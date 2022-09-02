#include "s21_calc.h"

int calc(Node *list, Node *s_list, int prior, char oper) {
    if (list->next != NULL) {
        Data var1;
        Data var2;
        Data sum = 0;
        char stek_oper = s_list->operator;
            //передаю инвентированную строку 
        if (prior >= s_list->prioritet || oper == ')' || oper == '(') {
            push(s_list, 0, oper, prior);
        } else {
            var1 = pop(&list);
            var2 = pop(&list);
            if (oper == '+') {
                sum = var2 + var1;  
            } else if (oper == '-') {
                sum = var2 - var1;
            } else if (oper == '/') {
                sum = var2 / var1;
            } else if (oper == '*') {
                sum = var2 * var1;
            } else if (oper == '^') {
                sum = pow(var2, var1);
            } else if (oper == '(') {
                push(s_list, 0, oper, prior);
            } else if (oper == ')') {
                
            }
            printf("%d", sum);
        }
    } else {
        push(s_list, 0, oper, prior);
    }
   
}

int pars_sing(char val) {
    int prior = 0;
    if(val == '+') {
        prior = 1;
    } else if (val == '-') {
        prior = 1;
    } else if (val == '/') {
        prior = 2;          
    } else if (val == '*') {
        prior = 2;          
    } else if (val == '^') {
        prior = 5;       
    } else if (val == '(') {
        prior = 0;     
    } else if (val == ')') {
        prior = 0;
    }
    printf("\n");
    return prior;
}

// int pars_sing(Node *s_lst, char val) {
//     int oper = 0;
//     int prior = s_lst->prioritet;
//     Data var1;
//     Data var2;
//     char sign;    
//     if (val == '+') {
//         if (s_lst->prioritet >= 1) {

//         }
//     } else if (val == '-') {
//         if (prior > s_lst->prioritet) {
//             push(s_list, 0, oper, prior);
//         } else {            
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
// }
  
