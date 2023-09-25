#include "Server.h"
#include <qDebug>


Server::Server()
{
    if(this->listen(QHostAddress::Any, 2323)){ // first argument is any Ip client addres, second - our port
        qDebug() << "Cool";
    }
    else{
        qDebug() << "Bad";
    }
    nextBlock = 0;
}

void Server::IncomingConnection(qintptr socketDescriptor){
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    sockets.push_back(socket);
    qDebug() << "client is connected " << socketDescriptor;
}

void Server::slotReadyRead(){
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if(in.status() == QDataStream::Ok){
         qDebug() << "read...";
        // QString str;
        // in >> str;
        // qDebug() << str;
        // SendToClient(str);
        for(;;){
            if(nextBlock == 0){
                if(socket->bytesAvailable() < 2){
                    break;
                }
                in >> nextBlock;
            }
            if(socket->bytesAvailable() < nextBlock){
                break;
            }
            QString str;
            in >> str;
            nextBlock = 0;
            qDebug() << str;
            SendToClient(str);
            break;
        }
    }
    else{
        qDebug() << "DataStream error";
    }
}

void Server::SendToClient(QString str){
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << qint16(0) << str;
    out.device()->seek(0);
    out << qint16(data.size() - sizeof(qint16));
    //out << str;
    //socket->write(data);
    for(int i = 0; i < sockets.size(); i++){
        sockets[i]->write(data);
    }
}
