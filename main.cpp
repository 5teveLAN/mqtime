#include "session.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Session s;
    w.show();
    s.start();
    s.initConnections(&w);
    return QCoreApplication::exec();
}
