#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	//construct
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void)copy;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{ 
	// destruct
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

bool literal_verification(const std::string& literal)
{
	bool dot = false;
	bool f = false;
	if (literal.length() == 0)
		return true;
	else if (literal == "nan" || literal == "nanf"
		|| literal == "inf" || literal == "-inf" || literal == "+inf"
		||	literal == "inff" || literal == "-inff" || literal == "+inff")
		return (true);

	if (literal.length() == 1 && std::isalpha(literal[0]) )
		return true; 
	else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
	{
		if (!std::isalpha(literal[1]))
			return true;
	}
	std::string str = literal;
	if (literal[0] == '-' || literal[0] == '+')
		str = literal.substr(1);
	size_t i = 0;
	if (!(std::isdigit(str[i])))
		return false;
	if ( (literal.find('.') == std::string::npos) && (literal.find('f') == std::string::npos))
	{
		for (; i < str.length() ; ++i)
		{
			if (!(std::isdigit(str[i])))
				return false;
		}
		if ((str.length() > 10))
		   throw std::runtime_error("More than int max\n"); 
		else
			return true;
	}
	i = 0;
	for (; i < str.length(); i++)
	{
		if (!std::isdigit(str[i])) 
		{
			if ((literal.find('.') != std::string::npos) && i != 0 && !dot) 
				dot = true;
			else if (str[i] == 'f' && dot && (i == str.length() - 1) && !f && std::isdigit(str[i - 1])) 
				f = true;
			else 
				break;
		}
	}
	if (i == str.length())
		return true;
	else
		return false;
}


int find_type(const std::string& str)
{
	if (isalpha(str[0]) && str.length() == 1)
		return CHAR;
	else if (str == "inf" || str == "-inf" || str == "+inf" ||	str == "inff" || str == "-inff" || str == "+inff")
		return (INF);
	else if (str == "nan" || str == "nanf")
		return (NANS);
	else if ((str.find('.') == std::string::npos) && (str.find('f') == std::string::npos))
	{
		if (isWithinRangeInt(std::atoi(str.c_str()))) 
			return INT;
	}
	else if (str.find('.') != std::string::npos)
	{
		if (str.find('f') != std::string::npos)
			return FLOAT;
		else
			return DOUBLE;
	}
	return -1;
}


void ScalarConverter::convert(const std::string& type)
{
	int detect_t = find_type(type);
	if (!literal_verification(type))
		throw std::runtime_error("Not valid argument");
	// std::cout << "type is -> " << detect_t << std::endl;
	if (detect_t == CHAR)
		for_char(type);
	else if (detect_t == INT)
		for_int(type);
	else if (detect_t == FLOAT)
		for_float(type);
	else if (detect_t == DOUBLE)
		for_double(type);
	else if (detect_t == INF)
		for_inf(type);
	else if (detect_t == NANS)
		for_nans(type);
	else
		throw std::runtime_error(" We support only valid int, char, float, double >_<"); 
}



void  for_nans(const std::string& type)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << "nanf" << std::endl;
	std::cout << "double: " << "nan" << std::endl;
}


void  for_inf(const std::string& type)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: ";

	if (type[0] == '-') 
		std::cout << "-";
	else if (type[0] == '+') 
		std::cout << "+";
	std::cout << "inff" << std::endl;

	std::cout << "double: ";
	if (type[0] == '-') 
		std::cout << "-";
	else if (type[0] == '+') 
		std::cout << "+";
	std::cout << "inf" << std::endl;

}

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

}


void for_int(const std::string& literal)
{
	long val = std::atoi(literal.c_str());
	std::cout << "char: ";
	if (!std::isprint(val))
		std::cout << "Non displayable" << std::endl;
	else if (val < 0 || val > 127)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << static_cast<char>(val) << "'" << std::endl;

	std::cout << "int: ";
	if (isWithinRangeInt(val))
		std::cout << static_cast<int>(val) << std::endl;
	else
		std::cout << "impossible" << std::endl;

	if(isWithinRangeFloat(val))
	{
		if (literal.find('.') == std::string::npos)
			std::cout << "float: " <<  static_cast<float>(val) << ".0f" << std::endl;
		else
		{

		}
			std::cout << "float: " << val << "f" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;

	if (isWithinRangeDouble(val))
	{
		if (literal.find('.') == std::string::npos)
			std::cout << "double: " <<  static_cast<float>(val) << ".0" << std::endl;
		else
			std::cout << "double: " << val << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

void for_float(const std::string& literal)
{
	float val = std::atof(literal.c_str());
	std::cout << "char: ";
	if (!std::isprint(val))
		std::cout << "Non displayable" << std::endl;
	else if (val < 0 || val > 127)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << static_cast<char>(val) << "'" << std::endl;

	std::cout << "int: ";
	if (isWithinRangeInt(val))
		std::cout << static_cast<int>(val) << std::endl;
	else
		std::cout << "impossible" << std::endl;

	if(isWithinRangeFloat(val))
	{
		if (literal.find('.') == std::string::npos)
			std::cout << std::fixed << std::setprecision(1) << "float: " <<  static_cast<float>(val) << ".0f" << std::endl;
		else
		{
			std::cout << std::fixed << std::setprecision(1) << "float: " << val << "f" << std::endl;
		}
	}
	else
		std::cout << "impossible" << std::endl;

	if (isWithinRangeDouble(val))
	{
		if (literal.find('.') == std::string::npos)
			std::cout << std::fixed << std::setprecision(1) << "double: " <<  static_cast<float>(val) << ".0" << std::endl;
		else
			std::cout << std::fixed << std::setprecision(1) << "double: " << val << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;

}

void for_double(const std::string& literal)
{
	double val = std::strtod(literal.c_str(), NULL);
	std::cout << "char: ";
	if (!std::isprint(val))
		std::cout << "Non displayable" << std::endl;
	else if (val < 0 || val > 127)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << static_cast<char>(val) << "'" << std::endl;

	std::cout << "int: ";
	if (isWithinRangeInt(val))
		std::cout << static_cast<int>(val) << std::endl;
	else
		std::cout << "impossible" << std::endl;

	if(isWithinRangeFloat(val))
	{
		if (literal.find('.') == std::string::npos)
			std::cout << std::fixed << std::setprecision(1) << "float: " <<  static_cast<float>(val) << ".0f" << std::endl;
		else
			std::cout << std::fixed << std::setprecision(1) << "float: " << val << "f" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;

	if (isWithinRangeDouble(val))
	{
		if (literal.find('.') == std::string::npos)
			std::cout << std::fixed << std::setprecision(1) << "double: " <<  static_cast<float>(val) << ".0" << std::endl;
		else
			std::cout << std::fixed << std::setprecision(1) << "double: " << val << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

