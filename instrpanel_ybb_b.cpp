#include "instrpanel_ybb_b.h"
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

#define TITLE1_STYLE "border-image:url(:/res/res/image/title_ybb_b.png);\n"

/********************************* page1->table1 *********************************/
static const LabelInfo g_label_table1[][TAB_COL_NUM_MAX] =
{
    {{"机油泵"  ,   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"示廓灯"  ,   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"百叶窗开",   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"前大灯强",   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"前大灯弱",   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"左转向"  ,   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"右转向"  ,   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"电喇叭"  ,   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"防空灯强",   KEY_STYLE1}, {"", VAL_STYLE1},},
};

static QPoint g_table1_pos = {0, 86};

static QSize g_table1_size[] =
{
    {252, 38},
    {145, 38}
};

/********************************* page1->table2 *********************************/
static const LabelInfo g_label_table2[][TAB_COL_NUM_MAX] =
{
    {{"防空灯弱",   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"百叶窗关",   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"空气起动",   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"风扇自动",   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"三防应急",   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"自动加温",   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"程控起动",   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"紧急停车",   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"",           KEY_STYLE1}, {"", VAL_STYLE1},},
};

static QPoint g_table2_pos = {403, 86};

static QSize g_table2_size[] =
{
    {252, 38},
    {145, 38}
};

/********************************* page1->start button *****************************/
static QRect g_start_rect = QRect(0, 432, 800, 40);
#define BUTTON_STYLE "background-color: rgb(31, 49, 87);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(255, 255, 255);\n"

/********************************* page1->ui navigation map *****************************/
static const char* g_page1_map[][2] =
{
    {"机油泵"  , "防空灯弱"},
    {"示廓灯"  , "百叶窗关"},
    {"百叶窗开", "空气起动"},
    {"前大灯强", "风扇自动"},
    {"前大灯弱", "三防应急"},
    {"左转向"  , "自动加温"},
    {"右转向"  , "程控起动"},
    {"电喇叭"  , "紧急停车"},
    {"防空灯强", ""        },
};



InstrPanel_YBB_B::InstrPanel_YBB_B(QWidget* parent): PanelBase(parent)
{
    ENTER();
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("YBB_B"));

    Page* page1 = new Page(this);
    page1->AddTitle(g_title_rect, TITLE1_STYLE);
    Tab* table1 = new Tab(page1, 9, 2, g_label_table1, g_table1_pos, g_table1_size);
    page1->AddTable(table1);
    Tab* table2 = new Tab(page1, 9, 2, g_label_table2, g_table2_pos, g_table2_size);
    page1->AddTable(table2);
    page1->SetButton(g_start_rect, BUTTON_STYLE);
    //page1->SetNaviMap(g_page1_map, 9, 2);
    AddToPageList(page1);

    CreateTableMap(table1, g_label_table1, 9);
    CreateTableMap(table2, g_label_table2, 9);
    page1->CreateHlRect(398);

    SetPageIndex(0);
    LEAVE();
}


static MsgInfo g_read_info_query[] =
{
    {  1,  "机油泵",   { { 0,NULL, WHITE}, { 1, "接通", YELLOW }, { 2,"关断", YELLOW }, { 3,"正确", GREEN }, { 4,"错误", RED }, }, DISPLAY_TYPE_STR, 1, 0,},
    {  2,  "示廓灯",   { { 0,NULL, WHITE}, { 1, "接通", YELLOW }, { 2,"关断", YELLOW }, { 3,"正确", GREEN }, { 4,"错误", RED }, }, DISPLAY_TYPE_STR, 1, 0,},
    {  3,  "百叶窗开", { { 0,NULL, WHITE}, { 1, "接通", YELLOW }, { 2,"关断", YELLOW }, { 3,"正确", GREEN }, { 4,"错误", RED }, }, DISPLAY_TYPE_STR, 1, 0,},
    {  4,  "前大灯强", { { 0,NULL, WHITE}, { 1, "接通", YELLOW }, { 2,"关断", YELLOW }, { 3,"正确", GREEN }, { 4,"错误", RED }, }, DISPLAY_TYPE_STR, 1, 0,},
    {  5,  "前大灯弱", { { 0,NULL, WHITE}, { 1, "接通", YELLOW }, { 2,"关断", YELLOW }, { 3,"正确", GREEN }, { 4,"错误", RED }, }, DISPLAY_TYPE_STR, 1, 0,},
    {  6,  "左转向",   { { 0,NULL, WHITE}, { 1, "接通", YELLOW }, { 2,"关断", YELLOW }, { 3,"正确", GREEN }, { 4,"错误", RED }, }, DISPLAY_TYPE_STR, 1, 0,},
    {  7,  "右转向",   { { 0,NULL, WHITE}, { 1, "接通", YELLOW }, { 2,"关断", YELLOW }, { 3,"正确", GREEN }, { 4,"错误", RED }, }, DISPLAY_TYPE_STR, 1, 0,},
    {  8,  "电喇叭",   { { 0,NULL, WHITE}, { 1, "接通", YELLOW }, { 2,"关断", YELLOW }, { 3,"正确", GREEN }, { 4,"错误", RED }, }, DISPLAY_TYPE_STR, 1, 0,},
    {  9,  "防空灯强", { { 0,NULL, WHITE}, { 1, "接通", YELLOW }, { 2,"关断", YELLOW }, { 3,"正确", GREEN }, { 4,"错误", RED }, }, DISPLAY_TYPE_STR, 1, 0,},
    { 10,  "防空灯弱", { { 0,NULL, WHITE}, { 1, "接通", YELLOW }, { 2,"关断", YELLOW }, { 3,"正确", GREEN }, { 4,"错误", RED }, }, DISPLAY_TYPE_STR, 1, 0,},
    { 11,  "百叶窗关", { { 0,NULL, WHITE}, { 1, "接通", YELLOW }, { 2,"关断", YELLOW }, { 3,"正确", GREEN }, { 4,"错误", RED }, }, DISPLAY_TYPE_STR, 1, 0,},
    { 12,  "空气起动", { { 0,NULL, WHITE}, { 1, "接通", YELLOW }, { 2,"关断", YELLOW }, { 3,"正确", GREEN }, { 4,"错误", RED }, }, DISPLAY_TYPE_STR, 1, 0,},
    { 13,  "风扇自动", { { 0,NULL, WHITE}, { 1, "接通", YELLOW }, { 2,"关断", YELLOW }, { 3,"正确", GREEN }, { 4,"错误", RED }, }, DISPLAY_TYPE_STR, 1, 0,},
    { 14,  "三防应急", { { 0,NULL, WHITE}, { 1, "接通", YELLOW }, { 2,"关断", YELLOW }, { 3,"正确", GREEN }, { 4,"错误", RED }, }, DISPLAY_TYPE_STR, 1, 0,},
    { 15,  "自动加温", { { 0,NULL, WHITE}, { 1, "接通", YELLOW }, { 2,"关断", YELLOW }, { 3,"正确", GREEN }, { 4,"错误", RED }, }, DISPLAY_TYPE_STR, 1, 0,},
    { 16,  "程控起动", { { 0,NULL, WHITE}, { 1, "接通", YELLOW }, { 2,"关断", YELLOW }, { 3,"正确", GREEN }, { 4,"错误", RED }, }, DISPLAY_TYPE_STR, 1, 0,},
    { 17,  "紧急停车", { { 0,NULL, WHITE}, { 1, "接通", YELLOW }, { 2,"关断", YELLOW }, { 3,"正确", GREEN }, { 4,"错误", RED }, }, DISPLAY_TYPE_STR, 1, 0,},
};


void InstrPanel_YBB_B::RecvMsg(unsigned char* msg, int size)
{
	ENTER();
    ShowState(msg, size, g_read_info_query, sizeof(g_read_info_query)/sizeof(g_read_info_query[0]));
}

