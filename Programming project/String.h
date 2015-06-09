#ifndef __String_H__
#define __String_H__

#include <stdlib.h>
#include <string.h>
class String
{
	/////////////
	//Atributes//
	/////////////
public:
	char* str;
	int memorySize;


	////////////////
	//Constructors//
	////////////////

	String();

	String(const char*format, ...);

	String(const String& string);


	///////////
	//Methods//
	///////////

	bool operator == (const char* string) const;

	bool operator == (const String& string) const;

	bool operator != (const char* string) const;

	bool operator != (const String& string) const;

	String operator = (const char* string);

	String operator = (const String& string);

	String operator += (const char* string);

	String operator += (const String& string);

	String prefix(const String& string);

	String prefix(const char* string);

	void Trim();

	void DeleteSpaces();

	void Substitute(const char* previousStr, const char* newStr);

	void Clear();

	int GetLenght() const;

	int GetCapacity() const;

	char* GetString() const;

	void Alloc(const int memory);


	//////////////
	//Destructor//
	//////////////

	~String();


};

#endif //__String_H__