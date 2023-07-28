#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QObject>

class Client : public QObject
{
    Q_OBJECT
private:
    QString message;
public:
    explicit Client(QObject *parent = nullptr);

    Q_INVOKABLE void setMessage(QString message);
    Q_INVOKABLE QString getMessage();
};

#endif // CLIENT_H
