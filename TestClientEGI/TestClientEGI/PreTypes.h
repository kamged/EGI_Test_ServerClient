#ifndef PreTypes_H
#define PreTypes_H

#pragma once
#include <string>
#include <sstream>
#include <bitset>

enum PRETYPES {
    UInt8 = 0,
    Int8,
    UInt16,
    Int16
};

/// <summary>
/// Some EGI parameters
/// </summary>
enum ILDLTYPES {
    P_Att = 0,
    R_Att,
    Y_Att,
    Heading,
    IAS,
    TAS,
    GS,
    VSI,
};

/// <summary>
/// Two additional bits (are appended to the EGI parameters) to identify the correct PreType
/// </summary>
static const char* PRETYPES_STR[] = {"10","00","01","11"};

/// <summary>
/// 3 bits to determine the correct EGI parameter (out of 8 EGI paramters)
/// </summary>
static const char* ILDLTYPES_STR[] = {"000", "001", "010", "011", "100", "101", "110", "111"};

/// <summary>
/// Stop byte is appended (to the EGI parameters) to detect their end in the bit stream
/// </summary>
static const char* EGIVALUE_ENDBITS = "00011100";

template<class T>
class PreTypes
{
public:
    PreTypes(void);
    // ~PreTypes();   
protected:
    T Value;
    bool Validity;
    std::string Hex;
    uint8_t* Bytes;
    std::string Binary;
    std::string Int2Hex(T val);
    uint8_t* Int2Bytes(T val);
    std::string ToBinary(T val);
    int GetILDLType(std::string name);
};

#endif // ! PreTypes_H

template <class T>
PreTypes<T>::PreTypes()
{

}

template <class T>
std::string PreTypes<T>::Int2Hex(T val)
{
    std::stringstream stream;
    stream << std::hex << val;

    return stream.str();
}

template <class T>
uint8_t* PreTypes<T>::Int2Bytes(T val)
{
    static uint8_t bytes[4]{};

    bytes[0] = (val >> 24) & 0xFF;
    bytes[1] = (val >> 16) & 0xFF;
    bytes[2] = (val >> 8) & 0xFF;    
    bytes[3] = (val) & 0xFF;

    return bytes;
}

template <class T>
std::string PreTypes<T>::ToBinary(T val)
{
    std::bitset<sizeof(T) * CHAR_BIT> bs(val);

    return bs.to_string();
}

template <class T>
int PreTypes<T>::GetILDLType(std::string name)
{
        if (name == "Heading")
            return ILDLTYPES::Heading;
        else if (name == "P_Att")
            return ILDLTYPES::P_Att;
        else if (name == "Y_Att")
            return ILDLTYPES::Y_Att;
        else if (name == "R_Att")
            return ILDLTYPES::R_Att;
        else if (name == "IAS")
            return ILDLTYPES::IAS;
        else if (name == "TAS")
            return ILDLTYPES::TAS;
        else if (name == "VSI")
            return ILDLTYPES::VSI;
        else if (name == "GS")
            return ILDLTYPES::GS;
        else
            return -1;
}