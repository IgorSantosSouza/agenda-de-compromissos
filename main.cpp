#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classes.h"

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Pilha<Pessoa> pessoas(10);

    return a.exec();
    system("pause");
    return 0;
}
