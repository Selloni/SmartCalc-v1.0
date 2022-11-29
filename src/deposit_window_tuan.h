#ifndef DEPOSIT_WINDOW_TUAN_H
#define DEPOSIT_WINDOW_TUAN_H

#include <QDialog>

namespace Ui {
class deposit_window_tuan;
}

class deposit_window_tuan : public QDialog {
  Q_OBJECT

public:
  explicit deposit_window_tuan(QWidget *parent = nullptr);
  ~deposit_window_tuan();

private:
  Ui::deposit_window_tuan *ui;
};

#endif // DEPOSIT_WINDOW_TUAN_H
