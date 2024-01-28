#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <fstream>
#include <iostream>

/**
 * @brief The FileManager class provides functionality for working with files.
 */
class FileManager {
private:
    std::string filePath; ///< Шлях до файлу.

public:
    /**
     * @brief Конструктор класу FileManager.
     *
     * Ініціалізує об'єкт FileManager з вказаним шляхом до файлу.
     *
     * @param path Шлях до файлу.
     */
    FileManager(const std::string& path);

    /**
     * @brief Пошук вказаного рядка у файлі та виведення статистики.
     *
     * @param searchString Рядок для пошуку.
     */
    void searchAndPrintStatistics(const std::string& searchString);

    /**
     * @brief Заміна рядка на новий рядок та виведення статистики.
     *
     * @param oldString Старий рядок для заміни.
     * @param newString Новий рядок.
     */
    void replaceAndPrintStatistics(const std::string& oldString, const std::string& newString);

    /**
     * @brief Виведення вмісту файлу на екран.
     */
    void displayFileContents() const;

    /**
     * @brief Перевертання вмісту файлу та виведення на екран.
     */
    void reverseFileContents();
};

#endif // FILE_MANAGER_H
