#include "serverdialog.h"
#include "ui_serverdialog.h"

serverDialog::serverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::serverDialog)
{
    ui->setupUi(this);
}

serverDialog::~serverDialog()
{
    delete ui;
}

void serverDialog::on_btn_cancel_clicked()
{
    close();
}
