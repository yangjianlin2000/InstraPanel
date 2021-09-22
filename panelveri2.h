#ifndef PANELVERI2_H
#define PANELVERI2_H

#include <QTimer>
#include "panelbase.h"


class PanelVeri2 : public PanelBase
{
    Q_OBJECT
public:
    PanelVeri2(QWidget *parent = nullptr);
    ~PanelVeri2(){}
    
    KeyHandleState PreKeyHandle(const KeyInfo & keyinfo);
    KeyHandleState keyEvent(const KeyInfo & keyinfo);

protected:
    void RecvMsg(unsigned char* msg, int size);
    void SetValue(const QString& name, int val);
    OutType CheckOutUnitType(const QString& name);

signals:
    void signal_shiftKeyChange(unsigned int val);

private:
    QWidget* m_parent;
};

#endif // PANELVERI2_H
