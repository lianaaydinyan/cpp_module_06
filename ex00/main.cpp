#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	std::string type;

	if (argv[1] && !argv[2])
	{
		type = argv[1];
		ScalarConverter::convert(type); 	
	}
	else
		std::cout << "No aguments provided or too many arguments ..." << std::endl;
	return (0);
}
