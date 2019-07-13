#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show(); //first vending machine

    Widget w2;
    w2.show(); //second vending machine
    return a.exec();
}
