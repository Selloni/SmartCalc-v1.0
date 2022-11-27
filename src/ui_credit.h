/********************************************************************************
** Form generated from reading UI file 'credit.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_H
#define UI_CREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Credit
{
public:
    QLabel *total_month;
    QLabel *pereplatas;
    QLabel *total;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QRadioButton *radioButton;
    QRadioButton *ann;
    QLineEdit *sum;
    QLineEdit *procent;
    QLineEdit *term;
    QLineEdit *output;
    QLineEdit *cr_pereplata;
    QLineEdit *total_cr;

    void setupUi(QDialog *Credit)
    {
        if (Credit->objectName().isEmpty())
            Credit->setObjectName(QString::fromUtf8("Credit"));
        Credit->resize(679, 300);
        total_month = new QLabel(Credit);
        total_month->setObjectName(QString::fromUtf8("total_month"));
        total_month->setGeometry(QRect(380, 40, 161, 16));
        pereplatas = new QLabel(Credit);
        pereplatas->setObjectName(QString::fromUtf8("pereplatas"));
        pereplatas->setGeometry(QRect(390, 110, 151, 16));
        total = new QLabel(Credit);
        total->setObjectName(QString::fromUtf8("total"));
        total->setGeometry(QRect(400, 190, 131, 16));
        label_4 = new QLabel(Credit);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(170, 30, 161, 16));
        label_5 = new QLabel(Credit);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(170, 70, 62, 16));
        label_6 = new QLabel(Credit);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(170, 110, 151, 16));
        radioButton = new QRadioButton(Credit);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(50, 180, 191, 22));
        ann = new QRadioButton(Credit);
        ann->setObjectName(QString::fromUtf8("ann"));
        ann->setGeometry(QRect(80, 220, 106, 22));
        sum = new QLineEdit(Credit);
        sum->setObjectName(QString::fromUtf8("sum"));
        sum->setGeometry(QRect(40, 30, 113, 23));
        procent = new QLineEdit(Credit);
        procent->setObjectName(QString::fromUtf8("procent"));
        procent->setGeometry(QRect(40, 70, 113, 23));
        term = new QLineEdit(Credit);
        term->setObjectName(QString::fromUtf8("term"));
        term->setGeometry(QRect(40, 110, 113, 23));
        output = new QLineEdit(Credit);
        output->setObjectName(QString::fromUtf8("output"));
        output->setGeometry(QRect(270, 60, 391, 31));
        cr_pereplata = new QLineEdit(Credit);
        cr_pereplata->setObjectName(QString::fromUtf8("cr_pereplata"));
        cr_pereplata->setGeometry(QRect(360, 130, 211, 31));
        total_cr = new QLineEdit(Credit);
        total_cr->setObjectName(QString::fromUtf8("total_cr"));
        total_cr->setGeometry(QRect(360, 210, 201, 31));

        retranslateUi(Credit);

        QMetaObject::connectSlotsByName(Credit);
    } // setupUi

    void retranslateUi(QDialog *Credit)
    {
        Credit->setWindowTitle(QCoreApplication::translate("Credit", "Dialog", nullptr));
        total_month->setText(QCoreApplication::translate("Credit", "\320\225\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\320\271 \320\277\320\273\320\260\321\202\320\265\320\266", nullptr));
        pereplatas->setText(QCoreApplication::translate("Credit", "\320\237\321\200\320\265\320\277\320\273\320\260\321\202\320\260 \320\277\320\276 \320\272\321\200\320\265\320\264\320\270\321\202\321\203", nullptr));
        total->setText(QCoreApplication::translate("Credit", "\320\236\320\261\321\211\320\260\321\217 \320\262\321\213\320\277\320\273\320\260\321\202\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("Credit", "\320\236\320\261\321\211\320\260\321\217 \321\201\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("Credit", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202", nullptr));
        label_6->setText(QCoreApplication::translate("Credit", "\320\241\321\200\320\276\320\272 \320\262\321\213\320\277\320\273\320\260\321\202 \320\262 \320\263\320\276\320\264\320\260\321\205", nullptr));
        radioButton->setText(QCoreApplication::translate("Credit", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\262\320\260\320\275\321\213\320\271", nullptr));
        ann->setText(QCoreApplication::translate("Credit", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Credit: public Ui_Credit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDIT_H
