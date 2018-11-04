#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
int ssock, csock;
void func();

void main(){
	int port=55000;
	struct sockaddr_in client, server;
	memset(&server, 0x00, sizeof(server));
	ssock=socket(AF_INET, SOCK_STREAM, 0);
	server.sin_family=AF_INET; server.sin_port=htons(port); 
	server.sin_addr.s_addr=inet_addr("127.0.0.2");
	int len=sizeof(client);
	bind(ssock, (struct sockaddr*) &server, sizeof(server));
	listen(ssock, 5);

  //ACCEPTING REQUESTS
	while(csock=accept(ssock,(struct sockaddr*)&client, &len)){
		int pid=fork();
		if(!pid){
			char message[100];
			while(recv(csock, message, sizeof(message),0)) printf("Received from %d : %s\n", csock, message);
			exit(0);
		}
	}
	
	close(ssock);
}
