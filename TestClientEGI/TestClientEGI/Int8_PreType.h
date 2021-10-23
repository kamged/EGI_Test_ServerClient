#ifndef Int8_PreType_H
#define Int8_PreType_H

#pragma once
#include "PreTypes.h"
#include "ILDL_Types_V.h"

class Int8_PreType : public PreTypes<int8_t>
{
public:
	Int8_PreType();
	void setValue(std::string parameterName, int8_t val);
	int8_t getValue();
	std::string getHex();
	std::string getBinary();
	uint8_t* getBytes();
private:

};

#endif // ! Int8_PreType_H