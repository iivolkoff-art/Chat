#include "Client.h"
#include <qDebug>
#include <iostream>

Client::Client(QObject *parent) : QObject(parent)
{
    qDebug() <<"connect is good";
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &Client::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    nextBlock = 0;
    qDebug() <<"connect is good";
}

//Client::Client(){
//    socket = new QTcpSocket(this);
//    connect(socket, &QTcpSocket::readyRead, this, &Client::slotReadyRead);
//    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
//    connectedToServer();
//}

void Client::connectedToServer(){
    socket->connectToHost("127.0.0.1", 2323);
}


void Client::setMessage(QString message){
    this->message = message;
}

QString Client::getMessage(){
    return message;
}

void Client::slotReadyRead(){
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if(in.status() == QDataStream::Ok){
//        QString str;
//        in >> str;
//        setMessage(str);
//        qDebug() << "DataStream ok";
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
            //qDebug() << "DataStream ok";
            setMessage(str);
        }
    }
    else{
        qDebug() << "DataStream error";
    }

}

void Client::sendToServer(QString str){
    data.clear();
    qDebug() << "отправляем";
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << qint16(0) << str;
    out.device()->seek(0);
    out << qint16(data.size() - sizeof(qint16));

    socket->write(data);
}
