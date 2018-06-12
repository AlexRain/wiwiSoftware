#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QObject>
#include "commmon.h"
#include <QMutex>

class TaskManager
{
private:
	TaskManager();
	~TaskManager();

public:
	static TaskManager &Instance()
	{
		static TaskManager obj;
		return obj;
	}

	void InsetTask(PARAM param);

public:
	QList<PARAM> m_listTask;
	QMutex mutex;
};

#endif // TASKMANAGER_H
