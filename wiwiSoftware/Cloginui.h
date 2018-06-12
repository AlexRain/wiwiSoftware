#pragma once

#include <QDialog>
#include "ui_Cloginui.h"
#include <QEvent>

class Cloginui : public QDialog
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
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void keyPressEvent(QKeyEvent *event);
	bool event(QEvent *event);
private:
	void updateUi(QString strText);
private:
	Ui::Cloginui ui;
	QPoint m_dragPoint;
	bool m_bCanMove;
};
