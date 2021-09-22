#ifndef INSTRPANEL_DLC_A_H
#define INSTRPANEL_DLC_A_H

#include <QWidget>
#include "panelbase.h"


class InstrPanel_DLC_A : public PanelBase
{
public:
    InstrPanel_DLC_A(QWidget* parent = nullptr);
    virtual ~InstrPanel_DLC_A(){}

protected:
    void RecvMsg(unsigned char* msg, int size);
    void SetValue(const QString& name, int val);
    OutType CheckOutUnitType(const QString& name);
    KeyHandleState keyEvent(const KeyInfo & keyinfo);
};

#endif // InstrPanel_DLC_A_H
