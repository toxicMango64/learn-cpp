#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <map>
# include <cstdlib>
# include <sstream>
# include <iomanip>
# include <limits>

# define DATA_FILE "data.csv"

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &data);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();
		void feed(const std::string &data);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		void convertToValues(const std::string &input_file) const;
		class CantOpenFileException;
	private:
		//compare_dates 
		double	getClosestPriceAtDate(const std::string &date) const;
		//the default comparator std::less<std::string> is perfect because the date format yyyy-mm-dd is lexographically ordered
		std::map<std::string, double, std::less<std::string> > _price_history;
};

class BitcoinExchange::CantOpenFileException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

#endif
