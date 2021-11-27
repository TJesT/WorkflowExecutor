#pragma once
#include "Instruction.h"

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

typedef struct Workflow {
	unordered_map<size_t, vector<string> > instruction_args;
	unordered_map<size_t, Instruction*> instruction_bind;
	vector<size_t> order;
} Workflow;

