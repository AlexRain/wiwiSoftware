#ifndef AVPLAYER_H
#define AVPLAYER_H

#include <QWidget>
#include "multimedia_global.h"
#include "QtAV/VideoOutput.h"
#include "QtAV/AVPlayer.h"
#include <QTimer>
#include <QEvent>
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
    void slotTimeOut();
    void setFullScreen(bool bFull);
private:
    void initUi();
protected:
	void enterEvent(QEvent *event);
	void leaveEvent(QEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void showEvent(QShowEvent *event);

private:
	QtAV::VideoOutput *m_vo;
	QtAV::AVPlayer *m_player;
	AvControlWidget *m_pControl;

	int m_unit;

    QTimer m_timer;

    bool m_bPaused;
    bool m_bFullScreen;
	
};

#endif // AVPLAYER_H
