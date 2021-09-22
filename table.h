#ifndef TABLE_H
#define TABLE_H

#include <QLabel>
#include "common.h"

typedef struct _LabelInfo
{
    const char* name;
    const char* style;
}LabelInfo;

class Table
{
public:
    QLabel* create_label(QWidget* parent, const QPoint& pos, const QSize& size, const char* style, const char* name)
    {
        ENTER();
        QLabel* label = new QLabel(parent);
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
    void create_labels(QWidget* parent, QLabel* qlabels[][2] , int rownum, const LabelInfo label_info[][2], const Point label_pos, const Size rec_size[])
    {
        ENTER();
        uint32_t y = label_pos.y;
        uint32_t h = rec_size[0].height;
        for(uint32_t i = 0; i < rownum; i++)
        {
            uint32_t x = label_pos.x;
            for(uint32_t j = 0; j < sizeof(qlabels[0])/sizeof(qlabels[0][0]); j++)
            {
                qlabels[i][j] = create_label(parent, QPoint(x, y), QSize(rec_size[j].width, rec_size[j].height), label_info[i][j].style, label_info[i][j].name);
                x += rec_size[j].width + 1;
            }
            y += h;
        }
        LEAVE();
    }

    void create_labels(QWidget* parent, QLabel* qlabels[][3] , int rownum, const LabelInfo label_info[][3], const Point label_pos, const Size rec_size[])
    {
        ENTER();
        uint32_t y = label_pos.y;
        uint32_t h = rec_size[0].height;
        for(uint32_t i = 0; i < rownum; i++)
        {
            uint32_t x = label_pos.x;
            for(uint32_t j = 0; j < sizeof(qlabels[0])/sizeof(qlabels[0][0]); j++)
            {
                qlabels[i][j] = create_label(parent, QPoint(x, y), QSize(rec_size[j].width, rec_size[j].height), label_info[i][j].style, label_info[i][j].name);
                x += rec_size[j].width + 1;
            }
            y += h;
        }
        LEAVE();
    }

    void create_labels(QWidget* parent, QLabel* qlabels[][4] , int rownum, const LabelInfo label_info[][4], const Point label_pos, const Size rec_size[])
    {
        ENTER();
        uint32_t y = label_pos.y;
        uint32_t h = rec_size[0].height;
        for(uint32_t i = 0; i < rownum; i++)
        {
            uint32_t x = label_pos.x;
            for(uint32_t j = 0; j < sizeof(qlabels[0])/sizeof(qlabels[0][0]); j++)
            {
                qlabels[i][j] = create_label(parent, QPoint(x, y), QSize(rec_size[j].width, rec_size[j].height), label_info[i][j].style, label_info[i][j].name);
                x += rec_size[j].width + 1;
            }
            y += h;
        }
        LEAVE();
    }

};

#endif // TABLE_H
