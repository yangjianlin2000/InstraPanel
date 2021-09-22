#include "panelveri0.h"

#define FRAME_STYLE "border-image:url(:/res/res/image/frame_veri0.png);\n"

PanelVeri0::PanelVeri0(QWidget *parent) : PanelBase(parent)
{
    PRINT("Create:[%p]\n", this);
    Page* page1 = new Page(this);
    page1->AddTitle(QRect(0,0,800,480), FRAME_STYLE);
    AddToPageList(page1);
    SetPageIndex(0);

    QPoint pos(0, 0);
    m_hl_pad_for_mode = createHilightPad(pos);
    //activateMode(0);
    m_hl_pad_for_shift = createHilightPad(pos);
    //activateShift(0);

    m_hl_pad_for_ckqd = createHilightPad(pos);
    //activateCKQD(0);
    m_hl_pad_for_qdrc = createHilightPad(pos);
    //activateQDRC(0);
    m_hl_pad_for_sdqd = createHilightPad(pos);
    //activateSDQD(0);    

    m_hl_pad_other = createHilightPad(pos);

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(slot_activeTimeOut()));
}

PanelVeri0::~PanelVeri0()
{
    m_timer->stop();
}

KeyHandleState PanelVeri0::keyEvent(const KeyInfo & keyinfo)
{
    ENTER();

    if(keyinfo.keyid == KEY_PAGE_UP)
    {
        activatePageUp();
    }
    else if (keyinfo.keyid == KEY_PAGE_DOWN)
    {
        activatePageDown();
    }
    else if (keyinfo.keyid == KEY_UP)
    {
        activateUp();
    }
    else if (keyinfo.keyid == KEY_DOWN)
    {
        activateDown();
    }
    else if (keyinfo.keyid == KEY_LEFT)
    {
        activateLeft();
    }
    else if (keyinfo.keyid == KEY_RIGHT)
    {
        activateRight();
    }
    else if (keyinfo.keyid == KEY_ENTER)
    {
        activateEnter();
    }
    else if (keyinfo.keyid == KEY_ESC)
    {
        activateEsc();
    }
    else if (keyinfo.keyid == KEY_SDQD)
    {
        activateSDQD((int)keyinfo.data);
    }
    
    else if (keyinfo.keyid == KEY_CKQD)
    {
        activateCKQD((int)keyinfo.data);
    }
    else if (keyinfo.keyid == KEY_QDRC)
    {
        activateQDRC((int)keyinfo.data);
    }
    else if (keyinfo.keyid == KEY_MODE_CHANGE)
    {
        activateMode((int)keyinfo.data);
    }
    else if (keyinfo.keyid == KEY_TAP_POSITION)
    {
        activateShift((int)keyinfo.data);
    }
    else
    {
        ERROR("Unrecognized keyid[%d]\n", keyinfo.keyid);
        return KEY_TO_HANDLE;
    }

    return KEY_HANDLED;
}

QWidget* PanelVeri0::createHilightPad(const QPoint& pos)
{
    QString stylesheet("border-image:url(:/res/res/image/highlight_pad.png);");
    QWidget* hl_pad = new QWidget(this);
    hl_pad->setObjectName(QStringLiteral("hl_pad"));
    hl_pad->setStyleSheet(stylesheet);
    hl_pad->resize(QSize(40, 40));
    hl_pad->hide();
    return hl_pad;
}

void PanelVeri0::activateMode(int val)
{
    assert(val >= 0 && val <= 4);
    QPoint pos_array[] =
    {
        QPoint(141, 81),
        QPoint(265, 81),
        QPoint(388, 81),
        QPoint(512, 81),
        QPoint(635, 81)
    };

    m_hl_pad_for_mode->move(pos_array[val]);
    m_hl_pad_for_mode->show();
}

void PanelVeri0::activateShift(int val)
{
    assert(val >= 0 && val <= 4);
    QPoint pos_array[] =
    {
        QPoint(141, 172),
        QPoint(265, 172),
        QPoint(388, 172),
        QPoint(512, 172),
        QPoint(635, 172)
    };

    m_hl_pad_for_shift->move(pos_array[val]);
    m_hl_pad_for_shift->show();
}

void PanelVeri0::slot_activeTimeOut()
{
    PRINT("Key display time out\n");
    m_hl_pad_other->hide();
}

void PanelVeri0::activateOtherKey(const QPoint& pos)
{
    const int interval = 1000;
    if (m_hl_pad_other == nullptr)
    {
        m_hl_pad_other = createHilightPad(pos);
        m_hl_pad_other->show();
        m_timer->setSingleShot(true);
        m_timer->start(interval);
    }
    else
    {
        m_hl_pad_other->move(pos);
        if (m_timer->isActive())
            m_timer->stop();
        m_timer->start(interval);
        PRINT("Start timer\n");
    }
    m_hl_pad_other->show();
}

void PanelVeri0::activateSDQD(int val)
{
    QPoint pos(141, 259);
    if (val == 1)
    {
        m_hl_pad_for_sdqd->move(pos);
        m_hl_pad_for_sdqd->show();
    }
    else if (val == 0)
    {
        m_hl_pad_for_sdqd->hide();
    }
}

void PanelVeri0::activateCKQD(int val)
{
    QPoint pos(265, 259);
    if (val == 1)
    {
        m_hl_pad_for_ckqd->move(pos);
        m_hl_pad_for_ckqd->show();
    }
    else if (val == 0)
    {
        m_hl_pad_for_ckqd->hide();
    }
}

void PanelVeri0::activateQDRC(int val)
{
    QPoint pos(388, 259);
    if (val == 1)
    {
        m_hl_pad_for_qdrc->move(pos);
        m_hl_pad_for_qdrc->show();
    }
    else if (val == 0)
    {
        m_hl_pad_for_qdrc->hide();
    }
}

void PanelVeri0::activateLeft()
{
    QPoint pos(141, 350);
    activateOtherKey(pos);
}

void PanelVeri0::activateUp()
{
    QPoint pos(265, 350);
    activateOtherKey(pos);
}

void PanelVeri0::activateRight()
{
    QPoint pos(388, 350);
    activateOtherKey(pos);

}

void PanelVeri0::activatePageUp()
{
    QPoint pos(512, 350);
    activateOtherKey(pos);
}

void PanelVeri0::activateEsc()
{
    QPoint pos(141, 413);
    activateOtherKey(pos);
}

void PanelVeri0::activateDown()
{
    QPoint pos(265, 413);
    activateOtherKey(pos);
}

void PanelVeri0::activateEnter()
{
    QPoint pos(388, 413);
    activateOtherKey(pos);
}

void PanelVeri0::activatePageDown()
{
    QPoint pos(512, 413);
    activateOtherKey(pos);
}

