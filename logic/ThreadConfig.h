#ifndef THREADCONFIG_H
#define THREADCONFIG_H

#include <QObject>
#include "commmon.h"
#include <QVariant>
#include "logic_global.h"

class LOGIC_EXPORT ThreadConfig : public QObject
{
	Q_OBJECT

public:
	ThreadConfig(QObject *parent = 0);
	~ThreadConfig();
public slots:
	void calculate();
signals:
	void signalPostEvent(const E_WIDGET_ID &receiver, const QString &strFunName, const QVariant &value = QVariant());

private:
	
};

#endif // THREADCONFIG_H
