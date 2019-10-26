/*
 * \brief Example on how to use the Port Knocking
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 1 July 2019
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2019 Quentin Comte-Gaz
 * \version 2.0
 */

#include <QCoreApplication>
#include <QDebug>

#include <QPortKnocking.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // --- Get the ip and port sequence ---
    qDebug() << "Please provide the ip to knock:";
    QString ip = QTextStream(stdin).readLine();

    QList<quint16> ports;
    bool continueAddPort = true;
    while(continueAddPort)
    {
        qDebug() << "Please provide one new port for the port knocking sequence (empty to stop adding port):";
        bool okPort = false;
        QString portString = QTextStream(stdin).readLine();
        if (portString.isEmpty())
        {
            if (ports.size() < 2)
            {
                qCritical("At least two port must be provided for the port knocking sequence");
                return 1;
            }
            else
            {
                continueAddPort = false;
            }
        }
        else
        {
            quint16 port = portString.toUShort(&okPort);
            if (!okPort)
            {
                qCritical("Invalid port (must be a valid port: Unsigned integer)");
                return 1;
            }

            ports.push_back(port);
        }
    }

    // --- Send the port knocking sequence ---
    qDebug() << "Port knocking in progress...";
    QString error;
    if (!QPortKnocking::knock(QHostAddress(ip), ports, error))
    {
        qWarning() << "Failed to Port Knock " << ip << ": " << error;
        return 1;
    }

    qDebug() << "Port Knocking sent to " << ip;
    return 0;
}
