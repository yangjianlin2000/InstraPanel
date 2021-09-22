#include "instrpanel_ybb.h"


static QRect g_title_rect = QRect(0, 0, 800, 86);
#define TITLE_STYLE "background-color: rgb(5, 14, 42);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(163, 195, 255);\n" \
                    "border-image:url(:/res/res/image/title_ybb.png);\n"


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


/********************************* page1->table1 *********************************/
static const LabelInfo g_label_table1[][TAB_COL_NUM_MAX] =
{
    {{"拖车泵",     KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"加温锅电源", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"加温锅控制", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"程控启动",   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"前大灯强",   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"前大灯弱",   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"防空灯强",   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"防空灯弱",   KEY_STYLE2}, {"", VAL_STYLE2},},
};

static QPoint g_table1_pos = {0, 86};

static QSize g_table1_size[] =
{
    {178, 40},
    {88,  40},
};


/********************************* page1->table2 *********************************/
static const LabelInfo g_label_table2[][TAB_COL_NUM_MAX] =
{
    {{"左转向灯",  KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"右转向灯",  KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"示廓灯",    KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"百叶窗开",  KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"百叶窗关",  KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"机油泵",    KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"舱排水泵",  KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"排污阀",    KEY_STYLE2}, {"", VAL_STYLE2},},
};

static QPoint g_table2_pos = {272, 86};

static QSize g_table2_size[] =
{
    {188, 40},
    {74,  40},
};


/********************************* page1->table3 *********************************/
static const LabelInfo g_label_table3[][TAB_COL_NUM_MAX] =
{
    {{"停车",     KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"空气启动", KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"关闭体",   KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"电喇叭",   KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"三防应急", KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"进气",     KEY_STYLE2}, {"", VAL_STYLE2},},
    {{"排气",     KEY_STYLE1}, {"", VAL_STYLE1},},
    {{"后排气泵",  KEY_STYLE2}, {"", VAL_STYLE2},},
};

static QPoint g_table3_pos = {541, 86};

static QSize g_table3_size[] =
{
    {178, 40},
    {80,  40},
};


static QRect g_start_rect = QRect(0, 432, 800, 40);
#define BUTTON_STYLE "background-color: rgb(31, 49, 87);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(255, 255, 255);\n"



InstrPanel_YBB::InstrPanel_YBB(QWidget *parent) : PanelBase(parent)
{
    ENTER();
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("YBB"));

    Page* page1 = new Page(this);
    QLabel* title = page1->AddTitle(g_title_rect, TITLE_STYLE);
    page1->SetAppVersion(__APP_VERION__, title);
    Tab* table1 = new Tab(page1, 8, 2, g_label_table1, g_table1_pos, g_table1_size);
    page1->AddTable(table1);
    Tab* table2 = new Tab(page1, 8, 2, g_label_table2, g_table2_pos, g_table2_size);
    page1->AddTable(table2);
    Tab* table3 = new Tab(page1, 8, 2, g_label_table3, g_table3_pos, g_table3_size);
    page1->AddTable(table3);

    page1->SetButton(g_start_rect, BUTTON_STYLE);
    AddToPageList(page1);

    CreateTableMap(table1, g_label_table1, 8);
    CreateTableMap(table2, g_label_table2, 8);
    CreateTableMap(table3, g_label_table3, 8);

    page1->CreateHlRect(0);

    SetPageIndex(0);
    LEAVE();
}

////////////////////////////////////////////////////////////
static MsgInfo g_read_info_query[] =
{
	{1, "拖车泵",	 {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{2, "加温锅电源", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{3, "加温锅控制", {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{4, "程控启动",   {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{5, "前大灯强",   {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{6, "前大灯弱",   {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{7, "防空灯强",   {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{8, "防空灯弱",   {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},

	{9, "左转向灯",   {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{10, "右转向灯",  {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{11, "示廓灯",	 {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{12, "百叶窗开",  {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{13, "百叶窗关",  {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{14, "机油泵",	 {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{15, "舱排水泵",  {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{16, "排污阀",	 {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},

	{17, "停车",		{{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{18, "空气启动",  {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{19, "关闭体",	 {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{20, "电喇叭",	 {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{21, "三防应急",  {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{22, "进气",		{{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{23, "排气",		{{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1},
	{24, "后排气泵",  {{0, "", NONE}, {1, "接通", YELLOW},{2, "关断", YELLOW}, {3, "正确", GREEN},{4, "错误", RED}, }, DISPLAY_TYPE_STR, 1}
};


void InstrPanel_YBB::RecvMsg(unsigned char* msg, int size)
{
	ENTER();
    ShowState(msg, size, g_read_info_query, sizeof(g_read_info_query)/sizeof(g_read_info_query[0]));
}


#if 0
OutType InstrPanel_YBB::CheckOutUnitType(QString name)
{
	static QMap<QString, int> map;
	if (map.size() == 0)
	{
		map["主电源输出"] = TYPE_IO;
		map["百叶窗关"] = TYPE_IO;
		map["百叶窗开"] = TYPE_IO;
		map["程控起动"] = TYPE_IO;
		map["空气启动"] = TYPE_IO;
		map["电喇叭"] = TYPE_IO;
		map["加热锅控制"] = TYPE_IO;
		map["加热锅电源"] = TYPE_IO;
		map["后进气"] = TYPE_IO;
		map["三防应急"] = TYPE_IO;
		map["前进气"] = TYPE_IO;
		map["排污阀"] = TYPE_IO;
		map["关闭体"] = TYPE_IO;
		map["后舱水泵"] = TYPE_IO;
		map["前舱水泵"] = TYPE_IO;
		map["拖车泵"] = TYPE_IO;
		map["机油泵"] = TYPE_IO;
		map["防空灯弱"] = TYPE_IO;
		map["防空灯强"] = TYPE_IO;
		map["前大灯弱"] = TYPE_IO;
		map["前大灯强"] = TYPE_IO;
		map["右转向灯"] = TYPE_IO;
		map["左转向灯"] = TYPE_IO;
		map["示廓灯"] = TYPE_IO;
		map["停车"] = TYPE_IO;
	}

	int type = map[name];
	PRINT("name[%s]'s type is %d\n", name.toStdString().c_str(), type);
	return (OutType)type;
}

static MsgInfo_out g_io_out_info[] =
{
	{8, 0, "主电源输出",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	
	{1, 0, "百叶窗关",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "百叶窗开",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "程控起动",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "空气启动",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "电喇叭",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "加热锅控制",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "加热锅电源",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "后进气",2, {{"断开", RED}, {"接通", GREEN},}, -1},

	{1, 0, "三防应急",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "前进气",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "排污阀",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "关闭体",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "后舱水泵",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "前舱水泵",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "拖车泵",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "机油泵",2, {{"断开", RED}, {"接通", GREEN},}, -1},

	{1, 0, "防空灯弱",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "防空灯强",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "前大灯弱",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "前大灯强",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "右转向灯",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "左转向灯",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "示廓灯",2, {{"断开", RED}, {"接通", GREEN},}, -1},
	{1, 0, "停车",2, {{"断开", RED}, {"接通", GREEN},}, -1}
};

void InstrPanel_YBB::SetIoOut(QString name, int val)
{
	GenerateOutMsg(TYPE_IO, g_io_out_info, sizeof(g_io_out_info)/sizeof(g_io_out_info[0]), name, val);
}

void InstrPanel_YBB::resetOutInfo()
{
	for (int i = 0; i < sizeof(g_io_out_info)/sizeof(g_io_out_info[0]); i++)
	{
		g_io_out_info[i].val = 0;
	}
}

#endif


