/*
 * \brief 'Static class' to send a Port Knocking request
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 1 July 2019
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2019 Quentin Comte-Gaz
 * \version 1.0
 */

#include "QPortKnocking.h"

QPortKnocking::QPortKnocking()
{
}

bool QPortKnocking::knock(const QHostAddress& address, const quint16& port1, const quint16& port2, const quint16& port3, const quint16& port4, QString& error)
{
    bool ok = false;

    // Be sure the address is valid
    if (!address.isNull())
    {
        // Knock all 4 port
        bool isFirstPort = true;
        for (quint16 port : {port1, port2, port3, port4})
        {
            // Wait 300 ms between every port to knock
            if (isFirstPort)
            {
                isFirstPort = false;
            }
            else
            {
                QEventLoop loop;
                QTimer timer;
                timer.setSingleShot(true);
                QObject::connect(&timer, SIGNAL(timeout()),
                                 &loop, SLOT(quit()), Qt::DirectConnection);
                timer.start(300);
                loop.exec(QEventLoop::AllEvents);
            }

            // Port knock the port
            QTcpSocket socket;
            socket.connectToHost(address, port);
        }

        ok = true;
    }
    else
    {
        error = QObject::tr("Invalid host address");
    }

    return ok;
}
