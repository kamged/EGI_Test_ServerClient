#include "UInt16_PreType.h"

UInt16_PreType::UInt16_PreType()
{
	Value = 0;
	Validity = 0;
	Hex = "";
}

void UInt16_PreType::setValue(std::string parameterName, uint16_t val)
{
	Value = val;
	Hex = Int2Hex(val);
	Bytes = Int2Bytes(val);
	Binary = ToBinary(val);
	Binary = Binary.append(ILDLTYPES_STR[GetILDLType(parameterName)]);
	Binary = Binary.append(PRETYPES_STR[PRETYPES::UInt16]);
	Binary = Binary.append(EGIVALUE_ENDBITS);

	ILDL_Types_V::instance().Add(Binary);	
	ILDL_Types_V::instance().AddKV(parameterName, Binary);
}

uint16_t UInt16_PreType::getValue()
{
	return Value;
}

std::string UInt16_PreType::getHex()
{
	return Hex;
}

std::string UInt16_PreType::getBinary()
{
	return Binary;
}

uint8_t* UInt16_PreType::getBytes()
{
	return Bytes;
}