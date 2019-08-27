#include "mytcpserver.h"
#include <QApplication>

#define On 1
#define Off 0

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyTcpServer w;
    w.show();

    return a.exec();
}
