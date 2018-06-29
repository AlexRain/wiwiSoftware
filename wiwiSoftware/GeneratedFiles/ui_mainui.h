/********************************************************************************
** Form generated from reading UI file 'mainui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINUI_H
#define UI_MAINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainuiClass
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_request;

    void setupUi(QWidget *mainuiClass)
    {
        if (mainuiClass->objectName().isEmpty())
            mainuiClass->setObjectName(QStringLiteral("mainuiClass"));
        mainuiClass->resize(690, 457);
        verticalLayout = new QVBoxLayout(mainuiClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(mainuiClass);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);


        verticalLayout->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_request = new QPushButton(mainuiClass);
        pushButton_request->setObjectName(QStringLiteral("pushButton_request"));
        pushButton_request->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(pushButton_request);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(mainuiClass);

        QMetaObject::connectSlotsByName(mainuiClass);
    } // setupUi

    void retranslateUi(QWidget *mainuiClass)
    {
        mainuiClass->setWindowTitle(QApplication::translate("mainuiClass", "mainui", Q_NULLPTR));
        label->setText(QString());
        pushButton_request->setText(QApplication::translate("mainuiClass", "Request", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mainuiClass: public Ui_mainuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINUI_H
