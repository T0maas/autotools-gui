#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "configurator.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <sys/stat.h>
#include <QComboBox>

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
    (this->targets[index]).pkg = ui->tb_pkg->text().toUtf8().constData();
}

void MainWindow::on_btCreate_clicked()
{
    configurator::cAC(this);

    configurator::pkgfile(this);

    configurator::rootAm(this);
    struct stat info;
    if( stat( "src", &info ) != 0 ) {
        system("mkdir src");
    }
    configurator::srcAm(this);
    system("aclocal");
    system("libtoolize");
    system("automake --add-missing");
    system("autoconf");
}

void MainWindow::on_bt_pkSet_clicked()
{
    configurator::pkSet(this);
}

void MainWindow::on_bt_Init_clicked()
{
    ui->tb_cname->setStyleSheet("");
    ui->tb_cver->setStyleSheet("");

    configurator::Init(this);
    if (ui->tb_cname->text().size() > 0 && ui->tb_cver->text().size() > 0) {
        ui->tab_deps->setEnabled(true);
        ui->btCreate->setEnabled(true);
        ui->tab_deps->setStyleSheet("");
        ui->tab_pkg->setEnabled(true);
        ui->tab_pkg->setStyleSheet("");
        ui->tab_tgs->setEnabled(true);
        ui->tab_tgs->setStyleSheet("");
        ui->tab_head->setEnabled(true);
        ui->tab_head->setStyleSheet("");
    }
    else {
        if (ui->tb_cname->text().size() == 0)
            ui->tb_cname->setStyleSheet("background-color:#ff0000");
        if (ui->tb_cver->text().size() == 0)
            ui->tb_cver->setStyleSheet("background-color:#ff0000");
    }
}



void MainWindow::on_bt_AddHeader_clicked()
{
    Headers hdr;
    hdr.name = ui->tb_hname->text().toUtf8().constData();
    hdr.path = ui->tb_hpath->text().toUtf8().constData();
    ui->cb_Headers->addItem(QString::fromStdString( hdr.name));
    this->headers.push_back(hdr);
}

void MainWindow::on_btDel_clicked()
{
    int index = ui->tglist1->currentIndex();
    this->targets.erase( this->targets.begin() + index );
    ui->tglist1->removeItem(index);
}
