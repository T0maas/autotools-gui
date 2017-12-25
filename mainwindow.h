#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "target.h"
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

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

private:
    Ui::MainWindow *ui;
    std::vector<Target> targets;
    bool makepkg=false;
};

#endif // MAINWINDOW_H
