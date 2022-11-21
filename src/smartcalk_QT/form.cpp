#include "form.h"
//#include "s21_calc.h"
#include "ui_form.h"

extern "C" { // внешнее подключение
    #include "s21_calc.h"
}

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


void Form::paintGraph(char Y1, double X1)
{
//    printf("che ne tack ?");
    ui->widget->clearGraphs();
    double xBegin = 20, xEnd = X1+20, h = 0.1, Y;  // высота
    QVector<double> x,y;
    ui->widget->yAxis->setRange(-20, 20);
    ui->widget->xAxis->setRange(-20, 20);
//        int N = (xEnd - xBegin)/h+2;
    if (X1 == 0) {
        x.push_back(X1);
        Y = pull_stack(&Y1, X1);
//        printf("%f-hehe", X1);
        y.push_back(Y);
    } else {
        for(X1 = xBegin; X1 <= xEnd; X1 += h)
        {
            x.push_back(X1);
            Y = pull_stack(&Y1, X1);
//            printf("%f-hehe", X1);
//            printf("%s-YEYEYEY", Y1);
            y.push_back(Y);
        }
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->replot();
    x.clear();
    y.clear();
}

