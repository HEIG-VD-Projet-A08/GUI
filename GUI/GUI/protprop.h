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

private slots:
    void on_btn_run_clicked();

private:
    Ui::ProtProp *ui;
    QString nbWords;
    QString nbChars;
    QString nbIter;
    QString ip;
    QString caract;
};
#endif // PROTPROP_H
