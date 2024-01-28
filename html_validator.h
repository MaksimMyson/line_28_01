#ifndef HTML_VALIDATOR_H
#define HTML_VALIDATOR_H

#include <string>
#include <fstream>
#include <iostream>

/**
 * @brief Клас HTMLValidator надає функціональність для валідації та виведення вмісту HTML-файлів.
 */
class HTMLValidator {
public:
    /**
     * @brief Валідує та виводить вміст заданого HTML-файлу.
     *
     * @param filePath Шлях до HTML-файлу.
     */
    static void validateAndPrintContent(const std::string& filePath);
};

#endif // HTML_VALIDATOR_H
