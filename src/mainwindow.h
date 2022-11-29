#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "deposit_window_tuan.h"
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QVector>
#include <credit.h>
#include <form.h>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

extern "C" { // внешнее подключение
#include "s21_calc.h"
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  Form form;
  //    credit credit;
  QLabel *actWindow;

private slots:
  void number_for_calc();
  void on_pushButton_point_clicked();
  void operations();
  void trigonometr();
  void on_pushButton_C_clicked();
  void on_xlab_clicked();
  void on_pushButton_equel_clicked();
  void on_pushButton_back_clicked();
  void on_pushButton_X_clicked();
  void on_main_lab_clicked();
  void on_pushButton_Bgrav_clicked();
  void on_credit_clicked();
  void on_deposit_clicked();
  void on_pushButton_mod_clicked();
};
#endif // MAINWINDOW_H
