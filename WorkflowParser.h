#pragma once

#include "Workflow.h"

#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

class WorkflowParser {
public:
	Workflow parse(const string file_name) const;
};
