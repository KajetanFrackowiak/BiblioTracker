// BibliographyManager.h

#pragma once

#include "BibliographyRecord.h"
#include <vector>
#include <memory>
#include <string>

class BibliographyManager {
private:
    std::vector<std::unique_ptr<BibliographyRecord>> records;

public:
    void loadFromFile(const std::string& filename);
    void displayAllRecords() const;
    void sortByTitle();
    void sortByLastName();
    void searchByTitle(const std::string& title) const;
    void searchByLastName(const std::string& lastName) const;
    void searchByFirstName(const std::string& firstName) const;
    void searchByYear(int year) const;
    void addRecord(const BibliographyRecord& record);
    void removeLastRecord();
    static bool isNumber(const std::string &str);
    void removeRecord(const BibliographyRecord &record);
    void saveToFile(const std::string &filename) const;
    void clearRecords();

    static void displayMenu();
};