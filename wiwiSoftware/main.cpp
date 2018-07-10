#include "mainui.h"
#include <QtWidgets/QApplication>
#include "Cloginui.h"
#include "commmon.h"
#include <QDesktopWidget>
#include "playerWidget.h"
#include "CLog.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// »’÷æ
	CLog log;
	log.Install();

	int nExitCode = 0;
	do 
	{
		Cloginui w;
		if (VERIFY_SUCC != w.exec())
		{
			return 0;
		}
		
		mainui mainWidget;
		mainWidget.resize(800,600);
		QDesktopWidget obj;
		QRect rect = obj.availableGeometry();
		mainWidget.move((rect.width() - mainWidget.width()) / 2, (rect.height() - mainWidget.height()) / 2);
		mainWidget.show();

		nExitCode = a.exec();

	} while (RESTART_CODE == nExitCode);

	
	return 0;
}
