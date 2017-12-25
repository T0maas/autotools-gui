#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include "configs.h"
#include <cstdlib>
#include <sys/stat.h>

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
}

void MainWindow::on_btCreate_clicked()
{
    confsetup();
    std::ofstream configureac("configure.ac");
    configureac.write(configure_ac.c_str(),configure_ac.size());
    configureac.close();
    if (this->makepkg) {
        std::string pkgfile_in = out_pkgs + ".in";
        ofstream pkg(pkgfile_in);
        pkg << "prefix=@prefix@\n";
        pkg << "exec_prefix=@exec_prefix@\n";
        pkg << "libdir=@libdir@\n";
        pkg << "includedir=@includedir@\n" << endl;
        pkg << "Name: " << (ui->tb_pkname->text().toUtf8().constData()) << endl;
        pkg << "Description: " << ui->tb_pkdesc->text().toUtf8().constData()<<endl;
        pkg << "Version: @VERSION@\n";
        pkg << "Libs: " << ui->tb_pkldflags->text().toUtf8().constData() << endl;
        pkg << "Cflags: " << ui->tb_pkcflags->text().toUtf8().constData() << endl;;
        pkg.close();
    }
    struct stat info;
    if( stat( "src", &info ) != 0 ) {
    system("mkdir src");}

}

void MainWindow::on_bt_pkSet_clicked()
{
    out_pkgs = (ui->tb_pkname->text().toUtf8().constData());
    out_pkgs += ".pc";
    this->makepkg = true;
}

void MainWindow::on_bt_Init_clicked()
{
    cname = ui->tb_cname->text().toUtf8().constData();
    cversion = ui->tb_cver->text().toUtf8().constData();
}
