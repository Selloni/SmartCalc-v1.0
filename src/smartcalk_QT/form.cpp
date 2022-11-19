#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);


}

Form::~Form()
{
    delete ui;
}




void Form::on_pushButton_clicked()
{
//    double xBegin = -20, xEnd = 20, h = 0.1, X, Y;  // высота
////        int N;  // количество точек
//    QVector<double> x,y;
//    h = 0.1;
//    xBegin = -20;
//    xEnd = 20;

//    ui->widget->yAxis->setRange(-20, 20);
//    ui->widget->xAxis->setRange(-20, 20);

////        N = (xEnd - xBegin)/h+2;

//    for(X = xBegin; X <= xEnd; X += h)
//    {
//        x.push_back(X);
////            Y = on_pushButton_equel_clicked();
////            printf("%f-hehe", Y);
//        y.push_back(0.909);
//    }
//    ui->widget->clearGraphs();
//    ui->widget->addGraph();
//    ui->widget->graph(0)->addData(x,y);
//    ui->widget->replot();
}

void Form::paintGraph(double X1,  double Y1)
{
    double xBegin = X1, xEnd = 20 + X1, h = 0.1, X, Y;  // высота
//        int N;  // количество точек
    QVector<double> x,y;
//    h = 0.1;
//    xBegin = -20;
//    xEnd = 20;

    ui->widget->yAxis->setRange(-20, 20);
    ui->widget->xAxis->setRange(-20, 20);

//        N = (xEnd - xBegin)/h+2;

    for(X1 = xBegin; X1 <= xEnd; X1 += h)
    {
        x.push_back(X1);
//            Y = on_pushButton_equel_clicked();
                    printf("%f-hehe", Y1);
                y.push_back(Y1);
    }
    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->replot();
}

