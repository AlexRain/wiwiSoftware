#include "mainui.h"
#include <QtWidgets/QApplication>
#include "Cloginui.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Cloginui w;
	w.show();
	return a.exec();
}
