#ifndef INSTRPANEL_YBB_B_H
#define INSTRPANEL_YBB_B_H

#include <QWidget>
#include "panelbase.h"

class InstrPanel_YBB_B : public PanelBase
{
public:
    InstrPanel_YBB_B(QWidget* parent = nullptr);
    virtual ~InstrPanel_YBB_B(){}

    void RecvMsg(unsigned char* msg, int size);
};

#endif // INSTRPANEL_YBB_B_H
