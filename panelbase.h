#ifndef PANELBASE_H
#define PANELBASE_H


#include <assert.h>
#include <list>
#include <vector>
#include <future>
#include <QColor>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QRect>
#include <QKeyEvent>
#include <QStackedWidget>
#include <QMap>
#include <QPalette>
#include <QTimer>

#include "keymap.h"
#include "table.h"
#include "protocol.h"

#define TAB_COL_NUM_MAX 8

#define I_J_TO_KEY(i, j) (((i&0xffff)<<16) + (j&0xffff))
#define KEY_TO_I(key)    (key>>16)
#define KEY_TO_J(key)    (key&0xffff)

typedef enum _keyHandling
{
	KEY_TO_HANDLE,
	KEY_HANDLED,
}KeyHandleState;

class Tab
{
public:
    Tab(QWidget* parent, int rownum, int colnum, \
          const LabelInfo label_info[][TAB_COL_NUM_MAX], QPoint label_pos, const QSize rec_size[], int sep = 1);
    ~Tab();
    QLabel* GetLabel(int i, int j);
    QLabel* GetLabel(const QString& name);
    QLabel* GetLabel(const QString& name, int col);
	void Reset();
	int GetWidth();
    
private:
    QLabel* create_label(QWidget* parent, const QPoint& pos, const QSize& size, const char* style, const char* name);

private:
    int m_rownum;
    int m_colnum;
    QMap<unsigned int, QLabel*> m_labelbypos;
    QMap<QString, QLabel*> m_labelbystr;
    QMap<QString, int> m_rowidbystr;
    int m_width;
};


#define PAGE_NAVI_COL_MAX 8

class Page: public QWidget
{
    Q_OBJECT
public:
    Page(QWidget* parent);
    ~Page();
    void SetStyleSheet(const char* stylesheet);
    QLabel* AddTitle(const QRect& rect, const char* stylesheet);
    QLabel* SetButton(const QRect& rect, const char* stylesheet);
    void AddTable(int rownum, int colnum, \
                    const LabelInfo label_info[][TAB_COL_NUM_MAX], QPoint label_pos, const QSize rec_size[]);
    void AddTable(Tab *table);
    void SetNaviMap(const char* strmap[][PAGE_NAVI_COL_MAX], int navrownum, int navcolnum);
	const QString& GetNaviStringByPos(int i, int j);
    void GetNaviPosByName(const QString& name, int &i, int &j);
    int GetNaviRowNum();
    int GetNaviColNum();
    void GetHlPos(int &i, int &j);
	QLabel* StartBtn();
    bool IsHighlightEnabled();
    void MoveToPos(int i, int j);
	void MoveToPos(const QString& name);
	void MoveToStartBtn();
    int GetCurrentHlWidth();
    void GetCurrentHlSize(QSize &size);
    void CreateHlRect(int width, const char* style = nullptr);
	bool IsStartBtnFocused();
	void Reset();
	bool IsSubTable(Tab* tbl);
    void SetAppVersion(const char* ver, QWidget* parent, QRect rect = QRect(2,2,240,24), const char* str = "font: 16px bold; color: rgb(215, 230, 254); background-color:rgba(0,0,0,0);");

private:
    std::list<QLabel*> m_titleList;
    std::list<Tab*> m_tableList;
    int m_nav_row_num;
    int m_nav_col_num;
    int m_nav_i;
    int m_nav_j;
    QLabel* m_start_btn;
    QMap<unsigned int, QString> m_navmap;
    QLabel* m_hl;
    int m_hl_width;
    int m_hl_height;
    QWidget* m_parent;
    bool m_is_start_btn_focused;
    QLabel* m_appVer;
};

#define VAL_OPT_MAX 10

#define DISPLAY_TYPE_RESERVED (-1)
#define DISPLAY_TYPE_STR 1
#define DISPLAY_TYPE_INT 2
#define DISPLAY_TYPE_BINARY 3

#define NONE Qt::white
#define RED Qt::red
#define BLUE Qt::blue
#define GREEN Qt::green
#define YELLOW Qt::yellow
#define ORANGE Qt::magenta
#define WHITE Qt::white


typedef QString fDspStr(int dip);

typedef struct _MsgInfo
{
    int sn;
    const char* name;
    struct _ValOpt
    {
    	uint8_t dip;
        const char* valstr;
        QColor valstrcolor;
    }valoption[VAL_OPT_MAX];
    int type; // Value
    int column;
    int offset;
    fDspStr *func;
}MsgInfo;


typedef struct _MsgInfo_out
{
    int sock;
    const char* name;
    int optNum;
    struct _ValOpt
    {
        int dip;
        const char* valstr;
        QColor valstrcolor;
    }valoption[VAL_OPT_MAX];
    int column;
}MsgInfo_out;

typedef enum _outType
{
	TYPE_UNKNOWN = -1,
	TYPE_OPT_OFFON,
	TYPE_OPT_TUNE
}OutType;

typedef struct _defaultTestInfo
{
    int sock;
    int dip;
    int seconds;
}DefaultTestInfo;


class PanelBase: public QWidget
{
    Q_OBJECT

public:
    PanelBase(QWidget* parent);
	virtual ~PanelBase(){}

    virtual void AddToPageList(Page* page);
    virtual void SetPageIndex(int index);
    int GetCurrentPageIndex();
    Page* GetCurrentPage();
    int GetPageIndex(Page* page);
    bool IsTestStarted();
    bool IsAutoTestState();
    virtual KeyHandleState PreKeyHandle(const KeyInfo & keyinfo);
	virtual KeyHandleState keyEvent(const KeyInfo & keyinfo);
    Page* GetPage(const QString& qstr);
    Tab* GetTable(const QString& qstr);
    void CreatePageMap(Page* page, const LabelInfo label_info[][TAB_COL_NUM_MAX], int rownum);
    void CreateTableMap(Tab* tbl, const LabelInfo label_info[][TAB_COL_NUM_MAX], int rownum);
    void SetCell(const QString &itemstr, int col, const QString& statestr, QColor fontColor);

    virtual void RecvCanValue(unsigned char* msg, int size);
    virtual void RecvIoValue(unsigned char* msg, int size);
    static uint32_t FourCharsToUint(uint8_t c1, uint8_t c2 = 0, \
                                        uint8_t c3 = 0, uint8_t c4 = 0);
	void DoTest(bool flag);
	void SetFuncCode(unsigned      char code);
	void RecvSVN(unsigned char* msg);
	virtual void RecvMsg(unsigned char* msg, int size);

    void StartDefaultTest();
    void StopDefaultTest();

private:
	void createShadow();
	void activateFocusShadow(bool activeFlag, QPoint pos);
	bool isFocusShadowActivated();

signals:
    void sig_recvCanValue(unsigned char* msg, int size);
    void sig_recvIoValue(unsigned char* msg, int size);

#if 0
    void sig_sendCanValue(unsigned char* msg, int size);
    void sig_sendIoValue(unsigned char* msg, int size);
#endif

private slots:
    void slot_recvCanValue(unsigned char* msg, int size);
    void slot_recvIoValue(unsigned char* msg, int size);
	void slot_getVerTimeOut();

	void slot_doDefaultTest();

protected:
#if 0
	virtual void SetIoOut(QString name, int val);
	virtual void SetCanOut(QString name, int val);
#endif
	void GenerateOutMsg(OutType outtyp, MsgInfo_out *info_array, int count, const QString& name, int val);
	virtual void SetValue(const QString& name, int val);
	void SetSpecValue(const QString& name, int val, MsgInfo_out* msg_info_query, int query_num);
    void SetSpecValue(int sock, int val, MsgInfo_out* msg_info_query, int query_num);

	virtual OutType CheckOutUnitType(const QString&  name);

    virtual void ShowState(unsigned char* msg, int msg_size, MsgInfo* msg_info_query, int query_num);

    /* It must be inherited */
    virtual void GetCanState(unsigned char* msg, int size);
    virtual void GetIoState(unsigned char* msg, int size);

	void SwitchTest(bool onoff);
	void ShowVerInfo();
	QLabel* FindStartBtn();
	void ResetDisplayContent();

    virtual bool DefaultTest(int id);
    virtual bool GetDefaultTestItem(int id, QString &retname, DefaultTestInfo &retinfo);

    virtual void InitDefaultTestList();

private:
    std::vector<Page*> m_pagelist;
    QLabel* m_start_btn;
    QLabel* m_focusShadow;
    QStackedWidget* m_stackedWidget;
    QMap<QString, Page*> m_pagemap;
    QMap<QString, Tab*> m_tblmap;
    bool m_runningFlag;
    unsigned char m_funcCode;
    QString m_verStr;
    QTimer* m_verTimer;
    QLabel* m_ver;
    bool m_autoFlag;

    //bool m_defaultTestFlag;
    QTimer* m_defaultTestTimer;
    int m_defaultTestIndex;
};

#endif // PANELBASE_H

