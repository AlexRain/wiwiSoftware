#pragma once

#include <QWidget>
#include "ui_Cloginui.h"
#include <QEvent>

class Cloginui : public QWidget
{
	Q_OBJECT

public:
	Cloginui(QWidget *parent = Q_NULLPTR);
	~Cloginui();
private:
	void initUi();
	void initStyle();
private slots:
    void on_pushButton_cloese_clicked();
    void on_pushButton_confirm_clicked();
protected:
    bool eventFilter(QObject *obj,QEvent *event);

private:
	Ui::Cloginui ui;
};
