#include "Subject.h"
#include "Wrapper.h"
#include "Engine.h"
#include <unordered_map>
#include <any>
#include <iostream>

void Interface() {
    const string some_text = "hello! My name is Sergey. what is your name?";

    try {
        Subject subj;

        Subject subj;
        Wrapper replace(&subj, [&](const auto& arguments) { return subj.replace_word(arguments); });
        Wrapper find(&subj, [&](const auto& arguments) { return subj.find_word_combinations(arguments); });
        Wrapper to_capital_w(&subj, [&](const auto& arguments) { return subj.to_capital_word(arguments); });
        Wrapper to_capital_s(&subj, [&](const auto& arguments) { return subj.to_capital_sentence(arguments); });
        Wrapper number_format(&subj, [&](const auto& arguments) { return subj.number_and_format_sentence(arguments); });

        // Create Engine and register commands
        Engine engine;
        engine.register_command(&replace, "replace_word");
        engine.register_command(&find, "find_word_combinations");
        engine.register_command(&to_capital_w, "to_capital_word");
        engine.register_command(&to_capital_s, "to_capital_sentence");
        engine.register_command(&number_format, "number_and_format_sentence");

        unordered_map<string, any> arguments;
        int user_command;

        // User command interface
        while (true) {
            cout << "\nAvailable commands: 0. Exit\n1. Replace word\n2. Find word combination\n"
                    "3. Change the first letters of words to capital letters\n"
                    "4. Change the first letters of sentence to capital letters\n"
                    "5. Add sequential numbering to each sentence + start from a new line\n";
            cout << "Enter the number of command: ";
            cin >> user_command;

            if (user_command == 0) {
                break;
            }

            try {
                if (user_command == 1) {
                    arguments = { {"text", some_text }, {"before", string("Hello")}, {"after", string("Goodbye")} };
                    cout << "Result (Replace word): " << engine.execute("replace_word", arguments) << "\n";
                }
                else if (user_command == 2) {
                    arguments = { {"text", some_text }, {"phrase", string("Sergey")} };
                    cout << "Result (Find word combination): " << engine.execute("find_word_combinations", arguments) << "\n";
                }
                else if (user_command == 3) {
                    arguments = { {"text", some_text } };
                    cout << "Result (Change the first letters of words to capital letters): " << engine.execute("to_capital_word", arguments) << "\n";
                }
                else if (user_command == 4) {
                    arguments = { {"text", some_text } };
                    cout << "Result (Change the first letters of sentence to capital letters): " << engine.execute("to_capital_sentence", arguments) << "\n";
                }
                else if (user_command == 5) {
                    arguments = { {"text", some_text } };
                    cout << "Result (Add sequential numbering to each sentence + start from a new line): " << engine.execute("number_and_format_sentence", arguments) << "\n";
                }
                else {
                    cout << "Unknown command!\n";
                    break;
                }
            }
            catch (const exception& e) {
                cerr << "Error during command execution: " << e.what() << "\n";
            }
        }

    }
    catch (const exception& e) {
        cerr << "Error during testing: " << e.what() << "\n";
    }
}

int main() {
    Interface();

	return 0;
}