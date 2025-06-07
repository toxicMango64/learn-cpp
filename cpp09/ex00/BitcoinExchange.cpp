#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) : _database() {
    try {
        loadDatabase();
    } catch (std::exception &e) {
        throw DatabaseLoadException(e.what());
    }
    min_date = _database.begin()->first;
    max_date = _database.rbegin()->first;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _database(src._database), min_date(src.min_date), max_date(src.max_date) {}

// Destructor
BitcoinExchange::~BitcoinExchange(void) {}

/**
 * Copy assignment operator
 * Checks for self-assignment
 */
 BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src) {
    if (this != &src) {
        _database = src._database;
        min_date = src.min_date;
        max_date = src.max_date;
    }
    return (*this);
}

std::pair<std::string, double> BitcoinExchange::parseLine(std::string line, char delimiter) {
    std::string date = line.substr(0, line.find(delimiter));
    std::string value = line.substr(line.find(delimiter) + 1);
    double fvalue = std::atof(value.c_str());
    return std::make_pair(date, fvalue);
}

void BitcoinExchange::loadDatabase(void) {
    std::ifstream file(DATA_FILE);
    std::string line;

    if (!file.is_open()) {
        throw DatabaseNotFoundException();
    }

    std::getline(file, line);
    if (!checkHeader(line, DATABASE)) {
        throw BadDatabaseFormatException();
    }

    while (std::getline(file, line)) {
        try {
            checkLine(line, DATABASE);
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
            throw BadDatabaseFormatException();
        }
        std::pair<std::string, double> parsed = parseLine(line, ',');
        _database[parsed.first] = parsed.second;
    }
    file.close();
}

void BitcoinExchange::readInput(std::string filename) {    
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file.is_open())
        throw InputNotFoundException();
    std::getline(file, line);
    if (!checkHeader(line, INPUT))
        throw BadInputFormatException();
    while (std::getline(file, line)) {
        try {
            checkLine(line, INPUT);
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
            continue ;
        }
        std::pair<std::string, double> parsed = parseLine(line, '|');
        _btc(parsed.first, parsed.second);
    }
}

void BitcoinExchange::_btc(std::string date, float value) {
    std::map<std::string, float>::iterator it = _database.find(date);
    std::string last_date;
    float last_value;

    if (it != _database.end()) {
        std::cout << date << " => " << value << " = " << value * it->second << "\n";
        return;
    }

    for (it = _database.begin(); it != _database.end(); ++it) {
        if (it->first > date) {
            break;
        }
        last_date = it->first;
        last_value = it->second;
    }
    std::cout << date << " => " << value << " = " << value * last_value << "\n";
}

bool BitcoinExchange::checkHeader(std::string header, file_type type) {
    char delimiter = (type == DATABASE) ? ',' : '|';
    std::string column1 = "date";
    std::string column2 = (type == DATABASE) ? "exchange_rate" : "value";

    if (std::count(header.begin(), header.end(), delimiter) != 1) {
        return (false);
    }

    std::string header1 = header.substr(0, header.find(delimiter));
    std::string header2 = header.substr(header.find(delimiter) + 1);
    trimCell(header1);
    trimCell(header2);
    trimCell(column1);
    trimCell(column2);

    return (header1 == column1 && header2 == column2);
}

void BitcoinExchange::checkLine(std::string line, file_type type) {
    char delimiter = (type == DATABASE) ? ',' : '|';
    int delimiter_count = std::count(line.begin(), line.end(), delimiter);

    if (delimiter_count != 1) {
        throw BadInputDataException(line);
    }

    std::string date = line.substr(0, line.find(delimiter));
    std::string value = line.substr(line.find(delimiter) + 1);

    trimCell(date);
    trimCell(value);

    if (date.empty() || value.empty()) {
        throw BadInputDataException(line);
    } else if (!checkDate(date, type)) {
        throw BadDateException(date);
    } else if (!checkValue(value, type)) {
        if (std::atof(value.c_str()) < 0) {
            throw NegativeValueException();
        } else if (std::atof(value.c_str()) > 1000) {
            throw TooLargeValueException();
        } else {
            throw BadInputDataException(line);
        }
    }
}

bool BitcoinExchange::checkDate(std::string date, file_type type) {
    if (date.length() != 10) {
        return (false);
    }
    for (int i = 0; i < 10; ++i) {
        if ((i == 4 || i == 7) && date[i] != '-') {
            return (false);
        } else if (!std::isdigit(date[i])) {
            return (false);
        }
    }
    if (type == INPUT && date < min_date) {
        return (false);
    }

    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12) {
        return (false);
    }
    if ((month == 2 && day > 29) || 
        ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) ||
        day > 31) {
        return (false);
    }
    return (true);
}

bool BitcoinExchange::checkValue(std::string value, file_type type) {
    bool dot = false;

    for (size_t i = 0; i < value.length(); ++i) {
        if (value[i] == '.') {
            if (dot) return (false);
            dot = true;
        } else if (!std::isdigit(value[i])) {
            return (false);
        }
    }
    float floatValue = std::atof(value.c_str());
    if (type == INPUT) {
        if (floatValue < 0 || floatValue > 1000) {
            return (false);
        }
    }
    return (true);
}

void BitcoinExchange::trimCell(std::string &cell) {
    size_t start = cell.find_first_not_of(" \t");
    size_t end = cell.find_last_not_of(" \t");
    if (start == std::string::npos) {
        cell = "";
    } else {
        cell = cell.substr(start, end - start + 1);
    }
}

BitcoinExchange::DatabaseLoadException::DatabaseLoadException(std::string error_message) : _error_message(error_message) {
    return ;
}
const char *BitcoinExchange::DatabaseLoadException::what() const throw() {
    return (_error_message.c_str());
}

const char *BitcoinExchange::DatabaseNotFoundException::what() const throw() {
    return ("Database file not found. Please ensure there is a `data.csv` file.");
}

const char *BitcoinExchange::BadDatabaseFormatException::what() const throw() {
    return ("Bad format in Database file. Ensure the file follows the `date,exchange_rate` format.");
}

const char *BitcoinExchange::BadDatabaseDataException::what() const throw() {
    return ("Bad data in Database file. Please ensure the database is correctly filled.");
}

const char *BitcoinExchange::InputNotFoundException::what() const throw() {
    return ("Input file not found. Please ensure the input file exists and has proper permissions.");
}

const char *BitcoinExchange::BadInputFormatException::what() const throw() {
    return ("Bad format in Input file. Ensure the input file follows the `date|value` format.");
}

BitcoinExchange::BadInputDataException::BadInputDataException(std::string line)
    : _error_message("Bad input data => " + line) {}

const char *BitcoinExchange::BadInputDataException::what() const throw() {
    return (_error_message.c_str());
}

BitcoinExchange::BadDateException::BadDateException(std::string date)
    : _error_message("Invalid date => " + date) {}

const char *BitcoinExchange::BadDateException::what() const throw() {
    return (_error_message.c_str());
}

const char *BitcoinExchange::NegativeValueException::what() const throw() {
    return ("Negative value encountered. Values must be positive.");
}

const char *BitcoinExchange::TooLargeValueException::what() const throw() {
    return ("Value is too large. It should not exceed 1000.");
}
