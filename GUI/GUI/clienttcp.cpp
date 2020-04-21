#include "clienttcp.h"

ClientTcp::ClientTcp(QObject *parent) : parent(parent){
    // partie client TCP
    QTcpSocket *socket;
    socket = new QTcpSocket( parent );
}

ClientTcp::~ClientTcp(){

}

void ClientTcp::sendGreetings(){

}

void ClientTcp::sendData(QFile file){
    file.open(QIODevice::ReadOnly);
    QByteArray mydata=file.readAll();
}
