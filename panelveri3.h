#ifndef PANELVERI3_H
#define PANELVERI3_H

#include <QTimer>
#include "panelbase.h"


class PanelVeri3 : public PanelBase
{
    Q_OBJECT
public:
    PanelVeri3(QWidget *parent = nullptr);
    ~PanelVeri3(){}
    
    KeyHandleState keyEvent(const KeyInfo & keyinfo);
    KeyHandleState PreKeyHandle(const KeyInfo & keyinfo);
protected:
    void RecvMsg(unsigned char* msg, int size);
    void SetValue(const QString& name, int val);
    OutType CheckOutUnitType(const QString& name);

signals:
    void signal_shiftKeyChange(unsigned int val);

private:
    QWidget* m_parent;
};

#endif // PANELVERI3_H
