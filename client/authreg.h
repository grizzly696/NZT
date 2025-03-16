#ifndef AUTHREG_H
#define AUTHREG_H

#include <QWidget>

namespace Ui {
class AuthReg;
}

class AuthReg : public QWidget
{
    Q_OBJECT

public:
    explicit AuthReg(QWidget *parent = nullptr);
    ~AuthReg();
signals:
    void AuthIsOk();

private slots:
    void on_pushButtonAuth_clicked();

private:
    Ui::AuthReg *ui;

};

#endif // AUTHREG_H
