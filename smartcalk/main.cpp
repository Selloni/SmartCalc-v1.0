#include "mainwindow.h"
//#include <QTextEdit>  // for text
#include <QLabel> // для надписей
#include <QApplication> // for work whith parametr


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
