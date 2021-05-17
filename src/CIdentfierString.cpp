#include "CIdentfierString.h"
#include <iostream>
#include <cstring>

bool CIdentifierString::isValidCIdentifier(const char str[])
{
    // If first character is invalid
    if (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z') || str[0] == '_'))
        return false;

    // Traverse the string for the rest of the characters
    for (int i = 1; i < strlen(str); i++)
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_'))
            return false;
    }

    // String is a valid identifier
    return true;
}

CIdentifierString::CIdentifierString() : MyString()
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов конструктора CIdentifierString::CIdentifier() : MyString()\n";
#endif
    // Пустая строка
};

// Сначала вызываем конструктор базового класса, он собирает строку.
// Далее следует код этого конструктора, в котором мы просто проверяем,
// является ли строка в буфере char* buffer валидным c/c++ идентификатором.
CIdentifierString::CIdentifierString(const MyString &_) : MyString(_)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов конструктора CIdentifierString::CIdentifier(const MyString&) : MyString(const MyString&)\n";
#endif
    if (!CIdentifierString::isValidCIdentifier(this->buffer))
    {
        this->len = 0;
        delete this->buffer;
        this->buffer = new char;
        this->buffer[0] = '\0';
    }
};

// Тут не нужны никакие другие операции, так как CIdentifierString либо валидная c/c++ строка либо строка пустая,
// поэтому на выходе получается валидная CIdentifierString
CIdentifierString::CIdentifierString(const CIdentifierString &_) : MyString(_.buffer)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызвов конструктора CIdentifierString::CIdentifier(const CIdentifierString&) : MyString(const char[])\n";
#endif
};

CIdentifierString::CIdentifierString(const char _[]) : MyString(_)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов конструктора CIdentifierString::CIdentifier(const char[]) : MyString(const char[])\n";
#endif
    if (!CIdentifierString::isValidCIdentifier(this->buffer))
    {
        this->len = 0;
        delete this->buffer;
        this->buffer = new char;
        this->buffer[0] = '\0';
    }
};

CIdentifierString::CIdentifierString(const char _) : MyString(_)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов конструктора CIdentifierString::CIdentifier(const char) : MyString(const char)\n";
#endif
    if (!CIdentifierString::isValidCIdentifier(this->buffer))
    {
        this->len = 0;
        delete this->buffer;
        this->buffer = new char;
        this->buffer[0] = '\0';
    }
};

CIdentifierString::~CIdentifierString()
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов деструктора CIdentifierString::~CIdentifierString()\n";
#endif
};

void CIdentifierString::operator=(MyString rval)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов оператора CIdentifierString::operator=(MyString)\n";
#endif
    char *rvalBuffer = rval.getRawData();
    if (!CIdentifierString::isValidCIdentifier(rvalBuffer))
    {
        std::cerr << "[ERR] rvalue не является валидным C/C++ идентификатором.\n";
        return;
    }
    // lvalue уже мог быть проинициализирован, поэтому сначала освобождаем его буфер сперва
    if (buffer != nullptr)
        delete buffer;
    len = rval.getLength();
    buffer = new char[len + 1];
    for (size_t i = 0; i < len; ++i)
        buffer[i] = rvalBuffer[i];
    buffer[len + 1] = '\0';
};

void CIdentifierString::operator=(CIdentifierString rval)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов оператора CIdentifierString::operator=(CIdentifierString)\n";
#endif
    char *rvalBuffer = rval.getRawData();
    if (!CIdentifierString::isValidCIdentifier(rvalBuffer))
    {
        std::cerr << "[ERR] rvalue не является валидным C/C++ идентификатором.\n";
        return;
    }
    // lvalue уже мог быть проинициализирован, поэтому сначала освобождаем его буфер сперва
    if (buffer != nullptr)
        delete buffer;
    len = rval.getLength();
    buffer = new char[len + 1];
    for (size_t i = 0; i < len; ++i)
        buffer[i] = rvalBuffer[i];
    buffer[len + 1] = '\0';
};

void CIdentifierString::operator=(const char rval[])
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов оператора CIdentifierString::operator=(const char[])\n";
#endif
    if (!CIdentifierString::isValidCIdentifier(rval))
    {
        std::cerr << "[ERR] rvalue не является валидным C/C++ идентификатором.\n";
        return;
    }
    // lvalue уже мог быть проинициализирован, поэтому сначала освобождаем его буфер сперва
    if (buffer != nullptr)
        delete buffer;
    len = strlen(rval);
    buffer = new char[len + 1];
    for (size_t i = 0; i < len; ++i)
        buffer[i] = rval[i];
    buffer[len + 1] = '\0';
};
