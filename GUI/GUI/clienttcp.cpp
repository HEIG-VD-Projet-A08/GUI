#include "clienttcp.h"


ClientTcp::ClientTcp(QObject *parent, QString ipAdd, int port) : parent(parent), add(ipAdd), port(port), message(){
    // partie client TCP
    socket = new QTcpSocket( parent );

    connect(socket, &QTcpSocket::readyRead, this, &ClientTcp::readyRead);
    connect(socket, &QTcpSocket::readyRead, this, &ClientTcp::readResultXML);

    socket->connectToHost(ipAdd, port);
}

ClientTcp::~ClientTcp(){
}

int ClientTcp::sendGreetings(){
    if(!socket->waitForConnected()){
        message->Error_4();
        return 1;
    }

    socket->write( "Hello Server\n" );
    return 0;
}

void ClientTcp::sendStop(){
    // if disconnect
    if(!socket->waitForConnected()){
        message->Error_4();
        return;
    }

    socket->write( "STOP\n" );
}

void ClientTcp::sendStopRecovery(){
    // if disconnect
    if(!socket->waitForConnected()){
        message->Error_4();
        return;
    }

    socket->write( "STOP -R\n" );
}

void ClientTcp::TerminConnexion(){
    // if disconnect
    if(!socket->waitForConnected()){
        message->Error_4();
        return;
    }

    socket->write( "BYE\n" );
    socket->disconnectFromHost();
    socket->close();
}

void ClientTcp::sendData(QFile &file){
    file.open(QIODevice::ReadOnly);
    QByteArray mydata=file.readAll();

    socket->write( "START\n" + mydata + "\n");
    file.close();
    socket->disconnectFromHost();
    while(!socket->waitForBytesWritten());
    socket->connectToHost(add, port);
}

void ClientTcp::readyRead()
{
    // if disconnect
    if(!socket->waitForConnected()){
        message->Error_6();
        return;
    }

    // read the data from the socket
    QByteArray temp = socket->readAll();

    QDir dir;
    QString path(dir.currentPath());
    QFile file(path + "/tmp.xml");

    // partie client TCP
    file.open(QIODevice::WriteOnly);
    file.write(temp);
    file.close();
}
