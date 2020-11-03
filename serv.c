#include "erprog.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
	int server = Socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in adr = {0};
	adr.sin_family = AF_INET;
	adr.sin_port = htons(34543); //порд для подключения клиентов
	Bind(server, (struct sockaddr *) &adr, sizeof(adr));
  Listen(server, 5);//слушаю клиента
  socklen_t addrlen = sizeof adr;
  int fd[1];
  char buf[256];
	ssize_t nread;
	for (int i = 0; i < 2; i++) {
  	fd[i] = Accept(server, (struct sockaddr *) &adr, &addrlen); //приняли клиент
	}
  nread = read(fd[0], buf , 256);
  if (nread == -1) {
		perror("read fail");
    exit(1);
  }
  if (nread == 0) {
    printf("enf of file\n");
  }
  write(STDOUT_FILENO, buf, nread);
	printf("i take massage\n");
	sleep(2);
	write(fd[1], buf, nread);
	printf("i send massage\n");

  close(fd[0]);
  close(fd[1]);
  close(server);
	return 0;
}
