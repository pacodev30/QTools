#include "MainWindow.h"
#include <FileUtility.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _fileTest = new FileTest("C:\\Users\\pacof\\DEV\\RESSOURCES\\Test");

    _fileTest->writeData("C:\\Users\\pacof\\Desktop\\data.txt") ?
        qDebug("Data writed succesfully") :
        qDebug("Data can't writed");
}

MainWindow::~MainWindow() {}
