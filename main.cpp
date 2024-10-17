#include <QApplication>
#include <QDir>
#include "include\ui\menu\menu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w;
    w.show();
    return a.exec();
}
