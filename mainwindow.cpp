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

/**
 * @brief MainWindow::on_actionConnect_triggered
 * Called when the "Connect" menu entry is clicked.
 * Opens a dialog in which the user can select his nick
 * and server to connect to.
 */
void MainWindow::on_actionConnect_triggered()
{
    serverDialog dialog(this);
    dialog.setModal(true);
    dialog.exec();

    if(dialog.result() == QDialog::DialogCode::Accepted){
        //TODO: start IRC connection
    }

}
