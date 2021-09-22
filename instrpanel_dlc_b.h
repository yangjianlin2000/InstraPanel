#ifndef INSTRPANEL_DLC_B_H
#define INSTRPANEL_DLC_B_H

#include <QWidget>
#include "panelbase.h"


class InstrPanel_DLC_B : public PanelBase
{
public:
    InstrPanel_DLC_B(QWidget* parent = nullptr);
    virtual ~InstrPanel_DLC_B(){}
    
protected:
    void RecvMsg(unsigned char* msg, int size);
    void SetValue(const QString& name, int val);
    OutType CheckOutUnitType(const QString& name);
};

#endif // INSTRPANEL_DLC_B_H
