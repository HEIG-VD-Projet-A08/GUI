
#ifndef CLIENTTCP_H
#define CLIENTTCP_H

#include <QtCore>
#include <QtNetwork>
#include<QTcpSocket>
#include<QFile>

class ClientTcp
{
private:
    QObject *parent;
public:
    ClientTcp(QObject *parent);
    ~ClientTcp();

    void sendGreetings();
    void sendData(QFile file);
};

#endif // CLIENTTCP_H
