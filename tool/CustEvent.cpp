#include "CustEvent.h"
#include "commmon.h"

CustEvent::CustEvent(const QString &strFuncName, const QVariant &value)
:QEvent(CustomEventType), m_strFunCName(strFuncName), m_value(value)
{

}

CustEvent::~CustEvent()
{

}
