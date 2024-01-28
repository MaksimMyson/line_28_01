#include "file_manager.h"

using namespace std;

FileManager::FileManager(const string& path) : filePath(path) {}

void FileManager::searchAndPrintStatistics(const string& searchString) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filePath << endl;
        return;
    }

    string line;
    int lineCount = 0;
    int occurrences = 0;

    while (getline(file, line)) {
        lineCount++;
        size_t found = line.find(searchString);
        while (found != string::npos) {
            occurrences++;
            found = line.find(searchString, found + 1);
        }
    }

    cout << "Statistics for search string '" << searchString << "':" << endl;
    cout << "  Total lines: " << lineCount << endl;
    cout << "  Occurrences: " << occurrences << endl;
}

void FileManager::replaceAndPrintStatistics(const string& oldString, const string& newString) {
    ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file " << filePath << endl;
        return;
    }

    ofstream outputFile("temp_file.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to create temporary file" << endl;
        return;
    }

    string line;
    int replacements = 0;

    while (getline(inputFile, line)) {
        size_t found = line.find(oldString);
        while (found != string::npos) {
            line.replace(found, oldString.length(), newString);
            found = line.find(oldString, found + newString.length());
            replacements++;
        }
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    remove(filePath.c_str());
    rename("temp_file.txt", filePath.c_str());

    cout << "Statistics for replacement:" << endl;
    cout << "  Replacements: " << replacements << endl;
}

void FileManager::displayFileContents() const {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filePath << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
}

void FileManager::reverseFileContents() {
    ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file " << filePath << endl;
        return;
    }

    ofstream outputFile("temp_file.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to create temporary file" << endl;
        return;
    }

    string line;
    string reversedLine;

    while (getline(inputFile, line)) {
        reversedLine = string(line.rbegin(), line.rend());
        outputFile << reversedLine << endl;
    }

    inputFile.close();
    outputFile.close();

    remove(filePath.c_str());
    rename("temp_file.txt", filePath.c_str());

    cout << "File contents reversed successfully." << endl;
}
