#ifndef UInt8_PreType_H
#define UInt8_PreType_H

#pragma once
#include "PreTypes.h"
#include "ILDL_Types_V.h"

class UInt8_PreType : public PreTypes<uint8_t>
{
public:
	UInt8_PreType();
	void setValue(std::string parameterName, uint8_t val);
	uint8_t getValue();
	std::string getHex();
	std::string getBinary();
	uint8_t* getBytes();
private:
	
};

#endif // ! UInt_8_PreType_H