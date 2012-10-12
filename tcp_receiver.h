#ifndef TCP_RECEIVER_H
#define TCP_RECEIVER_H

#include <QtNetwork/QtNetwork>
#include <QDebug>

class tcp_receiver : public QObject
{
    Q_OBJECT
public:
    tcp_receiver();
private:
    QTcpServer tcp_server;
    QTcpSocket *tcp_server_connection;
    qint64 total_bytes;
    qint64 bytes_received;
    qint64 file_name_size;
    QString file_path;
    QFile *local_file;
    QByteArray in_block;
private slots:
    void accept_connection();
    void receive();
    void display_error(QAbstractSocket::SocketError socket_error);
public:
    void start();
};

#endif // TCP_RECEIVER_H
