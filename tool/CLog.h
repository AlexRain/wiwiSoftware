#ifndef CLOG_H
#define CLOG_H

#include <QObject>
#include <QFile>
#include "tool_global.h"

class TOOL_EXPORT CLog
{
public:
    CLog(/*int nType*/);
    ~CLog();
    void Install();

protected:
    //获取类型
    QString getLogger();
    
    static void MessageOutput(QtMsgType type , const QMessageLogContext &context , const QString &msg);

private:
    //int m_nType;

    static QFile* m_logFile;
};

#endif // CLOG_H
