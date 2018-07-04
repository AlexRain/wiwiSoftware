#include "mainui.h"
#include "EventManager.h"
#include "CustEvent.h"
#include <QDebug>
#include <QPainter>
#include "AvPlayer.h"

mainui::mainui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

    event_helper.RegistWidgetAndFunc(eMainWidget, this);
    //m_logic.getWebContent(eMainWidget, "updateText", "");
	registEvent();
}

mainui::~mainui()
{
    event_helper.UnRegist(eMainWidget);
}

void mainui::updateText(QString strText)
{
    qDebug() << "WebContent:" << strText;
}

void mainui::on_pushButton_request_clicked()
{
    //m_logic.getWebContent(eMainWidget, "updateText", "");
	AvPlayer *player = new AvPlayer;
	player->setFixedSize(800, 600);
	player->show();
	//ui.label->hide();
	//ui.verticalLayout_2->addWidget(player);
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

char mainui::FirstDriveFromMask(ULONG unitmask)
{
	char i;
	for (i = 0; i < 26; ++i)
	{
		if (unitmask & 0x1)
			break;
		unitmask = unitmask >> 1;
	}
	return (i + 'A');
}

bool mainui::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
	MSG* msg = reinterpret_cast<MSG*>(message);
	int msgType = msg->message;
	if (msgType == WM_DEVICECHANGE)
	{
		PDEV_BROADCAST_HDR lpdb = (PDEV_BROADCAST_HDR)msg->lParam;
		switch (msg->wParam) {
		case DBT_DEVICEARRIVAL:
			if (lpdb->dbch_devicetype == DBT_DEVTYP_VOLUME)
			{
				PDEV_BROADCAST_VOLUME lpdbv = (PDEV_BROADCAST_VOLUME)lpdb;
				if (lpdbv->dbcv_flags == 0)
				{
					//插入u盘
					QString USBDisk = QString(this->FirstDriveFromMask(lpdbv->dbcv_unitmask));
					qDebug() << "USB_Arrived and The USBDisk is: " << USBDisk;
					ui.label->setText("USB_Arrived and The USBDisk is " + USBDisk);

				}
			}
			if (lpdb->dbch_devicetype = DBT_DEVTYP_DEVICEINTERFACE)
			{
				PDEV_BROADCAST_DEVICEINTERFACE pDevInf = (PDEV_BROADCAST_DEVICEINTERFACE)lpdb;

				QString strname = QString::fromWCharArray(pDevInf->dbcc_name, pDevInf->dbcc_size);

				ui.label->setText(QString::fromLocal8Bit("插入设备 ：") + strname);
			}
			break;
		case DBT_DEVICEREMOVECOMPLETE:
			qDebug() << QString::fromLocal8Bit("移除设备(name)：") << endl;
			if (lpdb->dbch_devicetype == DBT_DEVTYP_VOLUME)
			{
				PDEV_BROADCAST_VOLUME lpdbv = (PDEV_BROADCAST_VOLUME)lpdb;
				if (lpdbv->dbcv_flags == 0)
				{
					ui.label->setText("USB_Remove");

				}
			}
			if (lpdb->dbch_devicetype = DBT_DEVTYP_DEVICEINTERFACE)
			{
				PDEV_BROADCAST_DEVICEINTERFACE pDevInf = (PDEV_BROADCAST_DEVICEINTERFACE)lpdb;
				qDebug() << QString::fromLocal8Bit("移除设备(name)：") << pDevInf->dbcc_name;
				qDebug() << QString::fromLocal8Bit("移除设备(name)：") << pDevInf->dbcc_size;

				QString strname = QString::fromWCharArray(pDevInf->dbcc_name, pDevInf->dbcc_size);

				ui.label->setText(QString::fromLocal8Bit("移除设备(name)：") + strname);
			}
			break;
		}
	}
	return false;
}

void mainui::registEvent()
{
	static const GUID GUID_DEVINTERFACE_LIST[] =
	{
		// GUID_DEVINTERFACE_USB_DEVICE
		{ 0xA5DCBF10, 0x6530, 0x11D2, { 0x90, 0x1F, 0x00, 0xC0, 0x4F, 0xB9, 0x51, 0xED } },
		// GUID_DEVINTERFACE_DISK
		{ 0x53f56307, 0xb6bf, 0x11d0, { 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b } },
		// GUID_DEVINTERFACE_HID,
		{ 0x4D1E55B2, 0xF16F, 0x11CF, { 0x88, 0xCB, 0x00, 0x11, 0x11, 0x00, 0x00, 0x30 } },
		// GUID_NDIS_LAN_CLASS
		{ 0xad498944, 0x762f, 0x11d0, { 0x8d, 0xcb, 0x00, 0xc0, 0x4f, 0xc3, 0x35, 0x8c } }
	};

	//注册插拔事件
	HDEVNOTIFY hDevNotify;
	DEV_BROADCAST_DEVICEINTERFACE NotifacationFiler;
	ZeroMemory(&NotifacationFiler, sizeof(DEV_BROADCAST_DEVICEINTERFACE));
	NotifacationFiler.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
	NotifacationFiler.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;

	for (int i = 0; i < sizeof(GUID_DEVINTERFACE_LIST) / sizeof(GUID); i++)
	{
		NotifacationFiler.dbcc_classguid = GUID_DEVINTERFACE_LIST[i];

		hDevNotify = RegisterDeviceNotification((HANDLE)this->winId(), &NotifacationFiler, DEVICE_NOTIFY_WINDOW_HANDLE);
		if (!hDevNotify)
		{
			int Err = GetLastError();
			qDebug() << "注册失败" << endl;
		}
	}
}
