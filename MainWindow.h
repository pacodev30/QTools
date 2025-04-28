#pragma once

#include <QMainWindow>
#include <FileTest.h>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QMenuBar>
#include <QToolBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /**
     * @brief onBrowseBtn_clicked
     */
    void onBrowseBtn_clicked();

    /**
     * @brief onVerifyBtn_clicked
     */
    void onVerifyBtn_clicked();

    /**
     * @brief onWriteBtn_clicked
     */
    void onSaveBtn_clicked();

    void onOpenFolderBtn_clicked();

private:
    /**
     * @brief initialize
     */
    void initialize();

    /**
     * @brief manageLayers
     */
    void manageLayout();

    /**
     * @brief manageMenu
     */
    void manageMenu();

    /**
     * @brief manageConnect
     */
    void manageConnect();

    FileTest    *_fileTest = nullptr;
    QWidget     *_central = nullptr;
    QHBoxLayout *_pathLayout = nullptr;
    QHBoxLayout *_optionLayout = nullptr;
    QVBoxLayout *_mainLayout = nullptr;

    QLineEdit   *_pathEdit = nullptr;
    QPushButton *_browseBtn = nullptr;
    QPushButton *_verifyBtn = nullptr;
    QPushButton *_saveBtn = nullptr;
    QPushButton *_openFolderBtn = nullptr;
    QLabel      *_resultLabel = nullptr;
    QString     _pathFolder;
    QString     _result;


    QMenu       *_fileMenu = nullptr;
    QToolBar    *_toolbar = nullptr;
    QAction     *_quitAction = nullptr;
};
