#include <string>

class Dec2Fact
{
public:
  static std::string dec2FactString(long long number);
  static long long factString2Dec(const std::string &str);
private:
  static std::string digit2Alnum(long long digit);
  static long long alnum2Digit(char alnumDigit);
};

std::string Dec2Fact::digit2Alnum(long long digit) {
    if (digit < 10)
        return std::string(1, '0' + digit);
    else
        return std::string(1, 'A' + (digit - 10));
}

long long Dec2Fact::alnum2Digit(char alnumDigit) {
    if (alnumDigit <= '9')
        return alnumDigit - '0';
    else
        return alnumDigit - 'A' + 10;
}

std::string Dec2Fact::dec2FactString(long long number) {
    long long fac = 1;
    long long place = 1;
    while (place <= 20 && fac * place <= number) {
        fac *= place;
        ++place;
    }
    std::string result;
    while (place > 0) {
        result.append(digit2Alnum(number / fac));
        number %= fac;
        --place;
        if (place)
            fac /= place;
    }
    return result;
}

long long Dec2Fact::factString2Dec(const std::string &str) {
    long long fac = 1;
    long long place = 1;
    long long number = 0;
    for (auto iterator = str.crbegin(); iterator != str.crend(); ++iterator) {
        char alnumDigit = *iterator;
        number += fac * alnum2Digit(alnumDigit);
        fac *= place;
        ++place;
    }
    return number;
}