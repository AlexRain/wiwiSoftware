#ifndef CHTTPMANAGE_H
#define CHTTPMANAGE_H

#include <QObject>

class CHttpManage:QObject
{
	Q_OBJECT
public:
	CHttpManage(QObject *parent = 0);
	~CHttpManage();

	QString getData(int nCmd, QString param);

	void initHttp(QUrl url);

private:
	
};

#endif // CHTTPMANAGE_H
