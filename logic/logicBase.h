#pragma once

#include "logic_global.h"
#include <QString>

class LOGIC_EXPORT logicBase
{
public:
	logicBase();

    void getWebContent(int nWidgetId,QString strFuncName,QString strParam);

private:
    void getData(int nCmd, int nWidgetId, QString strFuncName, QString strParam);
};
