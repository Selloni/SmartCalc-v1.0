#include "s21_calc.h"

int validation(char *value) {
  int err_flag = 1;
  int num_flag = 1;
  int i = 0;
  int point = 0;
  int len = strlen(value);
  if (len != 0) {
    if (value[0] == 94 || value[0] == 46 || value[0] == 47 || value[0] == 42 ||
        value[0] == 41 || value[i] == 37) {  //  )^./*
      err_flag = 1;
    } else {
      int bracket = 0;
      while (value[i] != '\0') {
        if (((value[i] > 41 && value[i] <= 47) || value[i] == 94 ||
             value[i] == 37) &&
            ((value[i + 1] >= 41 && value[i + 1] <= 47) || value[i + 1] == 94 ||
             value[i + 1] == 37)) {  //  )*+,-./^%
          if ((value[i] != ')' && value[i - 1] != ')') ||
              (value[i] != ')' && value[i + 1] != ')'))
            break;
        } else if (value[i] == '(' &&
                   ((value[i + 1] >= 41 && value[i + 1] <= 47) || value[i + 1] == 94 || value[i + 1] == 37) && (value[i + 1] != 45 || value[i + 1] != 43)) {
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
          num_flag = 0;  //  для защиты от пустых скобок
        }
        i++;
        if (i == len && bracket == 0 && num_flag == 0) {
          if ((value[i - 1] >= '0' && value[i - 1] <= '9') ||
              value[i - 1] == ')' || value[i - 1] == 'X') {
            err_flag = 0;
          }
        }
      }
    }
  }
  return (err_flag);  //  0 not error
}

int graf_validation(double xMax, double xMin, double yMin, double yMax) {
  int return_value = 0;
  if (xMin >= xMax || yMin >= yMax) return_value = 1;
  return return_value;
}
