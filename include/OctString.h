#ifndef __OCT_STRING_H__
#define __OCT_STRING_H__

#include "MyString.h"
#include <iostream>
#include <cstring>

class OctString : public MyString
{
private:
    static unsigned int copyConstructorCalls;
    bool positive;

public:
    OctString();
    OctString(const MyString &);
    OctString(const OctString &);
    OctString(const char[]);
    OctString(const char);

    ~OctString();

    void operator=(const MyString);
    void operator=(const OctString);
    void operator=(const char[]);
    OctString operator+(const OctString);

public:
    bool isPositive();
    bool ConvertableToUnsignedLong();

    static bool isValidOctString(const char[]);
    static OctString Add_Oct(const OctString&, const OctString&);
};

#endif // __OCT_STRING_H__
