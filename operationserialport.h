#ifndef OPERATIONSERIALPORT_H
#define OPERATIONSERIALPORT_H


#include <QObject>
#include <QDebug>
#include <QByteArray>
#include <cmath>


class OperationSerialPort : public QObject
{
    Q_OBJECT
public:
    explicit OperationSerialPort(QObject *parent = nullptr);

signals:

public slots:

public:
    static int parseReturnCode(QByteArray& returnString, QList<QByteArray>& returnHeader, QList<QByteArray>& returnData);
    static int calcCoordination(const double radium, const double angleH, const double angleV, double& x, double& y, double& z);
    static void SendToSerialPort(QString content);


};

#endif // OPERATIONSERIALPORT_H
