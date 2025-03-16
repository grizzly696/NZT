#include "authreg.h"
#include "ui_authreg.h"

AuthReg::AuthReg(QWidget *parent) : QWidget(parent), ui(new Ui::AuthReg) {
    ui -> setupUi(this);
    ui -> labelRegistration -> setVisible(false);
    ui -> labelChange -> setVisible(false);
}

AuthReg::~AuthReg()
{
    delete ui;
}

void AuthReg::on_pushButtonAuth_clicked() {
    emit AuthIsOk();
}

