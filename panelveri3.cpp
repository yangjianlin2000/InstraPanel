#include "panelveri3.h"
#include "protocol.h"


#define FRAME_CONFIRM_STYLE "border-image:url(:/res/res/image/frame_confirm.png);"

static QRect g_title_rect = QRect(0, 0, 800, 48);
#define TITLE_STYLE "background-color: rgb(5, 14, 42);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(163, 195, 255);\n" \
                    "border-image:url(:/res/res/image/title_veri3.png);\n"


#define KEY_STYLE1 "background-color: rgb(13, 25, 43);\n" \
                    "font: 20px bold;\n" \
                    "color: rgb(215, 230, 254);\n" \
                    "padding-left: 10px"
                    
#define KEY_STYLE2 "background-color: rgb(6, 17, 35);\n" \
                    "font: 20px bold;\n" \
                    "color: rgb(215, 230, 254);\n" \
                    "padding-left: 10px"

#define VAL_STYLE1 "background-color: rgb(13, 25, 43);\n" \
                    "font: 20px bold;\n"
                    
#define VAL_STYLE2 "background-color: rgb(6, 17, 35);\n" \
                    "font: 20px bold;\n"


/********************************* page1->table1 *********************************/
static const LabelInfo g_label_table1[][TAB_COL_NUM_MAX] =
{
    {{"IO_I34", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_I35", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"IO_I40", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_I41", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"IO_I48", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_I52", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"IO_I56", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_I58", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"IO_I59", KEY_STYLE1}, {"", VAL_STYLE1},},
};

static QPoint g_table1_pos = {0, 48};

static QSize g_table1_size[] =
{
    {99, 48},
    {99, 48},
};


/********************************* page1->table2 *********************************/
static const LabelInfo g_label_table2[][TAB_COL_NUM_MAX] =
{
    {{"IO_O30", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_O36", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"", KEY_STYLE1}, {"", VAL_STYLE1},},
};

static QPoint g_table2_pos = {200, 48};

static QSize g_table2_size[] =
{
    {99, 48},
    {99, 48},
};


/********************************* page1->table3 *********************************/
static const LabelInfo g_label_table3[][TAB_COL_NUM_MAX] =
{
    {{"RES3", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"DAC01", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"DAC02", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"DAC03", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"DAC04", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"DC24V 1", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"DC24V 2", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"", KEY_STYLE1}, {"", VAL_STYLE1},},
};

static QPoint g_table3_pos = {400, 48};

static QSize g_table3_size[] =
{
    {99, 48},
    {99, 48},
};

/********************************* page1->table4 *********************************/
static const LabelInfo g_label_table4[][TAB_COL_NUM_MAX] =
{
    {{"", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"", KEY_STYLE1}, {"", VAL_STYLE1},},
};


static QPoint g_table4_pos = {600, 48};

static QSize g_table4_size[] =
{
    {99, 48},
    {99, 48},
};


/********************************* page1->ui navigation map *****************************/
static const char* g_page1_map[][PAGE_NAVI_COL_MAX] =
{
    {"IO_O30", "RES3",   },
    {"IO_O36", "DAC01",  },
    {"",       "DAC02",  },
    {"",       "DAC03",  },
    {"",       "DAC04",  },
    {"",       "DC24V 1",},
    {"",       "DC24V 2",},
};


PanelVeri3::PanelVeri3(QWidget *parent) : PanelBase(parent)
{
	m_parent = parent;

    ENTER();
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("Veri3"));

    Page* page1 = new Page(this);
    page1->AddTitle(g_title_rect, TITLE_STYLE);
    Tab* table1 = new Tab(page1, 9, 2, g_label_table1, g_table1_pos, g_table1_size, 0);
    page1->AddTable(table1);
    Tab* table2 = new Tab(page1, 9, 2, g_label_table2, g_table2_pos, g_table2_size, 0);
    page1->AddTable(table2);
    Tab* table3 = new Tab(page1, 9, 2, g_label_table3, g_table3_pos, g_table3_size, 0);
    page1->AddTable(table3);
    Tab* table4 = new Tab(page1, 9, 2, g_label_table4, g_table4_pos, g_table4_size, 0);
    page1->AddTable(table4);
    page1->SetNaviMap(g_page1_map, 7, 2);
    AddToPageList(page1);
    CreateTableMap(table1, g_label_table1, 9);
    CreateTableMap(table2, g_label_table2, 2);
    CreateTableMap(table3, g_label_table3, 7);
    page1->CreateHlRect(200);

    Page* page2 = new Page(this);
    page2->AddTitle(QRect(0,0,800,480), FRAME_CONFIRM_STYLE);
    AddToPageList(page2);

    connect(this, SIGNAL(signal_shiftKeyChange(unsigned int)), m_parent, SLOT(slot_shiftKeyChange(unsigned int)), Qt::QueuedConnection);
    SetPageIndex(1);

    LEAVE();
}

KeyHandleState PanelVeri3::PreKeyHandle(const KeyInfo & keyinfo)
{
    ENTER();
    if (1 == GetCurrentPageIndex())
    {
        //! In page confirm, respond to ENTER only
        if (keyinfo.keyid == KEY_ENTER)
        {
            DoTest(true);
            SetPageIndex(0);
        }

        return KEY_HANDLED;
    }

    if (keyinfo.keyid == KEY_PAGE_UP || keyinfo.keyid == KEY_PAGE_DOWN)
    {
        //! Do not response to PAGE_UP or PAGE_DOWN
        return KEY_HANDLED;
    }

    return KEY_TO_HANDLE;
}

KeyHandleState PanelVeri3::keyEvent(const KeyInfo & keyinfo)
{
    ENTER();

    if (KEY_HANDLED == PanelBase::keyEvent(keyinfo))
    {
        return KEY_HANDLED;
    }

    if (keyinfo.keyid == KEY_TAP_POSITION)
    {
        emit signal_shiftKeyChange((unsigned int)keyinfo.data);
    }

    return KEY_TO_HANDLE;
}

////////////////////////////////////////////////////////////
static MsgInfo g_read_info_query[] =
{
    { 1, "IO_I34", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 2, "IO_I35", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 3, "IO_I40", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 4, "IO_I41", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 5, "IO_I48", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 6, "IO_I52", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 7, "IO_I56", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 8, "IO_I58", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 9, "IO_I59", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
};

void PanelVeri3::RecvMsg(unsigned char* msg, int size)
{
	ENTER();
    ShowState(msg, size, g_read_info_query, sizeof(g_read_info_query)/sizeof(g_read_info_query[0]));
}

static MsgInfo_out g_out_info[] =
{
    { 'A',   "IO_O30", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'B',   "IO_O36", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'C',   "RES3",   5, {{59,"无穷大", ORANGE}, { 64, "803Ω",  ORANGE}, {65, "1000Ω", ORANGE}, {66, "1385Ω", ORANGE}, {67, "1442Ω", ORANGE},}, 1 },
    { 'D',   "DAC01",  5, {{9, "0V"    , ORANGE}, {78, "2.44V",  ORANGE}, {79, "2.93V", ORANGE}, {80, "4.68V", ORANGE}, {81, "7.2V",  ORANGE},}, 1 },
    { 'E',   "DAC02",  5, {{9, "0V"    , ORANGE}, {82, "2.35V",  ORANGE}, {83, "2.66V", ORANGE}, {84, "5.28V", ORANGE}, {81, "7.2V",  ORANGE},}, 1 },
    { 'F',   "DAC03",  5, {{9, "0V"    , ORANGE}, {85, "2.4V",   ORANGE}, {86, "2.8V",  ORANGE}, {87, "4.2V",  ORANGE}, {81, "7.2V",  ORANGE},}, 1 },
    { 'G',   "DAC04",  5, {{9, "0V"    , ORANGE}, {88, "2.533V", ORANGE}, {89, "3.533V",ORANGE}, {87, "4.2V",  ORANGE}, {81, "7.2V",  ORANGE},}, 1 },
    { 'H',   "DC24V 1",2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'I',   "DC24V 2",2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
};

void PanelVeri3::SetValue(const QString& name, int val)
{
	ENTER();
	SetSpecValue(name, val, g_out_info, sizeof(g_out_info)/sizeof(g_out_info[0]));
}

OutType PanelVeri3::CheckOutUnitType(const QString& name)
{
	static QMap<QString, int> omap;
	if (omap.size() == 0)
	{
        omap["IO_O30"] = TYPE_OPT_OFFON;
        omap["IO_O36"] = TYPE_OPT_OFFON;
        omap["DC24V 1"] = TYPE_OPT_OFFON;
        omap["DC24V 2"] = TYPE_OPT_OFFON;

        omap["RES3"] = TYPE_OPT_TUNE;
        omap["DAC01"] = TYPE_OPT_TUNE;
        omap["DAC02"] = TYPE_OPT_TUNE;
        omap["DAC03"] = TYPE_OPT_TUNE;
        omap["DAC04"] = TYPE_OPT_TUNE;
	}

    auto iter = omap.find(name);
    if (iter == omap.end())
	{
		return TYPE_UNKNOWN;
	}

	int type = iter.value();
	PRINT("name[%s]'s type is %d\n", name.toStdString().c_str(), type);
	return (OutType)type;
}



