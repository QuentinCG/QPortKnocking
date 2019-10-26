/*
 * \brief Test the Port Knocking library
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 26 October 2019
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2019 Quentin Comte-Gaz
 * \version 2.0
 */
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include <QCoreApplication>
#include <QDebug>

#include <QPortKnocking.h>

TEST_CASE("Create and use instance")
{
    QPortKnocking portKnockingInstance;
    QHostAddress addr("127.0.0.1");
    QList<quint16> ports({1000, 1001});
    QString error;

    REQUIRE(portKnockingInstance.knock(addr, ports, error) == true);
    REQUIRE(error.isEmpty() == true);
}

TEST_CASE("Invalid IP address")
{
    QHostAddress addr("127.0.0.999");
    QList<quint16> ports({1000, 1001, 1002, 1003});
    QString error;

    REQUIRE(QPortKnocking::knock(addr, ports, error) == false);
    REQUIRE(error.isEmpty() == false);
}

TEST_CASE("Empty IP address")
{
    QHostAddress addr;
    QList<quint16> ports({1000, 1001, 1002, 1003});
    QString error;

    REQUIRE(QPortKnocking::knock(addr, ports, error) == false);
    REQUIRE(error.isEmpty() == false);
}

TEST_CASE("Invalid sequence size")
{
    QHostAddress addr("127.0.0.1");
    QList<quint16> ports;
    QString error;

    REQUIRE(QPortKnocking::knock(addr, ports, error) == false);
    REQUIRE(error.isEmpty() == false);

    ports.append(1000);
    error.clear();
    REQUIRE(QPortKnocking::knock(addr, ports, error) == false);
    REQUIRE(error.isEmpty() == false);
}

TEST_CASE("Normal knock use")
{
    QHostAddress addr("127.0.0.1");
    QList<quint16> ports({1000, 1001});
    QString error;

    // With 2 ports
    REQUIRE(QPortKnocking::knock(addr, ports, error) == true);
    REQUIRE(error.isEmpty() == true);

    // With 3 ports
    ports.append(1002);
    error.clear();
    REQUIRE(QPortKnocking::knock(addr, ports, error) == true);
    REQUIRE(error.isEmpty() == true);

    // With 4 ports
    ports.append(1003);
    error.clear();
    REQUIRE(QPortKnocking::knock(addr, ports, error) == true);
    REQUIRE(error.isEmpty() == true);

    // With 5 ports
    ports.append(1004);
    error.clear();
    REQUIRE(QPortKnocking::knock(addr, ports, error) == true);
    REQUIRE(error.isEmpty() == true);
}

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << QString("Launching test using catch version %1.%2 - %3").arg(CATCH_VERSION_MAJOR).arg(CATCH_VERSION_MINOR).arg(CATCH_VERSION_PATCH);

    int result = Catch::Session().run(argc, argv);
    return result;
}
