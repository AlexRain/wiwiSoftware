#include "CRequestThread.h"
#include <QThread>
#include "TaskManager.h"

CRequestThread::CRequestThread(QObject *parent)
	: QObject(parent)
{
	m_bAlwaysOn = false;
}

CRequestThread::~CRequestThread()
{

}

void CRequestThread::getData()
{
	while (1)
	{
        QMutexLocker lock(&mutex);
		int nSize = TaskManager::Instance().m_listTask.size();
		if (nSize <= 0)
		{
			if (!m_bAlwaysOn)
			{
				break;
				QThread::sleep(200);
			}
		}
		else
		{
			PARAM param = TaskManager::Instance().m_listTask.front();
			QString strData = m_httpClient.getData(param.cmd, param.strParam);
			emit GetDataCallback(param.cmd,param.strWidgetId,param.strFuncName,strData);

            int n = TaskManager::Instance().m_listTask.size();

			TaskManager::Instance().m_listTask.pop_front();
		}
	}
}
