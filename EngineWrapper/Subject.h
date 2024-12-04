#pragma once
#include <iostream>

using namespace std;

class Subject {
public:
	int f1(int a, double b, double c) {
		cout << "Function f1 is called. Its arguments: " << a << ", " << b << ", " << c << endl;
		return a * b - c;
	}

	int f2(int a, double b) {
		cout << "Function f2 is called. Its arguments: " << a << ", " << b << endl;
		return b - a;
	}

	string f3(const string& str1, const string& str2) {
		cout << "Function f3 is called. Its arguments: " << str1 << ", " << str2 << endl;
		return str1 + str2;
	};
};