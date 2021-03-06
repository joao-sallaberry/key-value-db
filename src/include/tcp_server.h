/***********************
 TCP Server inspired by
 http://www.binarytides.com/server-client-example-c-sockets-linux/
 ***********************/
#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <stdint.h>

typedef enum {
	SOCKET_ERR,
	BIND_ERR,
	ACCEPT_ERR,
	WRITE_ERR
} socket_error_t;

typedef const char* (*const socket_callback_t)(const char*);

/*
 * Start TCP Server
 *     RETURNS 0 if successful, socket_error_t otherwise
 */
int start_server(uint16_t port);

/*
 * Accepts incomming connection and executes callback
 * for every new message received
 *     RETURNS 0 if successful, socket_error_t otherwise
 */
int wait_connection(socket_callback_t callback);

#endif
