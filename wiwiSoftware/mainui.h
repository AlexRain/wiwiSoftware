#pragma once

#include <QtWidgets/QWidget>
#include "ui_mainui.h"
#include "logicBase.h"

class mainui : public QWidget
{
	Q_OBJECT

public:
	mainui(QWidget *parent = Q_NULLPTR);
    ~mainui();

protected:
    bool event(QEvent *event);

private:
    void updateText(QString strText);

private slots:
    void on_pushButton_request_clicked();
private:
	Ui::mainuiClass ui;
    logicBase m_logic;
};
