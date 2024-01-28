#ifndef HTML_VALIDATOR_H
#define HTML_VALIDATOR_H

#include <string>
#include <fstream>
#include <iostream>

/**
 * @brief ���� HTMLValidator ���� ��������������� ��� �������� �� ��������� ����� HTML-�����.
 */
class HTMLValidator {
public:
    /**
     * @brief ����� �� �������� ���� �������� HTML-�����.
     *
     * @param filePath ���� �� HTML-�����.
     */
    static void validateAndPrintContent(const std::string& filePath);
};

#endif // HTML_VALIDATOR_H
