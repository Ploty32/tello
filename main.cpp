#define local_port 8889
#define local_ip "" 
#define tello_state_port 8890
#define tello_ip "192.168.10.1"


#include <winsock2.h>
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")
#include <Ws2tcpip.h>

int main() 
{

	using namespace std;
	SOCKET socket_tello;
	WSADATA WSAData;
	SOCKET socket_tello_state;

	/* Initialize Winsock - All processes (applications or DLLs)
	that call Winsock functions must initialize the use of the Windows Sockets DLL before making other Winsock functions calls */
	cout << "Before calling WSAData\n ";
	cout << "WSAData: " << &WSAData << endl;
	cout << "WSAData.szDescription: " << WSAData.szDescription << endl;

	int result = WSAStartup(MAKEWORD(2, 2), &WSAData);
	if (result != 0)
	{
		cout << "WSAStartup failed: " << result << endl;
	}
	cout << "Winsock successfully initialized" << endl;
	cout << "After calling WSAData\n ";
	cout << "WSAData: " << &WSAData << endl;
	cout << "WSAData.szDescription: " << WSAData.szDescription << endl;
	cout << "result: " << result << endl;

	/* Defining the client address structure */
	struct sockaddr_in client_addr = {};
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(local_port);
	cout << "Before call inet_pton: " << inet_pton << endl;
	cout << "client_addr.sin_addr.s_addr: " << client_addr.sin_addr.s_addr << endl;
	inet_pton(AF_INET, local_ip, &client_addr.sin_addr.s_addr);
	cout << "After call inet_pton: " << inet_pton << endl;
	cout << "client_addr.sin_addr.s_addr: " << client_addr.sin_addr.s_addr << endl;

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
