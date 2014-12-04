#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serverdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->splitter->setSizes({150, 400, 100});
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
        do_connect(dialog.get_user(), dialog.get_server());
    }
}

void MainWindow::on_text_received(){

}

bool MainWindow::do_connect(user u, server s){
    cur_conn = unique_ptr<connection>(new connection());
    connect(cur_conn.get(), SIGNAL(connection::text_received(std::string)), this, SLOT(on_text_received()));
    cur_user = u;
    cur_server = s;

    if(!cur_conn->connect(cur_user, cur_server)) {
        std::cout << "Could not create IRC session" << endl;
        return false;
    }
    return true;
}
