#include "credit.h"
#include "ui_credit.h"

Credit::Credit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Credit)
{
    ui->setupUi(this);
}

Credit::~Credit()
{
    delete ui;
}

void Credit::on_radioButton_clicked()
{

    double play_cr;
    double Sn, In, P;
    int sum_cr = ui->sum->text().toInt();
    double percent_cr = ui->procent->text().toDouble();
    int term_cr = ui->term->text().toInt();
    int month_all_cr = term_cr * 12;  //  всего месяцев
    double body_loan = sum_cr/month_all_cr;  // тело займа
    while (month_all_cr != 0) {
        sum_cr = sum_cr - sum_cr/month_all_cr;  //  тело постоянно уменьшаеться
        In = sum_cr * percent_cr / 12;  //  сумма на погошение проценитов
        ui->output->setText(ui->output->text()+In);
        P = P + In + body_loan;
        month_all_cr--;
    }
}

void Credit::on_ann_clicked()
{
    double play_cr;
    double Sn, In, P;
    int sum_cr = ui->sum->text().toInt();
    double percent_cr = ui->procent->text().toDouble();
    int term_cr = ui->term->text().toInt();
    int month_all_cr = term_cr * 12;  //  всего месяцев
    double body_loan = sum_cr/month_all_cr;  // тело займа
    while (month_all_cr != 0) {
        sum_cr = sum_cr - sum_cr/month_all_cr;  //  тело постоянно уменьшаеться
        In = sum_cr * percent_cr / 12;  //  сумма на погошение проценитов
        ui->total_month->setText(ui->total_month->text()+In);
        P = P + In + body_loan;
        month_all_cr--;
    }
}

