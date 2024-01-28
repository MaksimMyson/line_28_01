#include "html_validator.h"

using namespace std;

void HTMLValidator::validateAndPrintContent(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filePath << endl;
        return;
    }

    string line;
    int openTagCount = 0;
    bool isValid = true;

    while (getline(file, line)) {
        for (char ch : line) {
            if (ch == '<') {
                openTagCount++;
            }
            else if (ch == '>') {
                if (openTagCount > 0) {
                    openTagCount--;
                }
                else {
                    isValid = false;
                    break;
                }
            }
        }
        if (!isValid) {
            break;
        }
    }

    file.close();

    // Виведення результату валідації та вмісту файлу
    if (isValid && openTagCount == 0) {
        cout << "The HTML file is valid." << endl;

        ifstream contentFile(filePath);
        cout << "Вміст файлу:\n";
        cout << contentFile.rdbuf();
        contentFile.close();
    }
    else {
        cout << "The HTML file is valid." << endl;
    }
}
