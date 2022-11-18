#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

extern "C" { // внешнее подключение
    #include "s21_calc.h"
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel *actWindow;

private slots:
    void number_for_calc();
    void on_pushButton_point_clicked();
    void operations();
    void trigonometr();
    void on_pushButton_C_clicked();
//    void on_label_2_linkActivated(const QString &link);
//    void on_setX_clicked();
    void on_xlab_clicked();
    void on_pushButton_equel_clicked();
    void on_pushButton_back_clicked();
    void on_pushButton_X_clicked();
    void on_main_lab_clicked();
};
#endif // MAINWINDOW_H
