#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "abifmodel.h"
#include "abifreader.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void load();
    void load(const QString& fileName);

private:
    Ui::MainWindow *ui;
    AbifModel * mModel;
};

#endif // MAINWINDOW_H
