#include "instrpanel_jsc.h"


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
#define TITLE1_STYLE "border-image:url(:/res/res/image/title_jsc1.png);\n"


/********************************* page1->table1 *********************************/
static const LabelInfo g_label_table1[][TAB_COL_NUM_MAX] =
{
    {{"夜视仪",        KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1},},
    {{"毒剂报警盒",     KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2},},
    {{"辐射报警盒",     KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1},},
    {{"灭火报警盒",     KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2},},
    {{"潜望镜加温",     KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1},},
    {{"空气启动电磁阀", KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2},},
    {{"信息盒电源",     KEY_STYLE1}, {"", VAL_STYLE1}, { "——", NONE_STYLE1},},
    {{"驾驶员终端地",   KEY_STYLE2}, {"", VAL_STYLE2}, { "——", NONE_STYLE2},},
};

static QPoint g_table1_pos = QPoint(0, 86);

static QSize g_table1_size[] =
{
    QSize(168, 40),
    QSize(112, 40),
    QSize(116, 40),
};

/********************************* page1->table2 *********************************/
static const LabelInfo g_label_table2[8][TAB_COL_NUM_MAX] =
{
    {{"报警灯/蜂鸣器",  KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1},},
    {{"微压差盒",       KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2},},
    {{"发动机电控盒",   KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1},},
    {{"传动电控盒",     KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2},},
    {{"车长镜加温",     KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1},},
    {{"驾驶员终端电源", KEY_STYLE2}, {"", VAL_STYLE2}, { "——", NONE_STYLE2},},
    {{"发动机电控地",   KEY_STYLE1}, {"", VAL_STYLE1}, { "——", NONE_STYLE1},},
    {{"仪表板地",       KEY_STYLE2}, {"", VAL_STYLE2}, { "——", NONE_STYLE2},},
};

static QPoint g_table2_pos = {403, 86};

static QSize g_table2_size[] =
{
    QSize(168, 40),
    QSize(112, 40),
    QSize(116, 40),
};

/********************************* page1->ui navigation map *****************************/
static const char* g_page1_map[][PAGE_NAVI_COL_MAX] =
{
    {"夜视仪",        "报警灯/蜂鸣器" },
    {"毒剂报警盒",    "微压差盒"      },
    {"辐射报警盒",    "发动机电控盒"  },
    {"灭火报警盒",    "传动电控盒"    },
    {"潜望镜加温",    "车长镜加温"    },
    {"空气启动电磁阀","驾驶员终端电源"},
    {"信息盒电源",    "发动机电控地"  },
    {"驾驶员终端地",  "仪表板地"      }
};


/********************************* page1->start button *****************************/
static QRect g_start_rect = QRect(0, 432, 800, 40);
#define BUTTON_STYLE "background-color: rgb(31, 49, 87);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(255, 255, 255);\n"



/********************************* page2->title *********************************/
#define TITLE2_STYLE "border-image:url(:/res/res/image/title_jsc2.png);\n"


/********************************* page2->table3 *********************************/
static const LabelInfo g_label_table3[][TAB_COL_NUM_MAX] =
{
    {{"毒剂报警",   KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1},},
    {{"低辐射报警", KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2},},
    {{"高辐射报警", KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1},},
    {{"三防应急",   KEY_STYLE2}, {"", VAL_STYLE2}, { "——", NONE_STYLE2},},
    {{"",           KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1},},
    {{"",           KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2},},
    {{"",           KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1},},
    {{"",           KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2},},
    {{"",           KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1},},
    {{"",           KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2},}
};

static QPoint g_table3_pos = QPoint(0, 86);

static QSize g_table3_size[] =
{
    QSize(190, 40),
    QSize(102, 40),
    QSize(104, 40),
};

/********************************* page2->table4 *********************************/
static const LabelInfo g_label_table4[][TAB_COL_NUM_MAX] =
{
    {{"前进排气接触器",  KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}, { "", VAL_STYLE1}},
    {{"后进排气扇电机",  KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}, { "", VAL_STYLE2}},
    {{"前关闭体电磁阀",  KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}, { "", VAL_STYLE1}},
    {{"增压风机",        KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}, { "", VAL_STYLE2}},
    {{"",           KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}, { "", VAL_STYLE1}},
    {{"",           KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}, { "", VAL_STYLE2}},
    {{"",           KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}, { "", VAL_STYLE1}},
    {{"",           KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}, { "", VAL_STYLE2}},
    {{"",           KEY_STYLE1}, {"", VAL_STYLE1}, { "", VAL_STYLE1}, { "", VAL_STYLE1}},
    {{"",           KEY_STYLE2}, {"", VAL_STYLE2}, { "", VAL_STYLE2}, { "", VAL_STYLE2}}
};

static QPoint g_table4_pos = QPoint(404, 86);

static QSize g_table4_size[] =
{
    QSize(176, 40),
    QSize(74,  40),
    QSize(74,  40),
    QSize(70,  40),
};

/********************************* page2->ui navigation map *****************************/
static const char* g_page2_map[][PAGE_NAVI_COL_MAX] =
{
    {"毒剂报警",   "前进排气接触器"},
    {"低辐射报警", "后进排气扇电机"},
    {"高辐射报警", "前关闭体电磁阀"},
    {"三防应急",   "增压风机"     }
};



InstrPanel_JSC::InstrPanel_JSC(QWidget *parent) : PanelBase(parent)
{
    ENTER();
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("JSC"));

    Page* page1 = new Page(this);
    page1->AddTitle(g_title_rect, TITLE1_STYLE);
    Tab* table1 = new Tab(page1, 8, 3, g_label_table1, g_table1_pos, g_table1_size);
    page1->AddTable(table1);
    Tab* table2 = new Tab(page1, 8, 3, g_label_table2, g_table2_pos, g_table2_size);
    page1->AddTable(table2);
    page1->SetButton(g_start_rect, BUTTON_STYLE);
    //page1->SetNaviMap(g_page1_map, 8, 2);
    AddToPageList(page1);
    CreateTableMap(table1, g_label_table1, 8);
    CreateTableMap(table2, g_label_table2, 8);
    page1->CreateHlRect(398);

    Page* page2 = new Page(this);
    page2->AddTitle(g_title_rect, TITLE2_STYLE);
    Tab* table3 = new Tab(page2, 10, 3, g_label_table3, g_table3_pos, g_table3_size);
    page2->AddTable(table3);
    Tab* table4 = new Tab(page2, 10, 4, g_label_table4, g_table4_pos, g_table4_size);
    page2->AddTable(table4);
    page2->SetNaviMap(g_page2_map, 4, 2);
    AddToPageList(page2);
    CreateTableMap(table3, g_label_table3, 4);
    CreateTableMap(table4, g_label_table4, 4);
    page2->CreateHlRect(398);

    SetPageIndex(0);

    LEAVE();
}

static MsgInfo g_read_info_query[] =
{
	{  1,  "夜视仪"			, {    { 0, "", WHITE }, { 1,  "接通", YELLOW  },	{ 2,"关断", YELLOW	},	 { 3,"正确", GREEN  },   { 4,"错误", RED  },   { 49,"过流", RED  },	{ 50,"过压", RED	},	 { 51,"短路", RED  },   { 52,"过温", RED  }, }, DISPLAY_TYPE_STR,1 },
	{  2,  "毒剂报警盒"	  , {	 { 0, "", WHITE }, { 1,  "接通", YELLOW  },   { 2,"关断", YELLOW  },   { 3,"正确", GREEN	},	 { 4,"错误", RED	},	 { 49,"过流", RED  },   { 50,"过压", RED  },   { 51,"短路", RED  },	{ 52,"过温", RED	}, }, DISPLAY_TYPE_STR,1 },
	{  3,  "辐射报警盒"	  , {	 { 0, "", WHITE }, { 1,  "接通", YELLOW  },   { 2,"关断", YELLOW  },   { 3,"正确", GREEN	},	 { 4,"错误", RED	},	 { 49,"过流", RED  },   { 50,"过压", RED  },   { 51,"短路", RED  },	{ 52,"过温", RED	}, }, DISPLAY_TYPE_STR,1 },
	{  4,  "灭火报警盒"	  , {	 { 0, "", WHITE }, { 1,  "接通", YELLOW  },   { 2,"关断", YELLOW  },   { 3,"正确", GREEN	},	 { 4,"错误", RED	},	 { 49,"过流", RED  },   { 50,"过压", RED  },   { 51,"短路", RED  },	{ 52,"过温", RED	}, }, DISPLAY_TYPE_STR,1 },
	{  5,  "潜望镜加温"	  , {	 { 0, "", WHITE }, { 1,  "接通", YELLOW  },   { 2,"关断", YELLOW  },   { 3,"正确", GREEN	},	 { 4,"错误", RED	},	 { 49,"过流", RED  },   { 50,"过压", RED  },   { 51,"短路", RED  },	{ 52,"过温", RED	}, }, DISPLAY_TYPE_STR,1 },
	{  6,  "空气启动电磁阀"	, {    { 0, "", WHITE }, { 1,  "接通", YELLOW  },	{ 2,"关断", YELLOW	},	 { 3,"正确", GREEN  },   { 4,"错误", RED  },   { 49,"过流", RED  },	{ 50,"过压", RED	},	 { 51,"短路", RED  },   { 52,"过温", RED  }, }, DISPLAY_TYPE_STR,1 },
																																																																			
	{  7,  "信息盒电源"	  , {	 { 0, "", WHITE }, { 1,  "接通", GREEN },   { 2,"关断", RED  }, 							 }, DISPLAY_TYPE_STR,1 },
	{  8,  "驾驶员终端地"    , {	  { 0, "", WHITE }, { 1,  "接通", GREEN },   { 2,"关断", RED  },  						  }, DISPLAY_TYPE_STR,1 },
																																																																			
	{  9, "夜视仪"			, {    { 0, "", WHITE }, { 1,  "接通", YELLOW  },	{ 2,"关断", YELLOW	},	 { 3,"正确", GREEN  },   { 4,"错误", RED  },   { 49,"过流", RED  },	{ 50,"过压", RED	},	 { 51,"短路", RED  },   { 52,"过温", RED  }, }, DISPLAY_TYPE_STR,2 },
	{ 10, "毒剂报警盒" 	  , {	 { 0, "", WHITE }, { 1,  "接通", YELLOW  },   { 2,"关断", YELLOW  },   { 3,"正确", GREEN	},	 { 4,"错误", RED	},	 { 49,"过流", RED  },   { 50,"过压", RED  },   { 51,"短路", RED  },	{ 52,"过温", RED	}, }, DISPLAY_TYPE_STR,2 },
	{ 11, "辐射报警盒" 	  , {	 { 0, "", WHITE }, { 1,  "接通", YELLOW  },   { 2,"关断", YELLOW  },   { 3,"正确", GREEN	},	 { 4,"错误", RED	},	 { 49,"过流", RED  },   { 50,"过压", RED  },   { 51,"短路", RED  },	{ 52,"过温", RED	}, }, DISPLAY_TYPE_STR,2 },
	{ 12, "灭火报警盒" 	  , {	 { 0, "", WHITE }, { 1,  "接通", YELLOW  },   { 2,"关断", YELLOW  },   { 3,"正确", GREEN	},	 { 4,"错误", RED	},	 { 49,"过流", RED  },   { 50,"过压", RED  },   { 51,"短路", RED  },	{ 52,"过温", RED	}, }, DISPLAY_TYPE_STR,2 },
	{ 13, "潜望镜加温" 	  , {	 { 0, "", WHITE }, { 1,  "接通", YELLOW  },   { 2,"关断", YELLOW  },   { 3,"正确", GREEN	},	 { 4,"错误", RED	},	 { 49,"过流", RED  },   { 50,"过压", RED  },   { 51,"短路", RED  },	{ 52,"过温", RED	}, }, DISPLAY_TYPE_STR,2 },
	{ 14, "空气启动电磁阀"	, {    { 0, "", WHITE }, { 1,  "接通", YELLOW  },	{ 2,"关断", YELLOW	},	 { 3,"正确", GREEN  },   { 4,"错误", RED  },   { 49,"过流", RED  },	{ 50,"过压", RED	},	 { 51,"短路", RED  },   { 52,"过温", RED  }, }, DISPLAY_TYPE_STR,2 },
	{ 15, "报警灯/蜂鸣器"    , {	  { 0, "", WHITE }, { 1,  "接通", YELLOW  },   { 2,"关断", YELLOW  },	{ 3,"正确", GREEN  },   { 4,"错误", RED  },   { 49,"过流", RED  },   { 50,"过压", RED  },	{ 51,"短路", RED	},	 { 52,"过温", RED  }, }, DISPLAY_TYPE_STR,1 },
	{ 16, "微压差盒"		 , {	{ 0, "", WHITE }, { 1,	"接通", YELLOW	},	 { 2,"关断", YELLOW  },   { 3,"正确", GREEN  },	{ 4,"错误", RED  },	{ 49,"过流", RED	},	 { 50,"过压", RED  },   { 51,"短路", RED  },   { 52,"过温", RED  }, }, DISPLAY_TYPE_STR,1 },
	{ 17, "发动机电控盒"	   , {	  { 0, "", WHITE }, { 1,  "接通", YELLOW  },   { 2,"关断", YELLOW  },	{ 3,"正确", GREEN  },   { 4,"错误", RED  },   { 49,"过流", RED  },   { 50,"过压", RED  },	{ 51,"短路", RED	},	 { 52,"过温", RED  }, }, DISPLAY_TYPE_STR,1 },
	{ 18, "传动电控盒" 	  , {	 { 0, "", WHITE }, { 1,  "接通", YELLOW  },   { 2,"关断", YELLOW  },   { 3,"正确", GREEN	},	 { 4,"错误", RED	},	 { 49,"过流", RED  },   { 50,"过压", RED  },   { 51,"短路", RED  },	{ 52,"过温", RED	}, }, DISPLAY_TYPE_STR,1 },
	{ 19, "车长镜加温" 	  , {	 { 0, "", WHITE }, { 1,  "接通", YELLOW  },   { 2,"关断", YELLOW  },   { 3,"正确", GREEN	},	 { 4,"错误", RED	},	 { 49,"过流", RED  },   { 50,"过压", RED  },   { 51,"短路", RED  },	{ 52,"过温", RED	}, }, DISPLAY_TYPE_STR,1 },
																																																																			
	{ 20, "驾驶员终端电源"	, {    { 0, "", WHITE }, { 11, "24V" , GREEN },   { 9,"0V"	, RED  },						   }, DISPLAY_TYPE_STR,1 },
	{ 21, "发动机电控地"	   , {	  { 0, "", WHITE }, { 1,  "接通", GREEN },   { 2,"关断", RED  },  						  }, DISPLAY_TYPE_STR,1 },
	{ 22, "仪表板地"		 , {	{ 0, "", WHITE }, { 1,	"接通", GREEN },	 { 2,"关断", RED	},	 					}, DISPLAY_TYPE_STR,1 },
																																																																			
	{ 23, "报警灯/蜂鸣器"    , {	  { 0, "", WHITE }, { 1,  "接通", YELLOW  },   { 2,"关断", YELLOW  },	{ 3,"正确", GREEN  },   { 4,"错误", RED  },   { 49,"过流", RED  },   { 50,"过压", RED  },	{ 51,"短路", RED	},	 { 52,"过温", RED  }, }, DISPLAY_TYPE_STR,2 },
	{ 24, "微压差盒"		 , {	{ 0, "", WHITE }, { 1,	"接通", YELLOW	},	 { 2,"关断", YELLOW  },   { 3,"正确", GREEN  },	{ 4,"错误", RED  },	{ 49,"过流", RED	},	 { 50,"过压", RED  },   { 51,"短路", RED  },   { 52,"过温", RED  }, }, DISPLAY_TYPE_STR,2 },
	{ 25, "发动机电控盒"	   , {	  { 0, "", WHITE }, { 1,  "接通", YELLOW  },   { 2,"关断", YELLOW  },	{ 3,"正确", GREEN  },   { 4,"错误", RED  },   { 49,"过流", RED  },   { 50,"过压", RED  },	{ 51,"短路", RED	},	 { 52,"过温", RED  }, }, DISPLAY_TYPE_STR,2 },
	{ 26, "传动电控盒" 	  , {	 { 0, "", WHITE }, { 1,  "接通", YELLOW  },   { 2,"关断", YELLOW  },   { 3,"正确", GREEN	},	 { 4,"错误", RED	},	 { 49,"过流", RED  },   { 50,"过压", RED  },   { 51,"短路", RED  },	{ 52,"过温", RED	}, }, DISPLAY_TYPE_STR,2 },
	{ 27, "车长镜加温" 	  , {	 { 0, "", WHITE }, { 1,  "接通", YELLOW  },   { 2,"关断", YELLOW  },   { 3,"正确", GREEN	},	 { 4,"错误", RED	},	 { 49,"过流", RED  },   { 50,"过压", RED  },   { 51,"短路", RED  },	{ 52,"过温", RED	}, }, DISPLAY_TYPE_STR,2 },
																																																																			
	{ 28, "毒剂报警"	   , {	  { 0, "", WHITE }, { 1,  "接通", YELLOW },   { 2,"关断", YELLOW  }, 						 }, DISPLAY_TYPE_STR,2 },
	{ 29, "低辐射报警" 	, {    { 0, "", WHITE }, { 1,  "接通", YELLOW },   { 2,"关断", YELLOW  },							  }, DISPLAY_TYPE_STR,2 },
	{ 30, "高辐射报警" 	, {    { 0, "", WHITE }, { 1,  "接通", YELLOW },   { 2,"关断", YELLOW  },							  }, DISPLAY_TYPE_STR,2 },
	{ 31, "前进排气接触器"	, {    { 0, "", WHITE }, { 1,  "接通", YELLOW  },	{ 2,"关断", YELLOW	},						   }, DISPLAY_TYPE_STR,2 },
	{ 32, "后进排气扇电机"	, {    { 0, "", WHITE }, { 1,  "接通", YELLOW  },	{ 2,"关断", YELLOW	},						   }, DISPLAY_TYPE_STR,2 },
	{ 33, "前关闭体电磁阀"	, {    { 0, "", WHITE }, { 1,  "接通", YELLOW  },	{ 2,"关断", YELLOW	},						   }, DISPLAY_TYPE_STR,2 },
	{ 34, "增压风机"		 , {	{ 0, "", WHITE }, { 1,	"接通", YELLOW	},	 { 2,"关断", YELLOW  },         			}, DISPLAY_TYPE_STR,2 },
	{ 35, "前进排气接触器"	, {    { 0, "", WHITE }, { 1,  "接通", YELLOW  },	{ 2,"关断", YELLOW	},	 { 49,"过流",	RED },  { 50,"过压",	RED },  { 51,"短路", RED  },   { 52,"过温", RED  }, 	 }, DISPLAY_TYPE_STR,3 },
	{ 36, "后进排气扇电机"	, {    { 0, "", WHITE }, { 1,  "接通", YELLOW  },	{ 2,"关断", YELLOW	},	 { 49,"过流",	RED },  { 50,"过压",	RED },  { 51,"短路", RED  },   { 52,"过温", RED  }, 	 }, DISPLAY_TYPE_STR,3 },
	{ 37, "前关闭体电磁阀"	, {    { 0, "", WHITE }, { 1,  "接通", YELLOW  },	{ 2,"关断", YELLOW	},	 { 49,"过流",	RED },  { 50,"过压",	RED },  { 51,"短路", RED  },   { 52,"过温", RED  }, 	 }, DISPLAY_TYPE_STR,3 },
	{ 38, "增压风机"		 , {	{ 0, "", WHITE }, { 1,	"接通", YELLOW	},	 { 2,"关断", YELLOW  }, { 49,"过流", RED },{ 50,"过压",	RED },  { 51,"短路", RED  },   { 52,"过温", RED  },			}, DISPLAY_TYPE_STR,3 }
};

void InstrPanel_JSC::RecvMsg(unsigned char* msg, int size)
{
	ENTER();
    ShowState(msg, size, g_read_info_query, sizeof(g_read_info_query)/sizeof(g_read_info_query[0]));
}

static MsgInfo_out g_out_info[] =
{
    { 'A', "毒剂报警"        , 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'B', "低辐射报警"      , 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'C', "高辐射报警"      , 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'D', "三防应急"        , 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'E', "前进排气接触器"  , 3, {{2, "关断", ORANGE}, {39,"进气", ORANGE}, {40, "排气", ORANGE}, }, 1},
    { 'F', "后进排气扇电机"  , 3, {{2, "关断", ORANGE}, {39,"进气", ORANGE}, {40, "排气", ORANGE}, }, 1},
    { 'G', "前关闭体电磁阀"  , 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
    { 'H', "增压风机"        , 2, {{1, "接通", ORANGE}, {2, "关断", ORANGE}, },1 },
};

void InstrPanel_JSC::SetValue(const QString& name, int val)
{
	ENTER();
	if (name == "前进排气接触器" || name == "后进排气扇电机")
	{
		SetSpecValue("前进排气接触器", val, g_out_info, sizeof(g_out_info)/sizeof(g_out_info[0]));
		SetSpecValue("后进排气扇电机", val, g_out_info, sizeof(g_out_info)/sizeof(g_out_info[0]));
	}
	else
	{
		SetSpecValue(name, val, g_out_info, sizeof(g_out_info)/sizeof(g_out_info[0]));
	}
}

OutType InstrPanel_JSC::CheckOutUnitType(const QString& name)
{
	static QMap<QString, int> omap;
	if (omap.size() == 0)
	{
		omap["毒剂报警"]	  = TYPE_OPT_OFFON;
		omap["低辐射报警"]    = TYPE_OPT_OFFON;
		omap["高辐射报警"]    = TYPE_OPT_OFFON;
		omap["三防应急"]	  = TYPE_OPT_OFFON;
		omap["前关闭体电磁阀"]= TYPE_OPT_OFFON;
		omap["增压风机"]	  = TYPE_OPT_OFFON;
		
		omap["前进排气接触器"]= TYPE_OPT_TUNE;
		omap["后进排气扇电机"]= TYPE_OPT_TUNE;
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
	{4, 0, 5, 0, "夜视仪", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温", RED},}, DISPLAY_TYPE_STR, 2},
	{4, 0, 5, 0, "毒剂报警盒", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温", RED},}, DISPLAY_TYPE_STR, 2},
	
	{4, 0, 5, 0, "辐射报警盒", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温", RED},}, DISPLAY_TYPE_STR, 2},
	{4, 0, 5, 0, "灭火报警盒", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温", RED},}, DISPLAY_TYPE_STR, 2},
	
	{4, 0, 5, 0, "潜望镜加温", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温", RED},}, DISPLAY_TYPE_STR, 2},
	{4, 0, 5, 0, "空气起动电磁阀", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温", RED},}, DISPLAY_TYPE_STR, 2},
	
	{4, 0, 5, 0, "报警灯/蜂鸣器", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温", RED},}, DISPLAY_TYPE_STR, 2},
	{4, 0, 5, 0, "微压差盒", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温", RED},}, DISPLAY_TYPE_STR, 2},
	
	{4, 0, 5, 0, "发动机电控盒", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温", RED},}, DISPLAY_TYPE_STR, 2},
	{4, 0, 5, 0, "传动电控盒", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温", RED},}, DISPLAY_TYPE_STR, 2},
	
	{4, 0, 5, 0, "车长镜加温", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温", RED},}, DISPLAY_TYPE_STR, 2},
	{4, 0, 5, 0, "前进排气接触器", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温", RED},}, DISPLAY_TYPE_STR, 3},
	
	{4, 0, 5, 0, "后进排气扇电机", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温", RED},}, DISPLAY_TYPE_STR, 3},
	{4, 0, 5, 0, "前关闭体电磁阀", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温", RED},}, DISPLAY_TYPE_STR, 3},
	
	{4, 0, 5, 0, "增压风机", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温", RED},}, DISPLAY_TYPE_STR, 3},
	{1, 0, 1, 0, "毒剂报警", {{"未报警", GREEN}, {"报警", RED},}, DISPLAY_TYPE_STR, 2},
	{1, 0, 1, 0, "低辐射报警", {{"未报警", GREEN}, {"报警", RED},}, DISPLAY_TYPE_STR, 2},
	{1, 0, 1, 0, "高辐射报警", {{"未报警", GREEN}, {"报警", RED},}, DISPLAY_TYPE_STR, 2},
	{1, 0, 1, 0, "", {}, DISPLAY_TYPE_STR, -1}
};

void InstrPanel_JSC::GetCanState(unsigned char* msg, int msg_size)
{
    ShowState(msg, msg_size, g_can_read_info_query, sizeof(g_can_read_info_query)/sizeof(g_can_read_info_query[0]));
}

static MsgInfo g_io_read_info_query[] =
{
	{1, 0, 1, 0, "车长镜加温", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 1},
	{1, 0, 1, 0, "潜望镜加温", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 1},
	{1, 0, 1, 0, "微压差盒", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 1},
	{1, 0, 1, 0, "夜视仪", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 1},
	{1, 0, 1, 0, "前进排气接触器", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 2},
	{1, 0, 1, 0, "增压风机", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 2},
	{1, 0, 1, 0, "报警灯/蜂鸣器", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 1},
	{1, 0, 1, 0, "空气起动电磁阀", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 1},
	
	{1, 0, 1, 0, "后进排气扇电机", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 2},
	{1, 0, 1, 0, "前关闭体电磁阀", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 2},
	{1, 0, 1, 0, "信息盒电源", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 1},
	{1, 0, 1, 0, "传动电控盒", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 1},
	{1, 0, 1, 0, "驾驶员终端电源", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 1},
	{1, 0, 1, 0, "发动机电控盒", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 1},
	{1, 0, 1, 0, "毒剂报警盒", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 1},
	{1, 0, 1, 0, "灭火报警盒", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 1},
	
	{1, 0, 1, 0, "辐射报警盒", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 1},
	{1, 0, 1, 0, "驾驶员终端地", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 1},
	{1, 0, 1, 0, "精电地", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 1}, //?
	{1, 0, 1, 0, "发动机电控地", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 1},
	{1, 0, 1, 0, "仪表板地", {{"断开", RED}, {"接通", GREEN}, }, DISPLAY_TYPE_STR, 1},
	{3, 0, 1, 0, "", { }, DISPLAY_TYPE_STR, 1}
};

void InstrPanel_JSC::GetIoState(unsigned char* msg, int msg_size)
{
    ShowState(msg, msg_size, g_io_read_info_query, sizeof(g_io_read_info_query)/sizeof(g_io_read_info_query[0]));
}

OutType InstrPanel_JSC::CheckOutUnitType(QString name)
{
	static QMap<QString, int> map;
	if (map.size() == 0)
	{
		map["主电源输出"] = TYPE_IO;
		map["DC24V输入2"] = TYPE_IO;
		map["毒剂报警"]       = TYPE_IO;
		map["高辐射报警"]     = TYPE_IO;
		map["低辐射报警"]     = TYPE_IO;

		map["前进排气接触器"] = TYPE_CAN;
		map["后进排气扇电机"]       = TYPE_CAN;
		map["前关闭体电磁阀"]      = TYPE_CAN;
		map["增压风机"]      = TYPE_CAN;
		map["三防应急"]       = TYPE_CAN;
	}

	int type = map[name];
	PRINT("name[%s]'s type is %d\n", name.toStdString().c_str(), type);
	return (OutType)type;
}

static MsgInfo_out g_io_out_info[] =
{
	{8, 0, "主电源输出", 2,  {{"关闭", RED}, {"打开", GREEN},}, -1},
	{8, 0, "DC24V输入2", 2,  {{"关闭", RED}, {"打开", GREEN},}, -1},
	{8, 0, "毒剂报警", 2,  {{"无输出", RED}, {"有效输出", GREEN},}, 1},
	{8, 0, "高辐射报警", 2,  {{"无输出", RED}, {"有效输出", GREEN},}, 1},
	{8, 0, "低辐射报警", 2,  {{"无输出", RED}, {"有效输出", GREEN},}, 1}
};

void InstrPanel_JSC::SetIoOut(QString name, int val)
{
	GenerateOutMsg(TYPE_IO, g_io_out_info, sizeof(g_io_out_info)/sizeof(g_io_out_info[0]), name, val);
}

static MsgInfo_out g_can_out_info[] =
{
	{1, 0, "前进排气接触器", 2,  {{"关闭", RED}, {"打开", GREEN},}, 1},
	{1, 0, "后进排气扇电机", 2,  {{"关闭", RED}, {"打开", GREEN},}, 1},
	{1, 0, "前关闭体电磁阀", 2,  {{"关闭", RED}, {"打开", GREEN},}, 1},
	{1, 0, "增压风机", 2,  {{"关闭", RED}, {"打开", GREEN},}, 1},
	{1, 0, "三防应急", 2,  {{"关闭", RED}, {"打开", GREEN},}, 1},
	{3, 0, "", 2,  {}, -1},
};

void InstrPanel_JSC::SetCanOut(QString name, int val)
{
	GenerateOutMsg(TYPE_CAN, g_can_out_info, sizeof(g_can_out_info)/sizeof(g_can_out_info[0]), name, val);
}

void InstrPanel_JSC::resetOutInfo()
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

void InstrPanel_JSC::SwitchMainPower(bool flag)
{
	PRINT("flag: %d\n", (int)flag);
	SetIoOut("主电源输出", (int)flag);
}

#endif

