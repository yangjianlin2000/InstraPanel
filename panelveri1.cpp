#include "panelveri1.h"

#define FRAME_CONFIRM_STYLE "border-image:url(:/res/res/image/frame_confirm.png);"

static QRect g_title_rect = QRect(0, 0, 800, 48);
#define TITLE1_STYLE "background-color: rgb(5, 14, 42);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(163, 195, 255);\n" \
                    "border-image:url(:/res/res/image/title_veri1_1.png);\n"

#define TITLE2_STYLE "background-color: rgb(5, 14, 42);\n" \
                        "font: 24px bold;\n" \
                        "color: rgb(163, 195, 255);\n" \
                        "border-image:url(:/res/res/image/title_veri1_2.png);\n"


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
	{{"IO_I01", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_I02", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_I03", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_I04", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_I05", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_I06", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_I07", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_I08", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_I09", KEY_STYLE1}, {"", VAL_STYLE1},},
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
	{{"IO_I10", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_I11", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_I12", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_I13", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_I14", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_I15", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_I16", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_I17", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_I18", KEY_STYLE1}, {"", VAL_STYLE1},},
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
	{{"IO_I19", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_I20", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_I21", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_I22", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_I23", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_I24", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_I25", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_I26", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_I27", KEY_STYLE1}, {"", VAL_STYLE1},},
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
	{{"IO_I28", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_I29", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_I30", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_I31", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_I32", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_I33", KEY_STYLE2}, {"", VAL_STYLE2},},
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

/********************************* page2->table5 *********************************/
static const LabelInfo g_label_table5[][TAB_COL_NUM_MAX] =
{
	{{"IO_O01", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_O02", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_O03", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_O04", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_O05", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_O06", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_O07", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_O08", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_O09", KEY_STYLE1}, {"", VAL_STYLE1},},
};

static QPoint g_table5_pos = {0, 48};

static QSize g_table5_size[] =
{
    {99, 48},
    {99, 48},
};


/********************************* page2->table6 *********************************/
static const LabelInfo g_label_table6[][TAB_COL_NUM_MAX] =
{
	{{"IO_O10", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_O11", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_O12", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_O13", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_O14", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_O15", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_O16", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_O17", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_O18", KEY_STYLE1}, {"", VAL_STYLE1},},
};

static QPoint g_table6_pos = {200, 48};

static QSize g_table6_size[] =
{
    {99, 48},
    {99, 48},
};


/********************************* page2->table7 *********************************/
static const LabelInfo g_label_table7[][TAB_COL_NUM_MAX] =
{
	{{"IO_O19", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_O20", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_O21", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_O22", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_O23", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_O24", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_O25", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"IO_O26", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"IO_O27", KEY_STYLE1}, {"", VAL_STYLE1},},
};

static QPoint g_table7_pos = {400, 48};

static QSize g_table7_size[] =
{
    {99, 48},
    {99, 48},
};

/********************************* page2->table8 *********************************/
static const LabelInfo g_label_table8[][TAB_COL_NUM_MAX] =
{
	{{"IO_O28", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"", KEY_STYLE1}, {"", VAL_STYLE1},},
	{{"", KEY_STYLE2}, {"", VAL_STYLE2},},
	{{"", KEY_STYLE1}, {"", VAL_STYLE1},},
};

static QPoint g_table8_pos = {600, 48};

static QSize g_table8_size[] =
{
    {99, 48},
    {99, 48},
};

/********************************* page2->ui navigation map *****************************/
static const char* g_page2_map[][PAGE_NAVI_COL_MAX] =
{
    {"IO_O01", "IO_O10", "IO_O19", "IO_O28"},
    {"IO_O02", "IO_O11", "IO_O20", ""},
    {"IO_O03", "IO_O12", "IO_O21", ""},
    {"IO_O04", "IO_O13", "IO_O22", ""},
    {"IO_O05", "IO_O14", "IO_O23", ""},
    {"IO_O06", "IO_O15", "IO_O24", ""},
    {"IO_O07", "IO_O16", "IO_O25", ""},
    {"IO_O08", "IO_O17", "IO_O26", ""},
    {"IO_O09", "IO_O18", "IO_O27", ""},
};


PanelVeri1::PanelVeri1(QWidget *parent) : PanelBase(parent)
{
	m_parent = parent;

    ENTER();
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("Veri1"));

    Page* page1 = new Page(this);
    page1->AddTitle(g_title_rect, TITLE1_STYLE);
    Tab* table1 = new Tab(page1, 9, 2, g_label_table1, g_table1_pos, g_table1_size, 0);
    page1->AddTable(table1);
    Tab* table2 = new Tab(page1, 9, 2, g_label_table2, g_table2_pos, g_table2_size, 0);
    page1->AddTable(table2);
    Tab* table3 = new Tab(page1, 9, 2, g_label_table3, g_table3_pos, g_table3_size, 0);
    page1->AddTable(table3);
    Tab* table4 = new Tab(page1, 9, 2, g_label_table4, g_table4_pos, g_table4_size, 0);
    page1->AddTable(table4);
    AddToPageList(page1);
    CreateTableMap(table1, g_label_table1, 9);
    CreateTableMap(table2, g_label_table2, 9);
    CreateTableMap(table3, g_label_table3, 9);
    CreateTableMap(table4, g_label_table4, 6);

    Page* page2 = new Page(this);
    page2->AddTitle(g_title_rect, TITLE2_STYLE);
    Tab* table5 = new Tab(page2, 9, 2, g_label_table5, g_table5_pos, g_table5_size, 0);
    page2->AddTable(table5);
    Tab* table6 = new Tab(page2, 9, 2, g_label_table6, g_table6_pos, g_table6_size, 0);
    page2->AddTable(table6);
    Tab* table7 = new Tab(page2, 9, 2, g_label_table7, g_table7_pos, g_table7_size, 0);
    page2->AddTable(table7);
    Tab* table8 = new Tab(page2, 9, 2, g_label_table8, g_table8_pos, g_table8_size, 0);
    page2->AddTable(table8);
    page2->SetNaviMap(g_page2_map, 9, 4);
    AddToPageList(page2);
    CreateTableMap(table5, g_label_table5, 9);
    CreateTableMap(table6, g_label_table6, 9);
    CreateTableMap(table7, g_label_table7, 9);
    CreateTableMap(table8, g_label_table8, 1);
    page2->CreateHlRect(200);

    Page* page3 = new Page(this);
    page3->AddTitle(QRect(0,0,800,480), FRAME_CONFIRM_STYLE);
    AddToPageList(page3);

    connect(this, SIGNAL(signal_shiftKeyChange(unsigned int)), m_parent, SLOT(slot_shiftKeyChange(unsigned int)), Qt::QueuedConnection);
    SetPageIndex(2);
    
    LEAVE();
}

KeyHandleState PanelVeri1::PreKeyHandle(const KeyInfo & keyinfo)
{
    ENTER();
    if (2 == GetCurrentPageIndex())
    {
        //! In page confirm, respond to ENTER only
        if (keyinfo.keyid == KEY_ENTER)
        {
            SetPageIndex(0);
            DoTest(true);
        }

        return KEY_HANDLED;
    }

    if (keyinfo.keyid == KEY_PAGE_DOWN && 1 == GetCurrentPageIndex())
    {
        //! Do not response to PAGE_DOWN while curent page index is 1
        return KEY_HANDLED;
    }

    return KEY_TO_HANDLE;
}

KeyHandleState PanelVeri1::keyEvent(const KeyInfo & keyinfo)
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
    { 1, "IO_I01", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 2, "IO_I02", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 3, "IO_I03", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 4, "IO_I04", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 5, "IO_I05", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 6, "IO_I06", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 7, "IO_I07", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 8, "IO_I08", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    { 9, "IO_I09", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {10, "IO_I10", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {11, "IO_I11", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {12, "IO_I12", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {13, "IO_I13", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {14, "IO_I14", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {15, "IO_I15", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {16, "IO_I16", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {17, "IO_I17", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {18, "IO_I18", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {19, "IO_I19", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {20, "IO_I20", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {21, "IO_I21", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {22, "IO_I22", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {23, "IO_I23", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {24, "IO_I24", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {25, "IO_I25", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {26, "IO_I26", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {27, "IO_I27", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {28, "IO_I28", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {29, "IO_I29", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {30, "IO_I30", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {31, "IO_I31", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {32, "IO_I32", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
    {33, "IO_I33", { { 0, "", WHITE }, { 2, "关断", WHITE  }, { 1, "接通", GREEN }, }, DISPLAY_TYPE_STR,1 },
};

void PanelVeri1::RecvMsg(unsigned char* msg, int size)
{
	ENTER();
    ShowState(msg, size, g_read_info_query, sizeof(g_read_info_query)/sizeof(g_read_info_query[0]));
}

static MsgInfo_out g_out_info[] =
{
    { 'A',   "IO_O01", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'B',   "IO_O02", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'C',   "IO_O03", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'D',   "IO_O04", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'E',   "IO_O05", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'F',   "IO_O06", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'G',   "IO_O07", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'H',   "IO_O08", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'I',   "IO_O09", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'J',   "IO_O10", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'K',   "IO_O11", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'L',   "IO_O12", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'M',   "IO_O13", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'N',   "IO_O14", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'O',   "IO_O15", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'P',   "IO_O16", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'Q',   "IO_O17", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'R',   "IO_O18", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'S',   "IO_O19", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'T',   "IO_O20", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'U',   "IO_O21", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'V',   "IO_O22", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'W',   "IO_O23", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'X',   "IO_O24", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'Y',   "IO_O25", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'Z',   "IO_O26", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'Z'+1, "IO_O27", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'Z'+2, "IO_O28", 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
};

void PanelVeri1::SetValue(const QString& name, int val)
{
	ENTER();
	SetSpecValue(name, val, g_out_info, sizeof(g_out_info)/sizeof(g_out_info[0]));
}

OutType PanelVeri1::CheckOutUnitType(const QString& name)
{
	static QMap<QString, int> omap;
	if (omap.size() == 0)
	{
        omap["IO_O01"] = TYPE_OPT_OFFON;
        omap["IO_O02"] = TYPE_OPT_OFFON;
        omap["IO_O03"] = TYPE_OPT_OFFON;
        omap["IO_O04"] = TYPE_OPT_OFFON;
        omap["IO_O05"] = TYPE_OPT_OFFON;
        omap["IO_O06"] = TYPE_OPT_OFFON;
        omap["IO_O07"] = TYPE_OPT_OFFON;
        omap["IO_O08"] = TYPE_OPT_OFFON;
        omap["IO_O09"] = TYPE_OPT_OFFON;
        omap["IO_O10"] = TYPE_OPT_OFFON;
        omap["IO_O11"] = TYPE_OPT_OFFON;
        omap["IO_O12"] = TYPE_OPT_OFFON;
        omap["IO_O13"] = TYPE_OPT_OFFON;
        omap["IO_O14"] = TYPE_OPT_OFFON;
        omap["IO_O15"] = TYPE_OPT_OFFON;
        omap["IO_O16"] = TYPE_OPT_OFFON;
        omap["IO_O17"] = TYPE_OPT_OFFON;
        omap["IO_O18"] = TYPE_OPT_OFFON;
        omap["IO_O19"] = TYPE_OPT_OFFON;
        omap["IO_O20"] = TYPE_OPT_OFFON;
        omap["IO_O21"] = TYPE_OPT_OFFON;
        omap["IO_O22"] = TYPE_OPT_OFFON;
        omap["IO_O23"] = TYPE_OPT_OFFON;
        omap["IO_O24"] = TYPE_OPT_OFFON;
        omap["IO_O25"] = TYPE_OPT_OFFON;
        omap["IO_O26"] = TYPE_OPT_OFFON;
        omap["IO_O27"] = TYPE_OPT_OFFON;
        omap["IO_O28"] = TYPE_OPT_OFFON;
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


