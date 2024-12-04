#include <iostream>
#include "Wrapper.h"
#include "Subject.h"
#include "Engine.h"

int main() {
	Subject subj;
	Wrapper wrapper(&subj, &Subject::f1, { {"arg1", 0}, {"arg2", 0}, {"arg3", 0} });
	Engine engine;

	engine.register_command(&wrapper, "command1");
	cout << engine.execute("command1", { {"arg1", 3}, {"arg2", 2}, {"arg3", 4} }) << endl;

	return 0;
}