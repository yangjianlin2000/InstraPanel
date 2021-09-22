
#include "panelbase.h"
#include "string.h"


/**********************************************   Tab  **********************************************/
Tab::Tab(QWidget* parent, int rownum, int colnum, const LabelInfo label_info[][TAB_COL_NUM_MAX], \
			QPoint label_pos, const QSize rec_size[], int sep)
{
    PRINT("Tab[%p] created\n", this);
    PRINT("rownum:%d, colnum:%d\n", rownum, colnum);
    m_rownum = rownum;
    m_colnum = colnum;
    uint32_t y = label_pos.y();
    uint32_t h = rec_size[0].height();
    for(uint32_t i = 0; i < rownum; i++)
    {
        uint32_t x = label_pos.x();
        for(uint32_t j = 0; j < colnum; j++)
        {
            printf("label[%d][%d]: (%d,%d,%d,%d): %s\n", i, j, x, y, rec_size[j].width(), rec_size[j].height(), label_info[i][j].name);
            QLabel* qlabels = create_label(parent, QPoint(x, y), rec_size[j], label_info[i][j].style, label_info[i][j].name);
            m_labelbypos.insert(I_J_TO_KEY(i,j), qlabels);
            if (j == 0)
            {
                m_labelbystr.insert(label_info[i][j].name, qlabels);
                m_rowidbystr.insert(label_info[i][j].name, i);
            }
            else
            {
				qlabels->setAlignment(Qt::AlignCenter);
            }

            x += rec_size[j].width() + sep;
        }
        y += h;
    }

    m_width = 0;
    for(uint32_t j = 0; j < colnum; j++)
    {
        m_width += rec_size[j].width();
    }
}

Tab::~Tab()
{

}

QLabel* Tab::GetLabel(int i, int j)
{
    return m_labelbypos[I_J_TO_KEY(i,j)];
}

QLabel* Tab::GetLabel(const QString &name)
{
    return m_labelbystr[name];
}

QLabel* Tab::GetLabel(const QString &name, int col)
{
    int rowid = -1;
    auto iter = m_rowidbystr.find(name);
    if (iter == m_rowidbystr.end())
    {
    	return nullptr;
    }
    //rowid = m_rowidbystr[name];
    rowid = iter.value();
    assert(rowid >= 0 && rowid < m_rownum);
    return GetLabel(rowid, col);
}

QLabel* Tab::create_label(QWidget* parent, const QPoint& pos, const QSize& size, const char* style, const char* name)
{
    QLabel* label = new QLabel(parent);
    label->setStyleSheet(QLatin1String(style));
    label->move(pos);
    label->resize(size);

    if(name)
    {
    	PRINT("pos[%d, %d]: %s\n", pos.x(), pos.y(), name);
        label->setText(QString(name));
    }
    label->show();
    return label;
}

void Tab::Reset()
{
	PRINT("Tab::Reset: %p\n", this);
    QLabel* label = nullptr;
	for (int i = 0; i < m_rownum; i++)
	{
		for (int j = 1; j < m_colnum; j++)
		{
			label = GetLabel(i, j);
			if (label->text() != "——")
			{
				PRINT("clear cell[%d, %d]\n", i, j);
				label->setText("");
			}
		}
	}
}

int Tab::GetWidth()
{
    return m_width;
}

/**********************************************   Page  **********************************************/

Page::Page(QWidget* parent): QWidget(parent)
{
	m_is_start_btn_focused = false;
    m_hl = nullptr;
    m_hl_width = 0;
    m_hl_height = 0;
    m_start_btn = nullptr;
    m_nav_row_num = 0;
    m_nav_col_num = 0;
    m_nav_i = 0;
    m_nav_j = 0;
    m_parent = parent;
    PRINT("New page[%p] is created\n", this);

    if (objectName().isEmpty())
        setObjectName(QString("page_")+QString::number((uint64_t)this, 16));
    resize(800, 480);
    setStyleSheet(QStringLiteral("background-color: rgb(31, 31, 31);"));
}

Page::~Page()
{
    for (auto &iter: m_tableList)
        delete(iter);
}

void Page::SetStyleSheet(const char* stylesheet)
{
    PRINT("stylesheet: %s\n", stylesheet);
    setStyleSheet(stylesheet);
}

QLabel* Page::AddTitle(const QRect& rect, const char* stylesheet)
{
    QLabel* title = new QLabel(this);
    title->setGeometry(rect);
    title->setObjectName("title");
    QString style = "#title{";
    style += stylesheet;
    style += "}";
    title->setStyleSheet(style);
    m_titleList.push_back(title);

    return title;
}

QLabel* Page::SetButton(const QRect& rect, const char* stylesheet)
{
    PRINT("Enter\n");
    m_start_btn = new QLabel(this);
    m_start_btn->setGeometry(rect);
    m_start_btn->setObjectName(QStringLiteral("start"));
    m_start_btn->setStyleSheet(stylesheet);
    m_start_btn->setText(QStringLiteral("开始测试"));
    m_start_btn->setAlignment(Qt::AlignCenter);
    PRINT("Leave\n");
    return m_start_btn;
}

void Page::AddTable(int rownum, int colnum, \
                const LabelInfo label_info[][TAB_COL_NUM_MAX], QPoint label_pos, const QSize rec_size[])
{
    ENTER();
    Tab* table = new Tab(this, rownum, colnum, label_info, label_pos, rec_size);
    m_tableList.push_back(table);
    LEAVE();
}

void Page::AddTable(Tab *table)
{
    ENTER();
    m_tableList.push_back(table);
    LEAVE();
}

void Page::SetNaviMap(const char* strmap[][PAGE_NAVI_COL_MAX], int navRowNum, int navColNum)
{
    m_nav_row_num = navRowNum;
    m_nav_col_num = navColNum;
    PRINT("m_nav_row_num:[%d], m_nav_col_num:[%d]\n", m_nav_row_num, m_nav_col_num);
    assert(m_nav_col_num <= PAGE_NAVI_COL_MAX);

    for(int i = 0; i < m_nav_row_num; i++)
    {
        for(int j = 0; j < m_nav_col_num; j++)
        {
            m_navmap.insert(I_J_TO_KEY(i,j), QString(strmap[i][j]));
            PRINT("navimap, key[%x], value[%s]\n", I_J_TO_KEY(i,j), strmap[i][j]);
        }
    }
}

const QString& Page::GetNaviStringByPos(int i, int j)
{
    return m_navmap[I_J_TO_KEY(i,j)];
}

void Page::GetNaviPosByName(const QString& name, int &i, int &j)
{
    auto iter = m_navmap.begin();
    unsigned int key = 0;
    for (;iter != m_navmap.end(); iter++)
    {
        if (name == iter.value())
        {
            key = iter.key();
            i = KEY_TO_I(key);
            j = KEY_TO_J(key);
            return;
        }
    }

    ERROR("[%s]'s position is not found\n", name.toStdString().c_str());
    i = m_nav_i;
    j = m_nav_j;
}

int Page::GetNaviRowNum()
{
    return m_nav_row_num;
}

int Page::GetNaviColNum()
{
    return m_nav_col_num;
}

void Page::GetHlPos(int &i, int &j)
{
    i = m_nav_i;
    j = m_nav_j;
}

QLabel* Page::StartBtn()
{
    return m_start_btn;
}

bool Page::IsHighlightEnabled()
{
    if (m_hl == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Page::MoveToPos(int i, int j)
{
//	if (m_hl == nullptr)
//	{
//		CreateHlRect(m_);
//	}

    assert (j < m_nav_col_num);
    m_nav_i = i;
    m_nav_j = j;
    m_is_start_btn_focused = false;
    QString name = GetNaviStringByPos(i, j);

    Tab* tbl = dynamic_cast<PanelBase*>(m_parent)->GetTable(name);
    QLabel* label = tbl->GetLabel(name);
    PRINT("label[%s]\n", name.toStdString().c_str());
    int x = label->x();
    int y = label->y();
    m_hl_width = tbl->GetWidth();
    m_hl_height = label->height();
    int w = m_hl_width;
    int h = m_hl_height;
    PRINT("rect[%d, %d, %d, %d]\n", x, y, w, h);
    m_hl->setGeometry(QRect(x, y, w, h));
    m_hl->show();
}

void Page::MoveToPos(const QString& name)
{
//	if (m_hl == nullptr)
//	{
//		CreateHlRect(m_);
//	}

    Tab* tbl = dynamic_cast<PanelBase*>(m_parent)->GetTable(name);
    QLabel* label = tbl->GetLabel(name);
    PRINT("label[%s]\n", name.toStdString().c_str());
    GetNaviPosByName(name, m_nav_i, m_nav_j);

    int x = label->x();
    int y = label->y();
    m_hl_width = tbl->GetWidth();
    m_hl_height = label->height();
    int w = m_hl_width;
    int h = m_hl_height;
    PRINT("rect[%d, %d, %d, %d]\n", x, y, w, h);
    m_hl->setGeometry(QRect(x, y, w, h));
    m_hl->show();
}

void Page::MoveToStartBtn()
{
    int x = m_start_btn->x();
    int y = m_start_btn->y();
    int w = m_start_btn->width();
    int h = m_start_btn->height();
    m_nav_i = m_nav_row_num;
    m_hl->setGeometry(QRect(x, y, w, h));
    m_is_start_btn_focused = true;
}

int Page::GetCurrentHlWidth()
{
    return m_hl_width;
}

void Page::GetCurrentHlSize(QSize &size)
{
    size = std::move(QSize(m_hl_width, m_hl_height));
}

bool Page::IsStartBtnFocused()
{
	return m_is_start_btn_focused;
}


void Page::CreateHlRect(int width, const char* style)
{
#define HIGHLIGHT_RECT_STYLE "border: 2px solid yellow; border-radius: 8px\n;background-color:rgba(0,0,0,0)"
    QString hlstyle;
    if (style)
    {
        hlstyle = hlstyle;
    }
    else
    {
        hlstyle = HIGHLIGHT_RECT_STYLE;
    }
    m_hl = new QLabel(this);
    m_hl->setStyleSheet(hlstyle);
    m_hl_width = width;
    if (m_nav_row_num == 0 && m_start_btn)
    {
        MoveToStartBtn();
    }
    else
    {
        MoveToPos(0, 0);
    }
}

void Page::Reset()
{
	PRINT("Page::Reset: %p\n", this);
	for (auto& tab: m_tableList)
	{
		tab->Reset();
	}
}

bool Page::IsSubTable(Tab* tbl)
{
	for (Tab* it: m_tableList)
	{
		if (it == tbl)
		{
			return true;
		}
	}

	return false;
}

void Page::SetAppVersion(const char* ver, QWidget* parent, QRect rect, const char* str)
{
    m_appVer = new QLabel(parent);
    m_appVer->setStyleSheet(str);
    m_appVer->setGeometry(rect);
    m_appVer->setText(ver);
    m_appVer->show();
}

/**********************************************   PanelBase  **********************************************/
PanelBase::PanelBase(QWidget* parent): QWidget(parent)
{
    m_defaultTestIndex = 0;
    m_defaultTestTimer = nullptr;

	m_funcCode = 0;
	m_verTimer = nullptr;
	m_ver = nullptr;
	
    PRINT("Create:[%p]\n", this);
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("Frame")+QString::number((uint64_t)m_stackedWidget, 16));

    resize(800, 480);
    setStyleSheet(QStringLiteral("background-color: rgb(31, 31, 31);"));
//    setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
    m_stackedWidget = new QStackedWidget(this);
    m_stackedWidget->setObjectName(QStringLiteral("stackedWidget_")+QString::number((uint64_t)m_stackedWidget, 16));
    m_stackedWidget->setGeometry(QRect(0, 0, 800, 480));
    m_stackedWidget->setAutoFillBackground(true);

	createShadow();

    m_runningFlag = false;
    m_autoFlag = false;

    connect(this, SIGNAL(sig_recvCanValue(unsigned char*, int)), \
            this, SLOT(slot_recvCanValue(unsigned char*, int)),Qt::QueuedConnection);
    connect(this, SIGNAL(sig_recvIoValue(unsigned char*, int)), \
            this, SLOT(slot_recvIoValue(unsigned char*, int)),Qt::QueuedConnection);

#if 0
    connect(this, SIGNAL(sig_sendCanValue(unsigned char*, int)), \
            parent, SLOT(slot_sendCanValue(unsigned char*, int)),Qt::QueuedConnection);
    connect(this, SIGNAL(sig_sendIoValue(unsigned char*, int)), \
            parent, SLOT(slot_sendIoValue(unsigned char*, int)),Qt::QueuedConnection);
#endif
}

void PanelBase::AddToPageList(Page* page)
{
    m_pagelist.push_back(page);
    m_stackedWidget->addWidget(page);
}

void PanelBase::SetPageIndex(int index)
{
    PRINT("index:%d\n", index);
    if(index < m_pagelist.size() && index >= 0)
    {
        m_stackedWidget->setCurrentIndex(index);
    }
}

int PanelBase::GetPageIndex(Page* page)
{
    for (int i = 0; i < m_pagelist.size(); i++)
    {
        if (m_pagelist[i] == page)
        {
            return i;
        }
    }

    ERROR ("No page is found[%p]\n", page);
    return -1;
}

int PanelBase::GetCurrentPageIndex()
{
    PRINT("Current Page Index: %d\n", m_stackedWidget->currentIndex());
    return m_stackedWidget->currentIndex();
}

Page* PanelBase::GetCurrentPage()
{
    PRINT("Current Page Index: %d\n", m_stackedWidget->currentIndex());
    return m_pagelist[m_stackedWidget->currentIndex()];
}

bool PanelBase::IsTestStarted()
{
    return m_runningFlag;
}

bool PanelBase::IsAutoTestState()
{
    return m_autoFlag;
}

Page* PanelBase::GetPage(const QString& qstr)
{
    Tab* tbl = GetTable(qstr);
	if (tbl)
	{
		for (Page* page: m_pagelist)
		{
			if (page->IsSubTable(tbl))
			{
				return page;
			}
		}
	}

	return nullptr;
}

#if 0
Page* PanelBase::GetPage(const QString& qstr)
{
    return m_pagemap[qstr];
}
#endif

Tab* PanelBase::GetTable(const QString& qstr)
{
//	PRINT("key %s\n", qstr.toStdString().c_str());
    return m_tblmap[qstr];
}

void PanelBase::CreatePageMap(Page* page, const LabelInfo label_info[][TAB_COL_NUM_MAX], int rownum)
{
    for(uint32_t i = 0; i < rownum; i++)
    {
        if (strlen(label_info[i][0].name) > 1)  //!< Check if not empty string
        {
            m_pagemap.insert(QString(label_info[i][0].name), page);
        }
    }
}

void PanelBase::CreateTableMap(Tab* tbl, const LabelInfo label_info[][TAB_COL_NUM_MAX], int rownum)
{
    for(uint32_t i = 0; i < rownum; i++)
    {
        if (strlen(label_info[i][0].name) > 1)  //!< Check if not empty string
        {
            PRINT("insert, name[%s]: tbl[%p]\n", label_info[i][0].name, tbl);
            m_tblmap.insert(QString(label_info[i][0].name), tbl);

            PRINT("key [%s]: %p\n", label_info[i][0].name, GetTable(QString(label_info[i][0].name)));
        }
    }
}

void PanelBase::SetCell(const QString& itemstr, int col, const QString& statestr, QColor fontColor)
{
    Tab* tbl = PanelBase::GetTable(itemstr);
    PRINT("[%s]: %s\n", itemstr.toStdString().c_str(), statestr.toStdString().c_str());
    if (tbl == nullptr)
    {
		return;
    }
    QLabel* label = tbl->GetLabel(itemstr, col);
    if (label)
    {
        PRINT("[%s]: %s\n", itemstr.toStdString().c_str(), statestr.toStdString().c_str());
        QPalette pal;
        pal.setColor(QPalette::WindowText, fontColor);
        label->setPalette(pal);
        label->setAlignment(Qt::AlignCenter);
        label->setText(statestr);
    }
}

void PanelBase::createShadow()
{
#define FOCUS_RECT_STYLE "background-color:rgba(65,98,169,150)"
	m_focusShadow = new QLabel(this);
	m_focusShadow->setStyleSheet(FOCUS_RECT_STYLE);
	m_focusShadow->resize(398, 40);
	m_focusShadow->move(0, 0);

	m_focusShadow->hide();
}

void PanelBase::activateFocusShadow(bool activeFlag, QPoint pos)
{
	if (activeFlag)
	{
		m_focusShadow->move(pos);
		Page* p = GetCurrentPage();
        QSize size;
		p->GetCurrentHlSize(size);
        m_focusShadow->resize(size);
		return m_focusShadow->show();
	}
	else
		return m_focusShadow->hide();
}

bool PanelBase::isFocusShadowActivated()
{
	return m_focusShadow->isVisible();
}

void PanelBase::SetFuncCode(unsigned char code)
{
	m_funcCode = code;
	PRINT("code: %d\n", m_funcCode);
}

QLabel* PanelBase::FindStartBtn()
{
	for (auto pg : m_pagelist)
	{
		if (pg->StartBtn())
		{
			return pg->StartBtn();
		}
	}

	return nullptr;
}

void PanelBase::ResetDisplayContent()
{
	ENTER();
	for (auto &page: m_pagelist)
	{
		page->Reset();
	}
}

void PanelBase::DoTest(bool flag)
{
	PRINT("flag: %d\n", (int)flag);
	m_runningFlag = flag;
	SwitchTest(flag);
	Page* page = nullptr;
	QLabel* startBtn = nullptr;
	startBtn = FindStartBtn();

//	assert (startBtn != nullptr);
	if (flag)
	{
        if (startBtn)
        {
		    startBtn->setText("正在测试...");
        }
	}
	else
	{
		m_autoFlag = false;
        if (startBtn)
        {
		    startBtn->setText("开始测试");
        }
	}
}

KeyHandleState PanelBase::keyEvent(const KeyInfo & keyinfo)
{
    ENTER();

    if (m_defaultTestTimer)
    {
        StopDefaultTest();
    }


    int pagenum = (int)m_pagelist.size();
    int index = m_stackedWidget->currentIndex();
    PRINT("Page[%p] index[%d]\n", m_pagelist[index], index);

	Page* page = m_pagelist[index];

    if (KEY_HANDLED == PreKeyHandle(keyinfo))
    {
        return KEY_HANDLED;
    }
	
	if(IsTestStarted() && keyinfo.keyid == KEY_ESC && page->IsStartBtnFocused())
	{
		PRINT("Cancel key is pressed to stop test!\n");
		DoTest(false);
		return KEY_HANDLED;
	}

	if (isFocusShadowActivated())
	{
		if(keyinfo.keyid == KEY_ESC)
		{
			activateFocusShadow(false, QPoint(0,0));
		}
		else if(keyinfo.keyid == KEY_TAP_POSITION)
		{
			int i = 0;
			int j = 0;
			Page* page = m_pagelist[index];
			page->GetHlPos(i, j);
			PRINT("Current Position [%d, %d]\n", i, j);
			QString name = page->GetNaviStringByPos(i, j);
			SetValue(name, (int)keyinfo.data);
		}

		return KEY_HANDLED;
	}

	if(keyinfo.keyid == KEY_ESC)
	{
        PRINT("Get key: KEY_ESC\n");
		int i = 0;
		int j = 0;
		Page* page = m_pagelist[index];
		page->GetHlPos(i, j);
		QString name = page->GetNaviStringByPos(i, j);

		if (CheckOutUnitType(name) == TYPE_OPT_OFFON)
		{
			//! Set value off
			PRINT("Set [%s] OFF\n", name.toStdString().c_str());
			SetValue(name, 1);
		}
		
		return KEY_HANDLED;
	}
    else if(keyinfo.keyid == KEY_PAGE_DOWN)
    {
        PRINT("Get key: KEY_PAGE_DOWN\n");
        if (index < pagenum-1)
        {
            index++;
            m_stackedWidget->setCurrentIndex(index);
        }
        
		return KEY_HANDLED;
    }
    else if(keyinfo.keyid == KEY_PAGE_UP)
    {
        PRINT("Get key: KEY_PAGE_UP\n");
        if (index > 0)
        {
            index--;
            m_stackedWidget->setCurrentIndex(index);
        }
        
		return KEY_HANDLED;
    }
    else if(keyinfo.keyid == KEY_UP)
    {
        PRINT("Get key: KEY_UP\n");
        Page* page = m_pagelist[index];
        if(!page->IsHighlightEnabled())
        {
        	return KEY_HANDLED;
        }
        if (page->GetNaviColNum() == 0 && page->StartBtn())
        {
            page->MoveToStartBtn();
            return KEY_HANDLED;
        }
        int i = 0;
        int j = 0;
        page->GetHlPos(i, j);
        while(i >= 0)
        {
            i--;
            if (page->GetNaviStringByPos(i, j).length() >= 2)
            {
                break;
            }
        }
        if (i == -1)
        {
        	return KEY_HANDLED;
        }
		page->MoveToPos(i, j);
		
		return KEY_HANDLED;
    }
    else if(keyinfo.keyid == KEY_DOWN)
    {
        PRINT("Get key: KEY_DOWN\n");
        Page* page = m_pagelist[index];
        if(!page->IsHighlightEnabled())
        {
        	return KEY_HANDLED;
        }
        if (page->GetNaviColNum() == 0 && page->StartBtn())
        {
            page->MoveToStartBtn();
            return KEY_HANDLED;
        }
        int i = 0;
        int j = 0;
        page->GetHlPos(i, j);
        PRINT("Current Position [%d, %d]\n", i, j);
        if(i == page->GetNaviRowNum()-1 && page->StartBtn())
        {
            page->MoveToStartBtn();
            return KEY_HANDLED;
        }

        while(i < page->GetNaviRowNum()-1)
        {
            i++;
            if (page->GetNaviStringByPos(i, j).length() >= 2)
            {
                break;
            }
        }
        if (i <= page->GetNaviRowNum()-1 && page->GetNaviStringByPos(i, j).length() >= 2)
        {
            PRINT("Move to [%d, %d][%s]\n", i, j, page->GetNaviStringByPos(i, j).toStdString().c_str());
            page->MoveToPos(i, j);
        }
        
		return KEY_HANDLED;
    }
    else if(keyinfo.keyid == KEY_LEFT)
    {
        PRINT("Get key: KEY_LEFT\n");
        Page* page = m_pagelist[index];
        if(!page->IsHighlightEnabled())
        {
        	return KEY_HANDLED;
        }
        if (page->GetNaviColNum() == 0 && page->StartBtn())
        {
            page->MoveToStartBtn();
            return KEY_HANDLED;
        }
        int i = 0;
        int j = 0;
        page->GetHlPos(i, j);
        PRINT("Current Position [%d, %d]\n", i, j);
        if(j > 0)
        {
            j--;
            if (page->GetNaviStringByPos(i, j).length() < 2)
            {
                return KEY_HANDLED;
            }
            PRINT("Move to [%d, %d][%s]\n", i, j, page->GetNaviStringByPos(i, j).toStdString().c_str());
            page->MoveToPos(i, j);
        }
        
		return KEY_HANDLED;
    }
    else if(keyinfo.keyid == KEY_RIGHT)
    {
        PRINT("Get key: KEY_RIGHT\n");
        Page* page = m_pagelist[index];
        if(!page->IsHighlightEnabled())
        {
        	return KEY_HANDLED;
        }
        if (page->GetNaviColNum() == 0 && page->StartBtn())
        {
            page->MoveToStartBtn();
            return KEY_HANDLED;
        }

        int i = 0;
        int j = 0;
        page->GetHlPos(i, j);
        PRINT("Current Position [%d, %d]\n", i, j);
        if(j < page->GetNaviColNum()-1)
        {
            j++;
            if (page->GetNaviStringByPos(i, j).length() < 2)
            {
                return KEY_HANDLED;
            }
            PRINT("Move to [%d, %d][%s]\n", i, j, page->GetNaviStringByPos(i, j).toStdString().c_str());
            page->MoveToPos(i, j);
        }

		return KEY_HANDLED;
    }
    else if(keyinfo.keyid == KEY_ENTER)
    {
        PRINT("Get key: KEY_ENTER\n");
        Page* page = m_pagelist[index];
        if(!page->IsHighlightEnabled())
        {
            return KEY_HANDLED;
        }

		if (page->IsStartBtnFocused())
		{
			DoTest(true);
			return KEY_HANDLED;
		}

        int i = 0;
        int j = 0;
        page->GetHlPos(i, j);
        PRINT("Current Position [%d, %d]\n", i, j);
        QString name = page->GetNaviStringByPos(i, j);
        if (name.length() < 2)
        {
            return KEY_HANDLED;
        }
        else
        {
        	auto type = CheckOutUnitType(name);
			if (type == TYPE_OPT_OFFON)
			{
				//! Set value on, here value 0 means on 
				PRINT("Set [%s] ON\n", name.toStdString().c_str());
				SetValue(name, 0);
			}
			else if (type == TYPE_OPT_TUNE)
			{
				Tab* tbl = GetTable(name);
				int x = tbl->GetLabel(name)->x();
				int y = tbl->GetLabel(name)->y();
				
				activateFocusShadow(true, QPoint(x, y));
			}
			
			return KEY_HANDLED;
        }
    }

    return KEY_TO_HANDLE;
}

KeyHandleState PanelBase::PreKeyHandle(const KeyInfo & keyinfo)
{
    return KEY_TO_HANDLE;
}

void PanelBase::RecvCanValue(unsigned char* msg, int size)
{
    unsigned char* message = new unsigned char[size];
    memcpy(message, msg, size);
    emit sig_recvCanValue(message, size);
}

void PanelBase::RecvIoValue(unsigned char* msg, int size)
{
    unsigned char* message = new unsigned char[size];
    memcpy(message, msg, size);
    emit sig_recvIoValue(message, size);
}

void PanelBase::slot_recvCanValue(unsigned char* msg, int size)
{
    if (msg)
    {
        GetCanState(msg, size);
        delete[]msg;
    }
}

void PanelBase::slot_recvIoValue(unsigned char* msg, int size)
{
    if (msg)
    {
        GetIoState(msg, size);
        delete[]msg;
    }
}

void PanelBase::GetCanState(unsigned char* msg, int size)
{
    ERROR("Wrong call!!! it should call derived class's GetCanState\n");    
}

void PanelBase::GetIoState(unsigned char* msg, int size)
{
    ERROR("Wrong call!!! it should call derived class's GetIoState\n");
}

void PanelBase::RecvMsg(unsigned char* msg, int size)
{
    ERROR("Wrong call!!! it should call derived class's RecvMsg\n");
}


bool PanelBase::DefaultTest(int id)
{
    ERROR("Wrong call!!! it should call derived class's DefaultTest\n");
    return false;
}

bool PanelBase::GetDefaultTestItem(int id, QString &retname, DefaultTestInfo &retinfo)
{
    ERROR("Wrong call!!! it should call derived class's GetDefaultTestItem\n");
    return false;
}

void PanelBase::InitDefaultTestList()
{
    PRINT("No need of config file for auto_default_test\n");
}

void PanelBase::slot_doDefaultTest()
{
    if (m_defaultTestTimer == nullptr)
    {
        return;
    }
    ENTER();

    //！Implement here
    QString name;
    DefaultTestInfo dtinfo;
    if (!GetDefaultTestItem(m_defaultTestIndex, name, dtinfo))
    {
        m_defaultTestTimer->stop();
        m_defaultTestTimer->deleteLater();
        m_defaultTestTimer = nullptr;
        PRINT("Reach the end, quit default test\n");
        return;
    }

    PRINT("name[%s]\n", name.toStdString().c_str());
    Page* page = GetPage(name);
    int newPageIndex = GetPageIndex(page);
    int curPageIndex = GetCurrentPageIndex();
    if (newPageIndex != -1)
    {
        if (curPageIndex != newPageIndex)
        {
            SetPageIndex(newPageIndex);
        }        
        m_pagelist[newPageIndex]->MoveToPos(name);
    }
    DefaultTest(m_defaultTestIndex);

    m_defaultTestIndex++;

    m_defaultTestTimer->start(dtinfo.seconds * 1000);
}

void PanelBase::StartDefaultTest()
{
    ENTER();
    InitDefaultTestList();

    //m_defaultTestFlag = true;
    m_defaultTestIndex = 0;
    m_defaultTestTimer = new QTimer(this);
    connect(m_defaultTestTimer, SIGNAL(timeout()), this, SLOT(slot_doDefaultTest()));
    m_defaultTestTimer->start(1000);
}

void PanelBase::StopDefaultTest()
{
    if  (m_defaultTestTimer == nullptr)
    {
        return;
    }
    ENTER();

    //m_defaultTestFlag = false;
    m_defaultTestTimer->stop();
    m_defaultTestTimer->deleteLater();
    m_defaultTestTimer = nullptr;
    m_defaultTestIndex = 0;
}

void PanelBase::RecvSVN(unsigned char* msg)
{
	//! This function is not related to UI operation
	ENTER();
	struct VerInfo
	{
		uint8_t eff;
		uint8_t a;
		uint8_t xx;
		uint8_t yy;
		uint16_t year;
		uint8_t month;
		uint8_t day;
	}__attribute__ ((packed)) verinfo;

	assert(sizeof(verinfo) == LEN_GET_SVN);
	memcpy(&verinfo, msg, LEN_GET_SVN);

	if (verinfo.eff == 0)
	{
	    //! Not detected
		m_verStr = "未检测";
		m_verStr = "";
	}
	else if(verinfo.eff == 2)
	{
		m_verStr = "版本错误";
	}
	else if(verinfo.eff == 1)
	{
		m_verStr = "V" + QString::number(verinfo.a); m_verStr += ".";
        QString xx;
        xx.sprintf("%02d", verinfo.xx);
        QString yy;
        yy.sprintf("%02d", verinfo.yy);		
		m_verStr += xx; m_verStr += ".";
		m_verStr += yy; m_verStr += "/";
		m_verStr += QString::number(verinfo.year); m_verStr += "年";
		m_verStr += QString::number(verinfo.month); m_verStr += "月";
		m_verStr += QString::number(verinfo.day); m_verStr += "日";
	}
	else
	{
		ERROR("unknown EFF\n");
	}
	PRINT("%s\n", m_verStr.toStdString().c_str());

	if (m_verTimer)
	{
		m_verTimer->stop();
		m_verTimer->deleteLater();
		m_verTimer = nullptr;
	}
	ShowVerInfo();
	if (verinfo.eff == 2 )
	{
		DoTest(false);
	}
}


void PanelBase::SwitchTest(bool onoff)
{
	PRINT("%s, funcode[%d]\n", onoff? "turn on":"turn off", (int)m_funcCode);
	QLabel* startbtn = FindStartBtn();
	unsigned char msg[1];
	if (onoff)
	{
		msg[0] = m_funcCode;
		Protocol::Instance()->SendMsg(CMD_CN_TEST, msg, 1);

		if (startbtn)
		{
    		PRINT("Start qtimer for 5 seconds\n");
    		m_verTimer = new QTimer(this);
    		m_verTimer->setSingleShot(true);
    		connect(m_verTimer, SIGNAL(timeout()), this, SLOT(slot_getVerTimeOut()));
    		m_verTimer->start(30000);
        }
	}
	else
	{
		if (m_verTimer)
		{
			m_verTimer->stop();
			m_verTimer->deleteLater();
			m_verTimer = nullptr;
		}
		Protocol::Instance()->SendMsg(CMD_CN_REST, msg, 0);
	}
}

void PanelBase::ShowVerInfo()
{
#define VER_STR_STYLE "font: 20px bold; color: rgb(215, 230, 254);"
	QLabel* startbtn = FindStartBtn();

	if (startbtn)
	{
    	int w = startbtn->width();
    	int h = startbtn->height();
    	m_ver = new QLabel(startbtn);
    	m_ver->setStyleSheet(VER_STR_STYLE);
    	m_ver->resize(w/3, h);
    	m_ver->move(w*2/3, 0);
    	m_ver->setText(m_verStr);
    	m_ver->show();
    }
}

void PanelBase::slot_getVerTimeOut()
{
	PRINT("Time out, Version Info is not got, Stop test, then exit\n");
	if (m_verTimer)
	{
		m_verTimer->stop();
		m_verTimer->deleteLater();
		m_verTimer = nullptr;
	}
	DoTest(false);
}

#if 0
void PanelBase::GenerateOutMsg(OutType outtyp, MsgInfo_out *info_array, int count, QString name, int val)
{
	if (count == 0)
	{
		return;
	}
	PRINT("Output[%d] name[%s] val[%d]\n", outtyp, name.toStdString().c_str(), val);
	
	for (int j = 0; j < count; j++)
	{
		if (name == info_array[j].name)
		{
			if (val < info_array[j].optNum)
			{
				info_array[j].val = val;
				if (info_array[j].name[0] && info_array[j].column != -1)
				{
					SetCell(info_array[j].name, info_array[j].column, info_array[j].valoption[val].valstr, info_array[j].valoption[val].valstrcolor);
				}
			}
			break;
		}
	}

	int bitcnt = 0;
	int bytecnt = 0;
	uint8_t msg[64];
	memset(msg, 0, sizeof(msg));
	for (int i = 0; i < count; i++)
	{
		msg[bytecnt] |= (uint8_t)info_array[i].val << (bitcnt%8);
		
		bitcnt += info_array[i].bit_num;
		bytecnt = bitcnt/8;
	}

#if 1
	PRINT("Output[%d] bytes[%d]: ", outtyp, bytecnt);
	for (int k = 0; k < bytecnt; k++)
	{
		printf("%02x ", msg[k]);
	}
	printf("\n");
#endif
	
	if (outtyp == TYPE_CAN)
	{
		Protocol::Instance()->SendMsg(CMD_CN_CMSG, msg, bytecnt);
	}
	else if (outtyp == TYPE_IO)
	{
		Protocol::Instance()->SendMsg(CMD_CN_EMSG, msg, bytecnt);
	}
}
#else
void PanelBase::GenerateOutMsg(OutType outtyp, MsgInfo_out *info_array, int count, const QString& name, int val)
{
#if 0
	if (count == 0)
	{
		return;
	}
	PRINT("Output[%d] name[%s] val[%d]\n", outtyp, name.toStdString().c_str(), val);
	
	for (int j = 0; j < count; j++)
	{
		if (name == info_array[j].name)
		{
			if (val < info_array[j].optNum)
			{
				info_array[j].val = val;
				if (info_array[j].name[0] && info_array[j].column != -1)
				{
					SetCell(info_array[j].name, info_array[j].column, info_array[j].valoption[val].valstr, info_array[j].valoption[val].valstrcolor);
				}
			}
			break;
		}
	}

	int bitcnt = 0;
	int bytecnt = 0;
	uint8_t msg[64];
	memset(msg, 0, sizeof(msg));
	for (int i = 0; i < count; i++)
	{
		msg[bytecnt] |= (uint8_t)info_array[i].val << (bitcnt%8);
		
		bitcnt += info_array[i].bit_num;
		bytecnt = bitcnt/8;
	}

#if 1
	PRINT("Output[%d] bytes[%d]: ", outtyp, bytecnt);
	for (int k = 0; k < bytecnt; k++)
	{
		printf("%02x ", msg[k]);
	}
	printf("\n");
#endif
	
	if (outtyp == TYPE_CAN)
	{
		Protocol::Instance()->SendMsg(CMD_CN_CMSG, msg, bytecnt);
	}
	else if (outtyp == TYPE_IO)
	{
		Protocol::Instance()->SendMsg(CMD_CN_EMSG, msg, bytecnt);
	}
#endif
}
#endif

#if 0
void PanelBase::SetIoOut(QString name, int val)
{
    ERROR("Wrong call!!! it should call derived class's SetIoOut\n");
}

void PanelBase::SetCanOut(QString name, int val)
{
    ERROR("Wrong call!!! it should call derived class's SetCanOut\n");
}

void PanelBase::SetValue(const QString& name, int val)
{
	PRINT("name: %s, val: %d\n", name.toStdString().c_str(), val);
	OutType type = CheckOutUnitType(name);
	if (type == TYPE_IO)
	{
		SetIoOut(name, val);
	}
	else if (type == TYPE_CAN)
	{
		SetCanOut(name, val);
	}
}
#else
void PanelBase::SetValue(const QString& name, int val)
{
    ERROR("Wrong call!!! it should call derived class's SetValue\n");
}

void PanelBase::SetSpecValue(const QString& name, int val, MsgInfo_out* msg_info_query, int query_num)
{
	PRINT("name: %s, val: %d\n", name.toStdString().c_str(), val);
	OutType type = CheckOutUnitType(name);
	for (int i = 0; i < query_num; i++)
	{
		if (name == msg_info_query[i].name)
		{
			MsgInfo_out& msgRef = msg_info_query[i];
			struct _cnDis
			{
				uint8_t funCode;
				uint8_t sock;
				uint8_t dip;		
			}__attribute__ ((packed)) cndis;

			cndis.funCode = m_funcCode;
			cndis.sock = (uint8_t)msgRef.sock;

			if (val >= msgRef.optNum)
			{
				ERROR("Wrong value[%d] is set\n", val);
				return;
			}
			auto &valOpt = msgRef.valoption[val];
			cndis.dip = (uint8_t)valOpt.dip;

			SetCell(name, msgRef.column, valOpt.valstr, valOpt.valstrcolor);
			uint8_t msg[LEN_CN_MSG];
			assert(LEN_CN_MSG == sizeof(msg));
			memcpy(msg, &cndis, sizeof(msg));
			PRINT("Send %d %d %d\n", (int)msg[0], (int)msg[1], (int)msg[2]);
			Protocol::Instance()->SendMsg(CMD_CN_DIS, msg, LEN_CN_MSG);
			return;
		}
	}

	ERROR("Setting item is not found from table!\n");
}

void PanelBase::SetSpecValue(int sock, int dip, MsgInfo_out* msg_info_query, int query_num)
{
    int index = sock - (int)'A';
    MsgInfo_out& msgRef = msg_info_query[index];
	PRINT("name: %s, val: %d\n", msgRef.name, dip);
	struct _cnDis
	{
		uint8_t funCode;
		uint8_t sock;
		uint8_t dip;		
	}__attribute__ ((packed)) cndis;

	cndis.funCode = m_funcCode;
	cndis.sock = (uint8_t)msgRef.sock;

    int i = 0;
    for (i = 0; i < msgRef.optNum; i++)
    {
        if (dip == msgRef.valoption[i].dip)
        {
            break;
        }
    }

	if (i >= msgRef.optNum)
	{
		ERROR("Wrong value[%d] is set\n", dip);
		return;
	}
	auto &valOpt = msgRef.valoption[i];
	cndis.dip = (uint8_t)valOpt.dip;

	SetCell(QString(msgRef.name), msgRef.column, valOpt.valstr, valOpt.valstrcolor);
	uint8_t msg[LEN_CN_MSG];
	assert(LEN_CN_MSG == sizeof(msg));
	memcpy(msg, &cndis, sizeof(msg));
	PRINT("Send %d %d %d\n", (int)msg[0], (int)msg[1], (int)msg[2]);
	Protocol::Instance()->SendMsg(CMD_CN_DIS, msg, LEN_CN_MSG);
	return;
}

#endif

OutType PanelBase::CheckOutUnitType(const QString& name)
{
    ERROR("Wrong call!!! it should call derived class's SendCanValue\n");

    return TYPE_UNKNOWN;
}


#if 0
void PanelBase::ShowState(unsigned char* msg, int msg_size, MsgInfo* msg_info_query, int query_num)
{
    PRINT("Use base[ShowState] function!!!\n");
    int bit_num = 0;
    int bit_offset = 0;
    int byte_order = 0;
    int val = 0;
    QString name("");
    QString val_str("");
    for(int i = 0; i < query_num; i++)
    {
        name = msg_info_query[i].name;
        int this_bit_num = msg_info_query[i].bit_num;
        if (this_bit_num <= 8)
        {
            val = (int)msg[byte_order];
            val >>= bit_offset;
            val &= ((1<<this_bit_num) - 1);
        }
        else if (this_bit_num == 16)
        {
            val = (int)msg[byte_order+1];
            val <<= 8;
            val |= (int)msg[byte_order];
        }
        val += msg_info_query[i].val_offset;
        //assert(val >= msg_info_query[i].val_min && val >= msg_info_query[i].val_max);
        if (val < msg_info_query[i].val_min || val > msg_info_query[i].val_max)
        {
            ERROR("Value[%d] is out of range!!!\n", val);
            
            bit_num += msg_info_query[i].bit_num;
            byte_order = bit_num/8;
            bit_offset = bit_num%8;
            continue;
        }

        bit_num += msg_info_query[i].bit_num;
        byte_order = bit_num/8;
        bit_offset = bit_num%8;

        //! Get Val String
        if(msg_info_query[i].type == DISPLAY_TYPE_STR)
        {
            val_str = msg_info_query[i].valoption[val].valstr;
        }
        else if(msg_info_query[i].type == DISPLAY_TYPE_INT)
        {
            val_str = QString::number(val);
        }
        else if(msg_info_query[i].type == DISPLAY_TYPE_RESERVED)
        {
            //! If reserverd, don't set table cell
            continue;
        }

        //! Set cell
        QColor color = WHITE;
        if(msg_info_query[i].type == DISPLAY_TYPE_INT)
            color = WHITE;
        else if(msg_info_query[i].type == DISPLAY_TYPE_STR)
            color = msg_info_query[i].valoption[val].valstrcolor;

        PRINT("%s: %s\n", name.toStdString().c_str(), val_str.toStdString().c_str());
		if (name.length() < 2)
		{
			continue;
		}
        SetCell(name, msg_info_query[i].column, val_str, color);
    }    
}
#else
#if 0
void PanelBase::ShowState(unsigned char* msg, int msg_size, MsgInfo* msg_info_query, int query_num)
{
	struct _getDis
	{
		uint8_t funCode;
		uint8_t sn;
		uint8_t dip;		
		uint8_t extra1;
		uint8_t extra2;
		uint8_t extra3;
	}__attribute__ ((packed)) getdis;
	getdis.extra1 = 0;
	getdis.extra2 = 0;
	getdis.extra3 = 0;
	memcpy(&getdis, msg, msg_size);
	if (getdis.funCode != m_funcCode)
	{
		ERROR("Wrong function code[%d], which should be %d\n", getdis.funCode, m_funcCode);
		return;
	}

	if (0 == getdis.sn && 7 == getdis.dip)
	{
		PRINT("Auto test started\n");
		m_autoFlag = true;
		return;
	}
	if (0 == getdis.sn && 8 == getdis.dip)
	{
		PRINT("Auto test stopped\n");
		m_autoFlag = false;
		return;
	}

    int val = (int)getdis.dip;
	uint32_t index = getdis.sn-1;
	if (index >= query_num)
	{
		ERROR("Wrong sn[%d]\n", getdis.sn);
		return;
	}

	MsgInfo &msgRef = msg_info_query[index];
	if (200 == getdis.dip)
	{
		val = (int)getdis.extra1;
	}
	else if(201 == getdis.dip)
	{
		val = FourCharsToUint(getdis.extra1, getdis.extra2, 0, 0);
	}
	else if(202 == getdis.dip)
	{
		val = FourCharsToUint(getdis.extra1, getdis.extra2, getdis.extra3, 0);
	}
	else
	{
		ERROR("Wrong dip[%d]\n", (int)getdis.dip);
	}

	val += msgRef.val_offset;
	if (val < msgRef.val_min || val > msgRef.val_max)
	{
		ERROR("value[%d] out of range!\n", val);
		return;
	}
	PRINT("Set value %d\n", val);

	//! Set cell
	//! name
	QString name(msgRef.name);

	//! val_str
	QString val_str("");
	if (0 == getdis.dip) //! If dip == 0, don't care offset
	{
		val_str = "";
	}
	else
	{
		if(msgRef.type == DISPLAY_TYPE_INT)
		{
			val_str = QString::number(val);
		}
		else if (msgRef.type == DISPLAY_TYPE_STR)
		{
			val_str = msgRef.valoption[val].valstr;
		}
	}
	PRINT("%s: %s\n", msgRef.name, val_str.toStdString().c_str());

	//! color
	QColor color = WHITE;
	if(msgRef.type == DISPLAY_TYPE_INT)
	{
		color = msgRef.valoption[0].valstrcolor;
	}
	else if(msgRef.type == DISPLAY_TYPE_STR)
	{
		color = msgRef.valoption[val].valstrcolor;
	}

	//! column
	int col = msgRef.column;
	
	if (name.length() < 2)
	{
		return;
	}
	SetCell(name, col, val_str, color);
}
#else
void PanelBase::ShowState(unsigned char* msg, int msg_size, MsgInfo* msg_info_query, int query_num)
{
	struct _getDis
	{
		uint8_t funCode;
		uint8_t sn;
		uint8_t dip;		
		uint8_t extra1;
		uint8_t extra2;
		uint8_t extra3;
	}__attribute__ ((packed)) getdis;
	getdis.extra1 = 0;
	getdis.extra2 = 0;
	getdis.extra3 = 0;
	memcpy(&getdis, msg, msg_size);
	if (getdis.funCode != m_funcCode)
	{
		ERROR("Wrong function code[%d], which should be %d\n", getdis.funCode, m_funcCode);
		return;
	}

	if (0 == getdis.sn && 13 == getdis.dip)
	{
		PRINT("Cmd: Page down\n");
        int pageindex = GetCurrentPageIndex();
        SetPageIndex(pageindex+1);
		return;
	}
	if (0 == getdis.sn && 7 == getdis.dip)
	{
		PRINT("Auto test started\n");
		m_autoFlag = true;
		return;
	}
	if (0 == getdis.sn && 8 == getdis.dip)
	{
		PRINT("Auto test stopped\n");
		m_autoFlag = false;
		StartDefaultTest();
		return;
	}
	if (0xff == getdis.sn && 0 == getdis.dip)
	{
		PRINT("sn[0xff], dip[0], clear all content\n");
		ResetDisplayContent();
		return;
	}

    int val = (int)getdis.dip;
	uint32_t index = getdis.sn-1;
	if (index >= query_num)
	{
		ERROR("Wrong sn[%d]\n", getdis.sn);
		return;
	}

	MsgInfo &msgRef = msg_info_query[index];
	if (200 == getdis.dip)
	{
		val = (int)getdis.extra1;
	}
	else if(201 == getdis.dip)
	{
		val = FourCharsToUint(getdis.extra1, getdis.extra2, 0, 0);
	}
	else if(202 == getdis.dip)
	{
		val = FourCharsToUint(getdis.extra1, getdis.extra2, getdis.extra3, 0);
	}

	PRINT("Set dip %d\n", (int)getdis.dip);

	//! Set cell
	//! name
	QString name(msgRef.name);
	#if 0 //! Auto page change, according to cell page
	Page* page = GetPage(name);
	PRINT("name[%s] belong to page: %p\n", name.toStdString().c_str(), page);
	for (uint32_t i = 0; i < m_pagelist.size(); i++)
	{
		
		if (page == m_pagelist[i])
		{
			SetPageIndex(i);
			break;
		}
	}
	#endif

	//! val_str
	QString val_str("");
	int valIndex = 0;
	if (0 == getdis.dip) //! If dip == 0, don't care offset
	{
		val_str = "";
	}
	else
	{
        if (msgRef.func)
        {
            val_str = msgRef.func(val);
        }
        else
        {
    		if(msgRef.type == DISPLAY_TYPE_INT)
    		{
    			val_str = QString::number(val + msgRef.offset);
    		}
    		else if (msgRef.type == DISPLAY_TYPE_STR)
    		{
    			if (msgRef.type == DISPLAY_TYPE_STR)
    			{
    				for (valIndex = 0; valIndex < VAL_OPT_MAX; valIndex++)
    				{
    					if (msgRef.valoption[valIndex].dip == getdis.dip)
    					{
    						break;
    					}
    				}
    				if (valIndex == VAL_OPT_MAX)
    				{
    					ERROR("Can't find registered dip[%d]\n", (int)getdis.dip);
    					return;
    				}
    			}

    			val_str = msgRef.valoption[valIndex].valstr;
    		}
		}
	}
	PRINT("%s: %s\n", msgRef.name, val_str.toStdString().c_str());

	//! color
	QColor color = WHITE;
	if(msgRef.type == DISPLAY_TYPE_INT)
	{
		color = msgRef.valoption[0].valstrcolor;
	}
	else if(msgRef.type == DISPLAY_TYPE_STR)
	{
		color = msgRef.valoption[valIndex].valstrcolor;
	}

	//! column
	int col = msgRef.column;
	if (name.length() < 2)
	{
		return;
	}
	SetCell(name, col, val_str, color);

}

#endif
#endif

uint32_t PanelBase::FourCharsToUint(uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4)
{
    uint32_t ret = 0;
    ret |= (uint32_t)c4;
    ret <<= 8;
    ret |= c3;
    ret <<= 8;
    ret |= c2;
    ret <<= 8;
    ret |= c1;

    return ret;
}

