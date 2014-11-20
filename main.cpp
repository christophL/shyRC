#include "mainwindow.h"
#include <QApplication>
#include "libircclient.h"
#include "connection.h"

int main(int argc, char *argv[])
{
    connection con;
    con.connect();
    if (con.getSession() == nullptr) {
        printf("failure\n");
        return EXIT_FAILURE;
    }

    con.disconnect();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

