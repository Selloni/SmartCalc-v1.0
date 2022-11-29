QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    credit.cpp \
    deposit_window_tuan.cpp \
    form.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    s21_calc.c \
    s21_steck.c \
    s21_validation.c

HEADERS += \
    credit.h \
    deposit_window_tuan.h \
    form.h \
    mainwindow.h \
    qcustomplot.h \
    s21_calc.h

FORMS += \
    credit.ui \
    deposit_window_tuan.ui \
    form.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
