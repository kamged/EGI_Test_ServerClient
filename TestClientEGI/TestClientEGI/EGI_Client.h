#ifndef EGI_CLIENT_H
#define EGI_ClIENT_H

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <string>

using boost::asio::ip::udp;


class EGI_Client
{
public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="addr"></param>
	/// <param name="port"></param>
	EGI_Client(const std::string& addr, const std::string& port);
	
	/// <summary>
	/// Destructor
	/// </summary>
	~EGI_Client();

	/// <summary>
	/// Sends a message to the server
	/// </summary>
	/// <param name="msg"></param>
	/// <returns></returns>
	int send(const std::string& msg);

	/// <summary>
	/// Checks if socket is open
	/// </summary>
	/// <returns></returns>
	bool IsOpen();
private:
	/// <summary>
	/// Creates in instance of asio::io_service
	/// </summary>
	boost::asio::io_service io_service;

	/// <summary>
	/// Creates an instance of udp::endpoint
	/// </summary>
	udp::endpoint receiver_endpoint;

	/// <summary>
	/// Creates an instance of udp::socket
	/// </summary>
	udp::socket socket;
};

#endif // ! EGI_CLIENT_H