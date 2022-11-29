#ifndef CREDIT_H
#define CREDIT_H

#include <QDialog>

namespace Ui {
class Credit;
}

class Credit : public QDialog {
  Q_OBJECT

public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

private slots:
  void on_radioButton_clicked();

  void on_ann_clicked();

private:
  Ui::Credit *ui;
};

#endif // CREDIT_H
