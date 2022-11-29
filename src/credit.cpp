#include "credit.h"
#include "ui_credit.h"
#include <QMessageBox>
#include <math.h>
#include <QIntValidator>


Credit::Credit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Credit)
{
    ui->setupUi(this);
    ui->sum->setValidator( new QDoubleValidator(this));
    ui->procent->setValidator( new QDoubleValidator(this));
    ui->term->setValidator( new QIntValidator(this));
}

Credit::~Credit()
{
    delete ui;
}

void Credit::on_radioButton_clicked()
{

    if (ui->procent->text() == "" || ui->sum->text() == "" || ui->term->text() == "") {
        QMessageBox msbox;
        msbox.setText("Заполни поля, погода просто чудо как и ты");
    } else {
        QString qt_P = "", qt_diff = "";
        QString qt_total_cr = "";
        ui->output->setText("");
        ui->cr_pereplata->setText("");
        ui->total_cr->setText("");
        double In, P = 0, T = 0;

        QString qsum = ui->sum->text();
        qsum.replace(",", ".");
        double sum_cr = qsum.toDouble();
        
        QString qpersent_cr = ui->procent->text();
        qpersent_cr.replace(",", ".");
        double percent_cr = qpersent_cr.toDouble();

        int term_cr = ui->term->text().toInt();

        int month_all_cr = term_cr * 12;  //  всего месяцев
        double body_loan = sum_cr/month_all_cr;  // тело займа
        double const_sum_cr = sum_cr;
        while (month_all_cr != 0) {
            In = sum_cr * (percent_cr / 100) / 12;  //  сумма на погошение проценитов
            sum_cr = sum_cr - (sum_cr/month_all_cr);  //  тело постоянно уменьшаеться
            P = In + body_loan;
            T = T + In + body_loan;
            qt_P = QString::number(P);
            ui->output->setText(ui->output->text()+qt_P+"Руб "+"\n");
            month_all_cr--;
        }
        qt_total_cr = QString::number(T);
        ui->total_cr->setText(qt_total_cr);
        double diff = T - const_sum_cr;
        qt_diff = QString::number(diff);
        ui->cr_pereplata->setText(qt_diff);
    }
}

void Credit::on_ann_clicked()
{
    QString qt_P = "", qt_diff = "";
    QString qt_total_cr = "";
    ui->output->setText("");
    ui->cr_pereplata->setText("");
    ui->total_cr->setText("");


    QString qsum = ui->sum->text();
    qsum.replace(",", ".");
    double sum_cr = qsum.toDouble();
    
    QString qpersent_cr = ui->procent->text();
    qpersent_cr.replace(",", ".");
    double percent_cr = qpersent_cr.toDouble();

    int term_cr = ui->term->text().toInt();


    int month_all_cr = term_cr * 12;
    double i = percent_cr/100/12;
    double P = sum_cr * (i+(i/(pow((1+i), month_all_cr)-1)));
    qt_P = QString::number(P);
    ui->output->setText(qt_P);
    P = P * month_all_cr;
    qt_P = QString::number(P);
    ui->total_cr->setText(qt_P);
    P = P - sum_cr;
    qt_P = QString::number(P);
    ui->cr_pereplata->setText(qt_P);
}

