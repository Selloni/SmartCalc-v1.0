#include "s21_calc.h"

double diff_cr(double sum_cr, int term_cr, double percent_cr) {
    double play_cr;
    double Sn, In, P;
    int month_all_cr = term_cr * 12;  //  всего месяцев
    double body_loan = sum_cr/month_all_cr;  // тело займа
    while (month_all_cr != 0) {
        sum_cr = sum_cr - sum_cr/month_all_cr;  //  тело постоянно уменьшаеться
        In = sum_cr * percent_cr / 12;  //  сумма на погошение проценитов 
        P = P + In + body_loan;
        month_all_cr--;
    }
    return (P);
}

double annuitent (double sum_cr, int term_cr, double percent_cr) {
    int month_all_cr = term_cr * 12;
    double i = percent_cr/100/12;
    double P = sum_cr * (i+(i/(pow((1+i), month_all_cr)-1)));
    return P;
}

int main () {
    double total = annuitent(300000, 2, 12);
    printf("%f\n", total);
    printf("%f\n", total);
    return 0;
}