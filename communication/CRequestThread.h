#ifndef CREQUESTTHREAD_H
#define CREQUESTTHREAD_H

#include <QObject>
#include "commmon.h"
#include "CHttpManage.h"

class CRequestThread : public QObject
{
	Q_OBJECT

public:
	CRequestThread(QObject *parent = 0);
	~CRequestThread();
public slots:
	void getData();

signals:
	void GetDataCallback(int nCmd, int nWidget, QString strFuncName,QString strData);
private:
	QList<PARAM> m_listTask;
	QMutex mutex;
	CHttpManage m_httpClient;
public:
	bool m_bAlwaysOn; //是否为常驻线程
};

#endif // CREQUESTTHREAD_H
