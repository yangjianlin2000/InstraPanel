#include "panelveri2.h"
#include "protocol.h"

#define FRAME_CONFIRM_STYLE "border-image:url(:/res/res/image/frame_confirm.png);"

static QRect g_title_rect = QRect(0, 0, 800, 48);
#define TITLE_STYLE "background-color: rgb(5, 14, 42);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(163, 195, 255);\n" \
                    "border-image:url(:/res/res/image/title_veri2.png);\n"


#define KEY_STYLE1 "background-color: rgb(13, 25, 43);\n" \
                    "font: 20px bold;\n" \
                    "color: rgb(215, 230, 254);\n" \
                    "padding-left: 20px"
#define KEY_STYLE2 "background-color: rgb(6, 17, 35);\n" \
                    "font: 20px bold;\n" \
                    "color: rgb(215, 230, 254);\n" \
                    "padding-left: 20px"

#define VAL_STYLE1 "background-color: rgb(13, 25, 43);\n" \
                    "font: 20px bold;\n"
#define VAL_STYLE2 "background-color: rgb(6, 17, 35);\n" \
                    "font: 20px bold;\n"


/********************************* page1->table1 *********************************/
static const LabelInfo g_label_table1[][TAB_COL_NUM_MAX] =
{
    {{"IO_I36", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_I37", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"IO_I38", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_I39", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"IO_I42", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_I43", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"IO_I44", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_I45", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"IO_I46", KEY_STYLE1}, {"", VAL_STYLE1},},
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
    {{"IO_I47", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_I49", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"IO_I50", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_I51", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"IO_I53", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_I54", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"IO_I55", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_I57", KEY_STYLE2}, {"", VAL_STYLE2},},
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
    {{"IO_O29", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_O31", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"IO_O32", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_O33", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"IO_O34", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_O35", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"IO_O37", KEY_STYLE1}, {"", VAL_STYLE1},},
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
    {{"RES1", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"RES2", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"RES4", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"RES5", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"RES6", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"RES7", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"PWM01", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"PWM02", KEY_STYLE2}, {"", VAL_STYLE2},},
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
    {"IO_O29", "RES1", },
    {"IO_O31", "RES2", },
    {"IO_O32", "RES4", },
    {"IO_O33", "RES5", },
    {"IO_O34", "RES6", },
    {"IO_O35", "RES7", },
    {"IO_O37", "PWM01" },
    {"",       "PWM02" },
};


PanelVeri2::PanelVeri2(QWidget *parent) : PanelBase(parent)
{
	m_parent = parent;

    ENTER();
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("Veri2"));

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
    page1->SetNaviMap(g_page1_map, 8, 2);
    AddToPageList(page1);
    CreateTableMap(table1, g_label_table1, 9);
    CreateTableMap(table2, g_label_table2, 8);
    CreateTableMap(table3, g_label_table3, 7);
    CreateTableMap(table4, g_label_table4, 8);
    page1->CreateHlRect(200);

    Page* page2 = new Page(this);
    page2->AddTitle(QRect(0,0,800,480), FRAME_CONFIRM_STYLE);
    AddToPageList(page2);

    connect(this, SIGNAL(signal_shiftKeyChange(unsigned int)), m_parent, SLOT(slot_shiftKeyChange(unsigned int)), Qt::QueuedConnection);
    SetPageIndex(1);

    LEAVE();
}

KeyHandleState PanelVeri2::PreKeyHandle(const KeyInfo & keyinfo)
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

KeyHandleState PanelVeri2::keyEvent(const KeyInfo & keyinfo)
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
    { 1, "IO_I36", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 2, "IO_I37", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 3, "IO_I38", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 4, "IO_I39", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 5, "IO_I42", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 6, "IO_I43", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 7, "IO_I44", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 8, "IO_I45", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 9, "IO_I46", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {10, "IO_I47", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {11, "IO_I49", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {12, "IO_I50", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {13, "IO_I51", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {14, "IO_I53", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {15, "IO_I54", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {16, "IO_I55", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {17, "IO_I57", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
};

void PanelVeri2::RecvMsg(unsigned char* msg, int size)
{
	ENTER();
    ShowState(msg, size, g_read_info_query, sizeof(g_read_info_query)/sizeof(g_read_info_query[0]));
}

static MsgInfo_out g_out_info[] =
{
    { 'A',   "IO_O29", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'B',   "IO_O31", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'C',   "IO_O32", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'D',   "IO_O33", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'E',   "IO_O34", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'F',   "IO_O35", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'G',   "IO_O37", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },

    { 'H',   "RES1",  5, {{59, "无穷大", ORANGE}, {60, "3353Ω", ORANGE}, {61, "3070Ω", ORANGE}, {62, "2185Ω", ORANGE}, {63, "2012Ω", ORANGE}, }, 1},
    { 'I',   "RES2",  5, {{59, "无穷大", ORANGE}, {64, "803Ω", ORANGE}, {65, "1000Ω", ORANGE}, {66, "1385Ω", ORANGE}, {67, "1442Ω", ORANGE}, }, 1},
    { 'J',   "RES4",  5, {{59, "无穷大", ORANGE}, {60, "3353Ω", ORANGE}, {61, "3070Ω", ORANGE}, {62, "2185Ω", ORANGE}, {63, "2012Ω", ORANGE}, }, 1},
    { 'K',   "RES5",  5, {{59, "无穷大", ORANGE}, {64, "803Ω", ORANGE}, {65, "1000Ω", ORANGE}, {66, "1385Ω", ORANGE}, {67, "1442Ω", ORANGE}, }, 1},
    { 'L',   "RES6",  5, {{59, "无穷大", ORANGE}, {64, "803Ω", ORANGE}, {65, "1000Ω", ORANGE}, {66, "1385Ω", ORANGE}, {67, "1442Ω", ORANGE}, }, 1},
    { 'M',   "RES7",  5, {{59, "无穷大", ORANGE}, {64, "803Ω", ORANGE}, {65, "1000Ω", ORANGE}, {68, "1610Ω", ORANGE}, {69, "2505Ω", ORANGE}, }, 1},
    { 'N',   "PWM01", 5, {{2, "关断", ORANGE}, {70, "2930Hz", ORANGE}, {71, "3480Hz", ORANGE}, {72, "5000Hz", ORANGE}, {73, "5910Hz", ORANGE}, }, 1},
    { 'O',   "PWM02", 5, {{2, "关断", ORANGE}, {74, "2880Hz", ORANGE}, {75, "3690Hz", ORANGE}, {76, "4970Hz", ORANGE}, {73, "5910Hz", ORANGE}, }, 1},
};

void PanelVeri2::SetValue(const QString& name, int val)
{
	ENTER();
	SetSpecValue(name, val, g_out_info, sizeof(g_out_info)/sizeof(g_out_info[0]));
}

OutType PanelVeri2::CheckOutUnitType(const QString& name)
{
	static QMap<QString, int> omap;
	if (omap.size() == 0)
	{
        omap["IO_O29"] = TYPE_OPT_OFFON;
        omap["IO_O31"] = TYPE_OPT_OFFON;
        omap["IO_O32"] = TYPE_OPT_OFFON;
        omap["IO_O33"] = TYPE_OPT_OFFON;
        omap["IO_O34"] = TYPE_OPT_OFFON;
        omap["IO_O35"] = TYPE_OPT_OFFON;
        omap["IO_O37"] = TYPE_OPT_OFFON;

        omap["RES1"] = TYPE_OPT_TUNE;
        omap["RES2"] = TYPE_OPT_TUNE;
        omap["RES4"] = TYPE_OPT_TUNE;
        omap["RES5"] = TYPE_OPT_TUNE;
        omap["RES6"] = TYPE_OPT_TUNE;
        omap["RES7"] = TYPE_OPT_TUNE;
        omap["PWM01"] = TYPE_OPT_TUNE;
        omap["PWM02"] = TYPE_OPT_TUNE;
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



