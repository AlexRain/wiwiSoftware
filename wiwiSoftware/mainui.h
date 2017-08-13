#pragma once

#include <QtWidgets/QWidget>
#include "ui_mainui.h"

class mainui : public QWidget
{
	Q_OBJECT

public:
	mainui(QWidget *parent = Q_NULLPTR);

private:
	Ui::mainuiClass ui;
};
