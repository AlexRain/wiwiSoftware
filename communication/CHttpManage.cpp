#include "CHttpManage.h"
#include "commmon.h"
#include <QNetworkAccessManager>
#include <QTimer>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>

CHttpManage::CHttpManage(QObject *parent)
	:QObject(parent)
{

}

CHttpManage::~CHttpManage()
{

}

QString CHttpManage::getData(int nCmd, QString param)
{
	QString strData = QString();

	QTimer timer;
	timer.setInterval(30000);  // ���ó�ʱʱ�� 30 ��
	timer.setSingleShot(true);  // ���δ���

	QTime timeUse;
	timeUse.start();
	// ���� Qt ����
	QNetworkAccessManager manager;
	QNetworkRequest request;

	QSslConfiguration config = request.sslConfiguration();
	config.setPeerVerifyMode(QSslSocket::VerifyNone);
	config.setProtocol(QSsl::TlsV1SslV3);
	request.setSslConfiguration(config);

	request.setUrl(QUrl("https://www.baidu.com"));
	request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");

	QNetworkReply *pReply = manager.get(request);

	QEventLoop loop;
	connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
	connect(pReply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
	timer.start();
	loop.exec();  // �����¼�ѭ��

	if (timer.isActive()) {  // ������Ӧ
		timer.stop();
		if (pReply->error() != QNetworkReply::NoError) {
			// ������
			qDebug() << "Error String : " << pReply->errorString();
			strData = pReply->errorString();
		}
		else {
			QVariant variant = pReply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
			int nStatusCode = variant.toInt();
			// ����״̬������һ�����ݴ���
			QByteArray bytes = pReply->readAll();
			strData = QString::fromUtf8(bytes);
		}
	}
	else {  // ����ʱ
		disconnect(pReply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
		pReply->abort();
		pReply->deleteLater();
		strData = "Request Timeout!";
		qDebug() << "Http Timeout";
	}

	qWarning() << "Cmd:" << nCmd << TOCH("ʹ��ʱ�䣺") << timeUse.elapsed() << "ms";
	return strData;
}
