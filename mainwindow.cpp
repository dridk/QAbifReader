#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mModel = new AbifModel;
    ui->tableView->setModel(mModel);
    connect(ui->actionLoad,SIGNAL(triggered()),this,SLOT(load()));

    ui->tableView->horizontalHeader()->setStretchLastSection(true);


    load("/home/sacha/temp/M3.fsa");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load(const QString &fileName)
{

    mModel->setFilename(fileName);



}

void MainWindow::load()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open abif file"), "", tr("Abif Files (*.ab1 *.fsa)"));
    if (fileName.isEmpty())
        return;

    load(fileName);
}
