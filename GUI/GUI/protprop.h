#ifndef PROTPROP_H
#define PROTPROP_H

#include <QMainWindow>
#include <QFileDialog>
#include <QtCore>
#include <QtNetwork>
<<<<<<< HEAD
#include<QTcpSocket>
=======
#include <QTcpSocket>
>>>>>>> master
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
    void getValuesFromServer(QVector<double> contX, QVector<double> contY);

private slots:
    void on_btn_run_clicked();
    void on_btn_stop_clicked();
    void on_btn_save_actual_clicked();
    void on_btn_save_res_clicked();
    void on_plot_clicked();
<<<<<<< HEAD
    void ReadXMLFile(QString &it, QString &score, QString &newValue);
    void getValuesFromServer(double &x, double &y1, double &y2);
    void updateGraphe();

    void on_pushButton_clicked();
=======
    void ReadXMLFile(QString &it, QString &score);
    void getValuesFromServer(double &x, double &y);
    void updateGraphe();
>>>>>>> master

private:
    Ui::ProtProp *ui;
    QString nbWords;
    QString nbCharsMax;
    QString nbCharsMin;
    QString nbIter;
    QString ip;
    QString port;
    ClientTcp *socket;

    QVector<double> contX, contY1, contY2;
    QString caract;

};
#endif // PROTPROP_H
