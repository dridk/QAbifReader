#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mModel = new QStringListModel;
    ui->listView->setModel(mModel);
    connect(ui->actionLoad,SIGNAL(triggered()),this,SLOT(load()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load()
{

    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open abif file"), "", tr("Abif Files (*.ab1 *.fsa)"));
    if (fileName.isEmpty())
        return;


    AbifReader reader(fileName);

    if(!reader.isAbif()){
        QMessageBox::information(this,"error","not an abif file");
        return;
    }



    mModel->setStringList(reader.directoryKeys());

}
