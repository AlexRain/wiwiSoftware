#include "AvPlayer.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFileDialog>
#include <QSlider>
#include <QpushButton>
#include "AvControlWidget.h"
#include <QMouseEvent>

AvPlayer::AvPlayer(QWidget *parent)
: QWidget(parent)
{
	m_unit = 1000;
    m_bPaused = false;
    m_bFullScreen = false;
    this->setMouseTracking(true);
    initUi();
}

AvPlayer::~AvPlayer()
{
	
}

void AvPlayer::initUi()
{
    m_player = new AVPlayer(this);
    m_player->setVideoDecoderPriority(QStringList() << "DXVA");
    QVBoxLayout *vl = new QVBoxLayout();
    vl->setContentsMargins(0, 0, 0, 0);
    vl->setSpacing(0);
    setLayout(vl);
    m_vo = new VideoOutput(this);
    if (!m_vo->widget()) {
        QMessageBox::warning(0, QString::fromLatin1("QtAV error"), tr("Can not create video renderer"));
        return;
    }
    m_player->setRenderer(m_vo);
    m_vo->widget()->setMouseTracking(true);
    vl->addWidget(m_vo->widget());

    //Ìí¼Ó¿ØÖÆÃæ°å
    m_pControl = new AvControlWidget(this);
    m_pControl->setFixedHeight(65);
    m_pControl->setObjectName("m_pControl");
    m_pControl->setStyleSheet("m_pControl{background-color:transparent;}");

    connect(m_pControl->ui.slider, SIGNAL(sliderMoved(int)), SLOT(seekBySlider(int)));
    connect(m_pControl->ui.slider, SIGNAL(sliderPressed()), SLOT(seekBySlider()));
    connect(m_player, SIGNAL(positionChanged(qint64)), SLOT(updateSlider(qint64)));
    connect(m_player, SIGNAL(started()), SLOT(updateSlider()));
    connect(m_player, SIGNAL(notifyIntervalChanged()), SLOT(updateSliderUnit()));


    //connect(m_openBtn, SIGNAL(clicked()), SLOT(openMedia()));
    connect(m_pControl->ui.btn_play, SIGNAL(clicked()), SLOT(playPause()));
    connect(m_pControl->ui.btn_forward, SIGNAL(clicked()), SLOT(playPause()));
    connect(m_pControl->ui.btn_volume, SIGNAL(clicked()), SLOT(playPause()));
    connect(m_pControl->ui.btn_setting, SIGNAL(clicked()), SLOT(openMedia()));
    connect(m_pControl->ui.btn_fullScreen, &QPushButton::clicked, [=] {
        
        m_bFullScreen = !m_bFullScreen;
        setFullScreen(m_bFullScreen);
    });
    //connect(m_stopBtn, SIGNAL(clicked()), this, SLOT(playStop()));
    connect(&m_timer, &QTimer::timeout, this, &AvPlayer::slotTimeOut);
}

void AvPlayer::openMedia()
{
	QString file = QFileDialog::getOpenFileName(0, tr("Open a video"));
	if (file.isEmpty())
		return;
	m_player->play(file);
}

void AvPlayer::seekBySlider(int value)
{
	if (!m_player->isPlaying())
		return;
	qDebug("seekbyslider: %d", value);
	m_player->seek(qint64(value*m_unit));
}

void AvPlayer::seekBySlider()
{
	qDebug("pressed: %d", m_pControl->ui.slider->value());
	seekBySlider(m_pControl->ui.slider->value());
}

void AvPlayer::playPause()
{
	if (!m_player->isPlaying()) {
        m_bPaused = false;
        m_player->play();
        m_pControl->ui.btn_play->setChecked(false);
		return;
	}
    m_bPaused = !m_player->isPaused();
    m_pControl->ui.btn_play->setChecked(m_bPaused);
	m_player->pause(!m_player->isPaused());
}

void AvPlayer::updateSlider(qint64 value)
{
	m_pControl->ui.slider->setRange(0, int(m_player->duration() / m_unit));
	m_pControl->ui.slider->setValue(int(value / m_unit));
}

void AvPlayer::updateSlider()
{
	updateSlider(m_player->position());
}

void AvPlayer::updateSliderUnit()
{
	m_unit = m_player->notifyInterval();
	updateSlider();
}

void AvPlayer::slotTimeOut()
{
    if (!m_bPaused)
        m_pControl->hide();
}

void AvPlayer::setFullScreen(bool bFull)
{
    if (bFull)
    {
        this->showFullScreen();
    }
    else
    {
        this->showNormal();
    }
}

void AvPlayer::playStop()
{
	m_player->stop();
}

void AvPlayer::enterEvent(QEvent *event)
{
    m_pControl->show();
    if (m_timer.isActive())
    {
        m_timer.stop();
    }
    m_timer.start(3000);
}

void AvPlayer::leaveEvent(QEvent *event)
{
    if(!m_bPaused)
        m_pControl->hide();
}

void AvPlayer::mouseMoveEvent(QMouseEvent *event)
{
    m_pControl->show();
    if (m_timer.isActive())
    {
        m_timer.stop();
    }
    m_timer.start(3000);
    QWidget::mouseMoveEvent(event);
}

void AvPlayer::mouseReleaseEvent(QMouseEvent *event)
{
    if (!m_pControl->geometry().contains(event->pos()))
    {
        if (Qt::LeftButton == event->button())
        {
            playPause();
        }
    }
        
    QWidget::mouseReleaseEvent(event);
}

void AvPlayer::mouseDoubleClickEvent(QMouseEvent * event)
{
    if (!m_pControl->geometry().contains(event->pos()))
    {
        m_bFullScreen = !m_bFullScreen;
        setFullScreen(m_bFullScreen);
    }

    QWidget::mouseDoubleClickEvent(event);
}

void AvPlayer::resizeEvent(QResizeEvent *event)
{
    m_pControl->setFixedWidth(this->width() - 20);
    m_pControl->move(10, this->height() - m_pControl->height());
    QWidget::resizeEvent(event);
}

void AvPlayer::showEvent(QShowEvent *event)
{
    m_pControl->setFixedWidth(this->width() - 20);
    m_pControl->move(10, this->height() - m_pControl->height());
    QWidget::showEvent(event);
}
