#ifndef INSTRPANEL_ZDC_H
#define INSTRPANEL_ZDC_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QStackedWidget>
#include <QPushButton>
#include <QKeyEvent>
#include "panelbase.h"


class InstrPanel_ZDC: public PanelBase
{
public:
    InstrPanel_ZDC(QWidget* parent = nullptr);
    virtual ~InstrPanel_ZDC(){}

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
	
};

#endif // INSTRPANEL_ZDC_H
