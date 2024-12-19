#include <any>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

class Subject {
public:
    string replace_word(const unordered_map<string, any>& arguments);
    string find_word_combinations(const unordered_map<string, any>& arguments);
    string to_capital_word(const unordered_map<string, any>& arguments);
    string to_capital_sentence(const unordered_map<string, any>& arguments);
    string number_and_format_sentence(const unordered_map<string, any>& arguments);
};