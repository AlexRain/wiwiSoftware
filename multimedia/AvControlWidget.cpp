#include "AvControlWidget.h"

AvControlWidget::AvControlWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

    ui.slider->installEventFilter(this);

	initStyle();
}

AvControlWidget::~AvControlWidget()
{

}

bool AvControlWidget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui.slider)
    {
        if (QEvent::Enter == event->type())
        {
            setSliderStyle(3, 15);
        }
        else if (QEvent::Leave == event->type())
        {
            setSliderStyle(1, 0);
        }
    }
    return QWidget::eventFilter(obj, event);
}

void AvControlWidget::setSliderStyle(int nHandleWidth, int nGrooveWidth)
{
    const QString &strStyle = "#slider{border-color: #bcbcbc;}"
        "QSlider::groove:horizontal{\
			border: 1px solid #999999;\
			height: %1px;\
			margin: 0px 0;\
			left: 5px; \
			right: 5px;\
		 }"
        "QSlider::handle:horizontal{\
			border: 0px ;\
			border-image:  url(skin/point.png);\
			width: %2px;\
			margin: -7px -7px -7px -7px;\
		}"
        "QSlider::add-page:horizontal{\
			background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #bcbcbc, stop:0.25 #bcbcbc, stop:0.5 #bcbcbc, stop:1 #bcbcbc);\
		 }"
        "QSlider::sub-page:horizontal{\
			background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #ff0000, stop:0.25 #ff0000, stop:0.5 #ff0000, stop:1 #ff0000);\
		}";

    ui.slider->setStyleSheet(strStyle.arg(nHandleWidth).arg(nGrooveWidth));
}

void AvControlWidget::initStyle()
{
	//ui.slider->setStyleSheet("");
    setSliderStyle(3, 15);

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
