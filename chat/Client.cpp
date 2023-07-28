#include "Client.h"

Client::Client(QObject *parent) : QObject(parent)
{

}

void Client::setMessage(QString message){
    this->message = message;
}

QString Client::getMessage(){
    return message;
}
