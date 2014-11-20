#include <QApplication>
#include "mainwindow.h"
#include "libircclient.h"
#include "connection.h"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    connection con;
    user hugo("xXxD4RkHuGoxXx", "Hugo Hurtig");
    server rizon("Rizon");
    rizon.set_address("irc.rizon.net");

    if(!con.connect(hugo, rizon)) {
        cout << "Could not create IRC session" << endl;
        return EXIT_FAILURE;
    }

    con.disconnect();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

