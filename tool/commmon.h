#pragma once

#include "tool_global.h"
#include <QString>
#include <QEvent>

enum E_WIDGET_ID
{
	eLoginUi = 0,
	eMainWidget,
};

#define TOCH(str) QString::fromLocal8Bit(str)

#define RESTART_CODE 1 //���������ʶ
#define VERIFY_SUCC 100 //��֤�ɹ�

enum E_CMD
{
	eLogin,
};

typedef struct REQUEST_STRUCT
{
	int     cmd;
	int     strWidgetId;
	QString strFuncName;
	QString strParam;
}PARAM;

//������
class TOOL_EXPORT commmon
{
public:
	commmon();
	~commmon();
};

