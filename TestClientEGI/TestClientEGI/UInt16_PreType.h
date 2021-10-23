#ifndef UInt16_PreType_H
#define UInt16_PreType_H

#pragma once
#include "PreTypes.h"
#include "ILDL_Types_V.h"

class UInt16_PreType : public PreTypes<uint16_t>
{
public:
	UInt16_PreType();
	void setValue(std::string parameterName, uint16_t val);
	uint16_t getValue();
	std::string getHex();
	std::string getBinary();
	uint8_t* getBytes();

private:

};

#endif // ! Uint16_PreType_H