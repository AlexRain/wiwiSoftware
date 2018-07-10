/********************************************************************************
** Form generated from reading UI file 'AvControlWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AVCONTROLWIDGET_H
#define UI_AVCONTROLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AvControlWidget
{
public:
    QVBoxLayout *verticalLayout;
    QSlider *slider;
    QWidget *widget_btns;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_play;
    QPushButton *btn_forward;
    QPushButton *btn_volume;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_setting;
    QPushButton *btn_fullScreen;

    void setupUi(QWidget *AvControlWidget)
    {
        if (AvControlWidget->objectName().isEmpty())
            AvControlWidget->setObjectName(QStringLiteral("AvControlWidget"));
        AvControlWidget->resize(681, 64);
        verticalLayout = new QVBoxLayout(AvControlWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 10);
        slider = new QSlider(AvControlWidget);
        slider->setObjectName(QStringLiteral("slider"));
        slider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider);

        widget_btns = new QWidget(AvControlWidget);
        widget_btns->setObjectName(QStringLiteral("widget_btns"));
        horizontalLayout = new QHBoxLayout(widget_btns);
        horizontalLayout->setSpacing(25);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(25, 0, 15, 0);
        btn_play = new QPushButton(widget_btns);
        btn_play->setObjectName(QStringLiteral("btn_play"));
        btn_play->setMinimumSize(QSize(32, 32));
        btn_play->setMaximumSize(QSize(32, 32));
        btn_play->setCheckable(true);

        horizontalLayout->addWidget(btn_play);

        btn_forward = new QPushButton(widget_btns);
        btn_forward->setObjectName(QStringLiteral("btn_forward"));
        btn_forward->setMinimumSize(QSize(32, 32));
        btn_forward->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(btn_forward);

        btn_volume = new QPushButton(widget_btns);
        btn_volume->setObjectName(QStringLiteral("btn_volume"));
        btn_volume->setMinimumSize(QSize(32, 32));
        btn_volume->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(btn_volume);

        label = new QLabel(widget_btns);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_setting = new QPushButton(widget_btns);
        btn_setting->setObjectName(QStringLiteral("btn_setting"));
        btn_setting->setMinimumSize(QSize(32, 32));
        btn_setting->setMaximumSize(QSize(32, 32));
        btn_setting->setCheckable(true);

        horizontalLayout->addWidget(btn_setting);

        btn_fullScreen = new QPushButton(widget_btns);
        btn_fullScreen->setObjectName(QStringLiteral("btn_fullScreen"));
        btn_fullScreen->setMinimumSize(QSize(32, 32));
        btn_fullScreen->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(btn_fullScreen);


        verticalLayout->addWidget(widget_btns);


        retranslateUi(AvControlWidget);

        QMetaObject::connectSlotsByName(AvControlWidget);
    } // setupUi

    void retranslateUi(QWidget *AvControlWidget)
    {
        AvControlWidget->setWindowTitle(QApplication::translate("AvControlWidget", "AvControlWidget", Q_NULLPTR));
        btn_play->setText(QString());
        btn_forward->setText(QString());
        btn_volume->setText(QString());
        label->setText(QApplication::translate("AvControlWidget", "00:00/00:00", Q_NULLPTR));
        btn_setting->setText(QString());
        btn_fullScreen->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AvControlWidget: public Ui_AvControlWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AVCONTROLWIDGET_H
