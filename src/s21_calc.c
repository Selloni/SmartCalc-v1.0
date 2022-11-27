#include "s21_calc.h"
int calc(Node **list, Node **s_lst, int next_prior, char oper) {
  if (*s_lst != NULL) {
    Data var1 = 0;
    Data var2 = 0;
    Data sum = 0;
    char stek_oper = (**s_lst).oper;
    if (oper == ')') {
      sum = total(list, s_lst);
    } else if (next_prior > (**s_lst).prioritet || oper == '(') {
// /* если в стеке приоритет меньше чем текущий, кладем знак в стек */
      push(s_lst, 0, oper, next_prior);
    } else {  //  рекурсия или цикл что бы постоянно проверял условие
      while (*s_lst != NULL && next_prior <= (**s_lst).prioritet) {
        stek_oper = pop_s(s_lst);
        if (stek_oper < 75 && stek_oper > 65) {
          var1 = pop(list);
          sum = calc_triginimetr(var1, stek_oper);
          push(list, sum, '0', 0);
        } else {
          var1 = pop(list);
          var2 = pop(list);
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
          push(list, sum, '0', 0);
        }
      }
      push(s_lst, 0, oper, next_prior);
    }
  } else {
    push(s_lst, 0, oper, next_prior);
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
  while (*s_lst != NULL) {
    sign = pop_s(s_lst);
    if (sign == '(') {
      flag = 1;
      break;
    }
    if (sign > 65 && sign < 75) {
      sum = calc_triginimetr(pop(list), sign);
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
    }
    push(list, sum, '0', 0);
  }
  if (flag == 1) {
    total = sum;

  } else {
    total = pop(list);
  }
  return (total);
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
  } else if (stek_oper == 'J') {
    res = log(var);
  }
  return res;
}

int pars_sing(char val) {
  int prior = 0;
  if (val == '+') {
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
