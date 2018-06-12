#ifndef CHTTPTHREADMANAGER_H
#define CHTTPTHREADMANAGER_H

#include <QObject>
#include "commmon.h"
#include "CRequestThread.h"
#include "communication_global.h"

class COMMUNICATION_EXPORT CHttpThreadManager : public QObject
{
	Q_OBJECT

public:
	CHttpThreadManager(QObject *parent = 0);
	~CHttpThreadManager();

	static CHttpThreadManager &getInstance()
	{
		static CHttpThreadManager obj;
		return obj;
	}

	void getData(int nCmd,int nWidgetId,QString strFuncName,QString strParam);

private slots:
	void slot_threadFinish();
signals:
	void GetDataCallback(int nCmd,int nWidgetId,QString strFuncName,QString strData);
private:
	QList<PARAM> m_listTask;
	QMutex mutex;
	QList<CRequestThread*> m_listThread;
	CRequestThread *m_pThreadAlwaysOn; //³£×¤Ïß³Ì
	int m_nThreadCount;
	int m_nThreadOn;
};

#endif // CHTTPTHREADMANAGER_H
