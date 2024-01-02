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
    void loadFromFile(const std::string&filename);

    void displayAllRecords() const;

    void sortByLastName();

    void sortByTitle();

    void searchByTitle(const std::string&title);

    void searchByLastName(const std::string&lastName);

    void searchByFirstName(const std::string&firstName);

    void searchByYear(int year);

    void addRecord(const BibliographyRecord&record);

    void removeLastRecord();

    void removeRecord(const BibliographyRecord&record);

    void saveToFile(const std::string&filename) const;

    void clearRecords();

    int displayMenu();
};
