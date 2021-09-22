#ifndef INSTRPANEL_YBB_H
#define INSTRPANEL_YBB_H

#include "panelbase.h"

class InstrPanel_YBB : public PanelBase
{
    Q_OBJECT
public:
    explicit InstrPanel_YBB(QWidget *parent = nullptr);
    virtual ~InstrPanel_YBB(){}

protected:
	void RecvMsg(unsigned char* msg, int size);

#if 0
    OutType CheckOutUnitType(QString name);
    void SetIoOut(QString name, int val);
    void SwitchMainPower(bool flag);
    void resetOutInfo();
#endif
};

#endif // INSTRPANEL_YBB_H
