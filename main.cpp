#include <QCoreApplication>

#include "lib.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    pluginAutoLambda();

    return a.exec();
}


