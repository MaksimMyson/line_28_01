#include <iostream>
#include "html_validator.h"

using namespace std;

int main() {
    string filePath;
    cout << "Enter the path to the HTML file:  ";
    getline(cin, filePath);

    // Викликайте метод validateAndPrintContent через ім'я класу, оскільки він є static
    HTMLValidator::validateAndPrintContent(filePath);

    return 0;
}











    

