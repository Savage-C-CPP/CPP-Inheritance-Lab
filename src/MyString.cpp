#include "MyString.h"
#include <iostream>
#include <cstring>

unsigned int MyString::copyConstructorCalls = 0;

MyString::MyString()
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов конструктора MyString::MyString()\n";
#endif

    len = 0;
    buffer = new char;
    buffer[0] = '\0';
};

MyString::MyString(const char cstr[])
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов конструктора MyString::MyString(const char[])\n";
#endif
    if (cstr == nullptr)
    {
        buffer = new char;
        buffer[0] = '\0';
    }
    len = strlen(cstr);
    buffer = new char[len + 1];
    strcpy(buffer, cstr);
};

MyString::MyString(const char c)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов конструктора MyString::MyString(const char)\n";
#endif
    len = 1;
    buffer = new char[len + 1];
    buffer[0] = c;
    buffer[1] = '\0';
};

MyString::MyString(const MyString &_)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов конструктора MyString::MyString(const MyString&)\nКонструктор копирования был вызван " << copyConstructorCalls << " раз.\n";
#endif
    copyConstructorCalls++;
    len = _.getLength();
    buffer = new char[len + 1];
    // Copying not buffer pointer but each value
    for (size_t i = 0; i < len; ++i)
        buffer[i] = _.buffer[i];
    buffer[len + 1] = '\0';
};

MyString::~MyString()
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов деструктора MyString::~MyString()\n";
#endif
    delete buffer;
};

size_t MyString::getLength() const
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов метода MyString::getLength()\n";
#endif
    return len;
};

char *MyString::getRawData() const
{
    return buffer;
};

void MyString::operator=(MyString rval)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов оператора MyString::operator=(MyString)\n";
#endif
    // lvalue уже мог быть проинициализирован, поэтому сначала освобождаем его буфер
    delete buffer;
    // и выделяем память заново
    len = rval.getLength();
    buffer = new char[len + 1];
    for (size_t i = 0; i < len; ++i)
        buffer[i] = rval.buffer[i];
    buffer[len + 1] = '\0';
};

void MyString::operator=(const char rval[])
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов оператора MyString::operator=(const char[])\n";
#endif
    // lvalue уже мог быть проинициализирован, поэтому сначала освобождаем его буфер
    if (buffer != nullptr)
        delete buffer;
    // и выделяем память заново
    len = strlen(rval);
    buffer = new char[len + 1];
    for (size_t i = 0; i < len; ++i)
        buffer[i] = rval[i];
    buffer[len + 1] = '\0';
};

char MyString::operator[](unsigned int pos)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов оператора MyString::operator[](unsigned int)\n";
#endif
    if (pos > getLength())
    {
        std::cerr << "[ERR] Выход за предел буфера. " << pos << " > " << getLength() << ".\n";
        return '\0';
    }
    else
        return getRawData()[pos];
};


void MyString::println() const
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов метода MyString::print() const\n";
#endif
    std::cout << getRawData() << std::endl;
};
