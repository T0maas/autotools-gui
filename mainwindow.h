#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "target.h"
#include "headers.h"
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
friend class  configurator;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_btAdd_clicked();

    void on_tglist2_currentIndexChanged(int index);

    void on_btSet_clicked();

    void on_btCreate_clicked();

    void on_bt_pkSet_clicked();

    void on_bt_Init_clicked();

    void on_bt_AddHeader_clicked();

    void on_btDel_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<Target> targets;
    std::vector<Headers> headers;
    bool makepkg=false;
};

#endif // MAINWINDOW_H
