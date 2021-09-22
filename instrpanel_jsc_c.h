#ifndef INSTRPANEL_JSC_C_H
#define INSTRPANEL_JSC_C_H

#include <QWidget>
#include "panelbase.h"

class InstrPanel_JSC_C: public PanelBase
{
public:
    InstrPanel_JSC_C(QWidget* parent = nullptr);
    virtual ~InstrPanel_JSC_C(){}

    void RecvMsg(unsigned char* msg, int size);
    void SetValue(const QString& name, int val);
    OutType CheckOutUnitType(const QString& name);

private:

};

#endif // INSTRPANEL_JSC_C_H
