#include "CRequestThread.h"
#include <QThread>
#include "TaskManager.h"

CRequestThread::CRequestThread(QObject *parent)
	: QThread(parent)
{
	m_bAlwaysOn = false;
}

CRequestThread::~CRequestThread()
{

}

void CRequestThread::run()
{
	while (1)
	{
		TaskManager::Instance().mutex.lock();
		int nSize = TaskManager::Instance().m_listTask.size();
		if (nSize <= 0)
		{
			if (!m_bAlwaysOn)
			{
				TaskManager::Instance().mutex.unlock();
				break;
			}
			TaskManager::Instance().mutex.unlock();
			QThread::msleep(200);
		}
		else
		{
			mutex_task.lock();
			PARAM param = TaskManager::Instance().m_listTask.front();
			TaskManager::Instance().m_listTask.pop_front();
			mutex_task.unlock();
			TaskManager::Instance().mutex.unlock();

			QString strData = m_httpClient.getData(param.cmd, param.strParam);
			emit GetDataCallback(param.cmd,param.strWidgetId,param.strFuncName,strData);

			if (!m_bAlwaysOn)
			{
				break;
			}
		}
	}
}
