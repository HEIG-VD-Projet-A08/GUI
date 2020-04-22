#ifndef PROTPROP_H
#define PROTPROP_H

#include <QMainWindow>
#include <QFileDialog>
#include <QtCore>
#include <QtNetwork>
#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include "clienttcp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ProtProp; }
QT_END_NAMESPACE

class ProtProp : public QMainWindow
{
    Q_OBJECT

public:
    ProtProp(QWidget *parent = nullptr);
    ~ProtProp();

private slots:
    void on_btn_run_clicked();
    void on_btn_stop_clicked();
    void on_btn_save_actual_clicked();
    void on_btn_save_res_clicked();
    void on_plot_clicked();
    void ReadXMLFile(QString &it, QString &score);
    void getValuesFromServer(double &x, double &y);

private:
    Ui::ProtProp *ui;
    QString nbWords;
    QString nbChars;
    QString nbIter;
    QString ip;
    QString port;
    ClientTcp *test;

    QVector<double> contX, contY, contXFromServ, contYFromServ, contNameProt;
    QString caract;

};
#endif // PROTPROP_H
