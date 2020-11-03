#ifndef ERPROC_H
#define ERPROC_H
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int Socket(int domin, int type, int protocol);

void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

void Listen(int sockfd, int backlog);

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

void Connect (int sockfd, const struct sockaddr *addr, socklen_t adrlen);

void Inet_pton(int af, const char *src, void *dst);

char* get_word();

#endif
