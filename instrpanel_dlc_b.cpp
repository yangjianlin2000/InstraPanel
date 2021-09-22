#include "instrpanel_dlc_b.h"
#include "common.h"


#define KEY_STYLE1 "background-color: rgb(13, 25, 43);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(215, 230, 254);\n" \
                    "padding-left: 4px"
                    
#define KEY_STYLE2 "background-color: rgb(6, 17, 35);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(215, 230, 254);\n" \
                    "padding-left: 4px"

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


/********************************* page1->title *********************************/
static QRect g_title_rect = QRect(0, 0, 800, 86);

#define TITLE1_STYLE "border-image:url(:/res/res/image/title_dlc_b1.png);\n"


/********************************* page1->table1 *********************************/
static const LabelInfo g_label_table1[][TAB_COL_NUM_MAX] =
{
    {{"机油泵"    ,   KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1},},
    {{"前示廓灯"  ,   KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2},},
    {{"百叶窗开"  ,   KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1},},
    {{"前大灯强"  ,   KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2},},
    {{"前大灯弱"  ,   KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1},},
    {{"左前转向灯",   KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2},},
    {{"右前转向灯",   KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1},},
    {{"电喇叭"    ,   KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2},},
    {{""          ,   KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1},},
};

static QPoint g_table1_pos = {0, 86};

static QSize g_table1_size[] =
{
    {168, 38},
    {110, 38},
    {116, 38}
};

/********************************* page1->table2 *********************************/
static const LabelInfo g_label_table2[][TAB_COL_NUM_MAX] =
{
    {{"防空灯强"  ,   KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1},},
    {{"防空灯弱"  ,   KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2},},
    {{"百叶窗关"  ,   KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1},},
    {{"进气预热器",   KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2},},
    {{"拖车泵"    ,   KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1},},
    {{"抽油阀"    ,   KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2},},
    {{"放气阀"    ,   KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1},},
    {{"排污阀"    ,   KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2},},
    {{""          ,   KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1},},
};

static QPoint g_table2_pos = {403, 86};

static QSize g_table2_size[] =
{
    {168, 38},
    {110, 38},
    {116, 38}
};

/********************************* page1->start button *****************************/
static QRect g_start_rect = QRect(0, 432, 800, 40);
#define BUTTON_STYLE "background-color: rgb(31, 49, 87);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(255, 255, 255);\n"


/********************************* page1->ui navigation map *****************************/
static const char* g_page1_map[][PAGE_NAVI_COL_MAX] =
{
    {"机油泵"    , "防空灯强"  },
    {"前示廓灯"  , "防空灯弱"  },
    {"百叶窗开"  , "百叶窗关"  },
    {"前大灯强"  , "进气预热器"},
    {"前大灯弱"  , "拖车泵"    },
    {"左前转向灯", "抽油阀"    },
    {"右前转向灯", "放气阀"    },
    {"电喇叭"    , "排污阀"    },
};


/********************************* page2->title *********************************/
#define TITLE2_STYLE "border-image:url(:/res/res/image/title_dlc_b2.png);\n"


/********************************* page2->table3 *********************************/
static const LabelInfo g_label_table3[][TAB_COL_NUM_MAX] =
{
    {{"空气滤负压"         ,KEY_STYLE1}, {"", VAL_STYLE1},{"", VAL_STYLE1},{"", VAL_STYLE1},},
    {{"刹车"           ,KEY_STYLE2}, {"——", NONE_STYLE2},{"", VAL_STYLE2},{"", VAL_STYLE2},},
    {{"机油温度(℃)"    ,KEY_STYLE1}, {"——", NONE_STYLE1},{"", VAL_STYLE1},{"", VAL_STYLE1},},
    {{"分动箱油温(℃)"  ,KEY_STYLE2}, {"——", NONE_STYLE2},{"", VAL_STYLE2},{"", VAL_STYLE2},},
    {{"润滑油压(MPa)"       ,KEY_STYLE1}, {"", VAL_STYLE1},{"", VAL_STYLE1},{"", VAL_STYLE1},},
    {{""  ,KEY_STYLE2}, {"", NONE_STYLE2},{"", VAL_STYLE2},{"", VAL_STYLE2},},
};

static QPoint g_table3_pos = {0, 84};

static QSize g_table3_size[] =
{
    {179, 36},
    {72, 36},
    {72, 36},
    {72, 36}
};

/********************************* page2->table4 *********************************/
static const LabelInfo g_label_table4[][TAB_COL_NUM_MAX] =
{
    {{"发动机转速", KEY_STYLE2}, {"——", NONE_STYLE2},{"", VAL_STYLE2},{"——", NONE_STYLE2},},
    {{"发动机水温(℃)"  , KEY_STYLE1}, {"——", NONE_STYLE1},{"", VAL_STYLE1},{"——", NONE_STYLE1},},
    {{"变矩器油温(℃)",   KEY_STYLE2}, {"——", NONE_STYLE2},{"", VAL_STYLE2},{"——", NONE_STYLE2},},
    {{"蓄电池电压(V)",   KEY_STYLE1}, {"——", NONE_STYLE1},{"", VAL_STYLE1},{"——", NONE_STYLE1},},
};

static QPoint g_table4_pos = {0, 336};

static QSize g_table4_size[] =
{
    {179, 36},
    {72, 36},
    {72, 36},
    {72, 36}
};

/********************************* page2->table5 *********************************/
static const LabelInfo g_label_table5[][TAB_COL_NUM_MAX] =
{
    {{"动力舱火警"   ,KEY_STYLE1}, {"", VAL_STYLE1},{"——", NONE_STYLE1},{"——", NONE_STYLE1},},
    {{"高辐射报警"   ,KEY_STYLE2}, {"", VAL_STYLE2},{"——", NONE_STYLE2},{"——", NONE_STYLE2},},
    {{"百叶窗关 "     ,KEY_STYLE1}, {"", VAL_STYLE1},{"", VAL_STYLE1},{"", VAL_STYLE1},},
    {{""             ,KEY_STYLE2}, {"", VAL_STYLE2},{"", VAL_STYLE2},{"", VAL_STYLE2},},
    {{"起动电机"     ,KEY_STYLE1}, {"——", NONE_STYLE1},{"", VAL_STYLE1},{"", VAL_STYLE1},},
    {{""             ,KEY_STYLE2}, {"", VAL_STYLE2},{"", VAL_STYLE2},{"", VAL_STYLE2},},
    {{"风扇自动"     ,KEY_STYLE1}, {"", VAL_STYLE1},{"——", NONE_STYLE1},{"——", NONE_STYLE1},},
    {{"风扇电磁阀1"  ,KEY_STYLE2}, {"——", NONE_STYLE2},{"", VAL_STYLE2},{"", VAL_STYLE2},},
    {{"风扇电磁阀2"  ,KEY_STYLE1}, {"——", NONE_STYLE1},{"", VAL_STYLE1},{"", VAL_STYLE1},},
    {{"风扇状态指示" ,KEY_STYLE2}, {"——", NONE_STYLE2},{"——", NONE_STYLE2},{"", VAL_STYLE2},},
    {{""  ,KEY_STYLE1}, {"——", NONE_STYLE1},{"", VAL_STYLE1},{"", VAL_STYLE1},},
};

static QPoint g_table5_pos = {403, 84};

static QSize g_table5_size[] =
{
    {179, 36},
    {72, 36},
    {72, 36},
    {72, 36}
};

/********************************* page1->subtitle *********************************/
static QRect g_subtitle1_rect = QRect(0, 300, 398, 36);

#define SUBTITLE1_STYLE "border-image:url(:/res/res/image/subtitle_dlc_b2.png);\n"


/********************************* page2->ui navigation map *****************************/
static const char* g_page2_map[][PAGE_NAVI_COL_MAX] =
{
    {"空气滤负压"         , "动力舱火警" },
    {"刹车"           , "高辐射报警" },
    {"机油温度(℃)"    , "百叶窗关 "   },
    {"分动箱油温(℃)"  , ""          },
    {"润滑油压(MPa)"       , "起动电机"    },
    {""               , "风扇自动"  },
    {"发动机转速", "风扇电磁阀1" },
    {"发动机水温(℃)"  , "风扇电磁阀2" },
    {"变矩器油温(℃)",   "风扇状态指示"},
    {"蓄电池电压(V)",  ""},
};


InstrPanel_DLC_B::InstrPanel_DLC_B(QWidget* parent): PanelBase(parent)
{
    ENTER();
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("DLC_B"));

    Page* page1 = new Page(this);
    page1->AddTitle(g_title_rect, TITLE1_STYLE);
    Tab* table1 = new Tab(page1, 9, 3, g_label_table1, g_table1_pos, g_table1_size);
    page1->AddTable(table1);
    Tab* table2 = new Tab(page1, 9, 3, g_label_table2, g_table2_pos, g_table2_size);
    page1->AddTable(table2);
    page1->SetButton(g_start_rect, BUTTON_STYLE);
    //page1->SetNaviMap(g_page1_map, 8, 2);
    AddToPageList(page1);
    CreateTableMap(table1, g_label_table1, 8);
    CreateTableMap(table2, g_label_table2, 8);
    page1->CreateHlRect(398);

    Page* page2 = new Page(this);
    page2->AddTitle(g_title_rect, TITLE2_STYLE);
    Tab* table3 = new Tab(page2, 6, 4, g_label_table3, g_table3_pos, g_table3_size);
    page2->AddTable(table3);
    Tab* table4 = new Tab(page2, 4, 4, g_label_table4, g_table4_pos, g_table4_size);
    page2->AddTable(table4);
    Tab* table5 = new Tab(page2, 11, 4, g_label_table5, g_table5_pos, g_table5_size);
    page2->AddTable(table5);
    page2->AddTitle(g_subtitle1_rect, SUBTITLE1_STYLE);
    page2->SetNaviMap(g_page2_map, 10, 2);
    AddToPageList(page2);
    CreateTableMap(table3, g_label_table3, 5);
    CreateTableMap(table4, g_label_table4, 4);
    CreateTableMap(table5, g_label_table5, 10);
    page2->CreateHlRect(398);

    SetPageIndex(0);

    LEAVE();
}

QString displayStr_rhyy(int dip)
{
    QString ret("");
    int integar = dip/1000;
    int decimal = dip%1000/100;
    ret = QString::number(integar) + "." + QString::number(decimal);
    return ret; 
}

static MsgInfo g_read_info_query[] =
{
    { 1, "机油泵",       { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, },  DISPLAY_TYPE_STR, 1, 0},
    { 2, "前示廓灯",     { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, },  DISPLAY_TYPE_STR, 1, 0},
    { 3, "百叶窗开",     { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, },  DISPLAY_TYPE_STR, 1, 0},
    { 4, "前大灯强",     { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, },  DISPLAY_TYPE_STR, 1, 0},
    { 5, "前大灯弱",     { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, },  DISPLAY_TYPE_STR, 1, 0},
    { 6, "左前转向灯",   { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, },  DISPLAY_TYPE_STR, 1, 0},
    { 7, "右前转向灯",   { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, },  DISPLAY_TYPE_STR, 1, 0},
    { 8, "电喇叭",       { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, },  DISPLAY_TYPE_STR, 1, 0},
    { 9, "防空灯强",     { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, },  DISPLAY_TYPE_STR, 1, 0},
    {10, "防空灯弱",     { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, },  DISPLAY_TYPE_STR, 1, 0},
    {11, "百叶窗关",     { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, },  DISPLAY_TYPE_STR, 1, 0},
    {12, "进气预热器",   { { 0,NULL, WHITE},    {97,"——",  WHITE},                                                        },  DISPLAY_TYPE_STR, 1, 0},
    {13, "拖车泵",       { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, },  DISPLAY_TYPE_STR, 1, 0},
    {14, "抽油阀",       { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, },  DISPLAY_TYPE_STR, 1, 0},
    {15, "放气阀",       { { 0,NULL, WHITE},    {97,"——",  WHITE},                                                       },  DISPLAY_TYPE_STR, 1, 0},
    {16, "排污阀",       { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, },  DISPLAY_TYPE_STR, 1, 0},

    {17, "机油泵",       { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
    {18, "前示廓灯",     { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
    {19, "百叶窗开",     { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
    {20, "前大灯强",     { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
    {21, "前大灯弱",     { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
    {22, "左前转向灯",   { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
    {23, "右前转向灯",   { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
    {24, "电喇叭",       { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
    {25, "防空灯强",     { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
    {26, "防空灯弱",     { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
    {27, "百叶窗关",     { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
    {28, "进气预热器",   { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
    {29, "拖车泵",       { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
    {30, "抽油阀",       { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
    {31, "放气阀",       { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},
    {32, "排污阀",       { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {3, "正确",  GREEN}, {4, "错误", RED}, {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 2, 0},

    {33, "空气滤负压",   { { 0,NULL, WHITE},    { 92,"正常", GREEN},{ 94,"故障", RED},  },  DISPLAY_TYPE_STR, 1, 0},
    {34, "润滑油压(MPa)",     { { 0,NULL, WHITE},    { 92,"正常", GREEN},{ 94,"故障", RED}, },  DISPLAY_TYPE_STR, 1, 0},

    {35, "空气滤负压",   { { 0,NULL, WHITE},    { 92,"正常", GREEN},{ 91,"报警", YELLOW}, },  DISPLAY_TYPE_STR, 3, 0},
    {36, "刹车",         { { 0,NULL, WHITE},    { 92,"正常", GREEN},{ 93,"刹车", YELLOW}, },  DISPLAY_TYPE_STR, 3, 0},
    {37, "机油温度(℃)",     { { 0,NULL, WHITE},     },  DISPLAY_TYPE_STR, 3, -50},
    {38, "分动箱油温(℃)",   { { 0,NULL, WHITE},      },  DISPLAY_TYPE_STR, 3, -50},
    {39, "润滑油压(MPa)",     { { 0,NULL, WHITE},     },  DISPLAY_TYPE_STR, 3, 0, displayStr_rhyy},
    {40, "百叶窗关 ",     { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW}, },  DISPLAY_TYPE_STR, 2, 0},
    {41, "起动电机",     { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW}, },  DISPLAY_TYPE_STR, 2, 0},
    {42, "风扇电磁阀1",  { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW}, },  DISPLAY_TYPE_STR, 2, 0},
    {43, "风扇电磁阀2",  { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW}, },  DISPLAY_TYPE_STR, 2, 0},
    {44, "百叶窗关 ",     { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 3, 0},
    {45, "风扇电磁阀1",  { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 3, 0},
    {46, "风扇电磁阀2",  { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 3, 0},
    {47, "风扇状态指示", { { 0,NULL, WHITE},    { 2,"关断", YELLOW},  {99,"低速", YELLOW}, {100,"高速", YELLOW},                   },  DISPLAY_TYPE_STR, 1, 0},
    {48, "起动电机",     { { 0,NULL, WHITE},    { 1,"接通", YELLOW},  { 2,"关断", YELLOW},  {49,"过流", RED},   { 50,"过压", RED},   { 51,"短路", RED},  { 52,"过温", RED}, },  DISPLAY_TYPE_STR, 3, 0},
};


void InstrPanel_DLC_B::RecvMsg(unsigned char* msg, int size)
{
	ENTER();
    ShowState(msg, size, g_read_info_query, sizeof(g_read_info_query)/sizeof(g_read_info_query[0]));
}

static MsgInfo_out g_out_info[] =
{
    { 'A', "空气滤负压", 2, {{ 91, "报警", ORANGE}, { 92, "正常"  , ORANGE },                                                                               }, 2 },
    { 'B', "刹车",         2, {{ 93, "刹车", ORANGE}, { 92, "正常"  , ORANGE },                                                                               }, 2 },
    { 'C', "机油温度(℃)",       5, {{ 2,  "关断", ORANGE}, { 33, "-50℃" , ORANGE }, {  34, "0℃"    , ORANGE},  {   35, "100℃", ORANGE},  { 36,"115℃", ORANGE},  }, 2 },
    { 'D', "分动箱油温(℃)", 5, {{ 2,  "关断", ORANGE}, { 33, "-50℃" , ORANGE }, {  34, "0℃"    , ORANGE},  {   35, "100℃", ORANGE},  { 36,"115℃", ORANGE},  }, 2 },
    { 'E', "润滑油压(MPa)",       5, {{ 2,  "关断", ORANGE}, { 102,"0.1"   , ORANGE }, { 103, "0.4"   , ORANGE},  {  104, "0.6"  , ORANGE},  {105, "1.5" , ORANGE},  }, 2 },
    { 'F', "发动机转速", 3, {{ 2,  "关断", ORANGE}, { 15, "480", ORANGE }, {  16, "520", ORANGE},                                                     }, 2 },
    { 'G', "发动机水温(℃)", 4, {{ 2,  "关断", ORANGE}, { 107,"70℃"  , ORANGE }, { 108, "80℃"   , ORANGE},  { 109, "92℃"  , ORANGE},                          }, 2 },
    { 'H', "变矩器油温(℃)", 4, {{ 2,  "关断", ORANGE}, { 108,"80℃"  , ORANGE }, { 110, "90℃"   , ORANGE},  { 111, "102℃" , ORANGE},                          }, 2 },
    { 'I', "蓄电池电压", 2, {{ 12, "28V" , ORANGE}, { 9,  "0V"    , ORANGE },                                                                               }, 2 },
    { 'J', "动力舱火警", 2, {{ 91, "报警", ORANGE}, { 92, "正常"  , ORANGE },                                                                               }, 1 },
    { 'K', "高辐射报警", 2, {{ 91, "报警", ORANGE}, { 92, "正常"  , ORANGE },                                                                               }, 1 },
    { 'L', "百叶窗关 ",       2, {{ 1,  "接通", ORANGE}, { 2,  "关断"  , ORANGE },                                                                               }, 1 },
    { 'M', "风扇自动",       2, {{ 95, "自动", ORANGE}, { 96, "手动"  , ORANGE },                                                                               }, 1 },
};

void InstrPanel_DLC_B::SetValue(const QString& name, int val)
{
	ENTER();
	SetSpecValue(name, val, g_out_info, sizeof(g_out_info)/sizeof(g_out_info[0]));
}

OutType InstrPanel_DLC_B::CheckOutUnitType(const QString& name)
{
	static QMap<QString, int> omap;
	if (omap.size() == 0)
	{
        omap["空气滤负压"] = TYPE_OPT_OFFON;
        omap["刹车"] = TYPE_OPT_OFFON;
        omap["蓄电池电压"] = TYPE_OPT_OFFON;
        omap["动力舱火警"] = TYPE_OPT_OFFON;
        omap["高辐射报警"] = TYPE_OPT_OFFON;
        omap["百叶窗关 "] = TYPE_OPT_OFFON;
        omap["风扇自动"] = TYPE_OPT_OFFON;
        
        omap["机油温度(℃)"] = TYPE_OPT_TUNE;
        omap["分动箱油温(℃)"] = TYPE_OPT_TUNE;
        omap["润滑油压(MPa)"] = TYPE_OPT_TUNE;
        omap["发动机转速"] = TYPE_OPT_TUNE;
        omap["发动机水温(℃)"] = TYPE_OPT_TUNE;
        omap["变矩器油温(℃)"] = TYPE_OPT_TUNE;
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


