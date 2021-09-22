#ifndef INSTRPANEL_JSC_H
#define INSTRPANEL_JSC_H

#include "panelbase.h"

class InstrPanel_JSC: public PanelBase
{
public:
    InstrPanel_JSC(QWidget* parent = nullptr);
    virtual ~InstrPanel_JSC(){}

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

#endif // INSTRPANEL_JSC_H
