#include <winsock2.h>
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")

int main() {

	using namespace std;
	SOCKET socket_tello;
	WSADATA WSAData;
	/* Initialize Winsock - All processes (applications or DLLs)
	that call Winsock functions must initialize the use of the Windows Sockets DLL before making other Winsock functions calls */
	int result = WSAStartup(MAKEWORD(2, 2), &WSAData);
	socket_tello = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); //socket(IPv4, socket type using UDP, The UDP)
	cout << "Creating a socket... " << endl;
	cout << "AF_INET: " << AF_INET << endl;
	cout << "SOCK_DGRAM: " << SOCK_DGRAM << endl;
	cout << hex;
	cout << "socket_tello: " << socket_tello << endl;

	/* Checking if socket created is valid*/
	if (socket_tello == INVALID_SOCKET)
	{
		cout << "Error at socket(): " << WSAGetLastError() << endl;
	}
	else {
		cout << "Socket successfully created" << endl;
	}
	cout << "INVALID_SOCKET: " << INVALID_SOCKET << endl;
	return 0;
}
