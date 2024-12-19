#pragma once

#include "Wrapper.h"
#include <functional>
#include <any>

class Engine {
private:
	unordered_map<string, Wrapper*> commands;
public:
	Engine() = default;

	void register_command(Wrapper* wrapper, const string& name) {
		try {
			commands[name] = wrapper;
		}
		catch (exception& e) {
			throw runtime_error(e.what());
		}
	}

	string execute(const string& name, const unordered_map<string, any>& arguments) {
		auto found = commands.find(name);
		if (found != commands.end()) {
			return commands[name]->execute(arguments);
		}
		else {
			throw runtime_error(string("Requested command ") + name + string(" was not found"));
		}
	}
};