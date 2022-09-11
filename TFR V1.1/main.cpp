#include "mainwindow.h"
#include "nbwnd.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NBWnd w;

    w.show();
    return a.exec();
}
