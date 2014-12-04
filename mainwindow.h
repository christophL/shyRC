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
    void on_text_received();

private:
    Ui::MainWindow *ui;
    user cur_user;
    server cur_server;
    std::unique_ptr<connection> cur_conn;
    bool do_connect(user u, server s);
};

#endif // MAINWINDOW_H
