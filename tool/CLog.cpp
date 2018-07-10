#include "CLog.h"

CLog::CLog()
{
}

CLog::~CLog()
{
    if (m_logFile != NULL)
    {
        m_logFile->close();
        delete m_logFile;
        m_logFile = NULL;
    }
}

void CLog::Install()
{
    qInstallMessageHandler(CLog::MessageOutput);
}

QFile* CLog::m_logFile = NULL;

#include <QDateTime>
#include <QDir>
#include "qmutex.h"
void CLog::MessageOutput(QtMsgType type , const QMessageLogContext &context , const QString &msg)
{
    static QMutex mutex;
    QMutexLocker locker(&mutex);
    QString log;
    switch(type)
    {

    case QtDebugMsg:
        log = QString("Debug: ");
        return;//屏蔽掉debug的日志
        break;

    case QtWarningMsg:
        log = QString("Warning: ");
        break;
    case QtCriticalMsg:
        log = QString("Critical Error: ");
        break;
    case QtFatalMsg:
        log = QString("Fatal Error: ");
        abort();
        break;
    default:
        log = QString("Unknow Msg Type : ");
        break;
    };
    
    if ((m_logFile == NULL)
        ||((m_logFile != NULL)&&(m_logFile->pos() > 50000)))
    {
        if (m_logFile != NULL)
        {
            m_logFile->close();
            delete m_logFile;
            m_logFile = NULL;
        }
        QDir dir;
        if (!dir.exists("logs"))
        {
            if(!dir.mkdir("logs"))
            {
                return;
            }
        }
        QString str = QString("logs/log%1%2").arg(QDateTime::currentDateTime().toString(QString::fromLocal8Bit("yy-MM-dd hh时mm分ss秒zzz"))).arg(".log");
        m_logFile = new QFile(str, NULL);
        bool bRv = m_logFile->open(QIODevice::ReadWrite);
        if (!bRv)
        {
            delete m_logFile;
            m_logFile = NULL;
        }

    }
    if (m_logFile != NULL)
    {
        log += QDateTime::currentDateTime().toString("yy/MM/dd hh:mm:ss.zzz, File: ") + QString(context.file) ;    
        log += QString(", Line: " ) + QString::number(context.line) + QString(" : %1\r\n").arg(msg); 

        m_logFile->write(log.toLocal8Bit().data());    
        m_logFile->flush();
    }
}