#pragma once
#include "Instruction.h"
#include <string>
#include <map>
#include <functional>

using namespace std;

template <typename Mutation>
Instruction* InstructionBuilder() { static Mutation* m = new Mutation(); return m; }

class InstructionFactory {
public:
	typedef function<Instruction*()> Builder;

	static InstructionFactory* getInstance() {
		if (_instance == nullptr) { _instance = new InstructionFactory(); }
		return _instance;
	}

	bool Register(string const& key, Builder const& builder) {
		return this->_map.insert(std::make_pair(key, builder())).second;
	}
	
	Instruction* Build(std::string const& key) const {
		auto it = _map.find(key);
		if (it == _map.end()) { return nullptr; }
		return it->second;
	}
private:
	InstructionFactory() {
		this->Register("readfile",  InstructionBuilder<Readfile>);
		this->Register("writefile", InstructionBuilder<Writefile>);
		this->Register("grep",      InstructionBuilder<Grep>);
		this->Register("sort",      InstructionBuilder<Sort>);
		this->Register("replace",   InstructionBuilder<Replace>);
		this->Register("dump",      InstructionBuilder<Dump>);
	};

	static InstructionFactory* _instance;
	map<std::string, Instruction*> _map;
public:
	InstructionFactory(InstructionFactory const&) = delete;
	void operator=(InstructionFactory const&) = delete;
};

InstructionFactory* InstructionFactory::_instance = nullptr;

