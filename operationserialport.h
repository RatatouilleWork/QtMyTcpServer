#ifndef OPERATIONSERIALPORT_H
#define OPERATIONSERIALPORT_H

#include <QObject>

class OperationSerialPort : public QObject
{
    Q_OBJECT
public:
    explicit OperationSerialPort(QObject *parent = nullptr);

signals:

public slots:
};

#endif // OPERATIONSERIALPORT_H
