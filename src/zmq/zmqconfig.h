// Copyright (c) 2014 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Raven Core developers
// Copyright (c) 2020 The Chellit Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CHELLIT_ZMQ_ZMQCONFIG_H
#define CHELLIT_ZMQ_ZMQCONFIG_H

#if defined(HAVE_CONFIG_H)
#include "config/chellit-config.h"
#endif

#include <stdarg.h>
#include <string>

#if ENABLE_ZMQ
#include <zmq.h>
#endif

#include "primitives/block.h"
#include "primitives/transaction.h"

void zmqError(const char *str);

#endif // CHELLIT_ZMQ_ZMQCONFIG_H
