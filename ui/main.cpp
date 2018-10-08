#include "mainwindow.h"
#include <QApplication>
#include "../os_541/file.h"
#include "../os_541/file_mangement.h"
#include "../os_541/global.h"
#include "../os_541/memory.h"
#include "../os_541/new.h"
#include "../os_541/run.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType<string>("string");
    QApplication a(argc, argv);
    initialization();
    MainWindow w;
    //run();
    w.show();

    return a.exec();
}
