#ifndef CUSTEVENT_H
#define CUSTEVENT_H

#include <QEvent>
#include "tool_global.h"
#include <QString>
#include <QVariant>

const QEvent::Type CustomEventType = (QEvent::Type)5001;//建议用5000以上唯一的标识

class TOOL_EXPORT CustEvent : public QEvent
{
public:
	CustEvent(const QString &strFuncName = QString(), const QVariant &value = QVariant());
	~CustEvent();

public:
	QString funcName(){ return m_strFunCName; };
	QVariant value(){ return m_value; };

private:
	QString m_strFunCName;
	QVariant m_value;
};

#endif // CUSTEVENT_H
