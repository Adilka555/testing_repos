
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
int Socket(int domin, int type, int protocol) {
int res = socket(domin, type, protocol);
if (res == -1) {
 perror("error of socket");
 exit(1);
}
return res;
}
void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
int res = bind(sockfd, addr, addrlen);
if  (res == -1) {
  perror("error of bind");
  exit(1);
}
}
void Listen(int sockfd, int backlog){
int res = listen(sockfd, backlog);
if (res == -1) {
  perror("error of listen");
  exit(1);
}
}
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
int res = accept(sockfd, addr, addrlen);
if(res == -1) {
  perror("error of accept");
  exit(1);
}
return res;
}

void Connect (int sockfd, const struct sockaddr *addr, socklen_t adrlen) {
  int res = connect(sockfd, addr, adrlen);
  if (res == -1) {
    perror("error of connect");
    exit(1);
  }
}

void Inet_pton(int af, const char *src, void *dst){
  int res = inet_pton(af, src, dst);
  if (res == -1) {
    perror("error of inet_piton");
    exit(1);
  }
  if (res == 0) {
    printf("fail : no valid");
    exit(1);
  }
}

char* get_word() {
  char ch;
  char *arr = malloc(20 * sizeof(char));
  int i = 0;
  ch = getchar();
  arr[0] = ch;
  while (ch!= '\n') {
    i++;
    ch = getchar();
    arr[i] = ch;
  }
  if (i > 20) {
    perror("so long mass");
    exit(1);
  }
  return arr;
}
