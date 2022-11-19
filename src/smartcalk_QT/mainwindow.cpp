#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"
#include <QDebug>
#include <QTextStream>
//#include <QVector>
#include <QMessageBox>

// отчистить график
// открывать график в ссоеднем окне
// убрать бак со скобками
// пердавать в график тригонометрию

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("");
    ui->label_2->setText("");
//    ui->label->setReadOnly(true);
    ui->label->setAlignment(Qt::AlignRight); // для вывода цифр с права
    ui->label_2->setText("0");
    ui->label_2->setAlignment(Qt::AlignRight); // для вывода цифр с права
    this->actWindow = ui->label;
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
    connect(ui->pushButton_close_,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_open_,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_div,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(trigonometr()));
    connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(trigonometr()));
    connect(ui->pushButton_tan,SIGNAL(clicked()),this,SLOT(trigonometr()));
    connect(ui->pushButton_acos,SIGNAL(clicked()),this,SLOT(trigonometr()));
    connect(ui->pushButton_asin,SIGNAL(clicked()),this,SLOT(trigonometr()));
    connect(ui->pushButton_atan,SIGNAL(clicked()),this,SLOT(trigonometr()));
    connect(ui->pushButton_log,SIGNAL(clicked()),this,SLOT(trigonometr()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(trigonometr()));
    connect(ui->pushButton_pow,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_mod,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_sqrt,SIGNAL(clicked()),this,SLOT(trigonometr()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int flag_br = 0;  // глобальная переменная

void MainWindow::number_for_calc()
{
//  sender-создает соединение типа по сигналу
    QPushButton *button = (QPushButton *)sender();
        if (this->actWindow->text()=="0") { // если в строчке только 0, заменяем его
            this->actWindow->setText(button->text());
        } else {
//          append - добавить текст с права
            actWindow->setText(actWindow->text().append(button->text()));
        }
}

void MainWindow::trigonometr()
{
    this->actWindow = ui->label;

    QPushButton *button = (QPushButton *)sender();
    flag_br++;
   if (this->actWindow->text()=="0") { // если в строчке только 0, заменяем его
        this->actWindow->setText(button->text());
    } else {
        ui->label->setText(ui->label->text().append(button->text()+"("));

    }
}

void MainWindow::operations()
{
    this->actWindow = ui->label;
    QPushButton *button = (QPushButton *)sender(); 
    if (button == ui->pushButton_open_) {
        flag_br++;
        ui->label->setText(ui->label->text()+("("));
    } else if (button == ui->pushButton_close_) {
        if (flag_br > 0) {
            flag_br--;
            ui->label->setText(ui->label->text()+(")"));
        } else {
            flag_br++;
            ui->label->setText(ui->label->text()+("("));
        }
    } else {
        ui->label->setText(ui->label->text()+(button->text()));
    }
}

void MainWindow::on_pushButton_point_clicked()
{
    if(!(this->actWindow->text().contains('.'))) {
        this->actWindow->setText(this->actWindow->text()+".");
        if(this->actWindow->text()=='.') {
            this->actWindow->setText("0.");
        }
    }
}

void MainWindow::on_pushButton_C_clicked()
{
    this->actWindow->setText("");
    ui->label_2->setText("0");
    flag_br = 0;
}

void MainWindow::on_xlab_clicked()
{
    this->actWindow = ui->label_2;
}

void MainWindow::on_main_lab_clicked()
{
   this->actWindow = ui->label;
}

double MainWindow::on_pushButton_equel_clicked()
{
    double total;
//    if (ui->label->text()== "()") ui->label->setText("Error");  //  cruch
    QTextStream cout(stdout);
    QString tmp = ui->label->text();
    double qt_x = ui->label_2->text().toDouble();
    QByteArray ba = tmp.toLocal8Bit(); // перевод из Qstring in *str
    char *c_tmp = ba.data();
    if (!validation(c_tmp)) {
        total = pull_stack(c_tmp, qt_x);
        QString str_total = QString::number(total);
//        ui->label->setText(str_total).toDouble();
        ui->label->setText(str_total);
    } else {
        ui->label->setText("Error");
    }
    return total;
}

void MainWindow::on_pushButton_back_clicked()
{
    QString text = this->actWindow->text();
    text.chop(1);
    actWindow->setText(text);
    if (ui->label_2->text() == "") ui->label_2->setText("0");
}

void MainWindow::on_pushButton_X_clicked()
{
    this->actWindow = ui->label;
    ui->label->setText(actWindow->text().append("X"));
}

void MainWindow::on_pushButton_Bgrav_clicked()
{
    double qt_x = ui->label_2->text().toDouble();
    double Y = on_pushButton_equel_clicked();
     form.show();
    form.paintGraph(qt_x, Y);
//    double xBegin = -20, xEnd = 20, h = 0.1, X, Y;  // высота
//    int N;  // количество точек
//    QVector<double> x,y;
//    h = 0.1;
//    xBegin = -20;
//    xEnd = 20;

//    ui->widget->yAxis->setRange(-20, 20);
//    ui->widget->xAxis->setRange(-20, 20);

//    N = (xEnd - xBegin)/h+2;

//    for(X = xBegin; X <= xEnd; X += h)
//    {
//        x.push_back(X);
//        Y = on_pushButton_equel_clicked();
//        printf("%f-hehe", Y);
//        y.push_back(Y);
//    }
//    ui->widget->clearGraphs();
//    ui->widget->addGraph();
//    ui->widget->graph(0)->addData(x,y);
//    ui->widget->replot();
}

