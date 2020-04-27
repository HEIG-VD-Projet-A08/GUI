#ifndef PROTPROP_H
#define PROTPROP_H

#include <QMainWindow>
#include <QFileDialog>
#include <QtCore>
#include <QtNetwork>
#include<QTcpSocket>

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
    void ReadXMLFile(QString &it, QString &score);
    void getValuesFromServer(double &x, double &y);

private:
    Ui::ProtProp *ui;
    QString nbWords;
    QString nbChars;
    QString nbIter;
    QString ip;
    QString port;

    QVector<double> contNameProt, contX, contY, contXFromServ, contYFromServ;
    QString caract;

};
#endif // PROTPROP_H
