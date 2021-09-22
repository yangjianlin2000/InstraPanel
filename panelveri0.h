#ifndef PANELVERI0_H
#define PANELVERI0_H

#include <QTimer>
#include "panelbase.h"


class PanelVeri0 : public PanelBase
{
    Q_OBJECT
public:
    PanelVeri0(QWidget *parent = nullptr);
    ~PanelVeri0();

	KeyHandleState keyEvent(const KeyInfo & keyinfo);

private:
    QWidget* createHilightPad(const QPoint& pos);
    void activateMode(int val);
    void activateShift(int val);
    void activateOtherKey(const QPoint& pos);
    void activateSDQD(int val);
    void activateCKQD(int val);
    void activateQDRC(int val);
    void activateLeft();
    void activateUp();
    void activateRight();
    void activatePageUp();
    void activateEsc();
    void activateDown();
    void activateEnter();
    void activatePageDown();

private slots:
    void slot_activeTimeOut();

private:
    QWidget* m_hl_pad_for_mode;
    QWidget* m_hl_pad_for_shift;

    QWidget* m_hl_pad_for_sdqd;
    QWidget* m_hl_pad_for_ckqd;
    QWidget* m_hl_pad_for_qdrc;

    QWidget* m_hl_pad_other;
    QTimer* m_timer;
};

#endif // PANELVERI0_H
