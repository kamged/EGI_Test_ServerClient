#ifndef ILDL_Types_V_H
#define ILDL_Types_V_H

#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <utility> 

class ILDL_Types_V
{
public:
	/// Instance of ILDL_Types_V
	static ILDL_Types_V& instance();

	/// Adds a string value to v
	void Add(std::string val);
	void AddKV(std::string key, std::string val);

	/// Returns a binary string at position i
	std::string Get(int i);

	/// Returns a binary string at position i
	int GetDec(std::string val);

	/// Returns an decimal integer number of a binary string at position i
	int GetDec(int i);

	/// Returns the size of v
	int Size();

	/// Returns the size of a string
	std::string getStringSize(std::string val);

	/// <summary>
	/// Creates a byte stream of the vector v's elements
	/// </summary>
	/// <param name="_delim"></param>
	/// <param name="_del"></param>
	/// <returns></returns>
	std::string CreateByteStream(bool _delim, const char* _del = " ");

	std::string CreateByteStream_KV(bool delim);

	std::map<std::string, std::string> &KV();

private:
	std::vector<std::string> v;
	typedef std::map<std::string, std::string> mapParameterToValue;
	mapParameterToValue kv;
};

#endif // ! ILDL_Types_V_H