﻿/**
 * File:   socket_helper.h
 * Author: AWTK Develop Team
 * Brief:  socket helper functions
 *
 * Copyright (c) 2019 - 2019  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2019-09-05 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#ifndef TK_SOCKET_HELPER_H
#define TK_SOCKET_HELPER_H

BEGIN_C_DECLS

#ifdef WIN32
#include "windows.h"
#include <winsock2.h>
#include <ws2tcpip.h>
typedef int socklen_t;
#else
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>

#endif /*WIN32*/

#include "tkc/fs.h"
#include "tkc/iostream.h"

void socket_init();
void socket_deinit();
void socket_close(int sock);
bool_t socket_set_blocking(int sock, bool_t blocking);

int tcp_listen(int port);
int tcp_accept(int sock);
int tcp_connect(const char* host, int port);

END_C_DECLS

#endif /*TK_SOCKET_HELPER_H*/