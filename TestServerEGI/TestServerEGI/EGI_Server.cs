using System;
using System.Net;
using System.Net.Sockets;
namespace TestServerEGI
{
    class EGI_Server
    {
        private UdpClient _udpClient;
        private int _port;
        private bool _isconnected;

        public EGI_Server(int port)
        {
            IPEndPoint RemoteIpEndPoint = new IPEndPoint(IPAddress.Any, port);
            _udpClient = new UdpClient(RemoteIpEndPoint);
            _port = port;
            _isconnected = false;
        }

        public void Connect(string hostname)
        {
            try
            {
                //udpClient.Connect(hostname, _port);
                _isconnected = true;

                Console.WriteLine("\n[EGI Server] Connected. Listening on port {0}", Port);
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        public byte[] Receive()
        {
            byte[] receiveBytes = new byte[1024];

            if (IsConnected)
            {
                IPEndPoint sender = new IPEndPoint(IPAddress.Any, 0);
                receiveBytes = _udpClient.Receive(ref sender);
       

                return receiveBytes;
            }
            else
                throw new Exception("Connection error");
            
        }

        public UdpClient UdpClient
        {
            get { return _udpClient; }
        }

        public int Port
        {
            get
            {
                return _port;
            }
        }

        public bool IsConnected
        {
            get
            {
                return _isconnected;
            }
        }
    }
}
