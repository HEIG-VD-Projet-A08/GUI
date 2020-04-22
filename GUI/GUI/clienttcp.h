
#ifndef CLIENTTCP_H
#define CLIENTTCP_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QtCore>
#include <QtNetwork>

class ClientTcp : public QObject
{
private:
    QObject *parent;
    QTcpSocket *socket;
    QString add;
    int port;
public:
    ClientTcp(QObject *parent, QString ipAdd, int port);
    ~ClientTcp();

    void sendGreetings();
    void sendData(QFile &file);

signals:

public slots:
    void readyRead();
    void sendData1(QFile &file);
};

#endif // CLIENTTCP_H
