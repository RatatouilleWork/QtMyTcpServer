#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QMessageBox>
#include "operationserialport.h"
#include "theodo.h"


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


    bool m_isTheodoRespond = 0;
    QByteArray m_recvData;
    QByteArray m_theodoRespond;
    QList<QByteArray> m_respond;
    QList<QByteArray> m_respondHeader;
    QList<QByteArray> m_respondData;
    QString m_cmdName;

    QTcpSocket* dtuSocket;
    Theodo* Ts60;


signals:
    void feedbackFromTheodolite();

private:
    void SendToSerialPort(QString content);
    inline void edtShow(QString info);

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
    void on_btnStartPowerSearch_clicked();
    void on_btnTestSignal_clicked();
    void slot_GetCmd(QString cmd);
    void parseFeedbackFromTheodolite();
};

#endif // MYTCPSERVER_H
