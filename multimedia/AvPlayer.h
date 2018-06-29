#ifndef AVPLAYER_H
#define AVPLAYER_H

#include <QWidget>
#include "multimedia_global.h"
#include "QtAV/VideoOutput.h"
#include "QtAV/AVPlayer.h"
using namespace QtAV;

class QSlider;
class QPushButton;
class AvControlWidget;

class MULTIMEDIA_EXPORT AvPlayer : public QWidget
{
	Q_OBJECT

public:
	AvPlayer(QWidget *parent = 0);
	~AvPlayer();

public Q_SLOTS:
	void openMedia();
	void seekBySlider(int value);
	void seekBySlider();
	void playPause();
	void playStop();
private Q_SLOTS:
	void updateSlider(qint64 value);
	void updateSlider();
	void updateSliderUnit();

protected:
	void enterEvent(QEvent *event);
	void leaveEvent(QEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);

private:
	QtAV::VideoOutput *m_vo;
	QtAV::AVPlayer *m_player;
	AvControlWidget *m_pControl;
	int m_unit;
	
};

#endif // AVPLAYER_H
