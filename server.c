#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main() {
	int t = 0;
	int s1 = socket(AF_INET,SOCK_DGRAM,0);
	
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(11111);
	addr.sin_addr.s_addr = inet_addr("0.0.0.0");
	
	int r1 = bind(s1, (struct sockaddr*)&addr, sizeof(addr));
	if (r1<0) {
		printf("bind\n");
		return -1;
	}
	
	struct sockaddr_in cli;
	socklen_t len = sizeof(cli);
	
	while(t < 2) {
		t++;
		
		char data = 66;
		recvfrom(s1,&data,sizeof(data),0,(struct sockaddr*)&cli,&len);
		printf("%hhd\n",data);	//%hhd print ascii value
	
	data = 66;
	sendto(s1, &data, sizeof(data),0,(struct sockaddr*)&cli, len);
	
	}
	
	close(s1);	 
}
