#include "WorkflowParser.h"
#include "Workflow.h"
#include "Instruction.h"

#include "InstructionFactory.h"

#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Workflow WorkflowParser::parse(const string file_name) const {
	ifstream file(file_name);
	string line;

	getline(file, line);
	if (line.compare("desc")) { throw invalid_argument("invalid file format"); }

	InstructionFactory* Factory = InstructionFactory::getInstance();

	Workflow w;
	while (line.compare("csed")) {
		getline(file, line);

		stringstream ss(line);

		size_t id;
		ss >> id;

		ss >> line;

		string instruction;
		ss >> instruction;

		vector<string> args = vector<string>();
		while (ss >> line) { args.push_back(line); }

		w.instruction_args[id] = args;
		w.instruction_bind[id] = Factory->Build(instruction);
	}

	vector<size_t> order = vector<size_t>();
	while (file >> line) {
		if (!line.compare("->")) { continue; }
		order.push_back(stoi(line));
	}

	w.order = order;

	return w;
};
