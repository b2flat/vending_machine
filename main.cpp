#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    Widget w2;
    w2.show(); //ja pan gi two gae
    return a.exec();
}
