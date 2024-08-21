#include "ScalarConverter.hpp"


// "nanf" -> Represents "not a number" for the float data type
// "nan" -> Represents "not a number" for the double data type
// "-inff" -> Represents negative infinity for the float data type
// "-inf" -> Represents negative infinity for the double data type
// "inff" -> This is not a valid representation of a floating-point value
// "inf" -> Represents positive infinity for the double data type
// "+inff" -> Represents positive infinity for the float data type
// "+inf" -> Represents positive infinity for the double data type


bool literal_verification(const std::string& literal)
{
    if (literal == "nanf" || literal == "nan") 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return true;
    }
    else if (literal == "-inff" || literal == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return true;
    }
    else if (literal == "inff" || literal == "inf" || literal == "+inff" || literal == "+inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
        return true;
    }
    return false;   
}

ScalarConverter::ScalarConverter()
{
    //construct
}

ScalarConverter::ScalarConverter(ScalarConverter const& copy)
{
    *this = copy;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& copy)
{
    return (*this);
}

ScalarConverter::~ScalarConverter()
{ 
    // destruct
}

void ScalarConverter::convert(const std::string& type)
{
    if (literal_verification(type))
        return;
    if (_char(type))
        for_char(type);
    else if (_int(type))
        for_int(type);
    else if (_double(type))
        for_double(type);
    else if (_float(type))
        for_float(type);
}


bool _char(const std::string& str)
{
    if (isalpha(str[0]) && str.length() == 1)
        return true;
    return false;
}

bool _int(const std::string& str)
{
    int i;
    long int num;

    i = 0;
    if (str.length() > 0 && (str[0] == '-' || str[0] == '+'))
        i++;
    for (; i < str.size(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    num = std::atol(str.c_str());
    if (num <= std::numeric_limits<int>::max() && num >= std::numeric_limits<int>::min())
        return (true);
    else
        return (false);
}

bool _float(const std::string& str)
{
    int i = 0;
    bool has_decimal = false;

    if (str.length() > 0 && (str[0] == '-' || str[0] == '+'))
        i++;
    for (; i < str.length(); i++)
    {
        if (str[i] == '.') {
            if (has_decimal)
                return false;
            has_decimal = true;
        }
        else if (!std::isdigit(str[i]))
        {
            if ((str[i] == 'f' || str[i] == 'F') && i == str.length() - 1 && has_decimal)
                return true;
            return false;
        }
    }
    return has_decimal;
}

bool _double(const std::string& str)
{
    int i = 0;
    int dot_count = 0;
    bool has_exponent = false;

    if (str.length() > 0 && (str[0] == '-' || str[0] == '+'))
        i++;
    for (; i < str.length(); i++)
    {
        if (str[i] == '.') {
            dot_count++;
            if (dot_count > 1)
                return false;
        }
        else if (str[i] == 'e' || str[i] == 'E')
        {
            if (has_exponent)
                return false;
            has_exponent = true;
            if (i == str.length() - 1 || (!std::isdigit(str[i + 1]) && str[i + 1] != '+' && str[i + 1] != '-'))
                return false;
        }
        else if (str[i] == '+' || str[i] == '-')
        {
            if (i > 0 && (str[i - 1] != 'e' && str[i - 1] != 'E'))
                return false;
        }
        else if (str[i] == 'D' || str[i] == 'd')
        {
            if (dot_count == 1 && i == str.length() - 1)
                return true;
            return false;
        }
        else if (!std::isdigit(str[i]))
            return false;
    }
    return ((dot_count == 1 )|| has_exponent);
}


// void  cast_imposible()
// {
//     std::cout << "char: impossible" << std::endl;
//     std::cout << "int: impossible" << std::endl;
//     std::cout << "float: impossible" << std::endl;
//     std::cout << "double: impossible" << std::endl;   
// }

void for_char(const std::string& literal)
{
    char c;

    c = literal[0];
    if (literal.length() == 1)
    {
        std::cout << "char: " << "'" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;     
    }
}

bool isWithinRangeInt(long long value)
{
    return (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max());
}

bool isWithinRangeFloat(long long value)
{
    return (std::abs(static_cast<float>(value)) <= std::numeric_limits<float>::max());
}

bool isWithinRangeDouble(long long value)
{
    return (std::abs(static_cast<double>(value)) <= std::numeric_limits<double>::max());
}


void for_int(const std::string& literal)
{
    long long i = std::atoll(literal.c_str());
    std::cout << "char: ";
    if ((i >= 0 && i < 32) || (i == 127))
        std::cout << "Non displayable" << std::endl;
    else if (i < 0 || i > 127)
        std::cout << "impossible" << std::endl;
    else
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;

    std::cout << "int: ";
    if (isWithinRangeInt(i))
        std::cout << static_cast<int>(i) << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "float: ";
    if (isWithinRangeFloat(i))
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "double: ";
    if (isWithinRangeDouble(i))
        std::cout << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
    else
        std::cout << "impossible" << std::endl;
}

void for_float(const std::string& literal)
{
    
    if (literal_verification(literal) == true) { return; }
    double d = std::atof(literal.c_str());
    std::cout << "char: ";
    if ((d >= 0 && d < 32) || d == 127)
        std::cout << "Non displayable" << std::endl;
    else if (d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

    std::cout << "int: ";
    if (isWithinRangeInt(d))
        std::cout << static_cast<int>(d) << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "float: ";
    if (isWithinRangeFloat(d))
    {
        if (static_cast<float>(d) == static_cast<int>(d))
            std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
        else
            std::cout << static_cast<float>(d) << "f" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;

    std::cout << "double: ";
    if (isWithinRangeDouble(d))
        std::cout << d << std::endl;
    else
        std::cout << "impossible" << std::endl;
}

void for_double(const std::string& literal)
{
    if (literal_verification(literal) == true) {return ;}
    float f_value = std::strtof(literal.c_str(), nullptr);
    std::cout << "char: ";
    if ((f_value >= 0 && f_value < 32 ) || f_value == 127)
        std::cout << "Non displayable" << std::endl;
    else if (f_value < 0 || f_value > 127)
        std::cout << "impossible" << std::endl;
    else
        std::cout << "'" << static_cast<char>(f_value) << "'" << std::endl;

    std::cout << "int: ";
    if (isWithinRangeInt(f_value))
        std::cout << static_cast<int>(f_value) << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "float: ";
    if (isWithinRangeFloat(f_value))
    {
        if (static_cast<float>(f_value) == static_cast<int>(f_value))
            std::cout << std::fixed << std::setprecision(1) << f_value << "f" << std::endl;
        else
            std::cout << f_value << "f" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;

    std::cout << "double: ";
    if (isWithinRangeDouble(f_value))
        std::cout << static_cast<double>(f_value) << std::endl;
    else
        std::cout << "impossible" << std::endl;
}