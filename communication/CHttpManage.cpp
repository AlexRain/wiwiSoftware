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
	timer.setInterval(30000);  // 设置超时时间 30 秒
	timer.setSingleShot(true);  // 单次触发

	QTime timeUse;
	timeUse.start();
	// 请求 Qt 官网
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
	loop.exec();  // 启动事件循环

	if (timer.isActive()) {  // 处理响应
		timer.stop();
		if (pReply->error() != QNetworkReply::NoError) {
			// 错误处理
			qDebug() << "Error String : " << pReply->errorString();
			strData = pReply->errorString();
		}
		else {
			QVariant variant = pReply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
			int nStatusCode = variant.toInt();
			// 根据状态码做进一步数据处理
			QByteArray bytes = pReply->readAll();
			strData = QString::fromUtf8(bytes);
		}
	}
	else {  // 处理超时
		disconnect(pReply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
		pReply->abort();
		pReply->deleteLater();
		strData = "Request Timeout!";
		qDebug() << "Http Timeout";
	}

	qWarning() << "Cmd:" << nCmd << TOCH("使用时间：") << timeUse.elapsed() << "ms";
	return strData;
}
