#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include <iostream>
#include "connection.h"
#include "libircclient.h"
#include "server.h"
#include "user.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionConnect_triggered();
    void on_actionDisconnect_triggered();

    void on_le_cmd_returnPressed();

public slots:
    void on_text_received(QString received);
    void on_channel_joined(QString channel);

private:
    Ui::MainWindow *ui;
    user cur_user;
    server cur_server;
    std::unique_ptr<connection> cur_conn;
    bool do_connect();
};

#endif // MAINWINDOW_H
