#include "EGI_Client.h"

/// <summary>
/// Connects to the socket
/// </summary>
/// <param name="addr"></param>
/// <param name="port"></param>
EGI_Client::EGI_Client(const std::string& addr, const std::string& port) : socket(io_service, udp::endpoint(udp::v4(), 0))
{
	udp::resolver resolver(io_service); // UDP constructor
	receiver_endpoint = *resolver.resolve({ udp::v4(), addr, port }); // Provide send options: Server IP and port
}

/// <summary>
/// Closes the socket
/// </summary>
EGI_Client::~EGI_Client()
{
	socket.close();
}

/// <summary>
/// Sends a message as an UDP package
/// </summary>
/// <param name="msg"></param>
/// <returns></returns>
int EGI_Client::send(const std::string& msg)
{
	int res = 0;

	if(socket.is_open())	
		res = socket.send_to(boost::asio::buffer(msg, msg.size()), receiver_endpoint);

	return res;
}

/// <summary>
/// Returns true if socket is open
/// </summary>
/// <returns></returns>
bool EGI_Client::IsOpen()
{
	return socket.is_open();
}