#include "EventManager.h"
#include <QApplication> 
#include "CustEvent.h"
#include "CHttpThreadManager.h"
#include <QtDebug>

EventManager::EventManager(QObject *parent)
	: QObject(parent)
{
	connect(&CHttpThreadManager::getInstance(), SIGNAL(GetDataCallback(int, int, QString, QString)),
		this, SLOT(PostEvent(int, int, QString, QString)), Qt::QueuedConnection);
}

EventManager::~EventManager()
{

}

void EventManager::PostEvent(const E_WIDGET_ID &receiver, const QString& strFunName, const QVariant &value)
{
	if (NULL == mapWidget[receiver])
	{
		qWarning() << QString("the widget instance is null,widget id is %1,funcName is %2").arg(receiver).arg(strFunName);
		return;
	}
	qWarning() << QString("widget id is %1,funcName is %2").arg(receiver).arg(strFunName);
	QApplication::postEvent(mapWidget[receiver], new CustEvent(strFunName, value));
}

void EventManager::PostEvent(int nCmd, int nWidgetId, QString strFuncName, QString csData)
{
	E_WIDGET_ID widgetId = (E_WIDGET_ID)nWidgetId;

	if (NULL == mapWidget[widgetId])
	{
		qWarning() << QString("the widget instance is null,widget id is %1,funcName is %2").arg(widgetId).arg(strFuncName);
		return;
	}
	qWarning() << QString("widget id is %1,funcName is %2").arg(widgetId).arg(strFuncName);

	QApplication::postEvent(mapWidget[widgetId], new CustEvent(strFuncName, csData));
}

void EventManager::RegistWidgetAndFunc(E_WIDGET_ID eWidgetId, QWidget * pWidget)
{
	mapWidget[eWidgetId] = pWidget;
}

void EventManager::UnRegist(E_WIDGET_ID eWidgetId)
{
	if (mapWidget.find(eWidgetId) != mapWidget.end())
	{
		//remove the widget
		mapWidget.erase(mapWidget.find(eWidgetId));
	}
}
