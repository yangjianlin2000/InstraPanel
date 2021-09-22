#include "instrpanel_jsc_c.h"
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

#define TITLE1_STYLE "border-image:url(:/res/res/image/title_jsc_c1.png);\n"


/********************************* page1->subtitle *********************************/
static QRect g_subtitle1_rect = QRect(0, 275, 800, 38);

#define SUBTITLE1_STYLE "border-image:url(:/res/res/image/subtitle_jsc_c1.png);\n"


/********************************* page1->table1 *********************************/
static const LabelInfo g_label_table1[][TAB_COL_NUM_MAX] =
{
    {{"空气起动",    KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, },
    {{"后示廓灯",    KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, },
    {{"左后转向灯",  KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, },
    {{"右后转向灯",  KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, },
    {{"",            KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, },
    {{"",            KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, },
    {{"驾驶员辅助显示盒",KEY_STYLE1},{"", VAL_STYLE1},{"", VAL_STYLE1},},
    {{"充电机",      KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, },
    {{"毒剂报警盒",  KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, },
};

static QPoint g_table1_pos = {0, 86};

static QSize g_table1_size[] =
{
    {160, 38},
    {118, 38},
    {118, 38}
};

/********************************* page1->table2 *********************************/
static const LabelInfo g_label_table2[][TAB_COL_NUM_MAX] =
{
    {{"刹车灯",        KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, },
    {{"夜视仪",        KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, },
    {{"潜望镜加温",    KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, },
    {{"报警灯",        KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, },
    {{"",              KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, },
    {{"",              KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, },
    {{"辐射报警盒",    KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, },
    {{"微压差探测",    KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, },
    {{"灭火控制盒",    KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, },
};

static QPoint g_table2_pos = {403, 86};

static QSize g_table2_size[] =
{
    {160, 38},
    {118, 38},
    {118, 38}
};

/********************************* page1->start button *****************************/
static QRect g_start_rect = QRect(0, 432, 800, 40);
#define BUTTON_STYLE "background-color: rgb(31, 49, 87);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(255, 255, 255);\n"


/********************************* page1->ui navigation map *****************************/
const char* g_page1_map[][PAGE_NAVI_COL_MAX] =
{
    {"空气起动",         "刹车灯"},
    {"后示廓灯",         "夜视仪"},
    {"左后转向灯",       "潜望镜加温"},
    {"右后转向灯",       "报警灯"},
    {"驾驶员辅助显示盒",  "辐射报警盒"},
    {"充电机",          "微压差探测"},
    {"毒剂报警盒",       "灭火控制盒"}
};


/********************************* page2->title *********************************/
#define TITLE2_STYLE "border-image:url(:/res/res/image/title_jsc_c2.png);\n"


/********************************* page2->table3 *********************************/
static const LabelInfo g_label_table3[10][TAB_COL_NUM_MAX] =
{
    {{"低辐射报警",   KEY_STYLE1}, {"——", NONE_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, },
    {{"高辐射报警",   KEY_STYLE2}, {"——", NONE_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, },
    {{"毒剂报警",     KEY_STYLE1}, {"——", NONE_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, },
    {{"后门指示",     KEY_STYLE2}, {"——", NONE_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, },
    {{"舱门指示",     KEY_STYLE1}, {"——", NONE_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, },
    {{"左油量(L)",    KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, },
    {{"右前油量(L)",  KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, },
    {{"右后油量(L)",  KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, },
    {{"",             KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, },
    {{"蓄电池电压(V)",KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, },
};

static QPoint g_table3_pos = {0, 86};

static QSize g_table3_size[] =
{
    {179, 38},
    {72, 38},
    {72, 38},
    {72, 38}
};

/********************************* page2->table4 *********************************/
static const LabelInfo g_label_table4[10][TAB_COL_NUM_MAX] =
{
    {{"三防应急", KEY_STYLE1}, {"", VAL_STYLE1}, {"——", NONE_STYLE1}, {"——", NONE_STYLE1}, },
    {{"增压风机", KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, },
    {{"充气阀",   KEY_STYLE1}, {"——", NONE_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, },
    {{"",         KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, },
    {{"",         KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, },
    {{"",         KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, },
    {{"",         KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, },
    {{"",         KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, },
    {{"",         KEY_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, {"", VAL_STYLE1}, },
    {{"",         KEY_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, {"", VAL_STYLE2}, },
};

static QPoint g_table4_pos = {404, 86};

static QSize g_table4_size[] =
{
    {179, 38},
    {72, 38},
    {72, 38},
    {72, 38}
};

/********************************* page2->ui navigation map *****************************/
const char* g_page2_map[][PAGE_NAVI_COL_MAX] =
{
    {"低辐射报警",    "三防应急"},
    {"高辐射报警",    "增压风机"},
    {"毒剂报警",      "充气阀"  },
    {"后门指示",      ""        },
    {"舱门指示",      ""        },
    {"左油量(L)",     ""        },
    {"右前油量(L)",   ""        },
    {"右后油量(L)",   ""        },
    {"蓄电池电压(V)", ""        }
};


/********************************* page3->title *********************************/
#define TITLE3_STYLE "border-image:url(:/res/res/image/title_jsc_c3.png);\n"


/********************************* page3->table5 *********************************/
static const LabelInfo g_label_table5[][TAB_COL_NUM_MAX] =
{
    {{"自动加温",       KEY_STYLE1}, {"", VAL_STYLE1}, {"——", NONE_STYLE1}, {"——", NONE_STYLE1}, {"——", NONE_STYLE1}},
    {{"加温锅供电", KEY_STYLE2}, {"——", NONE_STYLE2}, {"", VAL_STYLE2}, {"——", NONE_STYLE2}, {"", VAL_STYLE2}},
    {{"加温锅运行", KEY_STYLE1}, {"——", NONE_STYLE1}, {"", VAL_STYLE1}, {"——", NONE_STYLE1}, {"", VAL_STYLE1}},
};

static QPoint g_table5_pos = {0, 86};

static QSize g_table5_size[] =
{
    {212, 40},
    {146, 40},
    {146, 40},
    {146, 40},
    {146, 40}
};

/********************************* page3->table6 *********************************/
static const LabelInfo g_label_table6[][TAB_COL_NUM_MAX] =
{
    {{"状态文字",   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"状态代码",   KEY_STYLE2}, {"", VAL_STYLE2},},
};

static QPoint g_table6_pos = {0, 245};

static QSize g_table6_size[] =
{
    {0, 40},
    {212, 40},
};

/********************************* page3->table7 *********************************/
static const LabelInfo g_label_table7[][TAB_COL_NUM_MAX] =
{
    {{"状态1",   KEY_STYLE2}, {"", VAL_STYLE2},},
};

static QPoint g_table7_pos = {213, 285};

static QSize g_table7_size[] =
{
    {0, 40},
    {146, 40},
};

/********************************* page3->table8 *********************************/
static const LabelInfo g_label_table8[][TAB_COL_NUM_MAX] =
{
    {{"状态2",   KEY_STYLE2}, {"", VAL_STYLE2},},
};

static QPoint g_table8_pos = {360, 285};

static QSize g_table8_size[] =
{
    {0, 40},
    {146, 40},
};

/********************************* page3->table9 *********************************/
static const LabelInfo g_label_table9[][TAB_COL_NUM_MAX] =
{
    {{"状态3",   KEY_STYLE2}, {"", VAL_STYLE2},},
};

static QPoint g_table9_pos = {507, 285};

static QSize g_table9_size[] =
{
    {0, 40},
    {146, 40},
};

/********************************* page3->table10 *********************************/
static const LabelInfo g_label_table10[][TAB_COL_NUM_MAX] =
{
    {{"状态4",   KEY_STYLE2}, {"", VAL_STYLE2},},
};

static QPoint g_table10_pos = {654, 285};

static QSize g_table10_size[] =
{
    {0, 40},
    {146, 40},
};

/********************************* page3->subtitle *********************************/
static QRect g_subtitle2_rect = QRect(0, 205, 800, 40);
#define SUBTITLE2_STYLE "border-image:url(:/res/res/image/subtitle_jsc_c31.png);\n"

static QRect g_subtitle3_rect = QRect(213, 245, 587, 40);
#define SUBTITLE3_STYLE "border-image:url(:/res/res/image/subtitle_jsc_c32.png);\n"

static QRect g_subtitle4_rect = QRect(0, 325, 800, 155);
#define SUBTITLE4_STYLE "border-image:url(:/res/res/image/subtitle_jsc_c33.png);\n"


static const char* g_page3_map[][PAGE_NAVI_COL_MAX] =
{
    {"自动加温", "", "", "" },
    {"加温锅供电", "", "", "" },
    {"加温锅运行", "", "", "" },
    {"状态1", "状态2", "状态3", "状态4"},
};


InstrPanel_JSC_C::InstrPanel_JSC_C(QWidget* parent): PanelBase(parent)
{
    ENTER();
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("JSC_C"));

    Page* page1 = new Page(this);
    page1->AddTitle(g_title_rect, TITLE1_STYLE);
    Tab* table1 = new Tab(page1, 9, 3, g_label_table1, g_table1_pos, g_table1_size);
    page1->AddTable(table1);
    Tab* table2 = new Tab(page1, 9, 3, g_label_table2, g_table2_pos, g_table2_size);
    page1->AddTable(table2);
    page1->SetButton(g_start_rect, BUTTON_STYLE);
    page1->AddTitle(g_subtitle1_rect, SUBTITLE1_STYLE);
//    page1->SetNaviMap(g_page1_map, 7, 2);
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
//    page2->AddTitle(g_subtitle1_rect, SUBTITLE1_STYLE);
    page2->SetNaviMap(g_page2_map, 9, 2);
    AddToPageList(page2);
    CreateTableMap(table3, g_label_table3, 10);
    CreateTableMap(table4, g_label_table4, 10);
    page2->CreateHlRect(398);

    Page* page3 = new Page(this);
    page3->AddTitle(g_title_rect, TITLE3_STYLE);
    Tab* table5 = new Tab(page3, 4, 5, g_label_table5, g_table5_pos, g_table5_size);
    page3->AddTable(table5);
    Tab* table6 = new Tab(page3, 5, 5, g_label_table6, g_table6_pos, g_table6_size);
    page3->AddTable(table6);
    Tab* table7 = new Tab(page3, 1, 2, g_label_table7, g_table7_pos, g_table7_size);
    page3->AddTable(table7);
    Tab* table8 = new Tab(page3, 1, 2, g_label_table8, g_table8_pos, g_table8_size);
    page3->AddTable(table8);
    Tab* table9 = new Tab(page3, 1, 2, g_label_table9, g_table9_pos, g_table9_size);
    page3->AddTable(table9);
    Tab* table10 = new Tab(page3, 1, 2, g_label_table10, g_table10_pos, g_table10_size);
    page3->AddTable(table10);
    page3->AddTitle(g_subtitle2_rect, SUBTITLE2_STYLE);
    page3->AddTitle(g_subtitle3_rect, SUBTITLE3_STYLE);
    page3->AddTitle(g_subtitle4_rect, SUBTITLE4_STYLE);
    page3->SetNaviMap(g_page3_map, 4, 4);
    AddToPageList(page3);
    CreateTableMap(table5, g_label_table5, 3);
    CreateTableMap(table6, g_label_table6, 2);
    CreateTableMap(table7, g_label_table7, 1);
    CreateTableMap(table8, g_label_table8, 1);
    CreateTableMap(table9, g_label_table9, 1);
    CreateTableMap(table10, g_label_table10, 1);
    page3->CreateHlRect(200);

    SetPageIndex(0);

    LEAVE();
}


QString GetJwgStateText(int dip)
{
    QString ret("");
    switch (dip)
    {
    case 1:
        ret = "加温锅完成状态";
        break;
    case 8:
        ret = "加温锅失败状态";
        break;
    case 2:
        ret = "加温锅运行操作成功状态";
        break;
    case 11:
        ret = "点火成功";
        break;

    case 12:
        ret = "点火失败";
        break;

    case 13:
        ret = "出水温度报警";
        break;

    case 10:
        ret = "出水温度传感器故障";
        break;

    case 14:
        ret = "进水温度传感器故障";
        break;

    default:
        ret = "****";
        break;
    }

    return ret;
}

QString GetJwgStateCode(int dip)
{
    QString ret("");
    unsigned char code = (unsigned char)dip;
    code &= 0xf;
    ret += QString::number(code>>3);
    code &= 0x7;
    ret += QString::number(code>>2);
    code &= 0x3;
    ret += QString::number(code>>1);
    code &= 0x1;
    ret += QString::number(code);

    return ret;
}

static MsgInfo g_read_info_query[] =
{
    {  1,  "空气起动",         { { 97,"——", WHITE},                                                                                                                                                                }, DISPLAY_TYPE_STR, 1, 0, },
    {  2,  "后示廓灯",         { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3, "正确", GREEN}, {4, "错误", RED},                                                                             }, DISPLAY_TYPE_STR, 1, 0, },
    {  3,  "左后转向灯",       { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3, "正确", GREEN}, {4, "错误", RED},                                                                             }, DISPLAY_TYPE_STR, 1, 0, },
    {  4,  "右后转向灯",       { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3, "正确", GREEN}, {4, "错误", RED},                                                                             }, DISPLAY_TYPE_STR, 1, 0, },
    {  5,  "刹车灯",           { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3, "正确", GREEN}, {4, "错误", RED},                                                                             }, DISPLAY_TYPE_STR, 1, 0, },
    {  6,  "夜视仪",           { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3, "正确", GREEN}, {4, "错误", RED},                                                                             }, DISPLAY_TYPE_STR, 1, 0, },
    {  7,  "潜望镜加温",       { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3, "正确", GREEN}, {4, "错误", RED},                                                                             }, DISPLAY_TYPE_STR, 1, 0, },
    {  8,  "报警灯",           { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3, "正确", GREEN}, {4, "错误", RED},                                                                             }, DISPLAY_TYPE_STR, 1, 0, },
    {  9,  "驾驶员辅助显示盒", { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3, "正确", GREEN}, {4, "错误", RED},                                                                             }, DISPLAY_TYPE_STR, 1, 0, },
    { 10,  "充电机",           { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3, "正确", GREEN}, {4, "错误", RED},                                                                             }, DISPLAY_TYPE_STR, 1, 0, },
    { 11,  "毒剂报警盒",       { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW},                                                                                                                    }, DISPLAY_TYPE_STR, 1, 0, },
    { 12,  "辐射报警盒",       { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW},                                                                                                                    }, DISPLAY_TYPE_STR, 1, 0, },
    { 13,  "微压差探测",       { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW},                                                                                                                    }, DISPLAY_TYPE_STR, 1, 0, },
    { 14,  "灭火控制盒",       { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW},                                                                                                                    }, DISPLAY_TYPE_STR, 1, 0, },
    { 15,  "空气起动",         { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3, "正确", GREEN}, {4, "错误", RED}, {49, "过流", RED}, {50, "过压", RED}, {51, "短路", RED}, {52, "过温", RED}, }, DISPLAY_TYPE_STR, 2, 0, },
    { 16,  "后示廓灯",         { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3, "正确", GREEN}, {4, "错误", RED}, {49, "过流", RED}, {50, "过压", RED}, {51, "短路", RED}, {52, "过温", RED}, }, DISPLAY_TYPE_STR, 2, 0, },
    { 17,  "左后转向灯",       { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3, "正确", GREEN}, {4, "错误", RED}, {49, "过流", RED}, {50, "过压", RED}, {51, "短路", RED}, {52, "过温", RED}, }, DISPLAY_TYPE_STR, 2, 0, },
    { 18,  "右后转向灯",       { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3, "正确", GREEN}, {4, "错误", RED}, {49, "过流", RED}, {50, "过压", RED}, {51, "短路", RED}, {52, "过温", RED}, }, DISPLAY_TYPE_STR, 2, 0, },
    { 19,  "刹车灯",           { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3, "正确", GREEN}, {4, "错误", RED}, {49, "过流", RED}, {50, "过压", RED}, {51, "短路", RED}, {52, "过温", RED}, }, DISPLAY_TYPE_STR, 2, 0, },
    { 20,  "夜视仪",           { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3, "正确", GREEN}, {4, "错误", RED}, {49, "过流", RED}, {50, "过压", RED}, {51, "短路", RED}, {52, "过温", RED}, }, DISPLAY_TYPE_STR, 2, 0, },
    { 21,  "潜望镜加温",       { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3, "正确", GREEN}, {4, "错误", RED}, {49, "过流", RED}, {50, "过压", RED}, {51, "短路", RED}, {52, "过温", RED}, }, DISPLAY_TYPE_STR, 2, 0, },
    { 22,  "报警灯",           { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, { 3, "正确", GREEN}, {4, "错误", RED}, {49, "过流", RED}, {50, "过压", RED}, {51, "短路", RED}, {52, "过温", RED}, }, DISPLAY_TYPE_STR, 2, 0, },
    { 23,  "驾驶员辅助显示盒", { { 97,"——", WHITE},                                                                                                                                                                }, DISPLAY_TYPE_STR, 2, 0, },
    { 24,  "充电机",           { { 97,"——", WHITE},                                                                                                                                                                }, DISPLAY_TYPE_STR, 2, 0, },
    { 25,  "毒剂报警盒",       { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, {49, "过流", RED}, {50, "过压", RED}, {51, "短路", RED}, {52, "过温", RED},                                        }, DISPLAY_TYPE_STR, 2, 0, },
    { 26,  "辐射报警盒",       { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, {49, "过流", RED}, {50, "过压", RED}, {51, "短路", RED}, {52, "过温", RED},                                        }, DISPLAY_TYPE_STR, 2, 0, },
    { 27,  "微压差探测",       { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, {49, "过流", RED}, {50, "过压", RED}, {51, "短路", RED}, {52, "过温", RED},                                        }, DISPLAY_TYPE_STR, 2, 0, },
    { 28,  "灭火控制盒",       { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, {49, "过流", RED}, {50, "过压", RED}, {51, "短路", RED}, {52, "过温", RED},                                        }, DISPLAY_TYPE_STR, 2, 0, },
    { 29,  "左油量(L)",        { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW},                                                                                                                    }, DISPLAY_TYPE_STR, 1, 0, },
    { 30,  "右前油量(L)",      { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW},                                                                                                                    }, DISPLAY_TYPE_STR, 1, 0, },
    { 31,  "右后油量(L)",      { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW},                                                                                                                    }, DISPLAY_TYPE_STR, 1, 0, },
    { 32,  "低辐射报警",       { { 0,NULL , WHITE}, {91, "报警",  YELLOW},  {92, "正常",  YELLOW},                                                                                                                 }, DISPLAY_TYPE_STR, 3, 0, },
    { 33,  "高辐射报警",       { { 0,NULL , WHITE}, {91, "报警",  YELLOW},  {92, "正常",  YELLOW},                                                                                                                 }, DISPLAY_TYPE_STR, 3, 0, },
    { 34,  "毒剂报警",         { { 0,NULL , WHITE}, {91, "报警",  YELLOW},  {92, "正常",  YELLOW},                                                                                                                 }, DISPLAY_TYPE_STR, 3, 0, },
    { 35,  "后门指示",         { { 0,NULL , WHITE}, { 5, "打开",  YELLOW},  {6, "关闭",  YELLOW},                                                                                                                  }, DISPLAY_TYPE_STR, 3, 0, },
    { 36,  "舱门指示",         { { 0,NULL , WHITE}, { 5, "打开",  YELLOW},  {6, "关闭",  YELLOW},                                                                                                                  }, DISPLAY_TYPE_STR, 3, 0, },
    { 37,  "左油量(L)",        { { 0,NULL , WHITE},                                                                                                                                                                }, DISPLAY_TYPE_INT, 3, 0, },
    { 38,  "右前油量(L)",      { { 0,NULL , WHITE},                                                                                                                                                                }, DISPLAY_TYPE_INT, 3, 0, },
    { 39,  "右后油量(L)",      { { 0,NULL , WHITE},                                                                                                                                                                }, DISPLAY_TYPE_INT, 3, 0, },
    { 40,  "增压风机",         { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW},                                                                                                                    }, DISPLAY_TYPE_STR, 2, 0, },
    { 41,  "充气阀",           { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW},                                                                                                                    }, DISPLAY_TYPE_STR, 2, 0, },
    { 42,  "增压风机",         { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, {49, "过流", RED}, {50, "过压", RED}, {51, "短路", RED}, {52, "过温", RED},                                        }, DISPLAY_TYPE_STR, 3, 0, },
    { 43,  "充气阀",           { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW}, {49, "过流", RED}, {50, "过压", RED}, {51, "短路", RED}, {52, "过温", RED},                                        }, DISPLAY_TYPE_STR, 3, 0, },
    { 44,  "加温锅供电",       { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW},                                                                                                                    }, DISPLAY_TYPE_STR, 2, 0, },
    { 45,  "加温锅运行",       { { 0,NULL , WHITE}, { 1, "接通", YELLOW}, { 2, "关断", YELLOW},                                                                                                                    }, DISPLAY_TYPE_STR, 2, 0, },
    { 46,  "加温锅供电",       { { 0,NULL , WHITE}, {113, "计时清0",  GREEN},  {114, "计时开始",  GREEN},  {115, "计时停止",  GREEN},                                                                              }, DISPLAY_TYPE_STR, 4, 0, },
    { 47,  "加温锅运行",       { { 0,NULL , WHITE}, {113, "计时清0",  GREEN},  {114, "计时开始",  GREEN},  {115, "计时停止",  GREEN},                                                                              }, DISPLAY_TYPE_STR, 4, 0, },
    { 48,  "状态文字",           { { 0,NULL , WHITE},                                                                                                                                                              }, DISPLAY_TYPE_STR, 1, 0, GetJwgStateText},
    { 49,  "状态代码",           { { 0,NULL , WHITE},                                                                                                                                                              }, DISPLAY_TYPE_INT, 1, 0, GetJwgStateCode},
};

void InstrPanel_JSC_C::RecvMsg(unsigned char* msg, int size)
{
	ENTER();
    ShowState(msg, size, g_read_info_query, sizeof(g_read_info_query)/sizeof(g_read_info_query[0]));
}

static MsgInfo_out g_out_info[] =
{
    { 'A', "低辐射报警",    2, { {  91, "报警", ORANGE}, {  92,  "正常",  ORANGE},    },                                                                   2 },
    { 'B', "高辐射报警",    2, { {  91, "报警", ORANGE}, {  92,  "正常",  ORANGE},    },                                                                     2 },
    { 'C', "毒剂报警",      2, { {  91, "报警", ORANGE}, {  92,  "正常",  ORANGE},   },                                                                    2 },
    { 'D', "后门指示",      2, { {   5, "打开", ORANGE}, {   6,  "关闭",  ORANGE},   },                                                                    2 },
    { 'E', "舱门指示",      2, { {   5, "打开", ORANGE}, {   6,  "关闭",  ORANGE},   },                                                                    2 },
    { 'F', "左油量(L)",     5, { {   2, "关断", ORANGE}, { 117,  "10",   ORANGE}, { 118, "30", ORANGE}, { 119, "100", ORANGE}, {120, "205", ORANGE}, }, 2 },
    { 'G', "右前油量(L)",   5, { {   2, "关断", ORANGE}, { 117,  "10",   ORANGE}, { 118, "30", ORANGE}, { 119, "100", ORANGE}, {121, "250", ORANGE}, }, 2 },
    { 'H', "右后油量(L)",   5, { {   2, "关断", ORANGE}, { 117,  "10",   ORANGE}, { 118, "30", ORANGE}, { 122, "200", ORANGE}, {123, "325", ORANGE}, }, 2 },
    { 'I', "蓄电池电压(V)", 2, { {  12, "28",  ORANGE}, {   9,  "0",    ORANGE},  },                                                                     2 },
    { 'J', "三防应急",      2, { {  98, "应急", ORANGE}, {  92,  "正常",  ORANGE},     },                                                                  1 },
    { 'K', "增压风机",      2, { {   1, "接通", ORANGE}, {   2,  "关断",  ORANGE},     },                                                                  1 },
    { 'L', "自动加温",      2, { {  95, "自动", ORANGE}, {   96, "手动",  ORANGE},     },                                                                  1 },
    { 'M', "状态1",         2, { { 131, "BIT_1",ORANGE}, {  132, "BIT_0", ORANGE},  },                                                                     1 },
    { 'N', "状态2",         2, { { 131, "BIT_1",ORANGE}, {  132, "BIT_0", ORANGE},  },                                                                     1 },
    { 'O', "状态3",         2, { { 131, "BIT_1",ORANGE}, {  132, "BIT_0", ORANGE},  },                                                                     1 },
    { 'P', "状态4",         2, { { 131, "BIT_1",ORANGE}, {  132, "BIT_0", ORANGE},  },                                                                     1 },
};

void InstrPanel_JSC_C::SetValue(const QString& name, int val)
{
	ENTER();
	SetSpecValue(name, val, g_out_info, sizeof(g_out_info)/sizeof(g_out_info[0]));
}

OutType InstrPanel_JSC_C::CheckOutUnitType(const QString& name)
{
	static QMap<QString, int> omap;
	if (omap.size() == 0)
	{
        omap["低辐射报警"] = TYPE_OPT_OFFON;
        omap["高辐射报警"] = TYPE_OPT_OFFON;
        omap["毒剂报警"] = TYPE_OPT_OFFON;
        omap["后门指示"] = TYPE_OPT_OFFON;
        omap["舱门指示"] = TYPE_OPT_OFFON;
        omap["蓄电池电压(V)"] = TYPE_OPT_OFFON;
        omap["三防应急"] = TYPE_OPT_OFFON;
        omap["增压风机"] = TYPE_OPT_OFFON;
        omap["自动加温"] = TYPE_OPT_OFFON;
        omap["状态1"] = TYPE_OPT_OFFON;
        omap["状态2"] = TYPE_OPT_OFFON;
        omap["状态3"] = TYPE_OPT_OFFON;
        omap["状态4"] = TYPE_OPT_OFFON;
        
        omap["左油量(L)"] = TYPE_OPT_TUNE;
        omap["右前油量(L)"] = TYPE_OPT_TUNE;
        omap["右后油量(L)"] = TYPE_OPT_TUNE;
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


