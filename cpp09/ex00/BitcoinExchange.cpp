#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _price_history() {}

BitcoinExchange::BitcoinExchange(const std::string &filename) : _price_history()
{
	feed(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _price_history(other._price_history) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other) {
		_price_history = other._price_history;
	}
	return *this;
}

void BitcoinExchange::feed(const std::string &filename)
{
	std::ifstream		file(filename.c_str());
	std::string			line;
	std::istringstream	iss;
	std::string			date;
	std::string			price;
	double				price_value = 0;

	if (file.is_open() == false) {
		throw CantOpenFileException();
	}
	while (std::getline(file, line))
	{
		date = line.substr(0, line.find(','));
		price = line.substr(line.find(',') + 1);
		iss.str(price);
		iss >> price_value;
		if (iss.fail() == true) {
			price_value = 0;
		}
		iss.clear();
		_price_history[date] = price_value;
	}
	file.close();
}

bool	check_line_validity(const std::string &line)
{
	if (line.empty() || line.find('|') == std::string::npos || line.find(' ') == std::string::npos)
	{
		std::cerr << "Error: bad input: '" << line << "'\n";
		return (false);
	}
	return (true);
}

bool	check_date_validity(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cerr << "Error: bad date format: '" << date << "'\n";
		return (false);
	}
	else if (date.substr(5, 2) > "12" || date.substr(8, 2) > "31")
	{
		std::cerr << "Error: bad date format: '" << date << "'\n";
		return (false);
	}
	return (true);
}

bool	check_amount_validity(double amount, std::string &amount_str, std::istringstream &iss)
{
	if (iss.fail() == true)
	{
		std::cout << "Error: not a number: '" << amount_str << "'\n";
		return (false);
	}
	if (amount < 0)
	{
		std::cout << "Error: not a positive number: '" << amount_str << "'\n";
		return (false);
	}
	if (amount >= std::numeric_limits<int>::max())
	{
		std::cout << "Error: number too large: '" << amount_str << "'\n";
		return (false);
	}
	return (true);
}

double BitcoinExchange::getClosestPriceAtDate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it;

	it = _price_history.find(date);
	if (it != _price_history.end()) { /** found the exact date */
		return it->second;
	}
	it = _price_history.lower_bound(date); /** take the first element that's not less than date */
	if (it == _price_history.begin()) { /** date is before the first date in the csv */
		return (0);
	}
	return (--it)->second; /** returns the price just before the date found */
}

const char *BitcoinExchange::CantOpenFileException::what() const throw() {
	return "Error: can't open file";
}

void BitcoinExchange::convertToValues(const std::string &input_file) const
{
	std::ifstream		file(input_file.c_str());
	std::istringstream	iss;
	std::string			line;
	std::string			date;
	std::string			amount_str;
	double				amount = 0;
	double				transaction_value = 0;

	if (file.is_open() == false) {
		throw CantOpenFileException();
	}
	while (std::getline(file, line) && !line.empty())
	{
		if (check_line_validity(line) == false) {
			continue ;
		}
		date = line.substr(0, line.find(' '));
		if (check_date_validity(date) == false) {
			continue ;
		}
		amount_str = line.substr(line.find('|') + 1);
		iss.clear();
		iss.str(amount_str);
		iss >> amount;
		if (check_amount_validity(amount, amount_str, iss) == false) {
			continue ;
		}
		std::cout << std::setprecision(2) << std::fixed;
		transaction_value = amount * getClosestPriceAtDate(date);
		std::cout << date << ": " << transaction_value << "\n";
	}
	file.close();
}
