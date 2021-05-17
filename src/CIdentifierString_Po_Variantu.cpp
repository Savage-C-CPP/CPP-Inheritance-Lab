#include "CIdentfierString.h"
#include <cstring>
#include <iostream>

int CIdentifierString::findFirst(const char _)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов метода CIdentifierString::findFirst(const char)\n";
#endif
    size_t it = 0, l = getLength();
    char *const b = getRawData();
    for (; it < l; ++it)
    {
        if (b[it] == _)
            return it;
    }
    return -0;
}

CIdentifierString CIdentifierString::operator+(CIdentifierString rval)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов оператора CIdentifierString::operator+(CIdentifierString)\n";
#endif
    size_t l = getLength() + rval.getLength();
    char *buf = new char[l];
    strcat(buf, getRawData());
    strcat(buf, rval.getRawData());
    return CIdentifierString(buf);
};

CIdentifierString CIdentifierString::operator+(MyString rval)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов оператора CIdentifierString::operator+(MyString)\n";
#endif
    size_t l = getLength() + rval.getLength();
    char *buf = new char[l];
    strcat(buf, getRawData());
    strcat(buf, rval.getRawData());
    return CIdentifierString(buf);
};

CIdentifierString CIdentifierString::operator+(const char rval[])
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов оператора CIdentifierString::operator+(const char[])\n";
#endif
    size_t l = getLength() + strlen(rval);
    char *buf = new char[l];
    strcat(buf, getRawData());
    strcat(buf, rval);
    return CIdentifierString(buf);
};

// переопределил оператор [] для этого класса (пока пусть будет)
char CIdentifierString::operator[](unsigned int pos)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов оператора CIdentifierString::operator[](unsigned int)\n";
#endif
    if (pos > getLength())
    {
        std::cerr << "[ERR] Выход за предел буфера. " << pos << " > " << getLength() << ".\n";
        return '\0';
    }
    else
        return getRawData()[pos];
}
