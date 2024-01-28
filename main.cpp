#include <iostream>
#include "file_manager.h"

using namespace std;

int main() {
    string filePath;
    cout << "Enter the path to the file: ";
    getline(cin, filePath);

    FileManager fileManager(filePath);

    int choice;
    do {
        cout << "\nFile Manager Menu:\n"
            << "1. Search for a string\n"
            << "2. Replace a string\n"
            << "3. Display file contents\n"
            << "4. Reverse file contents\n"
            << "0. Exit\n"
            << "Enter your choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {
        case 1: {
            string searchString;
            cout << "Enter the string to search: ";
            getline(cin, searchString);
            fileManager.searchAndPrintStatistics(searchString);
            break;
        }
        case 2: {
            string oldString, newString;
            cout << "Enter the string to replace: ";
            getline(cin, oldString);
            cout << "Enter the new string: ";
            getline(cin, newString);
            fileManager.replaceAndPrintStatistics(oldString, newString);
            break;
        }
        case 3:
            fileManager.displayFileContents();
            break;
        case 4:
            fileManager.reverseFileContents();
            break;
        case 0:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
