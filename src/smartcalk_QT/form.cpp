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


void Form::paintGraph(char *Y1, double X1)
{
    double xBegin = -20, xEnd = 20, h = 0.1, Y;  // высота
       QVector<double> x,y;

        ui->widget->clearGraphs();



            ui->widget->xAxis->setRange(-20, 20);
            ui->widget->yAxis->setRange(-20, 20);

//            N = (xEnd-xBegin)/h + 2;

            for (X1 = xBegin; X1 <= xEnd; X1 += h) {
                Y = pull_stack(Y1, X1);
                x.push_back(X1);
                y.push_back(Y);
            }

            ui->widget->addGraph();
            ui->widget->graph(0)->addData(x, y);
            ui->widget->replot();
            x.clear();
            y.clear();
////    printf("che ne tack ?");

}

