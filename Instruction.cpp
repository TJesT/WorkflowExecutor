#include "Instruction.h"

#include <map>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

void Readfile::execute(std::string& text, std::vector<std::string> args) {
	if (args.empty()) { throw std::length_error("Not enough arguments for Readfile"); }

	std::ifstream input(args[0]);

	if (!input.is_open()) { throw std::invalid_argument("Wrong file name"); }

    std::string data = "";
    std::string line;

    while (std::getline(input, line)) {
        data += line + "\n";
    }

    input.close();

    text = data;
};

void Writefile::execute(std::string& text, std::vector<std::string> args) {
    if (args.empty()) { throw std::length_error("Not enough arguments for Writefile"); }
    
    std::ofstream output(args[0]);

    if (!output.is_open()) {
        throw std::invalid_argument("Cannot open file");
    }

    output << text;
    output.close();
};

void Grep::execute(std::string& text, std::vector<std::string> args) {
    if (args.empty()) { throw std::length_error("Not enough arguments for Grep"); }

    std::string word = args[0];
    if (word.empty()) { throw std::invalid_argument("Cant find empty word"); }

    std::stringstream ss(text);
    std::string line;
    std::vector<std::string> picked = std::vector<std::string>();
    
    while (std::getline(ss, line)) {
        if (line.find(word) != std::string::npos) { picked.push_back(line); }
    }
    
    text = "";
    
    for (std::string line : picked) {
        text += line + '\n';
    }
};

void Sort::execute(std::string& text, std::vector<std::string> args) {
    std::map<std::string, size_t> count;

    std::stringstream ss(text);
    std::string line;
    while (ss >> line) {
        if (count.find(line) == count.end()) {
            count[line] = 0;
        } else {
            ++count[line];
        }
    }

    count[line] += 1;

    text = "";

    for (std::map<std::string, size_t>::iterator p = count.begin(); p != count.end(); ++p) {
        for (size_t i = 0; i + 1 < p->second; ++i) {
            text += p->first + " ";
        }
        text += p->first;

        if (p != --count.end()) {
            text += " ";
        }
    }
};

void Replace::execute(std::string& text, std::vector<std::string> args) {
    if (args.size() < 2) { throw std::length_error("Not enough arguments for Replace"); }

    std::string w1 = args[0], w2 = args[1];

    std::stringstream ss(text);
    text = "";
    
    for (std::string line; getline(ss, line);) {
        size_t pos = 0;
        while ((pos = line.find(w1, pos)) != std::string::npos) {
            line.replace(pos, w1.length(), w2);
            pos += w2.length();
        }
        text += line + '\n';
    }
};

void Dump::execute(std::string& text, std::vector<std::string> args) {
    if (args.empty()) { throw std::length_error("Not enough arguments for Dump"); }

    std::ofstream output(args[0]);

    if (!output.is_open()) {
        throw std::invalid_argument("Cannot open file");
    }

    output << text;
    output.close();
};

