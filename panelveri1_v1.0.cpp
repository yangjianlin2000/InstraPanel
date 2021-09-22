#include "panelveri1_v1.0.h"
#include "common.h"


#define KEY_STYLE1 "background-color: rgb(13, 25, 43);\n" \
                    "font: 16px bold;\n" \
                    "color: rgb(215, 230, 254);\n" \
                    "padding-left: 16px"
#define KEY_STYLE2 "background-color: rgb(6, 17, 35);\n" \
                    "font: 16px bold;\n" \
                    "color: rgb(215, 230, 254);\n" \
                    "padding-left: 16px"
#define VAL_STYLE1 KEY_STYLE1
#define VAL_STYLE2 KEY_STYLE2

/********************************* page1->title *********************************/
static QRect g_title_rect = QRect(0, 0, 800, 86);

#define TITLE1_STYLE "border-image:url(:/res/res/image/title_dlc_b1.png);\n"


/********************************* page1->table1 *********************************/
static const LabelInfo g_label_table0[][TAB_COL_NUM_MAX] =
{
    {{"IO_I01",   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_I02",   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"IO_I03",   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_I04",   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"IO_I05",   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_I06",   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"IO_I07",   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"IO_I08",   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"IO_I09",   KEY_STYLE1}, {"", VAL_STYLE1},},
};

static QPoint g_table0_pos = {0, 48};

static QSize g_table0_size[] =
{
    {200, 48},
    {145, 38}
};

/********************************* page1->table2 *********************************/
static const LabelInfo g_label_table2[][TAB_COL_NUM_MAX] =
{
    {{"防空灯强"  ,   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"防空灯弱"  ,   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"百叶窗关"  ,   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"进气预热器",   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"拖车泵"    ,   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"抽油阀"    ,   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"放气阀"    ,   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"排污阀"    ,   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{""              KEY_STYLE1}, {"", VAL_STYLE1},},
};

static QPoint g_table2_pos = {403, 86};

static QSize g_table2_size[] =
{
    {252, 38},
    {144, 38}
};

/********************************* page1->start button *****************************/
static QRect g_start_rect = QRect(0, 432, 800, 40);
#define BUTTON_STYLE "background-color: rgb(31, 49, 87);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(255, 255, 255);\n"


/********************************* page1->ui navigation map *****************************/
static const char* g_page1_map[][2] =
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
    {{"空气滤"         ,KEY_STYLE1}, {"", VAL_STYLE1},{"", VAL_STYLE1},{"", VAL_STYLE1},},
    {{"刹车"           ,KEY_STYLE2}, {"", VAL_STYLE2},{"", VAL_STYLE2},{"", VAL_STYLE2},},
    {{"机油温度(℃)"    ,KEY_STYLE1}, {"", VAL_STYLE1},{"", VAL_STYLE1},{"", VAL_STYLE1},},
    {{"分油箱油度(℃)"  ,KEY_STYLE2}, {"", VAL_STYLE2},{"", VAL_STYLE2},{"", VAL_STYLE2},},
    {{"润滑油压"       ,KEY_STYLE1}, {"", VAL_STYLE1},{"", VAL_STYLE1},{"", VAL_STYLE1},},
};

static QPoint g_table3_pos = {0, 86};

static QSize g_table3_size[] =
{
    {179, 39},
    {72, 39},
    {72, 39},
    {72, 39}
};

/********************************* page2->table4 *********************************/
static const LabelInfo g_label_table4[][TAB_COL_NUM_MAX] =
{
    {{"发动机转速(rpm)", KEY_STYLE2}, {"", VAL_STYLE2},{"", VAL_STYLE2},{"", VAL_STYLE2},},
    {{"发动机水温(℃)"  , KEY_STYLE1}, {"", VAL_STYLE1},{"", VAL_STYLE1},{"", VAL_STYLE1},},
    {{"变矩器油温(℃)",   KEY_STYLE2}, {"", VAL_STYLE2},{"", VAL_STYLE2},{"", VAL_STYLE2},},
    {{"蓄电池电压(V)",   KEY_STYLE1}, {"", VAL_STYLE1},{"", VAL_STYLE1},{"", VAL_STYLE1},},
};

static QPoint g_table4_pos = {0, 320};

static QSize g_table4_size[] =
{
    {179, 39},
    {72, 39},
    {72, 39},
    {72, 39}
};

/********************************* page2->table5 *********************************/
static const LabelInfo g_label_table5[][TAB_COL_NUM_MAX] =
{
    {{"动力舱火警"   ,KEY_STYLE1}, {"", VAL_STYLE1},{"", VAL_STYLE1},{"", VAL_STYLE1},},
    {{"高辐射报警"   ,KEY_STYLE2}, {"", VAL_STYLE2},{"", VAL_STYLE2},{"", VAL_STYLE2},},
    {{"百叶窗关"     ,KEY_STYLE1}, {"", VAL_STYLE1},{"", VAL_STYLE1},{"", VAL_STYLE1},},
    {{""             ,KEY_STYLE2}, {"", VAL_STYLE2},{"", VAL_STYLE2},{"", VAL_STYLE2},},
    {{"起动电机"     ,KEY_STYLE1}, {"", VAL_STYLE1},{"", VAL_STYLE1},{"", VAL_STYLE1},},
    {{""             ,KEY_STYLE2}, {"", VAL_STYLE2},{"", VAL_STYLE2},{"", VAL_STYLE2},},
    {{"风扇自动"     ,KEY_STYLE1}, {"", VAL_STYLE1},{"", VAL_STYLE1},{"", VAL_STYLE1},},
    {{"风扇电磁阀1"  ,KEY_STYLE2}, {"", VAL_STYLE2},{"", VAL_STYLE2},{"", VAL_STYLE2},},
    {{"风扇电磁阀2"  ,KEY_STYLE1}, {"", VAL_STYLE1},{"", VAL_STYLE1},{"", VAL_STYLE1},},
    {{"风扇状态指示" ,KEY_STYLE2}, {"", VAL_STYLE2},{"", VAL_STYLE2},{"", VAL_STYLE2},},
};

static QPoint g_table5_pos = {403, 86};

static QSize g_table5_size[] =
{
    {179, 39},
    {72, 39},
    {72, 39},
    {72, 39}
};

/********************************* page1->subtitle *********************************/
static QRect g_subtitle1_rect = QRect(0, 281, 398, 39);

#define SUBTITLE1_STYLE "border-image:url(:/res/res/image/subtitle_dlc_b2.png);\n"


/********************************* page2->ui navigation map *****************************/
static const char* g_page2_map[][2] =
{
    {"空气滤"         , "动力舱火警" },
    {"刹车"           , "高辐射报警" },
    {"机油温度(℃)"    , "百叶窗关"   },
    {"分油箱油度(℃)"  , ""          },
    {"润滑油压"       , "起动电机"    },
    {""               , ""  },
    {"发动机转速(rpm)", "风扇自动" },
    {"发动机水温(℃)"  , "风扇电磁阀1" },
    {"变矩器油温(℃)",   "风扇电磁阀2"},
    {"蓄电池电压(V)",  "风扇状态指示"},
};


InstrPanel_DLC_B::InstrPanel_DLC_B(QWidget* parent): PanelBase(parent)
{
    ENTER();
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("DLC_B"));

    Page* page1 = new Page(this);
    page1->AddTitle(g_title_rect, TITLE1_STYLE);
    Tab* table1 = new Tab(page1, 9, 2, g_label_table1, g_table1_pos, g_table1_size);
    page1->AddTable(table1);
    Tab* table2 = new Tab(page1, 9, 2, g_label_table2, g_table2_pos, g_table2_size);
    page1->AddTable(table2);
    page1->SetButton(g_start_rect, BUTTON_STYLE);
    page1->SetNaviMap(g_page1_map, 8, 2);
    AddToPageList(page1);
    CreateTableMap(table1, g_label_table1, 8);
    CreateTableMap(table2, g_label_table2, 8);
    page1->CreateHlRect(398);

    Page* page2 = new Page(this);
    page2->AddTitle(g_title_rect, TITLE2_STYLE);
    Tab* table3 = new Tab(page2, 5, 4, g_label_table3, g_table3_pos, g_table3_size);
    page2->AddTable(table3);
    Tab* table4 = new Tab(page2, 4, 4, g_label_table4, g_table4_pos, g_table4_size);
    page2->AddTable(table4);
    Tab* table5 = new Tab(page2, 10, 4, g_label_table5, g_table5_pos, g_table5_size);
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

