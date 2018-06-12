#include "logicBase.h"
#include "CHttpThreadManager.h"

logicBase::logicBase()
{
}

//ÇëÇóÍøÒ³ÄÚÈİ
void logicBase::getWebContent(int nWidgetId, QString strFuncName, QString strParam)
{
    getData(eLogin,nWidgetId, strFuncName ,strParam);
}

void logicBase::getData(int nCmd, int nWidgetId, QString strFuncName, QString strParam)
{
    CHttpThreadManager::getInstance().getData(nCmd,nWidgetId,strFuncName,strParam);
}
