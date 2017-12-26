#include "configurator.h"
#include "configs.h"
#include <fstream>
#include "ui_mainwindow.h"
using namespace std;
bool configurator::makepkg = false;

configurator::configurator()
{

}


void configurator::cAC(MainWindow *mw) {
    pkgcheck ="";
    for (int i=0;i<mw->targets.size();i++) {
        if (mw->targets[i].pkg.size() > 0)
        pkgcheck += "PKG_CHECK_MODULES("+  mw->targets[i].pkg + ")\n";
    }
    confsetup();
    std::ofstream configureac("configure.ac");
    configureac.write(configure_ac.c_str(),configure_ac.size());
    configureac.close();
}


void configurator::pkgfile (MainWindow *mw) {
    if (makepkg) {
        std::string pkgfile_in = out_pkgs + ".in";
        ofstream pkg(pkgfile_in);
        pkg << "prefix=@prefix@\n";
        pkg << "exec_prefix=@exec_prefix@\n";
        pkg << "libdir=@libdir@\n";
        pkg << "includedir=@includedir@\n" << endl;
        pkg << "Name: " << (mw->ui->tb_pkname->text().toUtf8().constData()) << endl;
        pkg << "Description: " << mw->ui->tb_pkdesc->text().toUtf8().constData()<<endl;
        pkg << "Version: @VERSION@\n";
        pkg << "Libs: " << mw->ui->tb_pkldflags->text().toUtf8().constData() << endl;
        pkg << "Cflags: " << mw->ui->tb_pkcflags->text().toUtf8().constData() << endl;;
        pkg.close();
    }
}


void configurator::pkSet(MainWindow *mw) {
    out_pkgs = (mw->ui->tb_pkname->text().toUtf8().constData());
    out_pkgs += ".pc";
    makepkg = true;
}


void configurator::Init(MainWindow* mw) {
    cname = mw->ui->tb_cname->text().toUtf8().constData();
    cversion = mw->ui->tb_cver->text().toUtf8().constData();
}


void configurator::rootAm(MainWindow *mw) {
    ofstream makefileam("Makefile.am");
    makefileam << "AUTOMAKE_OPTIONS = foreign" << endl;
    makefileam << "SUBDIRS = src" << endl;
    if (makepkg) {
        makefileam << "pkgconfiglibdir = $(libdir)/pkgconfig" << endl;
        makefileam << "pkgconfiglib_DATA = " << out_pkgs << endl;
    }
    makefileam.close();

}

void configurator::srcAm(MainWindow *mw) {
    ofstream makefileam("src/Makefile.am");
    for (int i=0;i<mw->targets.size();i++) {
        if (mw->targets[i].type == "binary") {
            makefileam << "bin_PROGRAMS = " << mw->targets[i].name << endl;
            makefileam << mw->targets[i].name << "_SOURCES = " << mw->targets[i].src << endl;
            makefileam << mw->targets[i].name << "_LDFLAGS = " << mw->targets[i].libs << endl;

        }
        if (mw->targets[i].type == "library") {
            makefileam << "lib_LTLIBRARIES = " << mw->targets[i].name << ".la"  << endl;
            makefileam << mw->targets[i].name << "_la_SOURCES = " << mw->targets[i].src << endl;
            makefileam << mw->targets[i].name << "_la_LDFLAGS = " << mw->targets[i].libs << endl;
        }
    }

    for (int i=0;i < mw->headers.size();i++) {
        if (mw->headers[i].path.size() >0 ) {
            makefileam << mw->headers[i].path << "hdir = " << "$(includedir)/" << mw->headers[i].path << endl;
            makefileam << mw->headers[i].path << "h_HEADERS = " << mw->headers[i].name << endl;
        }
        else {
            makefileam << "HEADERS = " << mw->headers[i].name << endl;
        }
    }
    makefileam.close();
}
