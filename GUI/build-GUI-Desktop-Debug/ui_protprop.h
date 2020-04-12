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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProtProp
{
public:
    QWidget *centralwidget;
    QPushButton *btn_loadDB;
    QPushButton *btn_run;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProtProp)
    {
        if (ProtProp->objectName().isEmpty())
            ProtProp->setObjectName(QString::fromUtf8("ProtProp"));
        ProtProp->resize(1336, 714);
        centralwidget = new QWidget(ProtProp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_loadDB = new QPushButton(centralwidget);
        btn_loadDB->setObjectName(QString::fromUtf8("btn_loadDB"));
        btn_loadDB->setGeometry(QRect(20, 10, 91, 22));
        btn_run = new QPushButton(centralwidget);
        btn_run->setObjectName(QString::fromUtf8("btn_run"));
        btn_run->setGeometry(QRect(1180, 620, 80, 22));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(1060, 60, 231, 23));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1080, 620, 80, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(679, 640, 141, 23));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(570, 640, 80, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(870, 60, 131, 16));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(1060, 100, 231, 23));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(870, 100, 161, 16));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(1060, 180, 231, 23));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(1060, 140, 231, 23));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(870, 180, 161, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(870, 140, 131, 16));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(870, 230, 225, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        lineEdit_6 = new QLineEdit(widget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        horizontalLayout->addWidget(lineEdit_6);

        ProtProp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProtProp);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1336, 20));
        ProtProp->setMenuBar(menubar);
        statusbar = new QStatusBar(ProtProp);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ProtProp->setStatusBar(statusbar);

        retranslateUi(ProtProp);

        QMetaObject::connectSlotsByName(ProtProp);
    } // setupUi

    void retranslateUi(QMainWindow *ProtProp)
    {
        ProtProp->setWindowTitle(QCoreApplication::translate("ProtProp", "ProtProp", nullptr));
        btn_loadDB->setText(QCoreApplication::translate("ProtProp", "Upload Data", nullptr));
        btn_run->setText(QCoreApplication::translate("ProtProp", "Run", nullptr));
        pushButton->setText(QCoreApplication::translate("ProtProp", "Stop", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ProtProp", "Save actual state ", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ProtProp", "Save Result", nullptr));
        label->setText(QCoreApplication::translate("ProtProp", "Nombre de mots ", nullptr));
        label_2->setText(QCoreApplication::translate("ProtProp", "Nombre maximum de chars ", nullptr));
        label_3->setText(QCoreApplication::translate("ProtProp", "Adresse IP", nullptr));
        label_4->setText(QCoreApplication::translate("ProtProp", "It\303\251rations", nullptr));
        label_6->setText(QCoreApplication::translate("ProtProp", "Caract\303\251ristique", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProtProp: public Ui_ProtProp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTPROP_H
