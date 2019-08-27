#include "mytcpserver.h"
#include "ui_mytcpserver.h"

MyTcpServer::MyTcpServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyTcpServer)
{
    ui->setupUi(this);

    tcpServer = new QTcpServer(this);
    //获取本地IP:
    //ui->edtIP->setText(QNetworkInterface().allAddresses().at(1).toString());
    ui->edtIP->setText(QString("192.168.1.46"));
    //设置按键：
    ui->btnConnect->setEnabled(true);
    ui->btnSend->setEnabled(false);
    //首先将操作部分按钮设为非使能状态：
    ui->btnSetUserLockState->setEnabled(false);
    ui->btnSearchPrism->setEnabled(false);
    ui->btnSetAutoMode->setEnabled(false);
    ui->btnFineAdjust->setEnabled(false);
    ui->btnMesaDistanceAngle->setEnabled(false);
    ui->btnAutoLockIn->setEnabled(false);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(NewConnectionSlot()));
}

MyTcpServer::~MyTcpServer()
{
    delete ui;
}

// newConnection -> newConnectionSlot 新连接建立的槽函数
void MyTcpServer::NewConnectionSlot()
{
    currentClient = tcpServer->nextPendingConnection();
    tcpClient.append(currentClient);

    //DTU已连接，使能操作按钮：
    ui->btnSetUserLockState->setEnabled(true);
    ui->btnSearchPrism->setEnabled(true);
    ui->btnSetAutoMode->setEnabled(true);
    ui->btnFineAdjust->setEnabled(true);
    ui->btnMesaDistanceAngle->setEnabled(true);
    ui->btnAutoLockIn->setEnabled(true);

    ui->cbxConnection->addItem(tr("%1:%2").arg(currentClient->peerAddress().toString().split("::ffff:")[1])\
                                          .arg(currentClient->peerPort()));
    connect(currentClient, SIGNAL(readyRead()), this, SLOT(ReadData()));
    connect(currentClient, SIGNAL(disconnected()), this, SLOT(disconnectedSlot()));
}

// 客户端数据可读信号，对应的读数据槽函数
void MyTcpServer::ReadData()
{
    // 由于readyRead信号并未提供SocketDecriptor，所以需要遍历所有客户端
    for(int i=0; i<tcpClient.length(); i++)
    {
        QByteArray buffer = tcpClient[i]->readAll();
        if(buffer.isEmpty())    continue;

        static QString IP_Port, IP_Port_Pre;
        qDebug()<< tcpClient[i]->peerAddress().toString();
        IP_Port = tr("[%1:%2]:").arg(tcpClient[i]->peerAddress().toString().split("::ffff:")[1])\
                                     .arg(tcpClient[i]->peerPort());

        // 若此次消息的地址与上次不同，则需显示此次消息的客户端地址
        if(IP_Port != IP_Port_Pre)
            ui->edtRecv->append(IP_Port);

        ui->edtRecv->append(buffer);

        //更新ip_port
        IP_Port_Pre = IP_Port;
    }
}
// disconnected -> disconnectedSlot 客户端断开连接的槽函数
void MyTcpServer::disconnectedSlot()
{
    //由于disconnected信号并未提供SocketDescriptor，所以需要遍历寻找
    for(int i=0; i<tcpClient.length(); i++)
    {
        if(tcpClient[i]->state() == QAbstractSocket::UnconnectedState)
        {
            // 删除存储在combox中的客户端信息
            ui->cbxConnection->removeItem(ui->cbxConnection->findText(tr("%1:%2")\
                                  .arg(tcpClient[i]->peerAddress().toString().split("::ffff:")[1])\
                                  .arg(tcpClient[i]->peerPort())));
            // 删除存储在tcpClient列表中的客户端信息
             tcpClient[i]->destroyed();
             tcpClient.removeAt(i);
        }
    }
}
// 监听--断开
void MyTcpServer::on_btnConnect_clicked()
{
    if(ui->btnConnect->text()=="监听")
    {
        bool ok = tcpServer->listen(QHostAddress::Any, ui->edtPort->text().toUShort());
        if(ok)
        {
            ui->btnConnect->setText("断开");
            ui->btnSend->setEnabled(true);
        }
    }
    else
    {
        for(int i=0; i<tcpClient.length(); i++)//断开所有连接
        {
            tcpClient[i]->disconnectFromHost();
            bool ok = tcpClient[i]->waitForDisconnected(1000);
            if(!ok)
            {
                // 处理异常
                QMessageBox::critical(this, "Error", "Failed Disconnect");
            }
            tcpClient.removeAt(i);  //从保存的客户端列表中取去除
        }
        tcpServer->close();     //不再监听端口
        ui->btnConnect->setText("监听");
        ui->btnSend->setEnabled(false);
    }
}
// 发送数据
void MyTcpServer::on_btnSend_clicked()
{
    QString data = ui->edtSend->toPlainText();
    if(data == "")  return;    // 文本输入框为空时
    //全部连接
    if(ui->cbxConnection->currentIndex() == 0)
    {
        qDebug()<<"全部连接已选择";
        for(int i=0; i<tcpClient.length(); i++)
            tcpClient[i]->write(data.toLatin1()); //qt5除去了.toAscii()
    }
    //指定连接
    else
    {
        qDebug()<<"指定连接已选择";
        QString clientIP = ui->cbxConnection->currentText().split(":")[0];
        int clientPort = ui->cbxConnection->currentText().split(":")[1].toInt();
        qDebug() << clientIP;
        qDebug() << clientPort;

        for(int i=0; i<tcpClient.length(); i++)
        {
            if(tcpClient[i]->peerAddress().toString().split("::ffff:")[1]==clientIP\
                            && tcpClient[i]->peerPort()==clientPort)
            {
                tcpClient[i]->write(data.toLatin1());
                return; //ip:port唯一，无需继续检索
            }
        }
    }
}

void MyTcpServer::on_btnClear_clicked()
{
    ui->edtRecv->clear();

}void MyTcpServer::on_Lock_clicked()
{

}

void MyTcpServer::SendToSerialPort(QString content)
{
    QByteArray baContent = content.toLatin1();

    //全部连接
    if(ui->cbxConnection->currentIndex() == 0)
    {
        //qDebug()<<"全部连接已选择";
        for(int i=0; i<tcpClient.length(); i++)
            tcpClient[i]->write(baContent.data());
    }
    //指定连接
    else
    {
        //qDebug()<<"指定连接已选择";
        QString clientIP = ui->cbxConnection->currentText().split(":")[0];
        int clientPort = ui->cbxConnection->currentText().split(":")[1].toInt();
        //qDebug() << clientIP;
        //qDebug() << clientPort;

        for(int i=0; i<tcpClient.length(); i++)
        {
            if(tcpClient[i]->peerAddress().toString().split("::ffff:")[1]==clientIP\
                            && tcpClient[i]->peerPort()==clientPort)
            {
                tcpClient[i]->write(baContent.data());
                return;
            }
        }
    }

}

void MyTcpServer::on_btnSetUserLockState_clicked()
{
    QString Cmd = "\r\n%R1Q,18007:1\r\n";
    SendToSerialPort(Cmd);
    return;
}

void MyTcpServer::on_btnSearchPrism_clicked()
{
    QString Cmd = "\r\n%R1Q,9020:2,2,0\r\n";
    SendToSerialPort(Cmd);
    return;
}

void MyTcpServer::on_btnSetAutoMode_clicked()
{
    QString Cmd = "\r\n%R1Q,18005:1\r\n";
    SendToSerialPort(Cmd);
    return;

}

void MyTcpServer::on_btnFineAdjust_clicked()
{
    QString Cmd = "\r\n%R1Q,9037:0.5,0.5,0\r\n";
    SendToSerialPort(Cmd);
    return;

}

void MyTcpServer::on_btnMesaDistanceAngle_clicked()
{

    QString Cmd = "\r\n%R1Q,17017:1\r\n";
    SendToSerialPort(Cmd);
    return;
}

void MyTcpServer::on_btnAutoLockIn_clicked()
{

    QString Cmd = "\r\n%R1Q,9013:\r\n";
    SendToSerialPort(Cmd);
    return;
}
