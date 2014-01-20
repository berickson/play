#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionPrint_triggered()
{
    int answer = QMessageBox::question(
        this,
        "You clicked print",
        "Would you like to print?",
        QMessageBox::Yes,
        QMessageBox::No);

    QString s = "You clicked ";
    s+= QString::number(answer);
    QMessageBox::information(this, QString("Information"), s, QMessageBox::Ok);
}

void MainWindow::on_enablePrintCheckbox_stateChanged(int checkState)
{
    bool enabled = (checkState == Qt::Checked);
    ui->actionPrint->setEnabled(enabled);
}
