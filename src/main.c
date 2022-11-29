#include "s21_calc.h"

int main() {
    char str[] = "-(-3+6)";
    int i = validation(str);
    printf("%d", i);
}