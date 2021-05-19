#include "OctString.h"
#include <string>
#include <sstream>
#include <climits>

bool OctString::isValidOctString(const char str[])
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов метода OctString::isValidOctString(const char[])\n";
#endif
    // If strlen == 1 then only 0..7 can make a valid OctString
    if (strlen(str) == 1)
        if (!(str[0] >= '0' && str[0] <= '7'))
            return false;

    // First character may be '-' or '+' or may not be
    if (!((str[0] >= '0' && str[0] <= '7') || str[0] == '-' || str[0] == '+'))
        return false;

    // '-' or '+' can't be in the middle or at the end of oct string number, so it only has 0..7
    for (int i = 1; i < strlen(str); i++)
        if (!(str[i] >= '0' && str[i] <= '7'))
            return false;

    // String is a valid oct number
    return true;
}

bool OctString::isPositive()
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов метода OctString::isPositive()\n";
#endif
    return positive;
}

OctString::OctString() : MyString("0")
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов конструктора OctString::OctString() : MyString(\"0\")\n";
#endif
    // Нулевое значение
    positive = true;
};

// Сначала вызываем конструктор базового класса, он собирает строку.
// Далее следует код этого конструктора, в котором мы просто проверяем,
// является ли строка в буфере char* buffer валидным восьмиричным числом.
OctString::OctString(const MyString &_) : MyString(_)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов конструктора OctString::Oct(const MyString&) : MyString(const MyString&)\n";
#endif
    if (!OctString::isValidOctString(this->buffer))
    {
        std::cerr << "[ERR] аргумент не является валидным восьмиричным числом.\n";
        this->len = 0;
        delete this->buffer;
        this->buffer = new char[2];
        this->buffer[0] = '0';
        this->buffer[1] = '\0';
        this->positive = true;
    }
};

// Тут не нужны никакие другие операции, так как OctString либо валидное восьмиричное число либо строка пустая,
// поэтому на выходе получается валидная OctString
OctString::OctString(const OctString &_) : MyString(_.buffer)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызвов конструктора OctString::Oct(const OctString&) : MyString(const char[])\n";
#endif
};

OctString::OctString(const char _[]) : MyString(_)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов конструктора OctString::Oct(const char[]) : MyString(const char[])\n";
#endif
    if (!OctString::isValidOctString(this->buffer))
    {
        std::cerr << "[ERR] аргумент не является валидным восьмиричным числом.\n";
        this->len = 0;
        delete this->buffer;
        this->buffer = new char[2];
        this->buffer[0] = '0';
        this->buffer[1] = '\0';
        this->positive = true;
    }
    if (buffer[0] == '-')
        positive = false;
    else
        positive = true;
};

OctString::OctString(const char _) : MyString(_)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов конструктора OctString::Oct(const char) : MyString(const char)\n";
#endif
    if (!OctString::isValidOctString(this->buffer))
    {
        std::cerr << "[ERR] аргумент не является валидным восьмиричным числом.\n";
        this->len = 0;
        delete this->buffer;
        this->buffer = new char[2];
        this->buffer[0] = '0';
        this->buffer[1] = '\0';
        this->positive = true;
        return;
    }
    // One char string can't be negative
    positive = true;
};

OctString::~OctString()
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов деструктора OctString::~OctString()\n";
#endif
};

void OctString::operator=(MyString rval)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов оператора OctString::operator=(MyString)\n";
#endif
    char *rvalBuffer = rval.getRawData();
    if (!OctString::isValidOctString(rvalBuffer))
    {
        std::cerr << "[ERR] rvalue не является валидным восьмиричным числом.\n";
        this->len = 0;
        delete this->buffer;
        this->buffer = new char[2];
        this->buffer[0] = '0';
        this->buffer[1] = '\0';
        this->positive = true;
        return;
    }
    // lvalue уже мог быть проинициализирован, поэтому сначала освобождаем его буфер сперва
    if (buffer != nullptr)
        delete buffer;
    len = rval.getLength();
    // buffer = new char[len + 1];
    buffer = new char[len];
    for (size_t i = 0; i < len; ++i)
        buffer[i] = rvalBuffer[i];
    buffer[len] = '\0';

    if (buffer[0] == '-')
        positive = false;
    else
        positive = true;
};

void OctString::operator=(OctString rval)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов оператора OctString::operator=(OctString)\n";
#endif
    char *rvalBuffer = rval.buffer;
    if (!OctString::isValidOctString(rvalBuffer))
    {
        std::cerr << "[ERR] rvalue не является валидным восьмиричным числом.\n";
        this->len = 0;
        delete this->buffer;
        this->buffer = new char[2];
        this->buffer[0] = '0';
        this->buffer[1] = '\0';
        this->positive = true;
        return;
    }
    // lvalue уже мог быть проинициализирован, поэтому сначала освобождаем его буфер сперва
    if (buffer != nullptr)
        delete buffer;
    len = rval.getLength();
    // buffer = new char[len + 1];
    buffer = new char[len];
    for (size_t i = 0; i < len; ++i)
        buffer[i] = rvalBuffer[i];
    buffer[len] = '\0';
    positive = rval.positive;
};

void OctString::operator=(const char rval[])
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов оператора OctString::operator=(const char[])\n";
#endif
    if (!OctString::isValidOctString(rval))
    {
        std::cerr << "[ERR] rvalue не является валидным восьмиричным числом.\n";
        this->len = 0;
        delete this->buffer;
        this->buffer = new char[2];
        this->buffer[0] = '0';
        this->buffer[1] = '\0';
        this->positive = true;
        return;
    }
    // lvalue уже мог быть проинициализирован, поэтому сначала освобождаем его буфер сперва
    if (buffer != nullptr)
        delete buffer;
    len = strlen(rval);
    // buffer = new char[len + 1];
    buffer = new char[len];
    for (size_t i = 0; i < len; ++i)
        buffer[i] = rval[i];
    buffer[len] = '\0';

    if (buffer[0] == '-')
        positive = false;
    else
        positive = true;
};

OctString OctString::operator+(const OctString rval)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов оператора OctString::operator+(const OctString)\n";
#endif
    // Складывает 2 восьмеричных числа по правилам сложения
    return Add_Oct(*this, rval);
};

OctString OctString::Add_Oct(const OctString &a, const OctString &b)
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов метода OctString::Add_Oct(const OctString&, const OctString&)\n";
#endif
    using std::stoi;
    using std::string;

    long l, r, ans;

    l = stoi(a.buffer, 0, 8);
    r = stoi(b.buffer, 0, 8);
    ans = l + r;
    bool is_negative = false;

    std::stringstream anss;
    if (ans < 0)
    {
        ans = -ans;
        is_negative = true;
    }
    anss << std::oct << ans;
    const char *ans_cstr = anss.str().c_str();
    char *answer;
    if (is_negative)
    {
        answer = new char[strlen(ans_cstr) + 1];
        answer[0] = '-';
        strcat(answer, ans_cstr);
    }
    else
    {
        answer = new char[strlen(ans_cstr)];
        strcpy(answer, ans_cstr);
    }
    return OctString(answer);
}

bool OctString::ConvertableToUnsignedLong()
{
#ifdef __LOG_METHODS_CALLS__
    std::cout << "Вызов метода OctString::ConvertableToUnsignedLong()\n";
#endif

    unsigned long ul;
    try
    {
        ul = strtoul(this->buffer, nullptr, 8);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument: " << e.what() << '\n';
        return false;
    }
    if (ul == ULONG_MAX && len > 22)
    {
        std::cout << "Octal string " << this->buffer << " can not be converted to unsigned long.\n";
        return false;
    }
    else
    {
        std::cout << "Octal string " << this->buffer << " can be converted to unsigned long.\n\tul decimal: " << ul << '\n';
        return true;
    }
}
