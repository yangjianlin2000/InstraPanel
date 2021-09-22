#ifndef INSTRPANEL_ZDC_D_H
#define INSTRPANEL_ZDC_D_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QStackedWidget>
#include <QPushButton>
#include <QKeyEvent>
#include "panelbase.h"


class InstrPanel_ZDC_D: public PanelBase
{
public:
    InstrPanel_ZDC_D(QWidget* parent = nullptr);
    virtual ~InstrPanel_ZDC_D(){}

protected:
#if 0
    void GetCanState(unsigned char* msg, int size);
    void GetIoState(unsigned char* msg, int size);
	OutType CheckOutUnitType(QString name);
	void SetIoOut(QString name, int val);
	void SetCanOut(QString name, int val);
	void SwitchMainPower(bool flag);
	void resetOutInfo();  
#endif
	OutType CheckOutUnitType(const QString& name);
	void RecvMsg(unsigned char* msg, int size);
	void SetValue(const QString& name, int val);
    bool GetDefaultTestItem(int id, QString &retname, DefaultTestInfo &retinfo);
    bool DefaultTest(int id);
    void InitDefaultTestList();
};

#endif // INSTRPANEL_ZDC_D_H
