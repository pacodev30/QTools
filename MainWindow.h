#pragma once

#include <QMainWindow>
#include <FileTest.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    FileTest *_fileTest;
};
