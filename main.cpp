#include "WorkflowExecutor.h"
#include "WorkflowParser.h"
#include "Workflow.h"

#include <iostream>

using namespace std;

int main() {
    
    string file_name;
    cin >> file_name;

    WorkflowParser wp;

    std::cout << "Parsing!\n";

    Workflow w = wp.parse(file_name);

    WorkflowExecutor we;

    std::cout << "Running!\n";
    we.run(w);

    std::cout << "Done!\n";
}

