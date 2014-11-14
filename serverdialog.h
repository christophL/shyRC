#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

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

private slots:
    void on_btn_cancel_clicked();

private:
    Ui::serverDialog *ui;
};

#endif // SERVERDIALOG_H
