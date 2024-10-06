#ifndef _Converter_
#define _Converter_

#include <iostream>
#include <cstring>
#include <limits>
#include <cstdlib>
#include <string>
#include <iomanip>




#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define INF 4
#define NANS 5
class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& copy);
        ~ScalarConverter();
    public:
        static void convert(const std::string& type);
};

bool literal_verification(const std::string& literal);

bool validator_char(const std::string& str);
bool validator_int(const std::string& str);
bool validator_float(const std::string& str);
bool validator_double(const std::string& str);

void for_char(const std::string& literal);
void for_int(const std::string& literal);
void for_float(const std::string& literal);
void for_double(const std::string& literal);
void  for_nans(const std::string& type);
void  for_inf(const std::string& type);

bool isWithinRangeDouble(long long value);
bool isWithinRangeInt(long long value);
bool isWithinRangeDouble(long long value);

// "nanf" -> Represents "not a number" for the float data type
// "nan" -> Represents "not a number" for the double data type
// "-inff" -> Represents negative infinity for the float data type
// "-inf" -> Represents negative infinity for the double data type
// "inff" -> This is not a valid representation of a floating-point value
// "inf" -> Represents positive infinity for the double data type
// "+inff" -> Represents positive infinity for the float data type
// "+inf" -> Represents positive infinity for the double data type


#endif