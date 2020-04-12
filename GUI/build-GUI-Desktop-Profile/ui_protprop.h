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

QT_BEGIN_NAMESPACE

class Ui_ProtProp
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_4;
    QWidget *widget;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *btn_run;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_loadDB;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QFormLayout *formLayout;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QMenuBar *menubar;
    QMenu *menuTest;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProtProp)
    {
        if (ProtProp->objectName().isEmpty())
            ProtProp->setObjectName(QString::fromUtf8("ProtProp"));
        ProtProp->resize(1336, 714);
        centralwidget = new QWidget(ProtProp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(1119, 50, 151, 23));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 50, 1271, 571));
        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(680, 640, 621, 25));
        horizontalLayout_6 = new QHBoxLayout(widget1);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(widget1);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_6->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(widget1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_6->addWidget(pushButton_2);

        pushButton = new QPushButton(widget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_6->addWidget(pushButton);

        btn_run = new QPushButton(widget1);
        btn_run->setObjectName(QString::fromUtf8("btn_run"));

        horizontalLayout_6->addWidget(btn_run);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(10, 10, 1269, 27));
        horizontalLayout = new QHBoxLayout(widget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_loadDB = new QPushButton(widget2);
        btn_loadDB->setObjectName(QString::fromUtf8("btn_loadDB"));

        horizontalLayout->addWidget(btn_loadDB);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(widget2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        lineEdit = new QLineEdit(widget2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_5->addWidget(lineEdit);


        horizontalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(widget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lineEdit_2 = new QLineEdit(widget2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_4->addWidget(lineEdit_2);


        horizontalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_4 = new QLineEdit(widget2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_3->addWidget(lineEdit_4);


        horizontalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_3 = new QLineEdit(widget2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_2->addWidget(lineEdit_3);


        horizontalLayout->addLayout(horizontalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_6 = new QLabel(widget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        lineEdit_6 = new QLineEdit(widget2);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_6);


        horizontalLayout->addLayout(formLayout);

        ProtProp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProtProp);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1336, 20));
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
        pushButton_4->setText(QCoreApplication::translate("ProtProp", "Load parameters", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ProtProp", "Save Result", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ProtProp", "Save actual state ", nullptr));
        pushButton->setText(QCoreApplication::translate("ProtProp", "Stop", nullptr));
        btn_run->setText(QCoreApplication::translate("ProtProp", "Run", nullptr));
        btn_loadDB->setText(QCoreApplication::translate("ProtProp", "Upload Data", nullptr));
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
