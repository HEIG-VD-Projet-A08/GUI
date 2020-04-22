#include "clienttcp.h"
#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QtCore>
#include <QtNetwork>
#include <iostream>


ClientTcp::ClientTcp(QObject *parent, QString ipAdd, int port) : parent(parent){
    // partie client TCP
    socket = new QTcpSocket( parent );
    connect(socket, &QTcpSocket::readyRead,this, &ClientTcp::readyRead);

    qDebug() << "connecting...";

    // this is not blocking call
    socket->connectToHost(ipAdd, port);

    // we need to wait...
    if(!socket->waitForConnected(5000))
    {
        qDebug() << "Error: " << socket->errorString();
    }else{
         socket->write( "Hello Server\n" );
    }
}

ClientTcp::~ClientTcp(){
    socket->close();
}

void ClientTcp::sendGreetings(){

}

void ClientTcp::sendData(QFile file){
    file.open(QIODevice::ReadOnly);
    QByteArray mydata=file.readAll();
}

void ClientTcp::readyRead()
{
    qDebug() << "reading...";

    // we need to wait...
    if(!socket->waitForConnected(5000)){
        qDebug() << "Error: " << socket->errorString();
    }

    // read the data from the socket
    QByteArray temp = socket->readAll();
    socket->write(temp);
}
