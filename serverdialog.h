#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include "server.h"
#include "user.h"

#include <QDialog>

namespace Ui {
class serverDialog;
}

class serverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit serverDialog(QWidget *parent = 0);
    ~serverDialog();
    user get_user() const;
    server get_server() const;

private slots:
    void on_btn_cancel_clicked();

    void on_btn_connect_clicked();

private:
    Ui::serverDialog *ui;
    server res_server;
    user res_user;
    QPalette error_color;
    QPalette normal_color;
};

#endif // SERVERDIALOG_H
