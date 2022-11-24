/********************************************************************************
** Form generated from reading UI file 'deposit_window_tuan.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSIT_WINDOW_TUAN_H
#define UI_DEPOSIT_WINDOW_TUAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_deposit_window_tuan
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *deposit_window_tuan)
    {
        if (deposit_window_tuan->objectName().isEmpty())
            deposit_window_tuan->setObjectName(QString::fromUtf8("deposit_window_tuan"));
        deposit_window_tuan->resize(400, 300);
        label = new QLabel(deposit_window_tuan);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 40, 111, 16));
        label_2 = new QLabel(deposit_window_tuan);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 110, 181, 61));
        label_3 = new QLabel(deposit_window_tuan);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 190, 62, 16));

        retranslateUi(deposit_window_tuan);

        QMetaObject::connectSlotsByName(deposit_window_tuan);
    } // setupUi

    void retranslateUi(QDialog *deposit_window_tuan)
    {
        deposit_window_tuan->setWindowTitle(QCoreApplication::translate("deposit_window_tuan", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("deposit_window_tuan", "\320\222 \321\200\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\272\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("deposit_window_tuan", "\320\232\321\201\321\202\320\260\321\202\320\270 \321\202\321\213 \320\274\320\275\320\265 \320\275\321\200\320\260\320\262\320\270\321\210\321\214\321\201\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("deposit_window_tuan", "\342\212\202\342\201\240(\342\201\240\342\201\240^...^\342\212\202\342\201\240)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deposit_window_tuan: public Ui_deposit_window_tuan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSIT_WINDOW_TUAN_H
