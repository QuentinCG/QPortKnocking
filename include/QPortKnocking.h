/*
 * \brief 'Static class' to send a Port Knocking request
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 1 July 2019
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2019 Quentin Comte-Gaz
 * \version 1.0
 */

#ifndef QPORTKNOCKING_H
#define QPORTKNOCKING_H

#include <QObject>
#include <QtNetwork>

class QPortKnocking
{

public:
  /*!
   * \brief knock Knock a specific address with sequence {port1, port2, port3, port4}
   *
   * \param address[in] Address to port knock
   * \param port1[in] First port of port knocking sequence
   * \param port2[in] Second port of port knocking sequence
   * \param port3[in] Third port of port knocking sequence
   * \param port4[in] Last port of port knocking sequence
   *
   * \param error[out] Error message
   *
   * \return Knock sent successfully
   *
   * \details Blocking function but allowing Qt events to execute during this function (QEventLoop::AllEvents)
   */
  static bool knock(const QHostAddress& address, const quint16& port1, const quint16& port2, const quint16& port3, const quint16& port4, QString& error);

private:
  QPortKnocking();
};

#endif // QPORTKNOCKING_H
