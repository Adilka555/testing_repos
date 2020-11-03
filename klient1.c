#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "erprog.h"

int main() {
  int fd = Socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in adr = {0};
  adr.sin_family = AF_INET;
  adr.sin_port = htons(34543); // порт должен совпадать
  Inet_pton(AF_INET, "127.0.0.1", &adr.sin_addr);
  Connect(fd, (struct sockaddr*) &adr, sizeof adr);
  char *arr = get_word();
  write(fd, arr , strlen(arr));
  printf("i send massage\n");
  free(arr);
  close(fd);
  return 0;
}
