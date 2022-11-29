#include "deposit_window_tuan.h"
#include "ui_deposit_window_tuan.h"

deposit_window_tuan::deposit_window_tuan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deposit_window_tuan)
{
    ui->setupUi(this);
}

deposit_window_tuan::~deposit_window_tuan()
{
    delete ui;
}
