#include "session.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Session s(&w);
    //w.show();
    w.test(&w);

    return QCoreApplication::exec();
}
