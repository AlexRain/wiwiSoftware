#include "CHttpThreadManager.h"
#include "TaskManager.h"
#include <QThread>
#include "CRequestThread.h"
#include <QDebug>

#define  MAX_THREADON_NUM  15

CHttpThreadManager::CHttpThreadManager(QObject *parent)
	: QObject(parent)
{
	m_nThreadCount = 0;
	m_nThreadOn = 0;
}

CHttpThreadManager::~CHttpThreadManager()
{

}

void CHttpThreadManager::getData(int nCmd, int nWidgetId, QString strFuncName, QString strParam)
{
	PARAM param;
	param.cmd = nCmd;
	param.strFuncName = strFuncName;
	param.strWidgetId = nWidgetId;
	param.strParam = strParam;

	TaskManager::Instance().InsetTask(param);

	if (m_nThreadCount < 2) //开启常驻线程
	{
		QThread *pThread = new QThread;
		CRequestThread *pObj = new CRequestThread;
		pObj->m_bAlwaysOn = true;
		pObj->moveToThread(pThread);
		pThread->start();
		m_nThreadCount++;

		connect(pObj, SIGNAL(GetDataCallback(int, int, QString, QString)),
			this, SIGNAL(GetDataCallback(int, int, QString, QString)));

		connect(pThread, &QThread::started, pObj, &CRequestThread::getData);
		connect(pThread, SIGNAL(finished()), this, SLOT(slot_threadFinish()));
		connect(pThread, SIGNAL(finished()), pObj, SLOT(deleteLater()));
		connect(pThread, SIGNAL(finished()), pThread, SLOT(deleteLater()));
	}

	if ((TaskManager::Instance().m_listTask.size() > 2) && (m_nThreadOn < MAX_THREADON_NUM)) //开启临时线程
	{
        QThread *pThread = new QThread;
		CRequestThread *pObj = new CRequestThread;
		pObj->m_bAlwaysOn = false;
		pObj->moveToThread(pThread);
		pThread->start();
        m_nThreadCount++;

		connect(pObj, SIGNAL(GetDataCallback(int, int, QString, QString)),
			this, SIGNAL(GetDataCallback(int, int, QString, QString)));

		connect(pThread, &QThread::started, pObj, &CRequestThread::getData);
		connect(pThread, SIGNAL(finished()), this, SLOT(slot_threadFinish()));
		connect(pThread, SIGNAL(finished()), pObj, SLOT(deleteLater()));
		connect(pThread, SIGNAL(finished()), pThread, SLOT(deleteLater()));
	}

    qDebug() << QString::fromLocal8Bit("当前线程数量：") << m_nThreadCount;
}

void CHttpThreadManager::slot_threadFinish()
{
	m_nThreadCount--;
    qDebug() << "One Thread Finished";
}
