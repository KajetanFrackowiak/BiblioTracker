// BibliographyManager.cpp

#include "BibliographyManager.h"
#include "Color.h"

#include <algorithm>
#include <iostream>
#include <fstream>

void BibliographyManager::loadFromFile(const std::string&filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        setColor(Color::RED);
        std::cerr << "Error opening file: " << filename << std::endl;
        setColor(Color::RESET);
        return;
    }

    records.clear();

    try {
        while (!file.eof()) {
            auto record = std::make_unique<BibliographyRecord>();
            file >> record->lastName >> record->firstName >> record->title >> record->year;
            records.push_back(std::move(record));
        }
    }
    catch (const std::exception&e) {
        setColor(Color::RED);
        std::cerr << "Error while reading file: " << e.what() << std::endl;
        setColor(Color::RESET);
    }

    file.close();
}

void BibliographyManager::displayAllRecords() const {
    for (const auto&record: records) {
        record->display();
    }
}

void BibliographyManager::sortByLastName() {
    std::sort(records.begin(), records.end(), [](const auto&a, const auto&b) {
        return a->lastName < b->lastName;
    });
}

void BibliographyManager::sortByTitle() {
    std::sort(records.begin(), records.end(), [](const auto&a, const auto&b) {
        return a->title < b->title;
    });
}

void BibliographyManager::searchByTitle(const std::string&title) {
    for (const auto&record: records) {
        if (record->title == title) {
            record->display();
        }
    }
}

void BibliographyManager::searchByLastName(const std::string&lastName) {
    for (const auto&record: records) {
        if (record->lastName == lastName) {
            record->display();
        }
    }
}

void BibliographyManager::searchByFirstName(const std::string&firstName) {
    for (const auto&record: records) {
        if (record->firstName == firstName) {
            record->display();
        }
    }
}

void BibliographyManager::searchByYear(int year) {
    for (const auto&record: records) {
        if (record->year == year) {
            record->display();
        }
    }
}

void BibliographyManager::addRecord(const BibliographyRecord&record) {
    auto newRecord = std::make_unique<BibliographyRecord>(record);
    records.push_back(std::move(newRecord));
}

void BibliographyManager::removeLastRecord() {
    if (!records.empty()) {
        records.pop_back();
    }
}

void BibliographyManager::removeRecord(const BibliographyRecord&record) {
    records.erase(std::remove_if(records.begin(), records.end(),
                                 [&record](const auto&r) { return *r == record; }), records.end());
}

void BibliographyManager::saveToFile(const std::string&filename) const {
    std::ofstream file(filename);

    if (!file.is_open()) {
        setColor(Color::RED);
        std::cerr << "Error opening file: " << filename << std::endl;
        setColor(Color::RESET);
        return;
    }

    try {
        for (const auto&record: records) {
            file << record->lastName << " " << record->firstName << " " << record->title << " " << record->year <<
                    std::endl;
        }
    }
    catch (const std::exception&e) {
        setColor(Color::RED);
        std::cerr << "Error while writing to file: " << e.what() << std::endl;
        setColor(Color::RESET);
    }

    file.close();
}

int BibliographyManager::displayMenu() {
    int choice;
    std::cout << "Bibliography Library Menu:" << std::endl;
    std::cout << "1. Display all records\n"
            << "2. Sort records by last name\n"
            << "3. Sort records by title\n"
            << "4. Search by title\n"
            << "5. Search by last name\n"
            << "6. Search by first name\n"
            << "7. Search by year\n"
            << "8. Add record\n"
            << "9. Remove last record\n"
            << "10. Remove record by index\n"
            << "11. Save to file\n"
            << "12. Load from file\n"
            << "13. Quit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

void BibliographyManager::clearRecords() {
    records.clear();
}
