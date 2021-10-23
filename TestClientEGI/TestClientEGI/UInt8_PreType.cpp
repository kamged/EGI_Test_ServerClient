#include "UInt8_PreType.h"

UInt8_PreType::UInt8_PreType()
{
	Value = 0;
	Validity = 0;
	Hex = "";
}

void UInt8_PreType::setValue(std::string parameterName, uint8_t val)
{
	Value = val;
	Hex = Int2Hex(val);
	Binary = ToBinary(val);
	Bytes = Int2Bytes(val);
	Binary = Binary.append(ILDLTYPES_STR[GetILDLType(parameterName)]);
	Binary = Binary.append(PRETYPES_STR[PRETYPES::UInt8]);
	Binary = Binary.append(EGIVALUE_ENDBITS);

	ILDL_Types_V::instance().Add(Binary);
	ILDL_Types_V::instance().AddKV(parameterName, Binary);
}

uint8_t UInt8_PreType::getValue()
{
	return Value;
}

std::string UInt8_PreType::getHex()
{
	return Hex;
}

std::string UInt8_PreType::getBinary()
{
	return Binary;
}

uint8_t* UInt8_PreType::getBytes()
{
	return Bytes;
}