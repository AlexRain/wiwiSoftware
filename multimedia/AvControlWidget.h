#ifndef AVCONTROLWIDGET_H
#define AVCONTROLWIDGET_H

#include <QWidget>
#include "ui_AvControlWidget.h"

class AvControlWidget : public QWidget
{
	Q_OBJECT

public:
	AvControlWidget(QWidget *parent = 0);
	~AvControlWidget();

private:
	void initStyle();

public:
	Ui::AvControlWidget ui;
};

#endif // AVCONTROLWIDGET_H
