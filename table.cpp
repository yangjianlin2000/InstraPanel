#include "table.h"
#include "common.h"
#include <QTextCodec>


static const char* g_title = "仪表板控制盒检测";
static QRect g_title_rect = QRect(0, 0, 800, 86);
#define TITLE_STYLE "background-color: rgb(5, 14, 42);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(163, 195, 255);\n" \
                    "border-image:url(:/res/res/image/title_ybp.png);\n"


#define KEY_STYLE1 "background-color: rgb(13, 25, 43);\n" \
                    "font: 16px bold;\n" \
                    "color: rgb(215, 230, 254);\n" \
                    "padding-left: 16px"
#define KEY_STYLE2 "background-color: rgb(6, 17, 35);\n" \
                    "font: 16px bold;\n" \
                    "color: rgb(215, 230, 254);\n" \
                    "padding-left: 16px"


typedef struct _LabelInfo
{
    const char* name;
    const char* style;
}LabelInfo;


static const LabelInfo g_label_key[3][8] =
{
    {
        {"拖车泵",    KEY_STYLE1},
        {"加温锅电源", KEY_STYLE2},
        {"加温锅控制", KEY_STYLE1},
        {"程控启动",   KEY_STYLE2},
        {"前大灯强",   KEY_STYLE1},
        {"前大灯弱",   KEY_STYLE2},
        {"防空灯强",   KEY_STYLE1},
        {"防空灯弱",   KEY_STYLE2}
    },
    {
        {"左转向灯", KEY_STYLE1},
        {"右转向灯", KEY_STYLE2},
        {"示廓灯", KEY_STYLE1},
        {"百叶窗开", KEY_STYLE2},
        {"百叶窗关", KEY_STYLE1},
        {"机油泵", KEY_STYLE2},
        {"仓排水泵", KEY_STYLE1},
        {"排污阀", KEY_STYLE2}
    },
    {
        {"停车",     KEY_STYLE1},
        {"空气启动",  KEY_STYLE2},
        {"关闭体",   KEY_STYLE1},
        {"电喇叭",   KEY_STYLE2},
        {"三防应急",  KEY_STYLE1},
        {"进气",     KEY_STYLE2},
        {"排气",     KEY_STYLE1},
        {"后排气泵",  KEY_STYLE2}
    }
};


static QRect g_start_rect = QRect(0, 432, 800, 40);
#define BUTTON_STYLE "background-color: rgb(31, 49, 87);\n" \
                    "font: 24px bold;\n" \
                    "color: rgb(255, 255, 255);\n"


Point g_label_pos[3] =
{
    {0, 86},
    {272, 86},
    {541, 86}
};

Size g_keyrec_size[3] =
{
    {178, 40},
    {188, 40},
    {178, 40}
};

Size g_valrec_size[3] =
{
    {88, 40},
    {74, 40},
    {80, 40}
};


Panel::Panel(QWidget *parent) : QWidget(parent)
{
    ENTER();
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("MainWindow"));
    resize(800, 480);
    setStyleSheet(QStringLiteral("background-color: rgb(31, 31, 31);"));

    m_i = 1;
    m_j = 1;

    m_title = new QLabel(this);
    m_title->setGeometry(g_title_rect);
    m_title->setObjectName(QStringLiteral("title_load"));
    m_title->setStyleSheet(QLatin1String(TITLE_STYLE));
    m_title->show();

    create_labels();

    create_start_button();
    LEAVE();
}


QLabel* Panel::create_label(const QPoint& pos, const QSize& size, const char* style, const char* name)
{
    ENTER();
    QLabel* label = new QLabel(this);
    label->setStyleSheet(QLatin1String(style));
    label->move(pos);
    label->resize(size);

    if(name)
    {
        label->setText(QString::fromLocal8Bit(name));
    }
    label->show();
    LEAVE();
    return label;
}


void Panel::create_labels(int rownum, int colnum)
{
    ENTER();
    m_rownum = rownum;
    m_colnum = colnum;

    for(uint32_t i = 0; i < 3; i++)
    {
        QPoint key_pos(g_label_pos[i].x, g_label_pos[i].y);
        QSize key_size(g_keyrec_size[i].width, g_keyrec_size[i].height);

        QPoint val_pos(key_pos.x() + key_size.width() + 1, key_pos.y());
        QSize val_size(g_valrec_size[i].width, g_valrec_size[i].height);

        for(uint32_t j = 0; j < 8; j++)
        {
            auto &key_style = g_label_key[i][j].style;
            auto &key_name = g_label_key[i][j].name;
            m_labels[i][j][0] = create_label(key_pos, key_size, key_style, key_name);

            m_labels[i][j][1] = create_label(val_pos, val_size, key_style, nullptr);

            key_pos.setY(key_size.height() + key_pos.y());
            val_pos.setY(val_size.height() + val_pos.y());
        }
    }

    LEAVE();
}


void Panel::create_start_button()
{
    m_start_btn = new QPushButton(this);
    m_start_btn->setGeometry(g_start_rect);
    m_start_btn->setObjectName(QStringLiteral("start"));
    m_start_btn->setStyleSheet(QLatin1String(BUTTON_STYLE));
    m_start_btn->setText(QLatin1String("START"));
    m_start_btn->show();
}

