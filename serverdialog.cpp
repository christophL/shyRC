#include "serverdialog.h"
#include "ui_serverdialog.h"

#include <QMessageBox>

serverDialog::serverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::serverDialog)
{
    ui->setupUi(this);
    error_color.setColor(QPalette::Base, QColor::fromRgb(255,200,200));
    normal_color.setColor(QPalette::Base, QColor::fromRgb(255,255,255));
}

serverDialog::~serverDialog()
{
    delete ui;
}

void serverDialog::on_btn_cancel_clicked()
{
    setResult(QDialog::DialogCode::Rejected);
    close();
}

void serverDialog::on_btn_connect_clicked()
{
    if(ui->le_server->text().isEmpty()){
        ui->le_server->setPalette(error_color);
        QMessageBox::critical(this, "Error", "Please provide a server address");
        setResult(QDialog::DialogCode::Rejected);
        return;
    } else {
        ui->le_server->setPalette(normal_color);
    }

    if(ui->le_nick->text().isEmpty()){
        ui->le_nick->setPalette(error_color);
        QMessageBox::critical(this, "Error", "Please provide a nick name");
        setResult(QDialog::DialogCode::Rejected);
        return;
    } else {
        ui->le_nick->setPalette(normal_color);
    }

    res_user.set_nick(ui->le_nick->text().toStdString());
    res_user.set_nick2(ui->le_nick2->text().toStdString());
    res_user.set_nick3(ui->le_nick3->text().toStdString());
    res_user.set_fullname(ui->le_fullname->text().toStdString());
    res_user.set_username(ui->le_username->text().toStdString());

    res_server.set_address(ui->le_server->text().toStdString());
    res_server.set_name(ui->le_server->text().toStdString());
    setResult(QDialog::DialogCode::Accepted);
    close();
}
