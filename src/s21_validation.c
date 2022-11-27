#include "s21_calc.h"
/////////  проверить на масимально допустимое число
int validation(char *value) {
  int err_flag = 1;
  int num_flag = 1;
  int i = 0;
  int point = 0;
  if (value[0] != 94 || value[0] != 46 || value[0] != 47 || value[0] != 42 ||
      value[0] != 41 || value[0] != 45) {  //  ^./*
    int len = strlen(value);
    int bracket = 0;
    while (value[i] != '\0') {
      char *cos = "cosintaqrlg";
      if ((value[i] > 41 && value[i] < 47 || value[i] == 94) &&
          ((value[i + 1] > 41 && value[i + 1] < 47) ||
           value[i + 1] == 94)) {  //  )*+,-./^
        break;
      } else if (value[i] == '*' || value[i] == '+' || value[i] == '/' ||
                 value[i] == '-') {
        point = 0;
      } else if (value[i] == 46 && point == 0) {  // точка
        point++;
        if (point > 1) {
          break;
        }
      } else if (value[i] == '(') {
        bracket++;
      } else if (value[i] == ')') {
        if (bracket > 0) {
          bracket--;
        } else {
          break;
        }
      } else if ((value[i] > 47 && value[i] < 58) || value[i] == 'X') {
        num_flag = 0;
      }
      i++;
      if (i == len && bracket == 0 && num_flag == 0) {
        err_flag = 0;
      }
    }
  }
  return (err_flag);  // 0 not error
}
