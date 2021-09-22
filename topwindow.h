#ifndef TOPWINDOW_H
#define TOPWINDOW_H

#include <vector>
#include <future>
#include <mutex>
#include <QObject>
#include <QWidget>
#include <stdint.h>
#include "panelbase.h"
#include "keymap.h"
#include "protocol.h"


typedef PanelBase* create_func(QWidget*);

class TopWindow : public QWidget
{
    Q_OBJECT
public:
	static TopWindow* GetInstance();
    explicit TopWindow(QWidget *parent = nullptr);
    virtual ~TopWindow();
    union KeyEvent parseKey(uint8_t *msg);
    void msgLoop();

protected:
//    virtual void keyPressEvent(QKeyEvent  *event);
    uint32_t getMsg();
	void getKey(unsigned int key);

protected slots:
    void slot_sendCanValue(unsigned char* msg, int size);
    void slot_sendIoValue(unsigned char* msg, int size);

private slots:
//    void slot_sendMsg(uint32_t msg);
//    void slot_getMsg(uint32_t msg);
//    void slot_getKey(unsigned int key);
    void slot_shiftKeyChange(unsigned int val);
	void slot_warningTimeOut();
	void slot_getMsg(unsigned int cmd, unsigned char* msg, int size);

signals:
//    void sig_sendMsg(uint32_t msg);
    void sig_getMsg(unsigned int cmd, unsigned char* msg, int size);
    void sig_getKey(unsigned int key);

private:
	void setWarning(const char* text);

    void setVeriMode();
    void checkProductType();
    int getModeIndex();
    int getShiftIndex();
    bool isVeriMode();
	void getInitialKey();

public:
    PanelBase * m_widget;
    int m_widget_index;
    std::future<void> m_key_loop_thread;
    bool m_loop_flag;
    KeyInfo m_key;
    std::vector<create_func*> m_createfunc;
    std::vector<unsigned char> m_modecode;
    std::vector<unsigned char> m_vericode;
    Protocol* m_proto;
    int m_modeIndex;
    int m_shiftIndex;

    QTimer* m_timer;
    QLabel* m_warningDiag;
	std::mutex m_mtx;    
    static TopWindow* m_instance;
};

#endif // TOPWINDOW_H
