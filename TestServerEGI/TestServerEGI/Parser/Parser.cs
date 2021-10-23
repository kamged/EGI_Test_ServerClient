using System;
using System.Collections.Generic;
using System.Text;

namespace TestServerEGI
{
    public class Parser
    {
        private string EGIValueEndBits = "00011100";
        private List<string> _listEGIRawValues;

        public Parser()
        {
            _listEGIRawValues = new List<string>();
        }

        public string ByteStream { set; get; }

        protected List<string> GetParsedRawValues(string val)
        {
            if (val.Length < 1)
                return null;

            ByteStream = val;

            int end = ByteStream.Length;
            
            string tmp = ByteStream;
            
            while(EGIValueEndBits.Length < tmp.Length)
            {
                
                end = tmp.IndexOf(EGIValueEndBits) - 1;

                _listEGIRawValues.Add(tmp.Substring(0, end + 1));
                
                tmp = tmp.Remove(0, (end + 1) + EGIValueEndBits.Length);

                
                /*Console.WriteLine("[Parser] BS Length: {0}", tmp.Length);
                Console.WriteLine("[Parser] BS: {0}", end);
                Console.WriteLine("[Parser] BS: {0}\n\n", _listEGIRawValues[i]);*/
            }

            return _listEGIRawValues;
        }
    }
}
