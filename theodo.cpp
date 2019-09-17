#include "theodo.h"

Theodo::Theodo(QObject *parent) : QObject(parent)
{
    qDebug()<<"Theodolite constructed";

}

int Theodo::AUS_SetUserLockStat(_Switch onSwitch = Theodo::ON)
{
    m_Cmd.clear();

    if(Theodo::ON == onSwitch)
    {
        m_Cmd = "%R1Q,18007:1\r\n";
    }
    else
    {
        m_Cmd = "%R1Q,18007:0\r\n";
    }

    emit cmdSent(QString("Aus_SetUserLockStat"));


    return 0;
}
void Theodo::testSignalEmit()
{
    qDebug()<<__FILE__<<__LINE__<<"testSignalEmit";
    QString temp = QString("test emit string with signal, hahahahahahahahahah");
    qDebug()<<__FILE__<<__LINE__<<temp;
    emit cmdSent(temp);
}
