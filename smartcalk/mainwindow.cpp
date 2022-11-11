#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("");
    ui->label_2->setText("");
    this->aabc = ui->label;
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(number_for_calc()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(number_for_calc()));
    connect(ui->pushButton_2_,SIGNAL(clicked()),this,SLOT(number_for_calc()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(number_for_calc()));
    connect(ui->pushButton_4_,SIGNAL(clicked()),this,SLOT(number_for_calc()));
    connect(ui->pushButton_5_,SIGNAL(clicked()),this,SLOT(number_for_calc()));
    connect(ui->pushButton_6_,SIGNAL(clicked()),this,SLOT(number_for_calc()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(number_for_calc()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(number_for_calc()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(number_for_calc()));
//    connect(ui->pushButton_close_,SIGNAL(clicked()),this,SLOT(number_for_calc()));
//    connect(ui->pushButton_open_,SIGNAL(clicked()),this,SLOT(number_for_calc()));
//    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(number_for_calc()));
//    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(number_for_calc()));
//    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(number_for_calc()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::number_for_calc()
{
    QPushButton *button = (QPushButton *)sender();
    aabc->setText(aabc->text().append(button->text()));


}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();
    ui->label->setText(ui->label->text()+(button->text()));
}

void MainWindow::on_pushButton_point_clicked()
{
    if(!(ui->label->text().contains('.')))
        ui->label->setText(ui->label->text()+".");
}



void MainWindow::on_pushButton_C_clicked()
{
    this->aabc->setText("");
}


//void MainWindow::on_setX_clicked()
//{
//    this->activeLabel = ui->label_2;
//}


void MainWindow::on_xlab_clicked()
{
    this->aabc = this->aabc == ui->label ? ui->label_2 : ui->label;
}

