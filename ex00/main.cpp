#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	std::string type;
	(void)argc;
	if (argv[1] && !argv[2])
	{
		type = argv[1];
		try
		{
			ScalarConverter::convert(type); 	
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	else
		std::cout << "No aguments provided or too many arguments ..." << std::endl;
	return (0);
}
