#pragma once

#include <vector>
#include <unordered_map>

#include "Workflow.h"

using namespace std;

class WorkflowExecutor {
public:
	WorkflowExecutor() = default;
	~WorkflowExecutor() = default;

	void run(Workflow w) const;
};

