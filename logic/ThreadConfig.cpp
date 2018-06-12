#include "ThreadConfig.h"
#include <QCoreApplication>
#include "EventManager.h"
#include <QThread>
#include <QTime>
#include <QColor>
#include <QDebug>

#define NUM_MAX 100

ThreadConfig::ThreadConfig(QObject *parent)
	: QObject(parent)
{
	qRegisterMetaType<E_WIDGET_ID>("E_WIDGET_ID");
	connect(this, SIGNAL(signalPostEvent(const E_WIDGET_ID &, const QString &, const QVariant &)),
		&EventManager::getInstance(), SLOT(PostEvent(const E_WIDGET_ID &, const QString &, const QVariant &)), Qt::QueuedConnection);
}

ThreadConfig::~ThreadConfig()
{

}

void ThreadConfig::calculate()
{
	int nIndex = 0;

	int nRed = qrand() % 255;
	int nGreen = qrand() % 255;
	int nBlue = qrand() % 255;

	while (true)
	{
		QMap<QString, QVariant> mapData;
		qsrand(QTime::currentTime().msec());

		if (nRed >= 255)
		{
			nRed = qrand() % 255;
		}

		if (nGreen >= 255)
		{
			nGreen = qrand() % 255;
		}

		if (nBlue >= 255)
		{
			nBlue = qrand() % 255;
		}

		QColor color = QColor(nRed,nGreen,nBlue);
		mapData["color"] = color;
		mapData["index"] = nIndex;
		if (color.isValid())
		{
			emit signalPostEvent(eMainWidget, "updateUi", mapData);
			qDebug() << color.red() << color.green() << color.blue();
		}
		else
		{
			qDebug() << "inValid Color....";
		}
		
		QThread::msleep(100);
		nRed += 1;
		nGreen += 1;
		nBlue += 1;
	}
}
