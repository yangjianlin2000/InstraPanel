#include "common.h"
#include "table.h"
#include "instrpanel_zdc.h"


#define KEY_STYLE1 "background-color: rgb(13, 25, 43);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(215, 230, 254);\n" \
                    "padding-left: 0px"
                    
#define KEY_STYLE2 "background-color: rgb(6, 17, 35);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(215, 230, 254);\n" \
                    "padding-left: 0px"
                    
#define VAL_STYLE1 "background-color: rgb(13, 25, 43);\n" \
                    "font: 24px bold;\n"
                    
                    
#define VAL_STYLE2 "background-color: rgb(6, 17, 35);\n" \
                    "font: 24px bold;\n"


#define NONE_STYLE1 "background-color: rgb(13, 25, 43);\n" \
                    "font: 24px bold;\n" \
					"color: rgb(215, 230, 254);"

#define NONE_STYLE2 "background-color: rgb(6, 17, 35);\n" \
                    "font: 24px bold;\n" \
					"color: rgb(215, 230, 254);"


static QRect g_title_rect = QRect(0, 0, 800, 86);

/********************************* page1->title *********************************/
#define TITLE1_STYLE "border-image:url(:/res/res/image/title_zdc1.png);\n"


/********************************* page1->table1 *********************************/
static const LabelInfo g_label_table1[][TAB_COL_NUM_MAX] =
{
    {{"后排水泵",        KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}},
    {{"枪镜 射手观察镜", KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}},
    {{"通话控制盒",      KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}},
    {{"刹车灯",          KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}},
    {{"倒车灯",          KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}},
    {{"右后转向灯",      KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}},
    {{"精电地1",         KEY_STYLE1}, {"", VAL_STYLE1}, { "——", NONE_STYLE1}},
    {{"精电地2",         KEY_STYLE2}, {"", VAL_STYLE2}, { "——", NONE_STYLE2}},
    {{"",                KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}},
};

static QPoint g_table1_pos = {0, 86};

static QSize g_table1_size[3] =
{
    {168, 40},
    {112, 40},
    {116, 40}
};

/********************************* page1->table2 *********************************/
static const LabelInfo g_label_table2[][TAB_COL_NUM_MAX] =
{
    {{"左后转向灯",   KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}},
    {{"后示廓灯",     KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}},
    {{"暖风机",       KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}},
    {{"电台1",        KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}},
    {{"电台2",        KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}},
    {{"",             KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}},
    {{"精电地3",      KEY_STYLE1}, {"", VAL_STYLE1}, { "——", NONE_STYLE1}},
    {{"",             KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}},
    {{"",             KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}},
};

static QPoint g_table2_pos = {403, 86};

static QSize g_table2_size[3] =
{
    {168, 40},
    {112, 40},
    {116, 40}
};

static const char* g_page1_map[][PAGE_NAVI_COL_MAX] =
{
    {"后排水泵",        "左后转向灯"},
    {"枪镜 射手观察镜", "后示廓灯"  },
    {"通话控制盒",      "暖风机"    },
    {"刹车灯",          "电台1"     },
    {"倒车灯",          "电台2"     },
    {"右后转向灯",      ""          },
    {"精电地1",         "精电地3"   },
    {"精电地2",         "精电地2"          },
};

/********************************* page1->start button *****************************/
static QRect g_start_rect = QRect(0, 432, 800, 40);
#define BUTTON_STYLE "background-color: rgb(31, 49, 87);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(255, 255, 255);\n"



/********************************* page2->title *********************************/
#define TITLE2_STYLE "border-image:url(:/res/res/image/title_zdc2.png);\n"


/********************************* page2->table3 *********************************/
static const LabelInfo g_label_table3[10][TAB_COL_NUM_MAX] =
{
    {{"毒剂报警",     KEY_STYLE1}, {"——", NONE_STYLE1}, { "", VAL_STYLE1}, { "——", NONE_STYLE1}},
    {{"低辐射报警",   KEY_STYLE2}, {"——", NONE_STYLE2}, { "", VAL_STYLE2}, { "——", NONE_STYLE2}},
    {{"高辐射报警",   KEY_STYLE1}, {"——", NONE_STYLE1}, { "", VAL_STYLE1}, { "——", NONE_STYLE1}},
    {{"三防应急",     KEY_STYLE2}, {"——", NONE_STYLE2}, { "", VAL_STYLE2}, { "——", NONE_STYLE2}},
    {{"",             KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}, { "", VAL_STYLE1}},
    {{"后门开关",     KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}, { "", VAL_STYLE2}},
    {{"主油量(V)",    KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}, { "", VAL_STYLE1}},
    {{"后油量(V)",    KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}, { "", VAL_STYLE2}},
    {{"主油量地",     KEY_STYLE1}, {"", VAL_STYLE1}, { "——", NONE_STYLE1}, { "——", NONE_STYLE1}},
    {{"后油量地",     KEY_STYLE2}, {"", VAL_STYLE2}, { "——", NONE_STYLE2}, { "——", NONE_STYLE2}},
};

static QPoint g_table3_pos = {0, 86};

static QSize g_table3_size[4] =
{
    {176, 40},
    {74,  40},
    {74,  40},
    {70,  40},
};

/********************************* page2->table4 *********************************/
static const LabelInfo g_label_table4[10][TAB_COL_NUM_MAX] =
{
    {{"后转换接触器",   KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}, { "", VAL_STYLE1}},
    {{"后进排气扇电机", KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}, { "", VAL_STYLE2}},
    {{"后关闭体电磁阀", KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}, { "", VAL_STYLE1}},
    {{"制氧机",         KEY_STYLE2}, {"——", NONE_STYLE2}, { "", VAL_STYLE2}, { "", VAL_STYLE2}},
    {{"",               KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}, { "", VAL_STYLE1}},
    {{"",               KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}, { "", VAL_STYLE2}},
    {{"蓄电池温度",       KEY_STYLE1}, {"", VAL_STYLE1}, { "——", NONE_STYLE1}, { "", VAL_STYLE1}},
    {{"蓄电池电压(V)",  KEY_STYLE2}, {"", VAL_STYLE2}, { "——", NONE_STYLE2}, { "——", NONE_STYLE2}},
    {{"蓄电池加温",     KEY_STYLE1}, {"——", NONE_STYLE1}, { "", VAL_STYLE1}, { "", VAL_STYLE1}},
    {{"",               KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}, { "", VAL_STYLE2}},
};

static QPoint g_table4_pos = {404, 86};

static QSize g_table4_size[4] =
{
    {176, 40},
    {74,  40},
    {74,  40},
    {70,  40},
};

static const char* g_page2_map[][PAGE_NAVI_COL_MAX] =
{
    {"毒剂报警",   "后转换接触器"  },
    {"低辐射报警", "后进排气扇电机"},
    {"高辐射报警", "后关闭体电磁阀"},
    {"三防应急",   "制氧机"        },
    {"后门开关",   ""              },
    {"主油量(V)",  "蓄电池温度"     },
    {"后油量(V)",  "蓄电池电压(V)" },
    {"主油量地",   "蓄电池加温"    },
    {"后油量地",   "后油量地"      }
};


InstrPanel_ZDC::InstrPanel_ZDC(QWidget *parent) : PanelBase(parent)
{
#if 0
    ENTER();
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("ZDC"));

    Page* page1 = new Page(this);
    page1->AddTitle(g_title_rect, TITLE1_STYLE);
    page1->AddTable(9, 3, g_label_table1, g_table1_pos, g_table1_size);
    page1->AddTable(9, 3, g_label_table2, g_table2_pos, g_table2_size);
    AddToPageList(page1);

    Page* page2 = new Page(this);
    page2->AddTitle(g_title_rect, TITLE2_STYLE);
    page2->AddTable(10, 4, g_label_table3, g_table3_pos, g_table3_size);
    page2->AddTable(10, 4, g_label_table4, g_table4_pos, g_table4_size);
    AddToPageList(page2);

    page1->SetButton(g_start_rect, BUTTON_STYLE);

    SetPageIndex(0);

    LEAVE();
#else
    ENTER();
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("ZDC"));

    Page* page1 = new Page(this);
    page1->AddTitle(g_title_rect, TITLE1_STYLE);
    Tab* table1 = new Tab(page1, 9, 3, g_label_table1, g_table1_pos, g_table1_size);
    page1->AddTable(table1);
    Tab* table2 = new Tab(page1, 9, 3, g_label_table2, g_table2_pos, g_table2_size);
    page1->AddTable(table2);
    page1->SetButton(g_start_rect, BUTTON_STYLE);
    //page1->SetNaviMap(g_page1_map, 8, 2);
    AddToPageList(page1);
    CreateTableMap(table1, g_label_table1, 9);
    CreateTableMap(table2, g_label_table2, 9);
    page1->CreateHlRect(398);

    Page* page2 = new Page(this);
    page2->AddTitle(g_title_rect, TITLE2_STYLE);
    Tab* table3 = new Tab(page2, 10, 4, g_label_table3, g_table3_pos, g_table3_size);
    page2->AddTable(table3);
    Tab* table4 = new Tab(page2, 10, 4, g_label_table4, g_table4_pos, g_table4_size);
    page2->AddTable(table4);
    page2->SetNaviMap(g_page2_map, 9, 2);
    AddToPageList(page2);
    CreateTableMap(table3, g_label_table3, 10);
    CreateTableMap(table4, g_label_table4, 10);
    page2->CreateHlRect(398);

    SetPageIndex(0);

    LEAVE();
#endif
}


////////////////////////////////////////////////////////////
static MsgInfo g_read_info_query[] =
{
	{1, "后排水泵", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 1},
	{2, "枪镜 射手观察镜", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 1},
	{3, "通话控制盒", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 1},
	{4, "刹车灯", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 1},
	{5, "倒车灯", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 1},
	{6, "右后转向灯", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 1},

	{7, "精电地1", {{0, "", NONE}, {1, "接通", GREEN},{2, "关断", RED}, }, DISPLAY_TYPE_STR, 1},
	{8, "精电地2", {{0, "", NONE}, {1, "接通", GREEN},{2, "关断", RED}, }, DISPLAY_TYPE_STR, 1},

	{9, "后排水泵", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 2},
	{10, "枪镜 射手观察镜", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 2},
	{11, "通话控制盒", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 2},
	{12, "刹车灯", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 2},
	{13, "倒车灯", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 2},
	{14, "右后转向灯", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 2},	

	{15, "左后转向灯", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 1},
	{16, "后示廓灯", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 1},
	{17, "暖风机", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 1},
	{18, "电台1", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 1},
	{19, "电台2", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 1},
	{20, "精电地3", {{0, "", NONE}, {1, "接通", GREEN},{2, "关断", RED}, }, DISPLAY_TYPE_STR, 1},

	{21, "左后转向灯", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 2},
	{22, "后示廓灯", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 2},
	{23, "暖风机", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 2},
	{24, "电台1", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 2},
	{25, "电台2", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 2},

	{26, "后门开关", {{0, "", NONE}, {9, "0V", RED}, {11, "24V", GREEN}, }, DISPLAY_TYPE_STR, 1},
	{27, "主油量(V)", {{0, "", NONE}, {9, "0V", RED},{10, "12V", GREEN}, }, DISPLAY_TYPE_STR, 1},
	{28, "后油量(V)", {{0, "", NONE}, {9, "0V", RED},{10, "12V", GREEN}, }, DISPLAY_TYPE_STR, 1},
	{29, "主油量地", {{0, "", NONE}, {9, "0V", GREEN}, {11, "24V", RED},}, DISPLAY_TYPE_STR, 1},
	{30, "后油量地", {{0, "", NONE}, {9, "0V", GREEN}, {11, "24V", RED},}, DISPLAY_TYPE_STR, 1},

	{31, "后门开关", {{0, "", NONE}, {5, "打开", YELLOW},{6, "关闭", YELLOW}, }, DISPLAY_TYPE_STR, 3},
	{32, "主油量(V)", {{0, "", GREEN}, }, DISPLAY_TYPE_INT, 3},
	{33, "后油量(V)", {{0, "", GREEN}, }, DISPLAY_TYPE_INT, 3},

	{34, "后转换接触器", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, }, DISPLAY_TYPE_STR, 2},
	{35, "后进排气扇电机", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, }, DISPLAY_TYPE_STR, 2},
	{36, "后关闭体电磁阀", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, }, DISPLAY_TYPE_STR, 2},
	{37, "制氧机", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, }, DISPLAY_TYPE_STR, 2},

	{38, "蓄电池加温", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, }, DISPLAY_TYPE_STR, 2},

	{39, "后转换接触器", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 3},
	{40, "后进排气扇电机", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 3},
	{41, "后关闭体电磁阀", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 3},
	{42, "制氧机",        {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 3},

	{43, "蓄电池温度", {{0, "", GREEN}, }, DISPLAY_TYPE_INT, 3},
	{44, "蓄电池加温", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, }, DISPLAY_TYPE_STR, 3}
};

void InstrPanel_ZDC::RecvMsg(unsigned char* msg, int size)
{
	ENTER();
    ShowState(msg, size, g_read_info_query, sizeof(g_read_info_query)/sizeof(g_read_info_query[0]));
}

static MsgInfo_out g_out_info[] =
{
	{'A', "毒剂报警", 2,		 { {1, "接通", ORANGE}, {2, "关断", ORANGE},		},	2},
	{'B', "低辐射报警", 2,        { {1, "接通", ORANGE}, {2, "关断", ORANGE},		},  2},
	{'C', "高辐射报警", 2,        { {1, "接通", ORANGE}, {2, "关断", ORANGE},		},  2},
	{'D', "三防应急",       2,   { {1, "接通", ORANGE}, {2, "关断", ORANGE},		},	2},
	{'E', "后门开关",		2,   { {5, "打开", ORANGE}, {6, "关闭", ORANGE},		},  2},
	{'F', "主油量(V)",     5, {{2, "关断", ORANGE}, {19, "8L", ORANGE}, {20, "88L", ORANGE}, {21, "226L", ORANGE}, {22, "276L", ORANGE},},  2},
	{'G', "后油量(V)",	    5, {{2, "关断", ORANGE}, {23, "14L",ORANGE}, {24, "167L",ORANGE}, {25, "373L", ORANGE}, {26, "525L", ORANGE},},  2},
	{'H', "后转换接触器",	3,        {{2, "关断", ORANGE}, {39,"进气",ORANGE},{40, "排气", ORANGE},},	1},
	{'I', "后进排气扇电机", 3,  {{2, "关断", ORANGE}, {39,"进气",ORANGE},{40, "排气", ORANGE},}, 1},
	{'J', "后关闭体电磁阀", 2,  { {1, "接通", ORANGE}, {2, "关断", ORANGE},		}, 1},
	{'K', "蓄电池温度", 5,	{{2, "关断", ORANGE},	{29, "4°C", 	ORANGE}, {30, "8°C", 	ORANGE}, {31, "15°C", 	ORANGE}, {32, "17°C", 	ORANGE},  },  1},
	{'L', "蓄电池电压(V)", 2,  {{12, "28V", ORANGE},   {9, "0V",		ORANGE},   },  1},
};

void InstrPanel_ZDC::SetValue(const QString& name, int val)
{
	ENTER();
	if (name == "后转换接触器" || name == "后进排气扇电机")
	{
		SetSpecValue("后转换接触器", val, g_out_info, sizeof(g_out_info)/sizeof(g_out_info[0]));
		SetSpecValue("后进排气扇电机", val, g_out_info, sizeof(g_out_info)/sizeof(g_out_info[0]));
	}
	else
	{
		SetSpecValue(name, val, g_out_info, sizeof(g_out_info)/sizeof(g_out_info[0]));
	}
}

OutType InstrPanel_ZDC::CheckOutUnitType(const QString& name)
{
	static QMap<QString, int> omap;
	if (omap.size() == 0)
	{
		omap["主油量(V)"]     = TYPE_OPT_TUNE;
		omap["后油量(V)"]     = TYPE_OPT_TUNE;
		omap["后转换接触器"]     = TYPE_OPT_TUNE;
		omap["后进排气扇电机"] = TYPE_OPT_TUNE;
		omap["蓄电池温度"] = TYPE_OPT_TUNE;
		
		omap["后门开关"]	   = TYPE_OPT_OFFON;
		omap["毒剂报警"]       = TYPE_OPT_OFFON;
		omap["低辐射报警"]      = TYPE_OPT_OFFON;
		omap["高辐射报警"]      = TYPE_OPT_OFFON;
		omap["三防应急"]       = TYPE_OPT_OFFON;
		omap["蓄电池电压"] =      TYPE_OPT_OFFON;
		omap["后关闭体电磁阀"] = TYPE_OPT_OFFON;
		omap["蓄电池电压(V)"] = TYPE_OPT_OFFON;
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

#if 0
static MsgInfo g_can_read_info_query[] =
{
    {4,	0, 5,	0, "后排水泵", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "枪镜 射手观察镜", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "通话控制盒", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "刹车灯", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "倒车灯", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "右后转向灯", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "左后转向灯", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "后示廓灯", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "暖风机", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "电台1", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "电台2", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "后转换接触器", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 3},
    {4,	0, 5,	0, "后进排气扇电机", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 3},
    {4,	0, 5,	0, "后关闭体电磁阀", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 3},
    {4,	0, 5,	0, "制氧机", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 3},
    {4,	0, 5,	0, "蓄电池加温", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 3},
    {1,	0, 1,	0, "后门开关", {{"后门关闭", GREEN}, {"后门未关", RED},}, DISPLAY_TYPE_STR, 3},
    {7,	0, 0,	0, "",{}, DISPLAY_TYPE_RESERVED, 2},
    {16,0, 530,	0, "后油量(V)",{}, DISPLAY_TYPE_INT, 3},
    {8,	0, 250,	0, "主油量(V)",{}, DISPLAY_TYPE_INT, 3},
    {8,	50, 70,	-50, "蓄电池温度",{}, DISPLAY_TYPE_INT, 3},
};

void InstrPanel_ZDC::GetCanState(unsigned char* msg, int msg_size)
{
    ShowState(msg, msg_size, g_can_read_info_query, sizeof(g_can_read_info_query)/sizeof(g_can_read_info_query[0]));
}

static MsgInfo g_io_read_info_query[] =
{
    {1, 0, 1,	0, "后门开关",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
    {1, 0, 1,	0, "后关闭体电磁阀",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 2},
	{1, 0, 1,	0, "后进排气扇电机",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 2},
	{1, 0, 1,	0, "右后转向灯",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "电台1",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "电台2",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, -1},
	{1, 0, 1,	0, "后转换接触器",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 2},

	{1, 0, 1,	0, "通话控制盒",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "倒车灯",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "刹车灯",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "后示廓灯",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "左后转向灯",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "枪镜 射手观察镜",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "制氧机",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 2},
	{1, 0, 1,	0, "蓄电池加温",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 2},

	{1, 0, 1,	0, "后排水泵",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "暖风机",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "精电地1",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "精电地2",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "精电地3",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, -1},
	{1, 0, 1,	0, "主油量地",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "后油量地",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},

	{1, 0, 1,	0, "主油量(V)",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "后油量(V)",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{6, 0, 1,	0, "",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, -1},
};

void InstrPanel_ZDC::GetIoState(unsigned char* msg, int msg_size)
{
    ShowState(msg, msg_size, g_io_read_info_query, sizeof(g_io_read_info_query)/sizeof(g_io_read_info_query[0]));
}

OutType InstrPanel_ZDC::CheckOutUnitType(QString name)
{
	static QMap<QString, int> map;
	if (map.size() == 0)
	{
		map["主电源输出"] = TYPE_IO;
		map["DC24V输入1"] = TYPE_IO;
		map["后门开关"]       = TYPE_IO;
		map["主油量(V)"]     = TYPE_IO;
		map["后油量(V)"]     = TYPE_IO;
		map["感温塞信号"] = TYPE_IO;

		map["后关闭体电磁阀"] = TYPE_CAN;
		map["毒剂报警"]       = TYPE_CAN;
		map["低辐射报警"]      = TYPE_CAN;
		map["高辐射报警"]      = TYPE_CAN;
		map["三防应急"]       = TYPE_CAN;
		map["蓄电池电压"] =      TYPE_CAN;
	}

	int type = map[name];
	PRINT("name[%s]'s type is %d\n", name.toStdString().c_str(), type);
	return (OutType)type;
}

static MsgInfo_out g_io_out_info[] =
{
	{8, 0, "主电源输出", 2, {{"关闭", RED}, {"打开", GREEN}, }, -1},
	{8, 0, "DC24V输入1", 2, {{"关闭", RED}, {"打开", GREEN}, }, -1},
	{8, 0, "后门开关",       2, {{"关闭", RED}, {"打开", GREEN}, },  2},
	{8, 0, "主油量(V)",	 5, {{"关闭", RED}, {"2930Hz", GREEN}, {"3480Hz", GREEN}, {"5000Hz", GREEN}, {"5910Hz", GREEN},},  2},
	{8, 0, "后油量(V)",	 5, {{"关闭", RED}, {"2880Hz", GREEN}, {"3690Hz", GREEN}, {"4970Hz", GREEN}, {"5910Hz", GREEN},},  2},
	{8, 0, "感温塞信号",	5, {{"无穷大",RED},{"3353Ω", GREEN},  {"3070", GREEN},   {"2185Ω",          GREEN}, {"2012Ω",  GREEN},},  2},
};

void InstrPanel_ZDC::SetIoOut(QString name, int val)
{
	GenerateOutMsg(TYPE_IO, g_io_out_info, sizeof(g_io_out_info)/sizeof(g_io_out_info[0]), name, val);
}

static MsgInfo_out g_can_out_info[] =
{
	{1, 0, "后进气开关", 2,  {{"关闭", RED}, {"打开", GREEN}, }, -1},
	{1, 0, "后排气开关", 2,  {{"关闭", RED}, {"打开", GREEN}, }, -1},
	{1, 0, "后关闭体电磁阀", 2,{{"关闭", RED}, {"打开", GREEN}, },  1},
	{1, 0, "毒剂报警", 2,        {{"正常", GREEN}, {"报警", RED},       },  2},
	{1, 0, "低辐射报警", 2,  {{"正常", GREEN}, {"报警", RED},   },  2},
	{1, 0, "高辐射报警", 2,  {{"正常", GREEN}, {"报警", RED},   },  2},
	{1, 0, "三防应急", 2,        {{"关闭", RED}, {"打开", GREEN},       },	2},
	{1, 0, "蓄电池电压", 2,  {{"0V", RED},   {"28V",       GREEN},   },  1},
};

void InstrPanel_ZDC::SetCanOut(QString name, int val)
{
	GenerateOutMsg(TYPE_CAN, g_can_out_info, sizeof(g_can_out_info)/sizeof(g_can_out_info[0]), name, val);
}

void InstrPanel_ZDC::resetOutInfo()
{
	for (int i = 0; i < sizeof(g_io_out_info)/sizeof(g_io_out_info[0]); i++)
	{
		g_io_out_info[i].val = 0;
	}
	
	for (int i = 0; i < sizeof(g_can_out_info)/sizeof(g_can_out_info[0]); i++)
	{
		g_can_out_info[i].val = 0;
	}
}

void InstrPanel_ZDC::SwitchMainPower(bool flag)
{
	PRINT("flag: %d\n", (int)flag);
	SetIoOut("主电源输出", (int)flag);
}
typedef struct _MsgInfo_out
{
    int sock;
    const char* name;
    int optNum;
    struct _ValOpt
    {
        const char* valstr;
        int dip;
        QColor valstrcolor;
    }valoption[VAL_OPT_MAX];
    int column;
}MsgInfo_out;



#endif
