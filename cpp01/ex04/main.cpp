#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;
using std::ofstream;

void	getNewLine(string &line, string s1, string s2) {
	size_t	startPos = 0;

	while ((startPos = line.find(s1, startPos)) != string::npos) {
		line = line.substr(0, startPos) + s2 + line.substr(startPos + s1.length());
		startPos += s2.length();
	}
}

void FileReplacer(string filename, string s1, string s2) {
	string  line;
	string  out_file = filename + ".replace";

	ifstream	input(filename.c_str());
	
	if (!input.is_open()) {
		cout << "Error: cannot open file." << "\n";
	}
	else {
		ofstream output(out_file.c_str());
		while (std::getline(input, line)) {
			getNewLine(line, s1, s2);
			output << line;
			if (!input.eof())
				output << "\n";
		}
		input.close();
		output.close();
	}
}

int main(int argc, char* argv[]) {
	try {
		if (argc < 4) {
			string errorMessage;
			if (argc < 2) {
				errorMessage += "Error: Filename is required.\n";
			}
			else if (argc < 3) {
				errorMessage += "Error: String 1 is required.\n";
			}
			else {
				errorMessage += "Error: String 2 is required.\n";
			}
			throw std::runtime_error(errorMessage);
		}
		FileReplacer(argv[1], argv[2], argv[3]);
		return (0);
	} catch (const std::exception &e) {
		cerr << e.what();
		cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << "\n";
		return (1);
	}
	return (0);
}