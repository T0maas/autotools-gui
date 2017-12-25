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
    void on_pushButton_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_btAdd_clicked();

    void on_tglist2_currentIndexChanged(int index);

    void on_btSet_clicked();

    void on_btCreate_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<Target> targets;
};

#endif // MAINWINDOW_H
