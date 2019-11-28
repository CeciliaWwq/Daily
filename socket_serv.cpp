/*
#include "udpsocket.hpp"
#define CHECK_RET(q) if((q)=false){return -1;}
int main()
{
	if (argc != 3) {
		printf("./udp_srv ip port\n");
		return -1;
	}
	std::string ip = argv[1];
	uint16_t port = atoi(argv[2]);
	UdpSocket sock;
	CHECK_RET(sock.Socket());
	CHECK_RET(sock.Bind(ip, port));

	while (1) {
		std::string buf;
		struct sockaddr_in cli_addr;
		CHECK_RET(sock.Recv(buf, &cli_addr));
		std::cout << "client say:" << buf << std::endl;
		std::cout << "server say:";
		fflush(stdout);
		std::cin >> buf;
		CHECK_RET(sock.Send(buf, &cli_addr));
	}
	sock.Close();
}
*/