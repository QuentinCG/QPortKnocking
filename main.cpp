/*
 * \brief Example on how to use the Port Knocking
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 1 July 2019
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2019 Quentin Comte-Gaz
 * \version 1.0
 */

#include <QCoreApplication>
#include <QDebug>

#include "QPortKnocking.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // --- Get the ip and port sequence ---
    qDebug() << "Please provide the ip to knock:";
    QString ip = QTextStream(stdin).readLine();

    qDebug() << "Please provide the first port of the port knocking sequence:";
    bool okPort = false;
    quint16 port1 = QTextStream(stdin).readLine().toUShort(&okPort);
    if (!okPort)
    {
        qCritical("Invalid port 1 (must be a valid port: Unsigned integer)");
        return 1;
    }

    qDebug() << "Please provide the second port of the port knocking sequence:";
    quint16 port2 = QTextStream(stdin).readLine().toUShort(&okPort);
    if (!okPort)
    {
        qCritical("Invalid port 2 (must be a valid port: Unsigned integer)");
        return 1;
    }

    qDebug() << "Please provide the third port of the port knocking sequence:";
    quint16 port3 = QTextStream(stdin).readLine().toUShort(&okPort);
    if (!okPort)
    {
        qCritical("Invalid port 3 (must be a valid port: Unsigned integer)");
        return 1;
    }

    qDebug() << "Please provide the last port of the port knocking sequence:";
    quint16 port4 = QTextStream(stdin).readLine().toUShort(&okPort);
    if (!okPort)
    {
        qCritical("Invalid port 4 (must be a valid port: Unsigned integer)");
        return 1;
    }

    // --- Send the port knocking sequence ---
    qDebug() << "Port knocking in progress...";
    QString error;
    if (!QPortKnocking::knock(QHostAddress(ip), port1, port2, port3, port4, error))
    {
        qWarning() << "Failed to Port Knock " << ip << ": " << error;
        return 1;
    }

    qDebug() << "Port Knocking sent to " << ip;
    return 0;
}
