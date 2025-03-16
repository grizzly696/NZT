#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_reg = new AuthReg;
    ui_reg -> show();
    connect(ui_reg, &AuthReg::AuthIsOk, this, &MainWindow::slot_is_auth_ok);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Exit_clicked()
{
    this -> close();
}

void MainWindow::slot_is_auth_ok() {
    delete ui_reg;
    this -> show();
    return;
}
