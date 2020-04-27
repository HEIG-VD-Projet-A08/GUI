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

    connect(socket, &QTcpSocket::readyRead, this, &ClientTcp::readyRead);
    connect(socket, &QTcpSocket::readyRead, this, &ClientTcp::readResultXML);

    this->add = ipAdd;
    this->port = port;

    socket->connectToHost(ipAdd, port);
}

ClientTcp::~ClientTcp(){
    socket->close();
}

void ClientTcp::sendGreetings(){
    if(!socket->waitForConnected()){
        qDebug() << "Error: " << socket->errorString();
    }else{
         socket->write( "Hello Server\n" );
    }
}

void ClientTcp::sendStop(){
    // if disconnect
    if(!socket->waitForConnected(1000)){
        qDebug() << "Error: " << socket->errorString();
        return;
    }

    socket->write( "STOP\n" );
}

void ClientTcp::sendStopRecovery(){
    // if disconnect
    if(!socket->waitForConnected(1000)){
        qDebug() << "Error: " << socket->errorString();
        return;
    }

    socket->write( "STOP -R\n" );
}

void ClientTcp::TerminConnexion(){
    // if disconnect
    if(!socket->waitForConnected(1000)){
        qDebug() << "Error: " << socket->errorString();
        return;
    }

    socket->write( "BYE" );
    socket->disconnectFromHost();
    socket->close();
}

void ClientTcp::sendData(QFile &file){
    file.open(QIODevice::ReadOnly);
    QByteArray mydata=file.readAll();

    socket->write( "START\n" );
    socket->write( mydata );
    file.close();
    socket->disconnectFromHost();
    while(!socket->waitForBytesWritten());
    socket->connectToHost(add, port);
}

void ClientTcp::readyRead()
{
    // if disconnect
    if(!socket->waitForConnected(1000)){
        qDebug() << "Error: " << socket->errorString();
        return;
    }

    // read the data from the socket
    QByteArray temp = socket->readAll();
    qDebug() << temp;

    QDir dir;
    QString path(dir.currentPath());
    QFile file(path + "/tmp.xml");

    // partie client TCP
    file.open(QIODevice::WriteOnly);
    file.write(temp);
    file.close();
}
