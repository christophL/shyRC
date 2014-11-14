#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serverdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionConnect_triggered()
{
    serverDialog dialog(this);
    dialog.setModal(true);
    dialog.exec();
}
