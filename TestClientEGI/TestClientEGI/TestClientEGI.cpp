
#include <iostream>
#include <iomanip>
#include "TestByteStream.h"
#include "ILDL_Types_V.h"
#include "EGI_Client.h"

int main()
{
    const std::string PORT_STR = "50002";
    const int PRETYPE_SUFFIX = 2;
    const int EGI_PARA_SUFFIX = 3;
    const int EGI_PARA_ENDBITS = 8;

    std::cout << "TestClientEGI\n\n\n";

    /// <summary>
    /// Creates an instance of TestByteStream
    /// </summary>
    /// <returns></returns>
    TestByteStream testByteStream;

    std::cout << "Number of EGI parameters: " << ILDL_Types_V::instance().Size() << "\n\n";
    std::cout << "Binary and decimal representation of the EGI parameters (defined in ILDL_Types.h) with and without suffix bits: \n\n";

    for (int i = 0; i < ILDL_Types_V::instance().Size(); i++)
        std::cout << std::setw(21) << std::left << ILDL_Types_V::instance().Get(i) << "\n";

    std::cout << std::endl;

    for (std::map<std::string, std::string>::iterator p = ILDL_Types_V::instance().KV().begin(); p != ILDL_Types_V::instance().KV().end(); ++p)
    {
        std::string bitVal = p->second.substr(0, p->second.size() - (EGI_PARA_SUFFIX + PRETYPE_SUFFIX + EGI_PARA_ENDBITS));

        std::cout << std::setw(10) << std::left << p->first << ": " << std::setw(24) << std::left << bitVal << " | Dec: " << ILDL_Types_V::instance().GetDec(p->second) << std::endl;
    }

    std::string bs = ILDL_Types_V::instance().CreateByteStream_KV(false);

    std::cout << "\n\nBytes to send: " << bs.size() / CHAR_BIT << std::endl;

    // Print the stream to send as an UDP package to the server
    std::cout << bs << std::endl << std::endl;

    try
    {
        EGI_Client client("127.0.0.1", PORT_STR);

        if (client.IsOpen())
            std::cout << "[Client] Connection open. Type 'q' to exit, type 'egi' to send the client's bit stream\n\n";

        std::string input = " ";

        while (input != "q")
        {
            std::cin >> input;

            if (input != "egi")
                std::cout << client.send(input) << "\n";
            else
            {
                std::cout << "Bytes to send: " << ILDL_Types_V::instance().getStringSize(bs) << " (" << bs.size() << " bits)" << std::endl;
                std::cout << "Bits sent: " << client.send(bs) << "\n\n";
            }
        }
    }
    catch (int e)
    {
        return e;
    }

    return 0;
}