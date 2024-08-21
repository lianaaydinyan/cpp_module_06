#ifndef _Converter_
#define _Converter_

#include <iostream>
#include <cstring>
#include <limits>
#include <cstdlib>
#include <string>
#include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const& copy);
        ScalarConverter& operator=(ScalarConverter const& copy);
        ~ScalarConverter();
    public:
        static void convert(const std::string& type);
};
// checking  "nanf", "nan", "-inff", "-inf", "inff", "inf", "+inff", "+inf"
bool literal_verification(const std::string& literal);
// check the type
bool _char(const std::string& str);
bool _int(const std::string& str);
bool _float(const std::string& str);
bool _double(const std::string& str);
// print depened the type 
void for_char(const std::string& literal);
void for_int(const std::string& literal);
void for_float(const std::string& literal);
void for_double(const std::string& literal);
// check the anges
bool isWithinRangeDouble(long long value);
bool isWithinRangeInt(long long value);
bool isWithinRangeDouble(long long value);

#endif