#include <iostream>
#include "html_validator.h"

using namespace std;

int main() {
    string filePath;
    cout << "Enter the path to the HTML file:  ";
    getline(cin, filePath);

    // ���������� ����� validateAndPrintContent ����� ��'� �����, ������� �� � static
    HTMLValidator::validateAndPrintContent(filePath);

    return 0;
}











    

