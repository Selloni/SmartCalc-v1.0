#include "mainwindow.h"
//#include <QTextEdit>  // for text
#include <QLabel> // для надписей
#include <QApplication> // for work whith parametr
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file(":/style.css");
    MainWindow w;
    w.show();
    return a.exec();
}
