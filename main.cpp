#include <winsock2.h>
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")

int main() {

	using namespace std;
	SOCKET socket_tello;
	socket_tello = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); //socket(IPv4, socket type using UDP, The UDP)
	cout << "Creating a socket... " << endl;
	cout << "AF_INET: " << AF_INET << endl;
	cout << "SOCK_DGRAM: " << SOCK_DGRAM << endl;
	cout << hex;
	cout << "socket_tello: " << socket_tello << endl;
}
