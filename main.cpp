#include <winsock2.h>
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")

int main() {

	using namespace std;
	SOCKET socket_tello;
	socket_tello = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); //socket(IPv4, socket type using UDP, The UDP)

}
