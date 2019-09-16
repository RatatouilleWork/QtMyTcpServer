/********************************************************************************
** Form generated from reading UI file 'mytcpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTCPSERVER_H
#define UI_MYTCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyTcpServer
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *edtRecv;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *edtIP;
    QLabel *label_2;
    QLineEdit *edtPort;
    QPushButton *btnConnect;
    QHBoxLayout *horizontalLayout;
    QCheckBox *ckbHexShow;
    QPushButton *btnClear;
    QComboBox *cbxConnection;
    QCheckBox *ckbHexSend;
    QPushButton *btnSetUserLockState;
    QPushButton *btnSearchPrism;
    QPushButton *btnSetAutoMode;
    QPushButton *btnFineAdjust;
    QPushButton *btnMesaDistanceAngle;
    QPushButton *btnAutoLockIn;
    QPushButton *btnStartPowerSearch;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *edtSend;
    QPushButton *btnSend;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyTcpServer)
    {
        if (MyTcpServer->objectName().isEmpty())
            MyTcpServer->setObjectName(QString::fromUtf8("MyTcpServer"));
        MyTcpServer->resize(789, 727);
        centralWidget = new QWidget(MyTcpServer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        edtRecv = new QTextEdit(groupBox);
        edtRecv->setObjectName(QString::fromUtf8("edtRecv"));
        edtRecv->setMinimumSize(QSize(400, 250));
        edtRecv->setReadOnly(true);

        horizontalLayout_2->addWidget(edtRecv);


        horizontalLayout_4->addWidget(groupBox);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        edtIP = new QLineEdit(groupBox_3);
        edtIP->setObjectName(QString::fromUtf8("edtIP"));

        verticalLayout->addWidget(edtIP);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        edtPort = new QLineEdit(groupBox_3);
        edtPort->setObjectName(QString::fromUtf8("edtPort"));

        verticalLayout->addWidget(edtPort);

        btnConnect = new QPushButton(groupBox_3);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));

        verticalLayout->addWidget(btnConnect);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ckbHexShow = new QCheckBox(groupBox_3);
        ckbHexShow->setObjectName(QString::fromUtf8("ckbHexShow"));

        horizontalLayout->addWidget(ckbHexShow);

        btnClear = new QPushButton(groupBox_3);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));

        horizontalLayout->addWidget(btnClear);


        verticalLayout->addLayout(horizontalLayout);

        cbxConnection = new QComboBox(groupBox_3);
        cbxConnection->addItem(QString());
        cbxConnection->setObjectName(QString::fromUtf8("cbxConnection"));

        verticalLayout->addWidget(cbxConnection);

        ckbHexSend = new QCheckBox(groupBox_3);
        ckbHexSend->setObjectName(QString::fromUtf8("ckbHexSend"));

        verticalLayout->addWidget(ckbHexSend);

        btnSetUserLockState = new QPushButton(groupBox_3);
        btnSetUserLockState->setObjectName(QString::fromUtf8("btnSetUserLockState"));

        verticalLayout->addWidget(btnSetUserLockState);

        btnSearchPrism = new QPushButton(groupBox_3);
        btnSearchPrism->setObjectName(QString::fromUtf8("btnSearchPrism"));

        verticalLayout->addWidget(btnSearchPrism);

        btnSetAutoMode = new QPushButton(groupBox_3);
        btnSetAutoMode->setObjectName(QString::fromUtf8("btnSetAutoMode"));

        verticalLayout->addWidget(btnSetAutoMode);

        btnFineAdjust = new QPushButton(groupBox_3);
        btnFineAdjust->setObjectName(QString::fromUtf8("btnFineAdjust"));

        verticalLayout->addWidget(btnFineAdjust);

        btnMesaDistanceAngle = new QPushButton(groupBox_3);
        btnMesaDistanceAngle->setObjectName(QString::fromUtf8("btnMesaDistanceAngle"));

        verticalLayout->addWidget(btnMesaDistanceAngle);

        btnAutoLockIn = new QPushButton(groupBox_3);
        btnAutoLockIn->setObjectName(QString::fromUtf8("btnAutoLockIn"));

        verticalLayout->addWidget(btnAutoLockIn);

        btnStartPowerSearch = new QPushButton(groupBox_3);
        btnStartPowerSearch->setObjectName(QString::fromUtf8("btnStartPowerSearch"));

        verticalLayout->addWidget(btnStartPowerSearch);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_4->addWidget(groupBox_3);


        verticalLayout_4->addLayout(horizontalLayout_4);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(610, 110));
        groupBox_2->setMaximumSize(QSize(16777215, 110));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        edtSend = new QTextEdit(groupBox_2);
        edtSend->setObjectName(QString::fromUtf8("edtSend"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(edtSend->sizePolicy().hasHeightForWidth());
        edtSend->setSizePolicy(sizePolicy1);
        edtSend->setMinimumSize(QSize(500, 75));
        edtSend->setMaximumSize(QSize(16777215, 75));

        horizontalLayout_3->addWidget(edtSend);

        btnSend = new QPushButton(groupBox_2);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnSend->sizePolicy().hasHeightForWidth());
        btnSend->setSizePolicy(sizePolicy2);
        btnSend->setMinimumSize(QSize(75, 75));
        btnSend->setMaximumSize(QSize(75, 75));

        horizontalLayout_3->addWidget(btnSend);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addWidget(groupBox_2);

        MyTcpServer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyTcpServer);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 789, 22));
        MyTcpServer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyTcpServer);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MyTcpServer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyTcpServer);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MyTcpServer->setStatusBar(statusBar);

        retranslateUi(MyTcpServer);

        QMetaObject::connectSlotsByName(MyTcpServer);
    } // setupUi

    void retranslateUi(QMainWindow *MyTcpServer)
    {
        MyTcpServer->setWindowTitle(QCoreApplication::translate("MyTcpServer", "MyTcpServer", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MyTcpServer", "\346\216\245\346\224\266\347\252\227\345\217\243", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MyTcpServer", "\347\275\221\347\273\234\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("MyTcpServer", "1\357\274\211\346\234\254\346\234\272IP\345\234\260\345\235\200", nullptr));
        edtIP->setText(QString());
        label_2->setText(QCoreApplication::translate("MyTcpServer", "2\357\274\211\346\234\254\345\234\260\347\253\257\345\217\243\345\217\267", nullptr));
        edtPort->setText(QCoreApplication::translate("MyTcpServer", "8000", nullptr));
        btnConnect->setText(QCoreApplication::translate("MyTcpServer", "\347\233\221\345\220\254", nullptr));
        ckbHexShow->setText(QCoreApplication::translate("MyTcpServer", "Hex\346\230\276\347\244\272", nullptr));
        btnClear->setText(QCoreApplication::translate("MyTcpServer", "\346\270\205\351\231\244\347\252\227\345\217\243", nullptr));
        cbxConnection->setItemText(0, QCoreApplication::translate("MyTcpServer", "\345\205\250\351\203\250\350\277\236\346\216\245", nullptr));

        ckbHexSend->setText(QCoreApplication::translate("MyTcpServer", "Hex\345\217\221\351\200\201", nullptr));
        btnSetUserLockState->setText(QCoreApplication::translate("MyTcpServer", "\351\224\201\345\256\232", nullptr));
        btnSearchPrism->setText(QCoreApplication::translate("MyTcpServer", "\346\220\234\347\264\242\346\243\261\351\225\234", nullptr));
        btnSetAutoMode->setText(QCoreApplication::translate("MyTcpServer", "\350\207\252\345\212\250\347\205\247\345\207\206", nullptr));
        btnFineAdjust->setText(QCoreApplication::translate("MyTcpServer", "\344\270\255\345\277\203\345\256\232\344\275\215", nullptr));
        btnMesaDistanceAngle->setText(QCoreApplication::translate("MyTcpServer", "\346\265\213\351\207\217\350\247\222\345\272\246", nullptr));
        btnAutoLockIn->setText(QCoreApplication::translate("MyTcpServer", "\350\267\237\350\270\252", nullptr));
        btnStartPowerSearch->setText(QCoreApplication::translate("MyTcpServer", "\350\266\205\347\272\247\346\220\234\347\264\242", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MyTcpServer", "\345\217\221\351\200\201\347\252\227\345\217\243", nullptr));
        btnSend->setText(QCoreApplication::translate("MyTcpServer", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyTcpServer: public Ui_MyTcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTCPSERVER_H
