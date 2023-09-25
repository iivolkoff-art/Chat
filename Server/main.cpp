#include <QCoreApplication>
#include <iostream>
#include "Server.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;


    return a.exec();
}
