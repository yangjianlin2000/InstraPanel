#include "instrpanel_dlc.h"
#include "common.h"
#include "table.h"


static QRect g_title_rect = QRect(0, 0, 800, 86);
#define TITLE1_STYLE "border-image:url(:/res/res/image/title_dlc1.png);\n"

#define TITLE2_STYLE "border-image:url(:/res/res/image/title_dlc2.png);\n"


#define KEY_STYLE1 "background-color: rgb(13, 25, 43);\n" \
                    "font: 16px bold;\n" \
                    "color: rgb(215, 230, 254);\n" \
                    "padding-left: 16px"
#define KEY_STYLE2 "background-color: rgb(6, 17, 35);\n" \
                    "font: 16px bold;\n" \
                    "color: rgb(215, 230, 254);\n" \
                    "padding-left: 16px"


/********************************* page1->table1 *********************************/
static const LabelInfo g_label_table1[9][3] =
{
    {{ "加温锅电源",    KEY_STYLE1 }, {"", KEY_STYLE1}, {"", KEY_STYLE1}},
    {{ "机油泵",       KEY_STYLE2 }, {"", KEY_STYLE2}, {"", KEY_STYLE2}},
    {{ "拖车泵",       KEY_STYLE1 }, {"", KEY_STYLE1}, {"", KEY_STYLE1}},
    {{ "百叶窗开",     KEY_STYLE2 }, {"", KEY_STYLE2}, {"", KEY_STYLE2}},
    {{ "排污阀",       KEY_STYLE1 }, {"", KEY_STYLE1}, {"", KEY_STYLE1}},
    {{ "电喇叭",       KEY_STYLE2 }, {"", KEY_STYLE2}, {"", KEY_STYLE2}},
    {{ "前大灯强",     KEY_STYLE1 }, {"", KEY_STYLE1}, {"", KEY_STYLE1}},
    {{ "前大灯弱",   	 KEY_STYLE2 },  {"", KEY_STYLE2}, {"", KEY_STYLE2}},
    {{ "防空灯强",     KEY_STYLE1 }, {"", KEY_STYLE1}, {"", KEY_STYLE1}}
};

Point g_table1_pos = {0, 86};

Size g_table1_size[3] =
{
    {168, 38},
    {110, 38},
    {116, 38}
};

/********************************* page1->table2 *********************************/
static const LabelInfo g_label_table2[9][3] =
{
    {{ "防空灯弱",    KEY_STYLE1 },{ "",    KEY_STYLE1 },{ "",    KEY_STYLE1 }},
    {{ "前左转向灯",  KEY_STYLE2 },{ "",    KEY_STYLE2 },{ "",    KEY_STYLE2 }},
    {{ "前右转向灯",   KEY_STYLE1 },{ "",    KEY_STYLE1 },{ "",    KEY_STYLE1 }},
    {{ "前示廓灯",    KEY_STYLE2 },{ "",    KEY_STYLE2 },{ "",    KEY_STYLE2 }},
    {{ "进气预热",    KEY_STYLE1 },{ "",    KEY_STYLE1 },{ "",    KEY_STYLE1 }},
    {{ "发动机放气阀", KEY_STYLE2 },{ "",    KEY_STYLE2 },{ "",    KEY_STYLE2 }},
    {{ "热烟幕阀",    KEY_STYLE1 },{ "",    KEY_STYLE1 },{ "",    KEY_STYLE1 }},
    {{ "加温锅控制",   KEY_STYLE2 },{ "",    KEY_STYLE2 },{ "",    KEY_STYLE2 }},
    {{ "敌我识别",    KEY_STYLE1 },{ "",    KEY_STYLE1 },{ "",    KEY_STYLE1 }}
};

Point g_table2_pos = {403, 86};

Size g_table2_size[3] =
{
    {168, 38},
    {110, 38},
    {116, 38}
};

/********************************* page2->table3 *********************************/
static const LabelInfo g_label_table3[6][3] =
{
    {{ "加温锅状态1",   KEY_STYLE1, },{ "-",    KEY_STYLE1 },{ "",    KEY_STYLE1 }},
    {{ "加温锅状态2",   KEY_STYLE2, },{ "-",    KEY_STYLE2 },{ "",    KEY_STYLE2 }},
    {{ "加温锅状态3",   KEY_STYLE1, },{ "-",    KEY_STYLE1 },{ "",    KEY_STYLE1 }},
    {{ "加温锅状态4",   KEY_STYLE2, },{ "-",    KEY_STYLE2 },{ "",    KEY_STYLE2 }},
    {{ "空气滤报警",   KEY_STYLE1, },{ "",    KEY_STYLE1 },{ "",    KEY_STYLE1 }},
    {{ "刹车",         KEY_STYLE2, },{ "-",    KEY_STYLE2 },{ "",    KEY_STYLE2 }}
};

Point g_table3_pos = {0, 86};

Size g_table3_size[3] =
{
    {168, 38},
    {74,  38},
    {154, 38}
};

/********************************* page2->table4 *********************************/
static const LabelInfo g_label_table4[10][4] =
{
    {{ "电压(V)",      KEY_STYLE1, },{ "",    KEY_STYLE1 },{ "-",    KEY_STYLE1 },{ "-",    KEY_STYLE1 }},
    {{ "转速(rpm)",    KEY_STYLE2, },{ "",    KEY_STYLE2 },{ "-",    KEY_STYLE2 },{ "-",    KEY_STYLE2 }},
    {{ "程控启动",     KEY_STYLE1, },{ "",    KEY_STYLE1 },{ "-",    KEY_STYLE1 },{ "-",    KEY_STYLE1 }},
    {{ "启动电机",     KEY_STYLE2, },{ "-",    KEY_STYLE2 },{ "",    KEY_STYLE2 },{ "",      KEY_STYLE2 }},
    {{ "累计启动次数", KEY_STYLE1, },{ "-",     KEY_STYLE1 },{ "-",    KEY_STYLE1 },{ "",      KEY_STYLE1 }},
    {{ "综合报警",     KEY_STYLE2, },{ "",    KEY_STYLE2 },{ "-",    KEY_STYLE2 },{ "-",    KEY_STYLE2 }},
    {{ "高辐射报警",   KEY_STYLE1, },{ "",    KEY_STYLE1 },{ "-",    KEY_STYLE1 },{ "-",    KEY_STYLE1 }},
    {{ "百叶窗关",     KEY_STYLE2, },{ "",    KEY_STYLE2 },{ "",    KEY_STYLE2 },{ "",      KEY_STYLE2 }},
    {{ "",             KEY_STYLE2, },{ "",   KEY_STYLE1 },{ "",   KEY_STYLE1 },{ "",      KEY_STYLE1 }},
    {{ "动力舱排水泵", KEY_STYLE1, },{ "",    KEY_STYLE2 },{ "",     KEY_STYLE2 },{ "",      KEY_STYLE2 }}
};

Point g_table4_pos = {403, 86};

Size g_table4_size[4] =
{
    {176, 38},
    {74,  38},
    {74,  38},
    {70,  38},
};

/********************************* page2->table5 *********************************/
static const LabelInfo g_label_table5[3][4] =
{
    {{ "机油温度(℃)",  KEY_STYLE2, },{ "-",    KEY_STYLE2 },{ "",      KEY_STYLE2 },{ "",      KEY_STYLE2 }},
    {{ "空气滤地",     KEY_STYLE1, },{ "",    KEY_STYLE1 },{ "-",      KEY_STYLE1 },{ "",      KEY_STYLE1 }},
    {{ "进水报警",      KEY_STYLE2, },{ "",    KEY_STYLE2 },{ "",      KEY_STYLE2 },{ "",      KEY_STYLE2 }}
};

Point g_table5_pos = {0, 354};

Size g_table5_size[4] =
{
    {168, 38},
    {74,  38},
    {78,  38},
    {75,  38},
};

/********************************* page1->start button *****************************/
static QRect g_start_rect = QRect(0, 432, 800, 40);
#define BUTTON_STYLE "background-color: rgb(31, 49, 87);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(255, 255, 255);\n"

/********************************* page2->subtitle *********************************/
static QRect g_subtitle2_rect = QRect(0, 314, 398, 38);
#define SUBTITLE2_STYLE "border-image:url(:/res/res/image/subtitle_dlc2.png);\n"


InstrPanel_DLC::InstrPanel_DLC(QWidget *parent) : QWidget(parent)
{
    ENTER();
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("DLC1"));
    resize(800, 480);
    //setStyleSheet(QStringLiteral("background-color: rgb(31, 31, 31);"));

    create_page1();
    create_page2();
    m_stackedWidget = new QStackedWidget(this);
    m_stackedWidget->setObjectName(QStringLiteral("stackedWidget_dlc"));
    m_stackedWidget->setGeometry(QRect(0, 0, 800, 480));
    m_stackedWidget->setAutoFillBackground(false);
    m_stackedWidget->addWidget(m_page1);
    m_stackedWidget->addWidget(m_page2);
    m_stackedWidget->setCurrentIndex(0);

    setFocus();
    LEAVE();
}

void InstrPanel_DLC::create_page1()
{
    m_page1 = new QWidget(this);
    m_page1->setObjectName(QStringLiteral("page_1"));
    m_page1->setBaseSize(QSize(800, 480));
    m_page1->setStyleSheet(QStringLiteral("background-color: rgb(31, 31, 31);"));

    m_title1 = new QLabel(m_page1);
    m_title1->setGeometry(g_title_rect);
    m_title1->setObjectName(QStringLiteral("title_dlc1"));
    m_title1->setStyleSheet(QLatin1String(TITLE1_STYLE));
    m_title1->show();

    create_page1_labels(m_page1);

    create_start_button(m_page1);
}

void InstrPanel_DLC::create_page2()
{
    m_page2 = new QWidget(this);
    m_page2->setObjectName(QStringLiteral("page_2"));
    m_page2->setBaseSize(QSize(800, 480));
    m_page2->setStyleSheet(QStringLiteral("background-color: rgb(31, 31, 31);"));

    m_title2 = new QLabel(m_page2);
    m_title2->setGeometry(g_title_rect);
    m_title2->setObjectName(QStringLiteral("title_dlc2"));
    m_title2->setStyleSheet(QLatin1String(TITLE2_STYLE));
    m_title2->show();

    m_subtitle2 = new QLabel(m_page2);
    m_subtitle2->setGeometry(g_subtitle2_rect);
    m_subtitle2->setObjectName(QStringLiteral("subtitle_dlc2"));
    m_subtitle2->setStyleSheet(QLatin1String(SUBTITLE2_STYLE));
    m_subtitle2->show();

    create_page2_labels(m_page2);
}

KeyHandleState InstrPanel_DLC::keyPressEvent(QKeyEvent  *event)
{
    ENTER();
    int pagenum = 2;
    if(event->key() == Qt::Key_Right)
    {
        int index = m_stackedWidget->currentIndex();
        index++;
        if (index == 2)
        {
            index = 0;
        }
        m_stackedWidget->setCurrentIndex(index);
    }
    else if(event->key() == Qt::Key_Left)
    {
        int index = m_stackedWidget->currentIndex();
        index--;
        if (index == -1)
        {
            index = pagenum - 1;
        }
        m_stackedWidget->setCurrentIndex(index);
    }
    else
        QWidget::keyPressEvent(event);
}

void InstrPanel_DLC::create_page1_labels(QWidget* parent)
{
    ENTER();
    Table::create_labels(parent, m_table1, sizeof(m_table1)/sizeof(m_table1[0]), \
                            g_label_table1, g_table1_pos, g_table1_size);

    Table::create_labels(parent, m_table2, sizeof(m_table2)/sizeof(m_table2[0]), \
                            g_label_table2, g_table2_pos, g_table2_size);

    LEAVE();
}

void InstrPanel_DLC::create_page2_labels(QWidget* parent)
{
    ENTER();
    Table::create_labels(parent, m_table3, sizeof(m_table3)/sizeof(m_table3[0]), \
                            g_label_table3, g_table3_pos, g_table3_size);

    Table::create_labels(parent, m_table4, sizeof(m_table4)/sizeof(m_table4[0]), \
                            g_label_table4, g_table4_pos, g_table4_size);

    Table::create_labels(parent, m_table5, sizeof(m_table5)/sizeof(m_table5[0]), \
                            g_label_table5, g_table5_pos, g_table5_size);

    LEAVE();
}


void InstrPanel_DLC::create_start_button(QWidget* parent)
{
    m_start_btn = new QPushButton(parent);
    m_start_btn->setGeometry(g_start_rect);
    m_start_btn->setObjectName(QStringLiteral("start"));
    m_start_btn->setStyleSheet(QLatin1String(BUTTON_STYLE));
    m_start_btn->setText(QLatin1String("START"));
    m_start_btn->show();
}

