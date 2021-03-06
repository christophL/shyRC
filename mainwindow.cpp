#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serverdialog.h"
#include "command.h"

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
        cur_user = dialog.get_user();
        cur_server = dialog.get_server();
        do_connect();
    }
}

void MainWindow::on_actionDisconnect_triggered()
{
    cur_conn->disconnect();
    ui->actionDisconnect->setEnabled(false);
}

void MainWindow::on_text_received(QString received){
    ui->txt_channel_msg->append(received);
}

void MainWindow::on_channel_joined(QString channel){
    cur_channel = channel;
}

bool MainWindow::do_connect(){
    cur_conn = std::unique_ptr<connection>(new connection());
    connect(cur_conn.get(), SIGNAL(text_received(QString)), this, SLOT(on_text_received(QString)));
    connect(cur_conn.get(), SIGNAL(channel_joined(QString)), this, SLOT(on_channel_joined(QString)));

    if(!cur_conn->connect(cur_user, cur_server)) {
        std::cout << "Could not create IRC session" << std::endl;
        return false;
    }
    ui->actionDisconnect->setEnabled(true);
    return true;
}

void MainWindow::on_le_cmd_returnPressed()
{
    QString input = ui->le_cmd->text();
    ui->le_cmd->clear();
    std::unique_ptr<command> cmd = command::create(cur_channel, input);
    if(cmd == nullptr){
        //print error
    } else {
        cur_conn->execute_command(cmd.get());
    }
}
