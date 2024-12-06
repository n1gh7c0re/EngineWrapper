#pragma once

#include <string>
#include "Subject.h"
#include <iostream>
#include <unordered_map>
#include <stdexcept>
#include <vector>
#include <any>

using namespace std;

class Wrapper {
private:
	Subject* subj;
	function<string(const unordered_map<string, any>&)> func;
public:
	Wrapper(Subject* subject, const function<string(const unordered_map<string, any>&)>& function)
		: subj(subject), func(function) {
	}

	string execute(const unordered_map<string, any>& arguments) {
		try {
			return func(arguments);
		}
		catch (const exception& e) {
			throw runtime_error("Execution error: " + string(e.what()));
		}
	}
};