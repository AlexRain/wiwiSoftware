#include "TaskManager.h"

TaskManager::TaskManager()
{

}

TaskManager::~TaskManager()
{

}

void TaskManager::InsetTask(PARAM param)
{
	QMutexLocker lock(&mutex);
	m_listTask.push_back(param);
}
