using System;
using System.Collections.Generic;

namespace TestServerEGI
{
    public class EGIParser : Parser
    {
        private Dictionary<string, EGIParameter> _egi_para_list;
        private List<string> _rawValues;
        private const int SUFFIX_LEN = 5;
        public EGIParser(string bytestream)
        {
            _egi_para_list = new Dictionary<string, EGIParameter>();

            _rawValues = GetParsedRawValues(bytestream);
        }

        private void ParseRawEGIPara(string raw_egi_parameter)
        {            
            string suffix = raw_egi_parameter.Substring(raw_egi_parameter.Length - SUFFIX_LEN, SUFFIX_LEN);

            EGIParameter ep = new EGIParameter();

            switch (suffix)
            {
                case "00000":
                    ep.Binary = raw_egi_parameter.Substring(0, raw_egi_parameter.Length - SUFFIX_LEN);
                    ep.Decimal = Convert.ToInt32(ep.Binary, 2).ToString();
                    ep.PreType = "Int8";

                    _egi_para_list.Add("Pitch attitude", ep);

                    break;
                case "00100":
                    ep.Binary = raw_egi_parameter.Substring(0, raw_egi_parameter.Length - SUFFIX_LEN);
                    ep.Decimal = Convert.ToInt32(ep.Binary, 2).ToString();
                    ep.PreType = "Int8";

                    _egi_para_list.Add("Roll attitude", ep);

                    break;
                case "01000":
                    ep.Binary = raw_egi_parameter.Substring(0, raw_egi_parameter.Length - SUFFIX_LEN);
                    ep.Decimal = Convert.ToInt32(ep.Binary, 2).ToString();
                    ep.PreType = "Int8";

                    _egi_para_list.Add("Yaw attitude", ep);

                    break;
                case "01101":
                    ep.Binary = raw_egi_parameter.Substring(0, raw_egi_parameter.Length - SUFFIX_LEN);
                    ep.Decimal = Convert.ToInt16(ep.Binary, 2).ToString();
                    ep.PreType = "UInt16";

                    _egi_para_list.Add("Heading", ep);

                    break;
                case "10001":
                    ep.Binary = raw_egi_parameter.Substring(0, raw_egi_parameter.Length - SUFFIX_LEN);
                    ep.Decimal = Convert.ToInt16(ep.Binary, 2).ToString();
                    ep.PreType = "UInt16";

                    _egi_para_list.Add("IAS", ep);

                    break;
                case "10101":
                    ep.Binary = raw_egi_parameter.Substring(0, raw_egi_parameter.Length - SUFFIX_LEN);
                    ep.Decimal = Convert.ToInt16(ep.Binary, 2).ToString();
                    ep.PreType = "UInt16";

                    _egi_para_list.Add("TAS", ep);
                    break;
                case "11001":
                    ep.Binary = raw_egi_parameter.Substring(0, raw_egi_parameter.Length - SUFFIX_LEN);
                    ep.Decimal = Convert.ToInt16(ep.Binary, 2).ToString();
                    ep.PreType = "UInt16";

                    _egi_para_list.Add("Ground speed", ep);
                    break;
                case "11101":
                    ep.Binary = raw_egi_parameter.Substring(0, raw_egi_parameter.Length - SUFFIX_LEN);
                    ep.Decimal = Convert.ToInt16(ep.Binary, 2).ToString();
                    ep.PreType = "UInt16";

                    _egi_para_list.Add("VSI", ep);
                    break;
                default:
                        break;
            }
        }

        public bool StartParsingEGIPara()
        {
            _rawValues.ForEach(val => ParseRawEGIPara(val));

            return true;
        }

        public int EGIParaListSize()
        {
            return _egi_para_list.Count;
        }

        public Dictionary<string, EGIParameter> EGIParaList()
        {
            return _egi_para_list;
        }
    }
}
