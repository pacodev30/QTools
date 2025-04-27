#include "MainWindow.h"
#include <FileUtility.h>
#include <QApplication>
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initialize();
    manageLayers();
    manageMenu();
    manageConnect();
}

MainWindow::~MainWindow() {}

void MainWindow::onBrowseBtn_clicked()
{
    _path = QFileDialog::getExistingDirectory(this, tr("Choisir un répertoire"));
    if(!_path.isEmpty())
    {
        _pathEdit->setText(_path);
        _openFolderBtn->setHidden(false);
        _verifyBtn->setHidden(false);
    }
}

void MainWindow::onVerifyBtn_clicked()
{
    QString path = _pathEdit->text();
    if(!path.isEmpty())
    {
        _fileTest = new FileTest(path, this);
        _result = _fileTest->result();
        _resultLabel->setText(_fileTest->result());
        _saveBtn->setHidden(false);
    }

}

void MainWindow::onSaveBtn_clicked()
{
    QString folderSave = QFileDialog::getSaveFileName(this, tr("Enregistrer le dans fichier"), QString(), "Texte (*.txt)");
    if(FileUtility::writeFile(folderSave, _result))
    {
        QMessageBox::information(this, tr("Sauvegarde"), tr("Sauvegarde effectuée"));
    }
}

void MainWindow::onOpenFolderBtn_clicked()
{
    QDesktopServices::openUrl(QUrl(_path));
}

void MainWindow::initialize()
{
    setWindowTitle(tr("QTOOL"));
    setWindowIcon(QIcon(":/img/icon/logo.png"));
    setFixedWidth(500);


    _pathEdit = new QLineEdit(this);
        _pathEdit->setPlaceholderText(tr("... lien du répertoire"));
    _browseBtn = new QPushButton(tr("Explorer"), this);
    _verifyBtn = new QPushButton(tr("Verifier le répertoire"), this);
        _verifyBtn->setHidden(true);
    _resultLabel = new QLabel(this);
    _openFolderBtn = new QPushButton(tr("Ouvrir le répertoire"), this);
        _openFolderBtn->setHidden(true);
    _saveBtn = new QPushButton(tr("Sauvegarder"), this);
        _saveBtn->setHidden(true);

    _central = new QWidget(this);
    _mainLayout = new QVBoxLayout(this);
    _pathLayout = new QHBoxLayout(this);
    _optionLayout = new QHBoxLayout(this);
}

void MainWindow::manageLayers()
{
    _pathLayout->addWidget(_pathEdit);
    _pathLayout->addWidget(_browseBtn);

    _optionLayout->addWidget(_openFolderBtn);
    _optionLayout->addWidget(_verifyBtn);

    _mainLayout->addLayout(_pathLayout);
    _mainLayout->addLayout(_optionLayout);
    _mainLayout->addWidget(_resultLabel);
    _mainLayout->addWidget(_saveBtn);

    _central->setLayout(_mainLayout);
    setCentralWidget(_central);
}

void MainWindow::manageMenu()
{
    _quitAction = new QAction(tr("Quitter"), this);
        _quitAction->setIcon(QIcon(":/img/icon/quit.png"));
        _quitAction->setShortcut(QKeySequence("Ctrl+Q"));
    _fileMenu = menuBar()->addMenu(tr("&Fichier"));
        _fileMenu->addAction(_quitAction);

    _toolbar = addToolBar(tr("Fichier"));
        _toolbar->addAction(_quitAction);
}

void MainWindow::manageConnect()
{
    connect(_browseBtn, SIGNAL(clicked(bool)), this, SLOT(onBrowseBtn_clicked()));
    connect(_verifyBtn, SIGNAL(clicked(bool)), this, SLOT(onVerifyBtn_clicked()));
    connect(_saveBtn, SIGNAL(clicked(bool)), this, SLOT(onSaveBtn_clicked()));
    connect(_quitAction, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    connect(_openFolderBtn, SIGNAL(clicked(bool)), this, SLOT(onOpenFolderBtn_clicked()));
}

