#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
private:
    QString message;
    QTcpSocket* socket;
    QByteArray data;
    qint16 nextBlock;

public:
    explicit Client(QObject *parent = nullptr);
    //Client();

    Q_INVOKABLE void setMessage(QString message);
    Q_INVOKABLE QString getMessage();
    Q_INVOKABLE void sendToServer(QString str);


public slots:
    void slotReadyRead();

protected:
    void connectedToServer();


};

#endif // CLIENT_H
