#include "Subject.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

string Subject::replace_word(const unordered_map<string, any>& arguments) {
    try {
        string text = any_cast<string>(arguments.at("text"));
        string before = any_cast<string>(arguments.at("before"));
        string after = any_cast<string>(arguments.at("after"));

        size_t pos = 0;
        while ((pos = text.find(before, pos)) != string::npos) {
            text.replace(pos, before.length(), after);
            pos += after.length();
        }
        return text;
    }
    catch (const exception& e) {
        throw invalid_argument("Missing required key in arguments: " + string(e.what()));
    }
    catch (const exception& e) {
        throw runtime_error("Error at replace_word: " + string(e.what()));
    }
}

string Subject::find_word_combinations(const unordered_map<string, any>& arguments) {
    try {
        string text = any_cast<string>(arguments.at("text"));
        string phrase = any_cast<string>(arguments.at("phrase"));
        if (text.find(phrase) != string::npos) {
            return "Required word combination was found";
        }
        else return "Required word combination wasn't found";
    }
    catch (const exception& e) {
        throw invalid_argument("Missing required key in arguments: " + string(e.what()));
    }
    catch (const exception& e) {
        throw runtime_error("Error at find_word_combinationse: " + string(e.what()));
    }
}

string Subject::to_capital_word(const unordered_map<string, any>& arguments) {
    try {
        string text = any_cast<string>(arguments.at("text"));
        bool isCapital = true;
        for (char& c : text) {
            if (isspace(c)) {
                isCapital = true;
            }
            else if (isCapital) {
                c = toupper(c);
                isCapital = false;
            }
        }
        return text;
    }
    catch (const exception& e) {
        throw invalid_argument("Missing required key in arguments: " + string(e.what()));
    }
    catch (const exception& e) {
        throw runtime_error("Error at to_capital_word: " + string(e.what()));
    }
}

string Subject::to_capital_word_sentence(const unordered_map<string, any>& arguments) {
    try {
        string text = any_cast<string>(arguments.at("text"));
        bool isCapital = true;
        for (char& c : text) {
            if (isCapital && isalpha(c)) {
                c = toupper(c);
                isCapital = false;
            }

            if (c == '.' || c == '!' || c == '?') {
                isCapital = true;
            }
        }
        return text;
    }
    catch (const exception& e) {
        throw invalid_argument("Missing required key in arguments: " + string(e.what()));
    }
    catch (const exception& e) {
        throw runtime_error("capitalize_sentences: " + string(e.what()));
    }
}

string Subject::number_and_format_sentence(const unordered_map<string, any>& arguments) {
    try {
        string text = any_cast<string>(arguments.at("text"));

        stringstream result;
        size_t start = 0; 
        size_t end = 0;    
        int counter = 1;    

        while ((end = text.find_first_of(".!?", start)) != string::npos) {
            string sentence = text.substr(start, end - start + 1);
            sentence.erase(0, sentence.find_first_not_of(" \t"));
            sentence.erase(sentence.find_last_not_of(" \t") + 1);

            result << counter++ << ". " << sentence << "\n";

            start = end + 1;
        }

        if (start < text.size()) {
            string sentence = text.substr(start);
            sentence.erase(0, sentence.find_first_not_of(" \t"));
            sentence.erase(sentence.find_last_not_of(" \t") + 1);
            if (!sentence.empty()) {
                result << counter++ << ". " << sentence << "\n";
            }
        }

        return result.str();
    }
    catch (const exception& e) {
        throw invalid_argument("Missing required key in arguments: " + string(e.what()));
    }
    catch (const exception& e) {
        throw runtime_error("Error in number_and_format_sentences: " + string(e.what()));
    }
}