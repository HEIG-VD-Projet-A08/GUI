/********************************************************************************
** Form generated from reading UI file 'protprop.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTPROP_H
#define UI_PROTPROP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_ProtProp
{
public:
    QWidget *centralwidget;
    QCustomPlot *widget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *plot;
    QPushButton *btn_save_res;
    QPushButton *btn_save_actual;
    QPushButton *btn_stop;
    QPushButton *btn_run;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *nbWords;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *CharMax;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *iterations;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *IP;
    QFormLayout *formLayout;
    QLabel *label_6;
    QComboBox *menu_list;
    QMenuBar *menubar;
    QMenu *menuTest;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProtProp)
    {
        if (ProtProp->objectName().isEmpty())
            ProtProp->setObjectName(QString::fromUtf8("ProtProp"));
        ProtProp->resize(1309, 715);
        centralwidget = new QWidget(ProtProp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 50, 1271, 571));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(490, 640, 767, 25));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        plot = new QPushButton(layoutWidget);
        plot->setObjectName(QString::fromUtf8("plot"));

        horizontalLayout_6->addWidget(plot);

        btn_save_res = new QPushButton(layoutWidget);
        btn_save_res->setObjectName(QString::fromUtf8("btn_save_res"));

        horizontalLayout_6->addWidget(btn_save_res);

        btn_save_actual = new QPushButton(layoutWidget);
        btn_save_actual->setObjectName(QString::fromUtf8("btn_save_actual"));

        horizontalLayout_6->addWidget(btn_save_actual);

        btn_stop = new QPushButton(layoutWidget);
        btn_stop->setObjectName(QString::fromUtf8("btn_stop"));

        horizontalLayout_6->addWidget(btn_stop);

        btn_run = new QPushButton(layoutWidget);
        btn_run->setObjectName(QString::fromUtf8("btn_run"));

        horizontalLayout_6->addWidget(btn_run);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 1269, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        nbWords = new QLineEdit(layoutWidget1);
        nbWords->setObjectName(QString::fromUtf8("nbWords"));

        horizontalLayout_5->addWidget(nbWords);


        horizontalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        CharMax = new QLineEdit(layoutWidget1);
        CharMax->setObjectName(QString::fromUtf8("CharMax"));

        horizontalLayout_4->addWidget(CharMax);


        horizontalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        iterations = new QLineEdit(layoutWidget1);
        iterations->setObjectName(QString::fromUtf8("iterations"));

        horizontalLayout_3->addWidget(iterations);


        horizontalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        IP = new QLineEdit(layoutWidget1);
        IP->setObjectName(QString::fromUtf8("IP"));

        horizontalLayout_2->addWidget(IP);


        horizontalLayout->addLayout(horizontalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        menu_list = new QComboBox(layoutWidget1);
        menu_list->setObjectName(QString::fromUtf8("menu_list"));

        formLayout->setWidget(0, QFormLayout::FieldRole, menu_list);


        horizontalLayout->addLayout(formLayout);

        ProtProp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProtProp);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1309, 20));
        menuTest = new QMenu(menubar);
        menuTest->setObjectName(QString::fromUtf8("menuTest"));
        ProtProp->setMenuBar(menubar);
        statusbar = new QStatusBar(ProtProp);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ProtProp->setStatusBar(statusbar);

        menubar->addAction(menuTest->menuAction());

        retranslateUi(ProtProp);

        QMetaObject::connectSlotsByName(ProtProp);
    } // setupUi

    void retranslateUi(QMainWindow *ProtProp)
    {
        ProtProp->setWindowTitle(QCoreApplication::translate("ProtProp", "ProtProp", nullptr));
        plot->setText(QCoreApplication::translate("ProtProp", "M\303\240j graphique", nullptr));
        btn_save_res->setText(QCoreApplication::translate("ProtProp", "sauvegarde des r\303\251sultats", nullptr));
        btn_save_actual->setText(QCoreApplication::translate("ProtProp", "sauvegarde de l'\303\251tat actuel", nullptr));
        btn_stop->setText(QCoreApplication::translate("ProtProp", "Stop", nullptr));
        btn_run->setText(QCoreApplication::translate("ProtProp", "Run", nullptr));
        label->setText(QCoreApplication::translate("ProtProp", "Nombre de mots ", nullptr));
        label_2->setText(QCoreApplication::translate("ProtProp", "Nombre maximum de chars ", nullptr));
        label_4->setText(QCoreApplication::translate("ProtProp", "It\303\251rations", nullptr));
        label_3->setText(QCoreApplication::translate("ProtProp", "Adresse IP", nullptr));
        label_6->setText(QCoreApplication::translate("ProtProp", "Caract\303\251ristique", nullptr));
        menuTest->setTitle(QCoreApplication::translate("ProtProp", "Test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProtProp: public Ui_ProtProp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTPROP_H
