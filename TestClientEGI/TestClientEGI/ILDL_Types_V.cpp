#include "ILDL_Types_V.h"

ILDL_Types_V& ILDL_Types_V::instance()
{
	static ILDL_Types_V theInstance;

	return theInstance;
}

/// <summary>
/// Adds an element to the end of vector v
/// </summary>
/// <param name="val"></param>
void ILDL_Types_V::Add(std::string val)
{
	v.insert(v.end(), val);
}

void ILDL_Types_V::AddKV(std::string key, std::string val)
{
	kv.insert(std::pair<std::string, std::string>(key, val));
}

/*
 * Get(): Returns the string element at position i
 */
std::string ILDL_Types_V::Get(int i)
{
	return v[i];
}

/*
 * GetDec(): Returns an integer decimal number of a binary string
 * stoi(): Converts the binary string v[i] to a decimal number
 */
int ILDL_Types_V::GetDec(int i)
{
	std::string tmp = v[i];
	tmp.erase(tmp.end()-2,tmp.end());

	return stoi(tmp, nullptr, 2);
}

/// <summary>
/// Returns an integer decimal number of the binary string val
/// </summary>
/// <param name="val"></param>
/// <returns></returns>
int ILDL_Types_V::GetDec(std::string val)
{
	std::string tmp = val;
	tmp.erase(tmp.end() - 13, tmp.end());

	return stoi(tmp, nullptr, 2);
}

/* 
 * Size(): Returns the size of vector v
 */
int ILDL_Types_V::Size()
{
	return v.size();
}

/// <summary>
/// Creates a byte stream of vector v's elements and returns the stream as a string
/// </summary>
/// <param name="_delim"></param>
/// <param name="_del"></param>
/// <returns></returns>
std::string ILDL_Types_V::CreateByteStream(bool _delim, const char* _del)
{
	std::stringstream bs;

	if(!_delim)
		std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(bs));
	else
		std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(bs, _del));

	return bs.str();
}

std::string ILDL_Types_V::CreateByteStream_KV(bool delim)
{
	// std::map<std::string, std::string>::iterator p = kv.begin();
	std::string bs = "";

	for (auto p = kv.begin(); p != kv.end(); p++)
	{
		std::string bitVal = p->second.substr(0, p->second.size());

		if (!delim)
			bs += bitVal;
		else
			bs += bitVal + ";";

	}

	if (delim)
		bs = bs.substr(0, bs.size() - 1);

	return bs;
}

std::string ILDL_Types_V::getStringSize(std::string val)
{
	return std::to_string(val.size() / CHAR_BIT);
}

std::map<std::string, std::string> &ILDL_Types_V::KV()
{
	return kv;
}