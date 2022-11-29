#ifndef FORM_H
#define FORM_H

#include <QWidget>

extern "C" { // внешнее подключение
#include "s21_calc.h"
}

namespace Ui {
class Form;
}

class Form : public QWidget {
  Q_OBJECT

public:
  explicit Form(QWidget *parent = nullptr);
  void paintGraph(char *Y1, double X1, double xMax, double yMax, double xMin, double yMin, double step);
  ~Form();

private slots:

private:
  Ui::Form *ui;
};

#endif // FORM_H
