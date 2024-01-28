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
    std::string filePath; ///< ���� �� �����.

public:
    /**
     * @brief ����������� ����� FileManager.
     *
     * �������� ��'��� FileManager � �������� ������ �� �����.
     *
     * @param path ���� �� �����.
     */
    FileManager(const std::string& path);

    /**
     * @brief ����� ��������� ����� � ���� �� ��������� ����������.
     *
     * @param searchString ����� ��� ������.
     */
    void searchAndPrintStatistics(const std::string& searchString);

    /**
     * @brief ����� ����� �� ����� ����� �� ��������� ����������.
     *
     * @param oldString ������ ����� ��� �����.
     * @param newString ����� �����.
     */
    void replaceAndPrintStatistics(const std::string& oldString, const std::string& newString);

    /**
     * @brief ��������� ����� ����� �� �����.
     */
    void displayFileContents() const;

    /**
     * @brief ������������ ����� ����� �� ��������� �� �����.
     */
    void reverseFileContents();
};

#endif // FILE_MANAGER_H
