/*
 * \brief 'Static class' to send a Port Knocking request
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 1 July 2019
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2019 Quentin Comte-Gaz
 * \version 2.0
 */

#ifndef QPORTKNOCKING_H
#define QPORTKNOCKING_H

#include <QObject>
#include <QtNetwork>

#include "QPortKnocking_global.h"

class QPORTKNOCKINGSHARED_EXPORT QPortKnocking
{

public:
  /*!
   * \brief QPortKnocking Basic instance of port knocking class (Not mandatory since all function are static)
   */
  QPortKnocking();

  /*!
   * \brief knock Knock a specified address with a specified port sequence
   *
   * \param address[in] Address to port knock (example: "127.0.0.1")
   * \param portSequence[in] Port sequence (example: {1001, 1002, 1003, 1004})
   *
   * \param error[out] Error message
   *
   * \return Knock sent successfully
   *
   * \details Blocking function but allowing Qt events to execute during this function (QEventLoop::AllEvents)
   */
  static bool knock(const QHostAddress& address, const QList<quint16>& portSequence, QString& error);
};

#endif // QPORTKNOCKING_H
