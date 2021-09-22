#ifndef INSTRPANEL_DLC_D_H
#define INSTRPANEL_DLC_D_H

#include <QWidget>
#include "panelbase.h"


class InstrPanel_DLC_D : public PanelBase
{
public:
    InstrPanel_DLC_D(QWidget* parent = nullptr);
	virtual ~InstrPanel_DLC_D(){}

protected:
    void RecvMsg(unsigned char* msg, int size);
    void SetValue(const QString& name, int val);
    OutType CheckOutUnitType(const QString& name);
    KeyHandleState keyEvent(const KeyInfo & keyinfo);

    bool GetDefaultTestItem(int id, QString &retname, DefaultTestInfo &retinfo);
    bool DefaultTest(int id);
    
    void InitDefaultTestList();
};

#endif // InstrPanel_DLC_D_H
