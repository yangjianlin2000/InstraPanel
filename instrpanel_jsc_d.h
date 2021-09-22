#ifndef INSTRPANEL_JSC_D_H
#define INSTRPANEL_JSC_D_H

#include "panelbase.h"

class InstrPanel_JSC_D: public PanelBase
{
public:
    InstrPanel_JSC_D(QWidget* parent = nullptr);
    virtual ~InstrPanel_JSC_D(){}

protected:
	OutType CheckOutUnitType(const QString& name);
	void RecvMsg(unsigned char* msg, int size);
	void SetValue(const QString& name, int val);

    bool GetDefaultTestItem(int id, QString &retname, DefaultTestInfo &retinfo);
    bool DefaultTest(int id);

    void InitDefaultTestList();
};

#endif // INSTRPANEL_JSC_D_H
