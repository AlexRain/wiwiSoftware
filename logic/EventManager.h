#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <QObject>
#include "commmon.h"
#include <QMap>
#include <QWidget>
#include <QVariant>
#include "logic_global.h"

#define event_helper EventManager::getInstance()

class LOGIC_EXPORT EventManager : public QObject
{
	Q_OBJECT

private:
	EventManager(QObject *parent = 0);
	~EventManager();

public:
	static EventManager & getInstance()
	{
		static EventManager obj;
		return obj;
	}

public:
	void RegistWidgetAndFunc(E_WIDGET_ID eWidgetId, QWidget * pWidget);
	void UnRegist(E_WIDGET_ID eWidgetId);

public slots:
	void PostEvent(const E_WIDGET_ID &receiver, const QString&strFunName, const QVariant &value = QVariant());
	void PostEvent(int nCmd, int nWidgetId, QString csFuncName, QString csData);
private:
	QMap<E_WIDGET_ID, QWidget*> mapWidget;
};

#endif // EVENTMANAGER_H
