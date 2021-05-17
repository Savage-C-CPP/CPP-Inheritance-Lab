#ifndef __C_IDENTIFIER_STRING_H__
#define __C_IDENTIFIER_STRING_H__
#include "MyString.h"

class CIdentifierString : public MyString
{
private:
    static unsigned int copyConstructorCalls;

public:
    CIdentifierString();
    CIdentifierString(const MyString &);
    CIdentifierString(const CIdentifierString &);
    CIdentifierString(const char[]);
    CIdentifierString(const char);

    ~CIdentifierString();

    void operator=(const MyString);
    void operator=(const CIdentifierString);
    void operator=(const char[]);

    static bool isValidCIdentifier(const char[]);

    // По варианту 18
    int findFirst(const char);
    CIdentifierString operator+(const CIdentifierString);
    CIdentifierString operator+(const MyString);
    CIdentifierString operator+(const char[]);
    char operator[](unsigned int);
};
#endif // __C_IDENTIFIER_STRING_H__
