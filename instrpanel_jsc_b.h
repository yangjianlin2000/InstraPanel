#ifndef INSTRPANEL_JSC_B_H
#define INSTRPANEL_JSC_B_H

#include <QWidget>
#include <panelbase.h>

class InstrPanel_JSC_B : public PanelBase
{
public:
    InstrPanel_JSC_B(QWidget* parent = nullptr);
    ~InstrPanel_JSC_B(){}

    void RecvMsg(unsigned char* msg, int size);
    void SetValue(const QString& name, int val);
    OutType CheckOutUnitType(const QString& name);

};

#endif // INSTRPANEL_JSC_B_H
