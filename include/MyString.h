#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include <iostream>
#include "log.h"

class MyString
{
private:
    static unsigned int copyConstructorCalls;

protected:
    char *buffer;
    size_t len;

public:
    MyString();
    MyString(const MyString &);
    MyString(const char[]);
    MyString(const char);
    ~MyString();

    void operator=(MyString);
    void operator=(const char[]);
    char operator[](const unsigned int);

    size_t getLength() const;
    char *getRawData() const;
    void println() const;
};

#endif // __MY_STRING_H__
