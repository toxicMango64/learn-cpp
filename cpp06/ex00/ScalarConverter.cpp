// Copyright [2025] myousaf
#include "ScalarConverter.hpp"

static void printCharImpossible() {
    std::cout << "char: impossible" << std::endl;
}

static void printCharNonDisplayable() {
    std::cout << "char: non-displayable" << std::endl;
}

static void charConvert(std::string param) {
    std::cout << "char: " << param[0] << std::endl;
    std::cout << "int: " << static_cast<int>(param[0]) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << \
        static_cast<float>(param[0]) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << \
        static_cast<double>(param[0]) << std::endl;
}

static void intConvert(std::string param) {
    int n = std::strtol(param.c_str(), NULL, 10);

    if (n < 0 || n > 127)
        printCharImpossible();
    else if (n < 32 || n == 127)
        printCharNonDisplayable();
    else
        std::cout << "char: " << static_cast<char>(n) << std::endl;
    std::cout << "int: " << n << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << \
        static_cast<float>(n) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << \
        static_cast<double>(n) << std::endl;
}

static void floatConvert(std::string param) {
    float n = std::strtof(param.c_str(), NULL);

    if (n < 0 || n > 127)
        printCharImpossible();
    else if (n < 32 || n == 127)
        printCharNonDisplayable();
    else
        std::cout << "char: " << static_cast<char>(n) << std::endl;
    std::cout << "int: " << static_cast<int>(n) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(2) << \
        n << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(2) << \
        static_cast<double>(n) << std::endl;
}

static void doubleConvert(std::string param) {
    double n = std::strtod(param.c_str(), NULL);

    if (n < 0 || n > 127)
        printCharImpossible();
    else if (n < 32 || n == 127)
        printCharNonDisplayable();
    else
        std::cout << "char: " << static_cast<char>(n) << std::endl;
    std::cout << "int: " << static_cast<int>(n) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(2) << \
        static_cast<float>(n) << "f" << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(2) << \
        n << std::endl;
}

static void minInfConvert() {
    printCharImpossible();
    std::cout << "int: " << INT_MIN << std::endl;
    std::cout << "float: " << __FLT_MIN__ << std::endl;
    std::cout << "double: " << __DBL_MIN__ << std::endl;
}

static void maxInfConvert() {
    printCharImpossible();
    std::cout << "int: " << INT_MAX << std::endl;
    std::cout << "float: " << __FLT_MAX__ << std::endl;
    std::cout << "double: " << __DBL_MAX__ << std::endl;
}

static void nanConvert() {
    printCharImpossible();
    std::cout << "int: " << 0 << std::endl;
    std::cout << "float: " << 0 << std::endl;
    std::cout << "double: " << 0 << std::endl;
}

static void error() {
    printCharImpossible();
    std::cout << "int: " << 0 << std::endl;
    std::cout << "float: " << 0 << std::endl;
    std::cout << "double: " << 0 << std::endl;
}

static void checkInput(std::string param) {
    if (std::isprint(param[0]) && !std::isdigit(param[0])) {
        if (param.length() == 1)
            charConvert(param);
        else if (param == "-inf" || param == "-inff")
            minInfConvert();
        else if (param == "+inf" || param == "+inff")
            maxInfConvert();
        else if (param == "nan" || param == "nanf")
            nanConvert();
        else
            error();
    } else if (param[param.length() - 1] == 'f') {
        // long unsigned int i = 0;
        int64_t i = 0;
        while (static_cast<size_t>(i) < param.length() - 1 && (std::isdigit(param[i]) || \
            param[i] == '.'))
            i++;
        if (static_cast<size_t>(i) == param.length() - 1)
            floatConvert(param);
        else
            error();
    } else if (param.find('.') != std::string::npos) {
        // long unsigned int i = 0;
        int64_t i = 0;
        while (static_cast<size_t>(i) < param.length() && (std::isdigit(param[i]) || param[i] == '.'))
            i++;
        (static_cast<size_t>(i) == param.length()) ? doubleConvert(param) : error();
    } else if (std::isdigit(param[0])) {
        // long unsigned int i = 0;
        int64_t i = 0;
        while (static_cast<size_t>(i) < param.length() && std::isdigit(param[i]))
            i++;
        if (static_cast<size_t>(i) == param.length())
            intConvert(param);
        else
            error();
    } else {
        error();
    }
}

void ScalarConverter::convert(std::string param) {
    checkInput(param);
}
