#include "instrpanel_dlc_a.h"
#include "common.h"
#include "table.h"

#include <QMessageBox>
void showMessageBox()
{
    QMessageBox::information(NULL, QString::fromLocal8Bit("我是中文！"), QString::fromLocal8Bit("我是中文！"));
}

static QRect g_title_rect = QRect(0, 0, 800, 86);
#define TITLE1_STYLE "border-image:url(:/res/res/image/title_dlc1.png);\n"

#define TITLE2_STYLE "border-image:url(:/res/res/image/title_dlc2.png);\n"


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



/********************************* page1->table1 *********************************/
static const LabelInfo g_label_table1[9][TAB_COL_NUM_MAX] =
{
    {{ "加温锅电源",    KEY_STYLE1 }, {"", VAL_STYLE1}, {"", VAL_STYLE1},},
    {{ "机油泵",       KEY_STYLE2 }, {"", VAL_STYLE2}, {"", VAL_STYLE2},},
    {{ "拖车泵",       KEY_STYLE1 }, {"", VAL_STYLE1}, {"", VAL_STYLE1},},
    {{ "百叶窗开",     KEY_STYLE2 }, {"", VAL_STYLE2}, {"", VAL_STYLE2},},
    {{ "排污阀",       KEY_STYLE1 }, {"", VAL_STYLE1}, {"", VAL_STYLE1},},
    {{ "电喇叭",       KEY_STYLE2 }, {"", VAL_STYLE2}, {"", VAL_STYLE2},},
    {{ "前大灯强",     KEY_STYLE1 }, {"", VAL_STYLE1}, {"", VAL_STYLE1},},
    {{ "前大灯弱",   	 KEY_STYLE2 },  {"", VAL_STYLE2}, {"", VAL_STYLE2},},
    {{ "防空灯强",     KEY_STYLE1 }, {"", VAL_STYLE1}, {"", VAL_STYLE1},},
};

static QPoint g_table1_pos = {0, 86};

static QSize g_table1_size[3] =
{
    {168, 38},
    {110, 38},
    {116, 38}
};

/********************************* page1->table2 *********************************/
static const LabelInfo g_label_table2[9][TAB_COL_NUM_MAX] =
{
    {{ "防空灯弱",    KEY_STYLE1 },{ "",    VAL_STYLE1 },{ "",    VAL_STYLE1 },},
    {{ "前左转向灯",  KEY_STYLE2 },{ "",    VAL_STYLE2 },{ "",    VAL_STYLE2 },},
    {{ "前右转向灯",   KEY_STYLE1 },{ "",    VAL_STYLE1 },{ "",    VAL_STYLE1 },},
    {{ "前示廓灯",    KEY_STYLE2 },{ "",    VAL_STYLE2 },{ "",    VAL_STYLE2 },},
    {{ "进气预热",    KEY_STYLE1 },{ "",    VAL_STYLE1 },{ "",    VAL_STYLE1 },},
    {{ "发动机放气阀", KEY_STYLE2 },{ "",    VAL_STYLE2 },{ "",    VAL_STYLE2 },},
    {{ "热烟幕阀",    KEY_STYLE1 },{ "",    VAL_STYLE1 },{ "",    VAL_STYLE1 },},
    {{ "加温锅控制",   KEY_STYLE2 },{ "",    VAL_STYLE2 },{ "",    VAL_STYLE2 },},
    {{ "敌我识别",    KEY_STYLE1 },{ "",    VAL_STYLE1 },{ "",    VAL_STYLE1 },},
};

static QPoint g_table2_pos = {403, 86};

static QSize g_table2_size[3] =
{
    {168, 38},
    {110, 38},
    {116, 38}
};

/********************************* page1->ui navigation map *****************************/
static const char* g_page1_map[][PAGE_NAVI_COL_MAX] =
{
    { "加温锅电源", "防空灯弱"    },
    { "机油泵",     "前左转向灯"  },
    { "拖车泵",     "前右转向灯"  },
    { "百叶窗开",   "前示廓灯"    },
    { "排污阀",     "进气预热"    },
    { "电喇叭",     "发动机放气阀"},
    { "前大灯强",   "热烟幕阀"    },
    { "前大灯弱",   "加温锅控制"  },
    { "防空灯强",   "敌我识别"    },
};


/********************************* page2->table3 *********************************/
static const LabelInfo g_label_table3[6][TAB_COL_NUM_MAX] =
{
    {{ "加温锅状态1",   KEY_STYLE1, },{ "——",    NONE_STYLE1 },{ "",    VAL_STYLE1 },},
    {{ "加温锅状态2",   KEY_STYLE2, },{ "——",    NONE_STYLE2 },{ "",    VAL_STYLE2 },},
    {{ "加温锅状态3",   KEY_STYLE1, },{ "——",    NONE_STYLE1 },{ "",    VAL_STYLE1 },},
    {{ "加温锅状态4",   KEY_STYLE2, },{ "——",    NONE_STYLE2 },{ "",    VAL_STYLE2 },},
    {{ "空气滤报警",   KEY_STYLE1, },{ "",    VAL_STYLE1 },{ "",    VAL_STYLE1 },},
    {{ "刹车",         KEY_STYLE2, },{ "——",    NONE_STYLE2 },{ "",    VAL_STYLE2 },}
};

static QPoint g_table3_pos = {0, 86};

static QSize g_table3_size[3] =
{
    {168, 39},
    {74,  39},
    {154, 39}
};

/********************************* page2->table4 *********************************/
static const LabelInfo g_label_table4[10][TAB_COL_NUM_MAX] =
{
    {{ "电压(V)",      KEY_STYLE1, },{ "",    VAL_STYLE1 },{ "——",    NONE_STYLE1 },{ "——",    NONE_STYLE1 },},
    {{ "转速(rpm)",    KEY_STYLE2, },{ "",    VAL_STYLE2 },{ "——",    NONE_STYLE2 },{ "——",    NONE_STYLE2 },},
    {{ "程控启动",     KEY_STYLE1, },{ "",    VAL_STYLE1 },{ "——",    NONE_STYLE1 },{ "——",    NONE_STYLE1 },},
    {{ "启动电机",     KEY_STYLE2, },{ "——",    NONE_STYLE2 },{ "",    VAL_STYLE2 },{ "",      VAL_STYLE2 },},
    {{ "累计启动次数", KEY_STYLE1, },{ "——",     NONE_STYLE1 },{ "——",   NONE_STYLE1 },{ "",      VAL_STYLE1 },},
    {{ "综合报警",     KEY_STYLE2, },{ "",    VAL_STYLE2 },{ "——",    NONE_STYLE2 },{ "——",    NONE_STYLE2 },},
    {{ "高辐射报警",   KEY_STYLE1, },{ "",    VAL_STYLE1 },{ "——",    NONE_STYLE1 },{ "——",    NONE_STYLE1 },},
    {{ "百叶窗关",     KEY_STYLE2, },{ "",    VAL_STYLE2 },{ "",    VAL_STYLE2 },{ "",      VAL_STYLE2 },},
    {{ "",             KEY_STYLE1, },{ "",   VAL_STYLE1 },{ "",   VAL_STYLE1 },{ "",      VAL_STYLE1 },},
    {{ "动力舱排水泵", KEY_STYLE2, },{ "",    VAL_STYLE2 },{ "",     VAL_STYLE2 },{ "",      VAL_STYLE2 },},
};

static QPoint g_table4_pos = {403, 86};

static QSize g_table4_size[4] =
{
    {176, 39},
    {74,  39},
    {74,  39},
    {70,  39},
};

/********************************* page2->table5 *********************************/
static const LabelInfo g_label_table5[3][TAB_COL_NUM_MAX] =
{
    {{ "机油温度(℃)",  KEY_STYLE2, },{ "——", NONE_STYLE2 },{ "",      VAL_STYLE2 },{ "",      VAL_STYLE2 },},
    {{ "空气滤地",     KEY_STYLE1, },{ "",    VAL_STYLE1 },{ "——",      NONE_STYLE1 },{ "——",      NONE_STYLE1 },},
    {{ "进水报警",      KEY_STYLE2, },{ "",    VAL_STYLE2 },{ "",      VAL_STYLE2 },{ "",      VAL_STYLE2 },},
};

static QPoint g_table5_pos = {0, 354};

static QSize g_table5_size[4] =
{
    {168, 39},
    {74,  39},
    {78,  39},
    {75,  39},
};

/********************************* page2->ui navigation map *****************************/
static const char* g_page2_map[][PAGE_NAVI_COL_MAX] =
{
    { "加温锅状态1",  "电压(V)"     ,},
    { "加温锅状态2",  "转速(rpm)",   },
    { "加温锅状态3",  "程控启动"    ,},
    { "加温锅状态4",  "启动电机"    ,},
    { "空气滤报警",   "累计启动次数",},
    { "刹车",         "综合报警"    ,},
    { "",             "高辐射报警",  },
    { "机油温度(℃)",  "百叶窗关"    ,},
    { "空气滤地",     ""            ,},
    { "进水报警",      "动力舱排水泵",}
};


/********************************* page1->start button *****************************/
static QRect g_start_rect = QRect(0, 432, 800, 40);
#define BUTTON_STYLE "background-color: rgb(31, 49, 87);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(255, 255, 255);\n"


/********************************* page2->subtitle *********************************/
static QRect g_subtitle2_rect = QRect(0, 314, 398, 38);
#define SUBTITLE2_STYLE "border-image:url(:/res/res/image/subtitle_dlc2.png);\n"



InstrPanel_DLC_A::InstrPanel_DLC_A(QWidget *parent) : PanelBase(parent)
{
    ENTER();
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("DLC_A"));

    Page* page1 = new Page(this);
    page1->AddTitle(g_title_rect, TITLE1_STYLE);
    Tab* table1 = new Tab(page1, 9, 3, g_label_table1, g_table1_pos, g_table1_size);
    page1->AddTable(table1);
    Tab* table2 = new Tab(page1, 9, 3, g_label_table2, g_table2_pos, g_table2_size);
    page1->AddTable(table2);
    page1->SetButton(g_start_rect, BUTTON_STYLE);
    //page1->SetNaviMap(g_page1_map, 9, 2);
    AddToPageList(page1);
    CreateTableMap(table1, g_label_table1, 9);
    CreateTableMap(table2, g_label_table2, 9);
    page1->CreateHlRect(398);

    Page* page2 = new Page(this);
    page2->AddTitle(g_title_rect, TITLE2_STYLE);
    Tab* table3 = new Tab(page2, 6, 3, g_label_table3, g_table3_pos, g_table3_size);
    page2->AddTable(table3);
    Tab* table4 = new Tab(page2, 10, 4, g_label_table4, g_table4_pos, g_table4_size);
    page2->AddTable(table4);
    Tab* table5 = new Tab(page2, 3, 4, g_label_table5, g_table5_pos, g_table5_size);
    page2->AddTable(table5);
    page2->AddTitle(g_subtitle2_rect, SUBTITLE2_STYLE);
    page2->SetNaviMap(g_page2_map, 10, 2);
    AddToPageList(page2);
    CreateTableMap(table3, g_label_table3, 6);
    CreateTableMap(table4, g_label_table4, 10);
    CreateTableMap(table5, g_label_table5, 3);
    page2->CreateHlRect(398);

    SetPageIndex(0);
    LEAVE();
}

static MsgInfo g_read_info_query[] =
{
	{ 1, "加温锅电源",    {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 1, 0},
	{ 2, "机油泵",		 {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },	DISPLAY_TYPE_STR, 1, 0},
	{ 3, "拖车泵",		 {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },	DISPLAY_TYPE_STR, 1, 0},
	{ 4, "百叶窗开",	  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 1, 0},
	{ 5, "排污阀",		 {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },	DISPLAY_TYPE_STR, 1, 0},
	{ 6, "电喇叭",		 {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },	DISPLAY_TYPE_STR, 1, 0},
	{ 7, "前大灯强",	  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 1, 0},
	{ 8, "前大灯弱",	  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 1, 0},
	{ 9, "防空灯强",	  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 1, 0},
	{ 10, "加温锅电源",   {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 11, "机油泵",		 {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },	DISPLAY_TYPE_STR, 2, 0},
	{ 12, "拖车泵",		 {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },	DISPLAY_TYPE_STR, 2, 0},
	{ 13, "百叶窗开",	  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 14, "排污阀",		 {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },	DISPLAY_TYPE_STR, 2, 0},
	{ 15, "电喇叭",		 {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },	DISPLAY_TYPE_STR, 2, 0},
	{ 16, "前大灯强",	  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 17, "前大灯弱",	  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 18, "防空灯强",	  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 19, "防空灯弱",	  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 1, 0},
	{ 20, "前左转向灯",   {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 1, 0},
	{ 21, "前右转向灯",   {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 1, 0},
	{ 22, "前示廓灯",	  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 1, 0},
	{ 23, "进气预热",	  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 1, 0},
	{ 24, "发动机放气阀", {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 1, 0},
	{ 25, "热烟幕阀",	  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 1, 0},
	{ 26, "加温锅控制",   {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 1, 0},
	{ 27, "敌我识别",	  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 1, 0},
	{ 28, "防空灯弱",	  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 29, "前左转向灯",   {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 30, "前右转向灯",   {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 31, "前示廓灯",	  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 32, "进气预热",	  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 33, "发动机放气阀", {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 34, "热烟幕阀",	  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 35, "加温锅控制",   {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 36, "敌我识别",	  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 37, "加温锅状态1",  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 38, "加温锅状态2",  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 39, "加温锅状态3",  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 40, "加温锅状态4",  {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 41, "空气滤报警",   {{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 42, "刹车", 		{{ 0, "", WHITE},{ 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3,"正确", GREEN}, { 4,"错误", RED}, { 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
	{ 43, "空气滤报警",   {{ 0, "", WHITE},{ 9, "0V",	 RED},	{11, "24V", GREEN}, }, DISPLAY_TYPE_STR, 1, 0},
	{ 44, "空气滤地",	  {{ 0, "", WHITE},{ 11, "24V", RED},  { 9, "0V",  GREEN}, }, DISPLAY_TYPE_STR, 1, 0},
	{ 45, "进水报警",	  {{ 0, "", WHITE},{ 9, "0V",	RED},  {11, "24V", GREEN}, }, DISPLAY_TYPE_STR, 1, 0},
	{ 46, "机油温度(℃)",	  {{0, "", GREEN}, }, DISPLAY_TYPE_INT, 3, -50},
	{ 47, "进水报警",	  {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, }, DISPLAY_TYPE_STR, 3, 0},
	{ 48, "启动电机",	  {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, }, DISPLAY_TYPE_STR, 2, 0},
	{ 49, "百叶窗关",	  {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, }, DISPLAY_TYPE_STR, 2, 0},
	{ 50, "动力舱排水泵", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, }, DISPLAY_TYPE_STR, 2, 0},
	{ 51, "启动电机",	  {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW},{ 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, }, DISPLAY_TYPE_STR, 3, 0},
	{ 52, "累计启动次数", {{0, "", GREEN}, }, DISPLAY_TYPE_INT, 3, 0},
	{ 53, "百叶窗关",	  {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW},{ 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, }, DISPLAY_TYPE_STR, 3, 0},
	{ 54, "动力舱排水泵", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW},{ 49,"过流", RED}, { 50,"过压", RED}, { 51,"短路", RED}, { 52,"过温", RED}, }, DISPLAY_TYPE_STR, 3, 0},
};

void InstrPanel_DLC_A::RecvMsg(unsigned char* msg, int size)
{
	ENTER();
    ShowState(msg, size, g_read_info_query, sizeof(g_read_info_query)/sizeof(g_read_info_query[0]));
}

static MsgInfo_out g_out_info[] =
{
    { 'A', "空气滤负压", 2, {{ 91, "报警", ORANGE}, { 92, "正常"  , ORANGE },                                                                               }, 2 },
    { 'B', "刹车",       2, {{ 93, "刹车", ORANGE}, { 92, "正常"  , ORANGE },                                                                               }, 2 },
    { 'C', "机油温度",   2, {{ 2,  "关断", ORANGE}, { 33, "-50℃" , ORANGE }, {  34, "0℃"    , ORANGE},  {   35, "100℃", ORANGE},  { 36,"115℃", ORANGE},  }, 2 },
    { 'D', "分动箱油温", 2, {{ 2,  "关断", ORANGE}, { 33, "-50℃" , ORANGE }, {  34, "0℃"    , ORANGE},  {   35, "100℃", ORANGE},  { 36,"115℃", ORANGE},  }, 2 },
    { 'E', "润滑油压",   2, {{ 2,  "关断", ORANGE}, { 102,"0.1"   , ORANGE }, { 103, "0.4"   , ORANGE},  {  104, "0.6"  , ORANGE},  {105, "1.5" , ORANGE},  }, 2 },
    { 'F', "发动机转速", 2, {{ 2,  "关断", ORANGE}, { 15, "480rpm", ORANGE }, {  16, "520rpm", ORANGE},                                                     }, 2 },
    { 'G', "发动机水温", 2, {{ 2,  "关断", ORANGE}, { 107,"70℃"  , ORANGE }, { 108, "80℃"   , ORANGE},  { 109, "92℃"  , ORANGE},                          }, 2 },
    { 'H', "变矩器油温", 2, {{ 2,  "关断", ORANGE}, { 108,"80℃"  , ORANGE }, { 110, "90℃"   , ORANGE},  { 111, "102℃" , ORANGE},                          }, 2 },
    { 'I', "蓄电池电压", 2, {{ 12, "28V" , ORANGE}, { 9,  "0V"    , ORANGE },                                                                               }, 2 },
    { 'J', "动力舱火警", 2, {{ 91, "报警", ORANGE}, { 92, "正常"  , ORANGE },                                                                               }, 1 },
    { 'K', "高辐射报警", 2, {{ 91, "报警", ORANGE}, { 92, "正常"  , ORANGE },                                                                               }, 1 },
    { 'L', "百叶窗关",   2, {{ 1,  "接通", ORANGE}, { 2,  "关断"  , ORANGE },                                                                               }, 1 },
    { 'M', "风扇自动",   2, {{ 95, "自动", ORANGE}, { 96, "手动"  , ORANGE },                                                                               }, 1 },
};

void InstrPanel_DLC_A::SetValue(const QString& name, int val)
{
	ENTER();
	SetSpecValue(name, val, g_out_info, sizeof(g_out_info)/sizeof(g_out_info[0]));
}

OutType InstrPanel_DLC_A::CheckOutUnitType(const QString& name)
{
	static QMap<QString, int> omap;
	if (omap.size() == 0)
	{
		omap["进水报警"] = TYPE_OPT_OFFON;
		omap["电压(V)"] = TYPE_OPT_OFFON;
		omap["程控启动"] = TYPE_OPT_OFFON;
		omap["综合报警"] = TYPE_OPT_OFFON;
		omap["高辐射报警"] = TYPE_OPT_OFFON;
		omap["百叶窗关"] = TYPE_OPT_OFFON;
		omap["动力舱排水泵"] = TYPE_OPT_OFFON;
		
		omap["机油温度(℃)"] = TYPE_OPT_TUNE;
		omap["转速(rpm)"] = TYPE_OPT_TUNE;
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



static MsgInfo_out g_out_info_ckqd[] =
{
    {'E', "程控启动"    , 2, { { 1,"接通", ORANGE}, {  2,"关断"    , ORANGE}, }, 1},
};

KeyHandleState InstrPanel_DLC_A::keyEvent(const KeyInfo & keyinfo)
{
	ENTER();
	if (keyinfo.keyid == KEY_CKQD && IsTestStarted() && !IsAutoTestState())
	{
        int val = (keyinfo.data == 0 ? 1 : 0);
		SetSpecValue("程控启动", val, g_out_info_ckqd, sizeof(g_out_info_ckqd)/sizeof(g_out_info_ckqd[0]));
	}
	else
	{
		PanelBase::keyEvent(keyinfo);
	}

    return KEY_HANDLED;
}


#if 0
static MsgInfo g_can_read_info_query[] =
{
    {4,	0, 5,	0, "加温锅电源", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "机油泵", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},

    {4,	0, 5,	0, "拖车泵", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "百叶窗开", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},

    {4,	0, 5,	0, "排污阀", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "电喇叭", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},

    {4,	0, 5,	0, "前大灯强", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "前大灯弱", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},

    {4,	0, 5,	0, "防空灯强", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "防空灯弱", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},

    {4,	0, 5,	0, "前左转向灯", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "前右转向灯", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},

    {4,	0, 5,	0, "前示廓灯", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "进气预热", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},

    {4,	0, 5,	0, "发动机放气阀", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
    {4,	0, 5,	0, "热烟幕阀", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},

	{4, 0, 5,	0, "加温锅控制", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},
	{4, 0, 5,	0, "敌我识别", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 2},

	{4, 0, 5,	0, "百叶窗关", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 3},
	{4, 0, 5,	0, "动力舱排水泵", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 3},

	{4, 0, 5,	0, "启动电机", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_STR, 3},
	{4, 0, 15,	0, "加温锅状态", {{"关闭", RED}, {"打开", GREEN}, {"过流", RED}, {"过压", RED}, {"短路", RED}, {"过温",RED},}, DISPLAY_TYPE_BINARY, 2},

    {1,	0, 1,	0, "刹车",       {{"未刹车", RED}, {"未刹车", GREEN},}, DISPLAY_TYPE_STR, 2},
    {1,	0, 1,	0, "进水报警", {{"未报警", RED}, {"报警", GREEN},}, DISPLAY_TYPE_STR, -1},  //?
	{1, 0, 1,	0, "空气滤报警", {{"未报警", RED}, {"报警", GREEN},}, DISPLAY_TYPE_STR, -1},//?
	{5, 0, 1,	0, "", {}, DISPLAY_TYPE_RESERVED, 2},

    {16, 0, 65536,	0, "累计启动次数",{}, DISPLAY_TYPE_INT, 3},

    { 8, 0, 250,  -50, "机油温度(℃)",{}, DISPLAY_TYPE_INT, 3}
};

void InstrPanel_DLC_A::GetCanState(unsigned char* msg, int msg_size)
{
    ShowState(msg, msg_size, g_can_read_info_query, sizeof(g_can_read_info_query)/sizeof(g_can_read_info_query[0]));
}

static MsgInfo g_io_read_info_query[] =
{
    {1, 0, 1,	0, "前左转向灯",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
    {1, 0, 1,	0, "前大灯强",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "防空灯强",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "前示廓灯",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "前右转向灯",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "百叶窗开",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "百叶窗关",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 2},
	{1, 0, 1,	0, "排污阀",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},

	{1, 0, 1,	0, "电喇叭",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "前大灯弱",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "防空灯弱",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "启动电机",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 2},
	{1, 0, 1,	0, "机油泵",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "拖车泵",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "动力舱排水泵",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 2},
	{1, 0, 1,	0, "敌我识别",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},

	{1, 0, 1,	0, "加温锅电源",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "发动机放气阀",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "空气滤报警",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, -1}, //?
	{1, 0, 1,	0, "进水报警",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, -1},   //?
	{1, 0, 1,	0, "加温锅控制",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "热烟幕阀",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "进气预热",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 1},
	{1, 0, 1,	0, "空气滤地",{{"关闭", RED}, {"打开", GREEN},}, DISPLAY_TYPE_STR, 3}
};

void InstrPanel_DLC_A::GetIoState(unsigned char* msg, int msg_size)
{
    ShowState(msg, msg_size, g_io_read_info_query, sizeof(g_io_read_info_query)/sizeof(g_io_read_info_query[0]));
}

OutType InstrPanel_DLC_A::CheckOutUnitType(QString name)
{
	static QMap<QString, int> map;
	if (map.size() == 0)
	{
		map["主电源输出"] = TYPE_IO;
		map["进水报警"] =       TYPE_IO;
		map["加温锅状态1"]       = TYPE_IO;
		map["加温锅状态2"]     = TYPE_IO;
		map["加温锅状态3"]     = TYPE_IO;
		map["加温锅状态4"] = TYPE_IO;
		map["手动启动开关"] = TYPE_IO; //?
		map["程控启动开关"] = TYPE_IO; //?
		map["采集刹车开关地信号"] = TYPE_IO; //?
		map["空气滤负压传感器地信号"] = TYPE_IO; //?
		map["起动机反馈电压"] = TYPE_IO; //?
		map["机油温度(℃)"] = TYPE_IO;

		map["电压(V)"]     = TYPE_CAN;
		map["转速(rpm)"]   = TYPE_CAN;
		map["程控启动"]      = TYPE_CAN;
		map["综合报警"]      = TYPE_CAN;
		map["高辐射报警"]     = TYPE_CAN;
	}

	int type = map[name];
	PRINT("name[%s]'s type is %d\n", name.toStdString().c_str(), type);
	return (OutType)type;
}


#if 0
static MsgInfo_out g_io_out_info[] =
{
	{8, 0, "主电源输出", 2, {{"关闭", RED}, {"打开", GREEN}, }, -1},

	{1, 0, "进水报警",       2, {{"关闭", RED}, {"打开", GREEN}, }, -1},
	{1, 0, "加温锅状态1",     2, {{"关闭", RED}, {"打开", GREEN}, },  2},
	{1, 0, "加温锅状态2",	   2, {{"关闭", RED}, {"打开", GREEN}, },  2},
	{1, 0, "加温锅状态3",	   2, {{"关闭", RED}, {"打开", GREEN}, },  2},
	{1, 0, "加温锅状态4",	   2, {{"关闭", RED}, {"打开", GREEN}, },  2},
	{1, 0, "手动启动开关",	   2, {{"关闭", RED}, {"打开", GREEN}, },  -1}, //?
	{1, 0, "程控启动开关",	   2, {{"关闭", RED}, {"打开", GREEN}, },  -1}, //?
	{1, 0, "采集刹车开关地信号",	   2, {{"关闭", RED}, {"打开", GREEN}, },  -1}, //?

	{1, 0, "空气滤负压传感器地信号",	   2, {{"关闭", RED}, {"打开", GREEN}, },  -1}, //?
	{1, 0, "起动机反馈电压",	   2, {{"关闭", RED}, {"打开", GREEN}, },  -1}, //?
	{6, 0, "",	1, {},  -1}, //?

	{8, 0, "机油温度(℃)", 5, {{"无穷大", RED}, {"0803Ω", GREEN}, {"1000Ω", GREEN}, {"1385Ω", GREEN}, {"1442Ω", GREEN}}, 2}
};

void InstrPanel_DLC_A::SetIoOut(QString name, int val)
{
	GenerateOutMsg(TYPE_IO, g_io_out_info, sizeof(g_io_out_info)/sizeof(g_io_out_info[0]), name, val);
}

static MsgInfo_out g_can_out_info[] =
{
	{1, 0, "电压(V)",     2,  {{"关闭", RED}, {"打开", GREEN}, },  1},
	{1, 0, "转速(rpm)", 2,  {{"关闭", RED}, {"打开", GREEN}, },  1},
	{1, 0, "程控启动",      2,  {{"关闭", RED}, {"打开", GREEN}, },      1},
	{1, 0, "综合报警",      2,  {{"关闭", RED}, {"打开", GREEN},     },  1},
	{1, 0, "高辐射报警",2,       {{"关闭", RED}, {"打开", GREEN},     },  1},
	{3, 0, "",          2,  { },  -1},
};

void InstrPanel_DLC_A::SetCanOut(QString name, int val)
{
	GenerateOutMsg(TYPE_CAN, g_can_out_info, sizeof(g_can_out_info)/sizeof(g_can_out_info[0]), name, val);
}

void InstrPanel_DLC_A::resetOutInfo()
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

void InstrPanel_DLC_A::SwitchMainPower(bool flag)
{
	PRINT("flag: %d\n", (int)flag);
	SetIoOut("主电源输出", (int)flag);
}
#endif
#endif

