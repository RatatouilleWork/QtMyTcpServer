#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QMessageBox>
namespace Ui {
class MyTcpServer;
}

class MyTcpServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyTcpServer(QWidget *parent = nullptr);
    ~MyTcpServer();

private:
    Ui::MyTcpServer *ui;
    QTcpServer *tcpServer;
    QList<QTcpSocket*> tcpClient;
    QTcpSocket *currentClient;

    QTcpSocket* dtuSocket;

private:
    void SendToSerialPort(QString content);

private slots:
    void NewConnectionSlot();
    void disconnectedSlot();
    void ReadData();

    void on_btnConnect_clicked();
    void on_btnSend_clicked();
    void on_btnClear_clicked();
    void on_Lock_clicked();
    void on_btnSetUserLockState_clicked();
    void on_btnSearchPrism_clicked();
    void on_btnSetAutoMode_clicked();
    void on_btnFineAdjust_clicked();
    void on_btnMesaDistanceAngle_clicked();
    void on_btnAutoLockIn_clicked();
};

#endif // MYTCPSERVER_H
