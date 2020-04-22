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
    this->add = ipAdd;
    this->port = port;
    qDebug() << "connecting...";

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
        socket->flush();
    }
}

void ClientTcp::sendData(QFile &file){
    file.open(QIODevice::ReadOnly);
    QByteArray mydata=file.readAll();

    socket->write( "START\n" );
    socket->write( mydata );
    socket->write( "\n" );
    socket->flush();
    file.close();
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
    // écriture du fichier XML dans le dossier de l'application
    QDir dir;
    QString path(dir.currentPath());
    QFile file(path + "/option.xml");

    // partie client TCP
    file.open(QIODevice::WriteOnly);
    file.write(temp);
    file.close();
}
