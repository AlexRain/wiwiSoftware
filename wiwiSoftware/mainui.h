#pragma once

#include <QtWidgets/QWidget>
#include "ui_mainui.h"
#include "logicBase.h"

#include <windows.h>
#include <dbt.h>
#include<devguid.h>
#include<SetupAPI.h>
#include<InitGuid.h>

class mainui : public QWidget
{
	Q_OBJECT

public:
	mainui(QWidget *parent = Q_NULLPTR);
    ~mainui();

protected:
    bool event(QEvent *event);
	bool nativeEvent(const QByteArray &eventType, void *message, long *result);

private:
    void updateText(QString strText);
	void registEvent();

private slots:
    void on_pushButton_request_clicked();
	char FirstDriveFromMask(ULONG unitmask);
private:
	Ui::mainuiClass ui;
    logicBase m_logic;
};
