#ifndef PANELVERI1_H
#define PANELVERI1_H

#include <QTimer>
#include "panelbase.h"


class PanelVeri1 : public PanelBase
{
    Q_OBJECT
public:
    PanelVeri1(QWidget *parent = nullptr);
    ~PanelVeri1(){}

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

#endif // PANELVERI1_H

