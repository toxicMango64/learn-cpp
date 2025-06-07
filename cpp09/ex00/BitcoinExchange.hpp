#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

# define DATA_FILE	"data.csv"

enum file_type {
    DATABASE,
    INPUT
};

class BitcoinExchange {
private:
    std::map<std::string, float> _database;
    
    BitcoinExchange(BitcoinExchange const &src) = delete;
    BitcoinExchange &operator=(BitcoinExchange const &src) = delete;
    
    std::string min_date;
    std::string max_date;
    
    // Helper functions for data validation and processing
    bool checkHeader(std::string line, file_type type);
    bool checkDate(std::string date, file_type type);
    bool checkValue(std::string value, file_type type);
    void loadDatabase(void);    
    void _btc(std::string date, float value);
    void checkLine(std::string line, file_type type);
    void trimCell(std::string &cell);

public:
    BitcoinExchange(void);
    ~BitcoinExchange(void);

    void readInput(std::string filename);

    // Exception classes for various error conditions

    class DatabaseLoadException : public std::exception {
        private:
            std::string _error_message;
        public:
            DatabaseLoadException(std::string error_message);
            virtual ~DatabaseLoadException(void) throw() {};
        virtual const char *what() const throw();
    };
    class DatabaseNotFoundException : public std::exception {
        virtual const char *what() const throw();
    };
    class BadDatabaseFormatException : public std::exception {
        virtual const char *what() const throw();
    };
    class BadDatabaseDataException : public std::exception {
        virtual const char *what() const throw();
    };
    class InputNotFoundException : public std::exception {
        virtual const char *what() const throw();
    };
    class BadInputFormatException : public std::exception {
        virtual const char *what() const throw();
    };
    class BadInputDataException : public std::exception {
        public:
            BadInputDataException(std::string line);
            virtual ~BadInputDataException(void) throw() {};
        virtual const char *what() const throw();
        private:
            std::string _error_message;
    };
    class BadDateException : public std::exception {
        public:
            BadDateException(std::string date);
            virtual ~BadDateException(void) throw() {};
        virtual const char *what() const throw();
        private:
            std::string _error_message;
    };
    class NegativeValueException : public std::exception {
        virtual const char *what() const throw();
    };
    class TooLargeValueException : public std::exception {
        virtual const char *what() const throw();
    };
};

#endif
