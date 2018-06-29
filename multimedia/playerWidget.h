#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include "multimedia_global.h"

class MULTIMEDIA_EXPORT playerWidget : public QWidget
{
	Q_OBJECT

public:
	playerWidget(QWidget *parent = 0);
	~playerWidget();

private:
	QLabel *m_pLabel;
	QHBoxLayout *m_pLayout;
};

#endif // PLAYERWIDGET_H
