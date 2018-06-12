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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainuiClass
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *mainuiClass)
    {
        if (mainuiClass->objectName().isEmpty())
            mainuiClass->setObjectName(QStringLiteral("mainuiClass"));
        mainuiClass->resize(600, 400);
        verticalLayout = new QVBoxLayout(mainuiClass);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(mainuiClass);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        retranslateUi(mainuiClass);

        QMetaObject::connectSlotsByName(mainuiClass);
    } // setupUi

    void retranslateUi(QWidget *mainuiClass)
    {
        mainuiClass->setWindowTitle(QApplication::translate("mainuiClass", "mainui", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mainuiClass: public Ui_mainuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINUI_H
