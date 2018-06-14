#include "TaskManager.h"
#include <QMutexLocker>

TaskManager::TaskManager()
{

}

TaskManager::~TaskManager()
{

}

void TaskManager::InsetTask(PARAM param)
{
	QMutexLocker lock(&mutex);
}
