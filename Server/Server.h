#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>

class Server : public QTcpServer
{
    Q_OBJECT
private:
    QVector<QTcpSocket*> sockets;
    QByteArray data;
    QString IP;
    qint16 nextBlock;
public:
    Server();
    QTcpSocket* socket;
    //Listen(QString clientIP, QString clientPort); // start server
    void SendToClient(QString str); // send message to client
    //Disconnected(); // close server


public slots:
    void IncomingConnection(qintptr socketDescriptor); //processing connection
    void slotReadyRead(); //processing message from client

};

#endif // SERVER_H
