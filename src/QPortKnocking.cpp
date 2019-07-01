/*
 * \brief 'Static class' to send a Port Knocking request
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 1 July 2019
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2019 Quentin Comte-Gaz
 * \version 2.0
 */

#include "QPortKnocking.h"

QPortKnocking::QPortKnocking()
{
}

bool QPortKnocking::knock(const QHostAddress& address, const QList<quint16>& portSequence, QString& error)
{
    bool ok = false;

    // Be sure port sequence is valid
    if (portSequence.size() < 2)
    {
        error = QObject::tr("Not enough port to knock (at least 2 port must be specified)");
        return false;
    }

    // Be sure the address is valid
    if (!address.isNull())
    {
        // Knock all ports
        bool isFirstPort = true;
        for (const quint16& port : portSequence)
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
