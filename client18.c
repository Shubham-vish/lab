#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int sock;
void func();

void main(int argc, char **argv){
	if(argc!=3){
		printf("ERROR Usage: ./a.out <ip> <port>");
		return ;
	}
	int port=atoi(argv[2]);
	struct sockaddr_in client;
	memset(&client, 0x00, sizeof(client));
	sock=socket(AF_INET, SOCK_STREAM, 0);
	client.sin_family=AF_INET; client.sin_port=htons(port); 
	client.sin_addr.s_addr=inet_addr(argv[1]);
	connect(sock, (struct sockaddr*) &client, sizeof(client));
	
	char message[100];
	while(scanf(" %s", message)!=EOF){
		send(sock, message, sizeof(message),0);
	} 
	close(sock);
}
