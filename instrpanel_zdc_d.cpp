#include "common.h"
#include "table.h"
#include "instrpanel_zdc_d.h"


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
#define TITLE1_STYLE "border-image:url(:/res/res/image/title_zdc_d1.png);\n"


/********************************* page1->table1 *********************************/
static const LabelInfo g_label_table1[][TAB_COL_NUM_MAX] =
{
    {{"舱排水泵",        KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}},
    {{"射手观察镜", KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}},
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
    {{"舱排水泵电源",         KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}},
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
    {"舱排水泵",        "左后转向灯"},
    {"射手观察镜", "后示廓灯"  },
    {"通话控制盒",      "暖风机"    },
    {"刹车灯",          "电台1"     },
    {"倒车灯",          "电台2"     },
    {"右后转向灯",      ""          },
    {"精电地1",         "精电地3"   },
    {"精电地2",         "舱排水泵电源"          },
};

/********************************* page1->start button *****************************/
static QRect g_start_rect = QRect(0, 432, 800, 40);
#define BUTTON_STYLE "background-color: rgb(31, 49, 87);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(255, 255, 255);\n"



/********************************* page2->title *********************************/
#define TITLE2_STYLE "border-image:url(:/res/res/image/title_zdc_d2.png);\n"


/********************************* page2->table3 *********************************/
static const LabelInfo g_label_table3[10][TAB_COL_NUM_MAX] =
{
    {{"毒剂报警",     KEY_STYLE1}, {"——", NONE_STYLE1}, { "", VAL_STYLE1}, { "——", NONE_STYLE1}},
    {{"低辐射报警",   KEY_STYLE2}, {"——", NONE_STYLE2}, { "", VAL_STYLE2}, { "——", NONE_STYLE2}},
    {{"高辐射报警",   KEY_STYLE1}, {"——", NONE_STYLE1}, { "", VAL_STYLE1}, { "——", NONE_STYLE1}},
    {{"三防应急",     KEY_STYLE2}, {"——", NONE_STYLE2}, { "", VAL_STYLE2}, { "——", NONE_STYLE2}},
    {{"",      KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}, { "", VAL_STYLE1}},
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
#if 0
    {{"蓄电池温度",       KEY_STYLE1}, {"", VAL_STYLE1}, { "——", NONE_STYLE1}, { "", VAL_STYLE1}},
    {{"蓄电池电压(V)",  KEY_STYLE2}, {"", VAL_STYLE2}, { "——", NONE_STYLE2}, { "——", NONE_STYLE2}},
    {{"蓄电池加温",     KEY_STYLE1}, {"——", NONE_STYLE1}, { "", VAL_STYLE1}, { "", VAL_STYLE1}},
#else
    {{"",       KEY_STYLE1}, {"", VAL_STYLE1}, { "", NONE_STYLE1}, { "", VAL_STYLE1}},
    {{"",  KEY_STYLE2}, {"", VAL_STYLE2}, { "", NONE_STYLE2}, { "", NONE_STYLE2}},
    {{"",     KEY_STYLE1}, {"", NONE_STYLE1}, { "", VAL_STYLE1}, { "", VAL_STYLE1}},
#endif
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
    {"", ""              },
    {"后门开关",   ""              },
    {"主油量(V)",  ""     },
    {"后油量(V)",  "" },
    {"主油量地",   ""    },
    {"后油量地",   ""      }
};


InstrPanel_ZDC_D::InstrPanel_ZDC_D(QWidget *parent) : PanelBase(parent)
{
    ENTER();

    if (objectName().isEmpty())
        setObjectName(QStringLiteral("ZDC"));

    Page* page1 = new Page(this);
    QLabel* title = page1->AddTitle(g_title_rect, TITLE1_STYLE);
    page1->SetAppVersion(__APP_VERION__, title);

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
    page2->SetNaviMap(g_page2_map, 10, 2);
    AddToPageList(page2);
    CreateTableMap(table3, g_label_table3, 10);
    CreateTableMap(table4, g_label_table4, 10);
    page2->CreateHlRect(398);

    SetPageIndex(0);

    LEAVE();
}


////////////////////////////////////////////////////////////
static MsgInfo g_read_info_query[] =
{
	{1, "舱排水泵", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 1},
	{2, "射手观察镜", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 1},
	{3, "通话控制盒", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 1},
	{4, "刹车灯", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 1},
	{5, "倒车灯", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 1},
	{6, "右后转向灯", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 1},

	{7, "精电地1", {{0, "", NONE}, {1, "接通", GREEN},{2, "关断", RED}, }, DISPLAY_TYPE_STR, 1},
	{8, "精电地2", {{0, "", NONE}, {1, "接通", GREEN},{2, "关断", RED}, }, DISPLAY_TYPE_STR, 1},

	{9, "舱排水泵", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 2},
	{10, "射手观察镜", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED},{ 49,"过流", RED,  },   { 50,"过压", RED,  },   { 51,"短路", RED,  },   { 52,"过温", RED,  }, }, DISPLAY_TYPE_STR, 2},
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
	{44, "蓄电池加温", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, }, DISPLAY_TYPE_STR, 3},

	{45, "舱排水泵电源", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, }, DISPLAY_TYPE_STR, 1},
};

void InstrPanel_ZDC_D::RecvMsg(unsigned char* msg, int size)
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
	{'F', "主油量(V)",     5, {{2, "关断", ORANGE}, {42, "23L", ORANGE}, {43, "85L", ORANGE}, {44, "224L", ORANGE}, {45, "271L", ORANGE},},  2},
	{'G', "后油量(V)",	    5, {{2, "关断", ORANGE}, {23, "14L",ORANGE}, {24, "167L",ORANGE}, {25, "373L", ORANGE}, {26, "525L", ORANGE},},  2},
	{'H', "后转换接触器",	3,        {{2, "关断", ORANGE}, {39,"进气",ORANGE},{40, "排气", ORANGE},},	1},
	{'I', "后进排气扇电机", 3,  {{2, "关断", ORANGE}, {39,"进气",ORANGE},{40, "排气", ORANGE},}, 1},
	{'J', "后关闭体电磁阀", 2,  { {1, "接通", ORANGE}, {2, "关断", ORANGE},		}, 1},
	{'K', "蓄电池温度", 5,	{{2, "关断", ORANGE},	{29, "4°C", 	ORANGE}, {30, "8°C", 	ORANGE}, {31, "15°C", 	ORANGE}, {32, "17°C", 	ORANGE},  },  1},
	{'L', "蓄电池电压(V)", 2,  {{12, "28V", ORANGE},   {9, "0V",		ORANGE},   },  1},
};

void InstrPanel_ZDC_D::SetValue(const QString& name, int val)
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

OutType InstrPanel_ZDC_D::CheckOutUnitType(const QString& name)
{
	static QMap<QString, int> omap;
	if (omap.size() == 0)
	{
		omap["主油量(V)"]     = TYPE_OPT_TUNE;
		omap["后油量(V)"]     = TYPE_OPT_TUNE;
		omap["后转换接触器"]     = TYPE_OPT_TUNE;
		omap["后进排气扇电机"] = TYPE_OPT_TUNE;
//		omap["蓄电池温度"] = TYPE_OPT_TUNE;
		
		omap["后门开关"]	   = TYPE_OPT_OFFON;
		omap["毒剂报警"]       = TYPE_OPT_OFFON;
		omap["低辐射报警"]      = TYPE_OPT_OFFON;
		omap["高辐射报警"]      = TYPE_OPT_OFFON;
		omap["三防应急"]       = TYPE_OPT_OFFON;
		omap["蓄电池电压"] =      TYPE_OPT_OFFON;
		omap["后关闭体电磁阀"] = TYPE_OPT_OFFON;
//		omap["蓄电池电压(V)"] = TYPE_OPT_OFFON;
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

static DefaultTestInfo g_defaultTestItems[] = 
{
#if 0
    {'A', 1,  1},
    {'A', 2,  1},
    {'B', 1,  1},
    {'B', 2,  1},
    {'C', 1,  1},
    {'C', 2,  1},
    {'D', 1,  1},
    {'D', 2,  1},
    {'E', 5,  1},
    {'E', 6,  1},
    {'F', 42, 1},
    {'F', 43, 1},
    {'F', 44, 1},
    {'F', 45, 1},
    {'G', 23, 1},
    {'G', 24, 1},
    {'G', 25, 1},
    {'G', 26, 1},
    {'H', 39, 1},
    {'H', 40, 1},
    {'H', 2,  1},
    {'J', 1,  1},
    {'J', 2,  1}
#else
    {'A', 1,  2},
    {'A', 2,  2},
    {'B', 1,  2},
    {'B', 2,  2},
    {'C', 1,  2},
    {'C', 2,  2},
    {'D', 1,  2},
    {'D', 2,  2},
    {'E', 5,  2},
    {'E', 6,  2},
    {'F', 42, 10},
    {'F', 43, 10},
    {'F', 44, 10},
    {'F', 45, 10},
    {'G', 23, 10},
    {'G', 24, 10},
    {'G', 25, 10},
    {'G', 26, 10},
    {'H', 39, 2},
    {'H', 40, 2},
    {'H', 2,  2},
    {'J', 1,  2},
    {'J', 2,  2}
#endif
};

#define DEFAULT_TEST_CONFIG_FILE  BIN_DIR "zdc_d_config.txt"
void InstrPanel_ZDC_D::InitDefaultTestList()
{
    ENTER();
    FILE* fp = fopen(DEFAULT_TEST_CONFIG_FILE, "r");
    if (fp == NULL)
    {
        PRINT("No config file: %s\n", DEFAULT_TEST_CONFIG_FILE);
        return;
    }

    char line[256];
    for (unsigned int i = 0; i < sizeof(g_defaultTestItems)/sizeof(g_defaultTestItems[0]); i++)
    {
        if (NULL == fgets(line, sizeof(line), fp))
        {
            PRINT("Not enough lines in config file[%s]\n", DEFAULT_TEST_CONFIG_FILE);
            break;
        }
        char chsock;
        if (3 != sscanf(line, "%c %d %d", \
            &chsock, &g_defaultTestItems[i].dip, &g_defaultTestItems[i].seconds))
        {
            ERROR("Wrong content of line %u\n", i+1);
            break;
        }
        g_defaultTestItems[i].sock = chsock;
    }
    fclose(fp);
}


bool InstrPanel_ZDC_D::GetDefaultTestItem(int id, QString &retname, DefaultTestInfo &retinfo)
{
    if ((unsigned int)id >= sizeof(g_defaultTestItems)/sizeof(g_defaultTestItems[0]) 
      || (unsigned int)id < 0)
    {
        return false;
    }
    auto &out_info = g_out_info[g_defaultTestItems[id].sock - (int)'A'];

    PRINT("sock [%d], name [%s]\n", g_defaultTestItems[id].sock, out_info.name);
    retname = QString(out_info.name);
    retinfo = g_defaultTestItems[id];
    return true;
}

bool InstrPanel_ZDC_D::DefaultTest(int id)
{
    if ((unsigned int)id >= sizeof(g_defaultTestItems)/sizeof(g_defaultTestItems[0])
        || (unsigned int)id < 0)
    {
        return false;
    }
    PRINT("sock [%d]\n", g_defaultTestItems[id].sock);

    if (g_defaultTestItems[id].sock == (int)'H' || g_defaultTestItems[id].sock == (int)'I')
    {
        SetSpecValue((int)'H', g_defaultTestItems[id].dip, g_out_info, sizeof(g_out_info)/sizeof(g_out_info[0]));
        SetSpecValue((int)'I', g_defaultTestItems[id].dip, g_out_info, sizeof(g_out_info)/sizeof(g_out_info[0]));
    }
    else
    {
        SetSpecValue(g_defaultTestItems[id].sock, g_defaultTestItems[id].dip, g_out_info, sizeof(g_out_info)/sizeof(g_out_info[0]));
    }
    return true;
}

