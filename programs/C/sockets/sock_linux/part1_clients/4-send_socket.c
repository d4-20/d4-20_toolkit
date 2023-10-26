#include <stdio.h>
#include <string.h> 	//strlen
#include <sys/socket.h>
#include <arpa/inet.h>  //inet_addr

int main(int argc, char *argv[])
{
	int socket_desc;
	struct sockaddr_in server;
	char *message;

	//Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1)
		printf("Could not create socket");

	server.sin_addr.s_addr = inet_addr("200.160.2.3");
	server.sin_family = AF_INET;
	server.sin_port = htons(43);

	//Connect to remote server
	if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		puts("connect error");
		return -1;
	}

	puts("Connected\n");

	//Send some data
	message = "businesscorp.com.br\r\n";
	if (send(socket_desc, message, strlen(message), 0) < 0)
	{
		puts("Send faield");
		return 1;
	}
	puts("Data Send\n");

	return 0;
}