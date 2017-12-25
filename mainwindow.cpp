#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include "configs.h"

using namespace  std;

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

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_btAdd_clicked()
{
    Target tg;
    tg.name = (ui->lineEdit->text()).toUtf8().constData();
    tg.type = (ui->cbType->currentText()).toUtf8().constData();
    this->targets.push_back(tg);

    ui->tglist1->addItem(ui->lineEdit->text());
    ui->tglist2->addItem(ui->lineEdit->text());
}

void MainWindow::on_tglist2_currentIndexChanged(int index)
{
    Target tg = this->targets[index];
    ui->tb_sources->setText(QString::fromStdString( tg.src ));
    ui->tb_link->setText ( QString::fromStdString( tg.libs));
}

void MainWindow::on_btSet_clicked()
{
    int index = ui->tglist2->currentIndex();
    (this->targets[index]).src = ui->tb_sources->text().toUtf8().constData();
    (this->targets[index]).libs = ui->tb_link->text().toUtf8().constData();
}

void MainWindow::on_btCreate_clicked()
{
    std::ofstream configureac("configure.ac");
    cout << configure_ac << endl;
    configureac.write(configure_ac.c_str(),configure_ac.size());
    configureac.close();
}
