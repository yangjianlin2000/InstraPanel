#ifndef INSTRPANEL_DLC_H
#define INSTRPANEL_DLC_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QKeyEvent>
#include "table.h"

class InstrPanel_DLC : public QWidget, public Table
{
    Q_OBJECT
public:
    explicit InstrPanel_DLC(QWidget *parent = nullptr);

protected:
    virtual KeyHandleState keyPressEvent(QKeyEvent  *event);

signals:

private:
    void create_page1();
    void create_page2();
    void create_page1_labels(QWidget* parent_frame);
    void create_page2_labels(QWidget* parent_frame);
    void create_start_button(QWidget* parent_frame);

private:
    QWidget* m_page1;
    QLabel* m_title1;
    QLabel* m_table1[9][3];
    QLabel* m_table2[9][3];

    QWidget* m_page2;
    QLabel* m_title2;
    QLabel* m_subtitle2;
    QLabel* m_table3[6][3];
    QLabel* m_table4[10][4];
    QLabel* m_table5[3][4];

    QPushButton* m_start_btn;
    QStackedWidget* m_stackedWidget;
};

#endif // INSTRPANEL_DLC_H
