#include "mainui.h"
#include "EventManager.h"
#include "CustEvent.h"
#include <QDebug>
#include <QPainter>

mainui::mainui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

    event_helper.RegistWidgetAndFunc(eMainWidget, this);
    m_logic.getWebContent(eMainWidget, "updateText", "");
}

mainui::~mainui()
{
    event_helper.UnRegist(eMainWidget);
}

void mainui::updateText(QString strText)
{
    qDebug() << "WebContent:" << strText;

    ui.textBrowser->append(strText);
}

void mainui::on_pushButton_request_clicked()
{
    m_logic.getWebContent(eMainWidget, "updateText", "");
}

bool mainui::event(QEvent *event)
{
    if (CustomEventType == event->type())
    {
        CustEvent *e = static_cast<CustEvent*>(event);
        if (NULL != e)
        {
            if ("updateText" == e->funcName())
            {
                this->updateText(e->value().toString());
            }
        }
    }
    return QWidget::event(event);
}
