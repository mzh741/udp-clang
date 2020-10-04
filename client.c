#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>

int main() {
	int t = 0;
	int s1=socket(AF_INET, SOCK_DGRAM, 0);
	
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(11111);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	while(t < 2) {
		t++;
		
		char data = 66;
		sendto(s1, &data, sizeof(data), 0, (struct sockaddr*)&addr, sizeof(addr));
		
		
		socklen_t len = sizeof(addr);
		recvfrom(s1, &data, sizeof(data), 0,(struct sockaddr*)&addr, &len);
		printf("%hhd\n", data);
	}
	close(s1);
}
