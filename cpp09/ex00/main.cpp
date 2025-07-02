#include "BitcoinExchange.hpp"

static int8_t	check_args(int argc, char **argv);

int main(int argc, char **argv)
{
	try
	{
		if (check_args(argc, argv) == 1) {
			return 1;
		}
		const BitcoinExchange exchange(DATA_FILE);
		exchange.convertToValues(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

static int8_t	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input_file>\n";
		return 1;
	}
	if (std::string(argv[1]).find(".csv") == std::string::npos)
	{
		std::cerr << "Error: input file must be a .csv file\n";
		return 1;
	}
	return 0;
}
