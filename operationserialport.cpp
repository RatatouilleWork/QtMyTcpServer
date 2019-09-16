#include "operationserialport.h"

OperationSerialPort::OperationSerialPort(QObject *parent) : QObject(parent)
{

}

int OperationSerialPort::parseReturnCode(QByteArray& returnString, QList<QByteArray>& returnHeader, QList<QByteArray>& returnData)
{
    if(returnString.isEmpty())
    {
        qDebug()<<"empty string";
        return -1;
    }
    QList<QByteArray> respond = returnString.split(':');
    returnHeader = respond[0].split(',');
    returnData = respond[1].split(',');

    int ret = returnData[0].toInt();

    return ret;
}

int OperationSerialPort::calcCoordination(const double radium, const double angleH, const double angleV, double& x, double& y, double& z)
{
    double r = radium * cos(angleV);
    x = r * cos(angleH);
    y = r * sin(angleH);
    z = r * sin(angleV);

    return 0;
}
