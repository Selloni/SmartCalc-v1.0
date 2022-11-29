#include "form.h"
//#include "s21_calc.h"
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


void Form::paintGraph(char *Y1, double X1, double xMax, double yMax, double xMin, double yMin, double step)
{
   double xBegin = xMin, xEnd = xMax, h = step, Y;
   QVector<double> x,y;

    ui->widget->clearGraphs();
    ui->widget->xAxis->setRange(xMin, xMax);
    ui->widget->yAxis->setRange(yMin, yMax);

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
}

