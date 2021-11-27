#pragma once
#include <iostream>
#include <string>
#include <vector>

class Instruction {
public:
	virtual void execute(std::string& text, std::vector<std::string> args) = 0;
};

class Readfile : public Instruction {
	void execute(std::string& text, std::vector<std::string> args) override;
};

class Writefile : public Instruction {
	void execute(std::string& text, std::vector<std::string> args) override;
};

class Grep : public Instruction {
	void execute(std::string& text, std::vector<std::string> args) override;
};

class Sort : public Instruction {
	void execute(std::string& text, std::vector<std::string> args) override;
};

class Replace : public Instruction {
	void execute(std::string& text, std::vector<std::string> args) override;
};

class Dump : public Instruction {
	void execute(std::string& text, std::vector<std::string> args) override;
};