#include "playerWidget.h"

playerWidget::playerWidget(QWidget *parent)
	: QWidget(parent)
{
	m_pLabel = new QLabel(this);
	m_pLayout = new QHBoxLayout;
	this->setLayout(m_pLayout);
	m_pLayout->addWidget(m_pLabel);

	m_pLabel->setStyleSheet("background-color:red;");
}

playerWidget::~playerWidget()
{

}
