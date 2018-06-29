#include "AvControlWidget.h"

AvControlWidget::AvControlWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	initStyle();
}

AvControlWidget::~AvControlWidget()
{

}

void AvControlWidget::initStyle()
{
	ui.slider->setStyleSheet("#slider{border-color: #bcbcbc;}"
		"QSlider::groove:horizontal{\
			border: 1px solid #999999;\
			height: 1px;\
			margin: 0px 0;\
			left: 5px; \
			right: 5px;\
		 }"
		"QSlider::handle:horizontal{\
			border: 0px ;\
			border-image:  url(skin/point.png);\
			width: 15px;\
			margin: -7px -7px -7px -7px;\
		}"
		"QSlider::add-page:horizontal{\
			background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #bcbcbc, stop:0.25 #bcbcbc, stop:0.5 #bcbcbc, stop:1 #bcbcbc);\
		 }"
		"QSlider::sub-page:horizontal{\
			background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #439cf3, stop:0.25 #439cf3, stop:0.5 #439cf3, stop:1 #439cf3);\
		}");

	//°´Å¥ÑùÊ½
	ui.btn_play->setStyleSheet("#btn_play{border-image:url(skin/play_normal.png);}"
		"#btn_play::checked{border-image:url(skin/pause.png);}");

	ui.btn_forward->setStyleSheet("#btn_forward{border-image:url(skin/skip-forward.png);}"
		"#btn_forward::checked{border-image:url();}");

	ui.btn_volume->setStyleSheet("#btn_volume{border-image:url(skin/volume_high.png);}");

	ui.btn_setting->setStyleSheet("#btn_setting{border-image:url(skin/settings .png)}");

	ui.btn_fullScreen->setStyleSheet("#btn_fullScreen{border-image:url(skin/full_screen.png);}"
		"#btn_fullScreen::checked{border-image:url(skin/full_screen.png);}");


}
