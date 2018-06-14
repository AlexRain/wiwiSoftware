#ifndef CREQUESTTHREAD_H
#define CREQUESTTHREAD_H

#include <QThread>
#include "commmon.h"
#include "CHttpManage.h"
#include <QMutex>

class CRequestThread : public QThread
{
	Q_OBJECT

public:
	CRequestThread(QObject *parent = 0);
	~CRequestThread();
protected:
	void run();
signals:
	void GetDataCallback(int nCmd, int nWidget, QString strFuncName,QString strData);
private:
	QMutex mutex_task;
	CHttpManage m_httpClient;
public:
	bool m_bAlwaysOn; //�Ƿ�Ϊ��פ�߳�
};

#endif // CREQUESTTHREAD_H
