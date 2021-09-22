#include <QFontDatabase>
#include <QApplication>
#include <QTextCodec>
#include <QPushButton>
#include <QMessageBox>
#include "mainwindow.h"
#include "common.h"
#include "topwindow.h"
#include "panelveri0.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ENTER();

#if 1
    int nIndex = QFontDatabase::addApplicationFont("/home/yangjl/ubuntu/QtProject/InstrPanel/res/fonts/msyh.ttf"); //这里设置加载的字库
    if (nIndex != -1)
    {
        QStringList strList(QFontDatabase::applicationFontFamilies(nIndex));
        if (strList.count() > 0)
        {
            QFont fontThis(strList.at(0));
            a.setFont(fontThis);
        }
    }
#endif
    //MainWindow w;
    //w.sho
    //InstrPanel_JSC_C w;
    //PanelVeri0 w;
    //w.show();

    void showMessageBox();

    TopWindow w;
    w.hide();
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();
    return a.exec();
}

