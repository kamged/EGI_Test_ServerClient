#include "Int8_PreType.h"

Int8_PreType::Int8_PreType()
{
	Value = 0;
	Validity = 0;
	Hex = "";
}

void Int8_PreType::setValue(std::string parameterName, int8_t val)
{
	Value = val;
	Hex = Int2Hex(val);
	Bytes = Int2Bytes(val);
	Binary = ToBinary(val);
	Binary = Binary.append(ILDLTYPES_STR[GetILDLType(parameterName)]);
	Binary = Binary.append(PRETYPES_STR[PRETYPES::Int8]);
	Binary = Binary.append(EGIVALUE_ENDBITS);

	ILDL_Types_V::instance().Add(Binary);
	ILDL_Types_V::instance().AddKV(parameterName, Binary);
}

int8_t Int8_PreType::getValue()
{
	return Value;
}

std::string Int8_PreType::getHex()
{
	return Hex;
}

std::string Int8_PreType::getBinary()
{
	return Binary;
}

uint8_t* Int8_PreType::getBytes()
{
	return Bytes;
}