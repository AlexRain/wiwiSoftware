#include "Cloginui.h"
#include "..\tool\commmon.h"
#include <QMouseEvent>
#include <QDesktopServices>

Cloginui::Cloginui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowFlags(Qt::FramelessWindowHint);
	initUi();
	initStyle();
}

Cloginui::~Cloginui()
{
}

void Cloginui::initUi()
{
    ui.label_forget->installEventFilter(this);


}

void Cloginui::initStyle()
{
	ui.widget_top->setStyleSheet(TOCH("#widget_top{border-image:url(skin/login/login_top.png);}"));
	ui.widget_center->setStyleSheet(TOCH("#widget_center{background-color:rgb(242,242,242);}"));
	ui.widget_user->setStyleSheet(TOCH("#widget_user{border-image:url(skin/login/bg_line.png);}"));
	ui.widget_pwd->setStyleSheet(TOCH("#widget_pwd{border-image:url(skin/login/bg_line.png);}"));
    ui.pushButton_confirm->setStyleSheet(TOCH("#pushButton_confirm{border-image:url(skin/login/login_confirm.png);font-size:13px;font-family:\"Î¢ÈíÑÅºÚ\";font-weight:bold;color:rgb(255,255,255);}"));
    ui.pushButton_cloese->setStyleSheet(TOCH("#pushButton_cloese{border-image:url(skin/login/close.png);}"));
    ui.label_user->setStyleSheet(TOCH("#label_user{border-image:url(skin/login/user.png);}"));
    ui.label_pwd->setStyleSheet(TOCH("#label_pwd{border-image:url(skin/login/pwd.png);}"));

    ui.label_forget->setStyleSheet(TOCH("#label_forget{border-image:url(skin/login/forget.png);}"));
    ui.label_tilte->setStyleSheet(TOCH("#label_tilte{font-weight:bold;color:rgb(255,255,255);font-family:\"Î¢ÈíÑÅºÚ\";font-size:13px;}"));

    ui.lineEdit_user->setStyleSheet(TOCH("#lineEdit_user{border:0;background-color:rgb(240,238,240);font-weight:bold;font-family:\"Î¢ÈíÑÅºÚ\";color:rgb(192,192,192);}"));
    ui.lineEdit_pwd->setStyleSheet(TOCH("#lineEdit_pwd{border:0;background-color:rgb(240,238,240);font-weight:bold;font-family:\"Î¢ÈíÑÅºÚ\";color:rgb(192,192,192);}"));
}

bool Cloginui::eventFilter(QObject *obj, QEvent *event)
{
    if (ui.label_forget == obj)
    {
        if (QEvent::MouseButtonRelease == event->type())
        {
            QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent*>(event);
            if (NULL != mouseEvent && Qt::LeftButton == mouseEvent->button())
            {//µã»÷Íü¼ÇÃÜÂë
                QDesktopServices::openUrl(QUrl("www.baidu.com"));
            }
        }
    }
    return QWidget::eventFilter(obj, event);
}

void Cloginui::on_pushButton_confirm_clicked()
{

}

void Cloginui::on_pushButton_cloese_clicked()
{
    this->close();
}
