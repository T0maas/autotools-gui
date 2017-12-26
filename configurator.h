#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H
#include "mainwindow.h"

class configurator
{
protected:

public:
    static bool makepkg;
    configurator();
    static void cAC(MainWindow* mw);
    static void pkgfile(MainWindow* mw);
    static void pkSet(MainWindow *mw);
    static void Init(MainWindow* mw);
    static void rootAm(MainWindow* mw);
    static void srcAm(MainWindow* mw);
};

#endif // CONFIGURATOR_H
