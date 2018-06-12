/********************************************************************************
** Form generated from reading UI file 'Cloginui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOGINUI_H
#define UI_CLOGINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cloginui
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_top;
    QHBoxLayout *horizontalLayout;
    QLabel *label_tilte;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_cloese;
    QWidget *widget_center;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_user;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_user;
    QLabel *label_user;
    QWidget *widget_pwd;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_pwd;
    QLabel *label_pwd;
    QWidget *widget_bottom;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_confirm;
    QLabel *label_forget;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Cloginui)
    {
        if (Cloginui->objectName().isEmpty())
            Cloginui->setObjectName(QStringLiteral("Cloginui"));
        Cloginui->resize(400, 300);
        Cloginui->setMinimumSize(QSize(400, 300));
        Cloginui->setMaximumSize(QSize(400, 300));
        verticalLayout = new QVBoxLayout(Cloginui);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_top = new QWidget(Cloginui);
        widget_top->setObjectName(QStringLiteral("widget_top"));
        widget_top->setMinimumSize(QSize(0, 63));
        widget_top->setMaximumSize(QSize(16777215, 63));
        horizontalLayout = new QHBoxLayout(widget_top);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(22, 0, 24, 0);
        label_tilte = new QLabel(widget_top);
        label_tilte->setObjectName(QStringLiteral("label_tilte"));

        horizontalLayout->addWidget(label_tilte);

        horizontalSpacer = new QSpacerItem(308, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_cloese = new QPushButton(widget_top);
        pushButton_cloese->setObjectName(QStringLiteral("pushButton_cloese"));
        pushButton_cloese->setMinimumSize(QSize(13, 13));
        pushButton_cloese->setMaximumSize(QSize(13, 13));
        pushButton_cloese->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_cloese->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButton_cloese);


        verticalLayout->addWidget(widget_top);

        widget_center = new QWidget(Cloginui);
        widget_center->setObjectName(QStringLiteral("widget_center"));
        verticalLayout_2 = new QVBoxLayout(widget_center);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(22, 23, 22, 34);
        widget_user = new QWidget(widget_center);
        widget_user->setObjectName(QStringLiteral("widget_user"));
        widget_user->setMinimumSize(QSize(358, 52));
        widget_user->setMaximumSize(QSize(358, 52));
        horizontalLayout_3 = new QHBoxLayout(widget_user);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(22, -1, 17, -1);
        lineEdit_user = new QLineEdit(widget_user);
        lineEdit_user->setObjectName(QStringLiteral("lineEdit_user"));

        horizontalLayout_3->addWidget(lineEdit_user);

        label_user = new QLabel(widget_user);
        label_user->setObjectName(QStringLiteral("label_user"));
        label_user->setMinimumSize(QSize(15, 17));
        label_user->setMaximumSize(QSize(15, 17));

        horizontalLayout_3->addWidget(label_user);


        verticalLayout_2->addWidget(widget_user);

        widget_pwd = new QWidget(widget_center);
        widget_pwd->setObjectName(QStringLiteral("widget_pwd"));
        widget_pwd->setMinimumSize(QSize(358, 52));
        widget_pwd->setMaximumSize(QSize(358, 52));
        horizontalLayout_4 = new QHBoxLayout(widget_pwd);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(22, -1, 17, -1);
        lineEdit_pwd = new QLineEdit(widget_pwd);
        lineEdit_pwd->setObjectName(QStringLiteral("lineEdit_pwd"));

        horizontalLayout_4->addWidget(lineEdit_pwd);

        label_pwd = new QLabel(widget_pwd);
        label_pwd->setObjectName(QStringLiteral("label_pwd"));
        label_pwd->setMinimumSize(QSize(15, 17));
        label_pwd->setMaximumSize(QSize(15, 17));

        horizontalLayout_4->addWidget(label_pwd);


        verticalLayout_2->addWidget(widget_pwd);

        widget_bottom = new QWidget(widget_center);
        widget_bottom->setObjectName(QStringLiteral("widget_bottom"));
        widget_bottom->setMinimumSize(QSize(0, 40));
        widget_bottom->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_2 = new QHBoxLayout(widget_bottom);
        horizontalLayout_2->setSpacing(30);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_confirm = new QPushButton(widget_bottom);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        pushButton_confirm->setMinimumSize(QSize(100, 40));
        pushButton_confirm->setMaximumSize(QSize(100, 40));
        pushButton_confirm->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(pushButton_confirm);

        label_forget = new QLabel(widget_bottom);
        label_forget->setObjectName(QStringLiteral("label_forget"));
        label_forget->setMinimumSize(QSize(125, 11));
        label_forget->setMaximumSize(QSize(125, 11));
        label_forget->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(label_forget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget_bottom);


        verticalLayout->addWidget(widget_center);


        retranslateUi(Cloginui);

        QMetaObject::connectSlotsByName(Cloginui);
    } // setupUi

    void retranslateUi(QWidget *Cloginui)
    {
        Cloginui->setWindowTitle(QApplication::translate("Cloginui", "Cloginui", Q_NULLPTR));
        label_tilte->setText(QApplication::translate("Cloginui", "Login", Q_NULLPTR));
        pushButton_cloese->setText(QString());
        lineEdit_user->setText(QString());
        lineEdit_user->setPlaceholderText(QApplication::translate("Cloginui", "Username", Q_NULLPTR));
        label_user->setText(QString());
        lineEdit_pwd->setText(QString());
        lineEdit_pwd->setPlaceholderText(QApplication::translate("Cloginui", "Password", Q_NULLPTR));
        label_pwd->setText(QString());
        pushButton_confirm->setText(QApplication::translate("Cloginui", "Sign In", Q_NULLPTR));
        label_forget->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Cloginui: public Ui_Cloginui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOGINUI_H
