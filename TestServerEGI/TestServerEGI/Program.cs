using System;
using System.Text;

namespace TestServerEGI
{
    class Program
    {
        static void Main(string[] args)
        {

            EGI_Server egi_server = new EGI_Server(50002);
            egi_server.Connect("127.0.0.1");

            while(true)
            {
                byte[] recvBytes = egi_server.Receive();

                if (recvBytes.Length > 0)
                {
                    Console.WriteLine("[EGI Server] {0} bytes received.", recvBytes.Length / 8*sizeof(bool));
                    Console.WriteLine("[EGI Server] Bit stream: {0} \n\n", Encoding.Default.GetString(recvBytes));

                    StartParsing(Encoding.Default.GetString(recvBytes));

                    if (Encoding.ASCII.GetString(recvBytes) == "q")
                    {
                        Console.WriteLine("[EGI Server]: Bye bye.");

                        break;
                    }
                }
            }

        }

        public static string GetHexString(byte[] byteArray)
        {
            return BitConverter.ToString(byteArray); // To convert the whole array
        }

        public static void StartParsing(string bs)
        {
            EGIParser egiParser = new EGIParser(bs); // Eample bit stream: "010110100000000011100110010111100100011100"
            bool status = egiParser.StartParsingEGIPara();
            

            if (status)
                Console.WriteLine("[EGI Server] Parsing Done. Output:");

            Console.WriteLine("[EGI Server] Number of identified parameters: {0} \n\n", egiParser.EGIParaListSize());

            foreach (var kv in egiParser.EGIParaList())
            {
                Console.WriteLine("Parameter: {0,15} | {1,8} | {2,16} | Dec: {3}", kv.Key, kv.Value.PreType, kv.Value.Binary, kv.Value.Decimal);
            }
        }
    }
}
