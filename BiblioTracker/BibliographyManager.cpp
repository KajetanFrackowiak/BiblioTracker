//
// Created by frackowiak on 01.01.24.
//

#include "BibliographyManager.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>


//std::vector<std::unique_ptr<BibliographyRecord> > records;

void BibliographyManager::loadFromFile(const std::string &filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        setColor(Color::RED);
        std::cerr << "Error opening file: " << filename << std::endl;
        setColor(Color::RESET);
        return;
    }

    records.clear();

    try {
        std::string line;
        while (std::getline(file, line)) {
            auto record = std::make_unique<BibliographyRecord>();
            std::istringstream iss(line);

            // Assuming CSV format, use getline to read the entire line
            std::getline(iss, record->lastName, ',');
            std::getline(iss, record->firstName, ',');
            std::getline(iss, record->title, ',');
            iss >> record->year;

            records.push_back(std::move(record));
        }
    } catch (const std::exception &e) {
        setColor(Color::RED);
        std::cerr << "Error while reading file: " << e.what() << std::endl;
        setColor(Color::RESET);
    }

    file.close();
}


void BibliographyManager::displayAllRecords() const {
    for (const auto &record: records) {
        record->display();
    }
}

void BibliographyManager::sortByTitle() {
    std::sort(records.begin(), records.end(), [](const auto &a, const auto &b) {
        return a->title < b->title; // asc
    });
    for (const auto &record: records) {
        record->display();
    }
}

void BibliographyManager::sortByLastName() {
    std::sort(records.begin(), records.end(), [](const auto &a, const auto &b) {
        return a->lastName < b->lastName;
    });
    for (const auto &record: records) {
        record->display();
    }
}


void BibliographyManager::searchByTitle(const std::string &title) const {
    for (const auto &record: records) {
        if (record->title == title) {
            record->display();
        }
    }
}

void BibliographyManager::searchByLastName(const std::string &lastName) const {
    for (const auto &record: records) {
        if (record->lastName == lastName) {
            record->display();
        }
    }
}

void BibliographyManager::searchByFirstName(const std::string &firstName) const {
    for (const auto &record: records) {
        if (record->firstName == firstName) {
            record->display();
        }
    }
}

void BibliographyManager::searchByYear(const int year) const {
    for (const auto &record: records) {
        if (record->year == year) {
            record->display();
        }
    }
}

void BibliographyManager::addRecord(const BibliographyRecord &record) {
    auto newRecord = std::make_unique<BibliographyRecord>(record);
    records.push_back(std::move(newRecord));
}

void BibliographyManager::removeLastRecord() {
    if (!records.empty()) {
        records.pop_back();
    }
    for (const auto &record: records) {
        record->display();
    }
}

bool BibliographyManager::isNumber(const std::string &str) {
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

void BibliographyManager::removeRecord(const BibliographyRecord &record) {
    try {
        auto it = std::remove_if(records.begin(), records.end(), [&record](const auto &ptr) {
            const BibliographyRecord &r = *ptr;  // Dereference the unique_ptr
            return r.lastName == record.lastName &&
                   r.firstName == record.firstName &&
                   r.title == record.title &&
                   r.year == record.year;
        });

        if (it != records.end()) {
            records.erase(it, records.end());
            setColor(Color::GREEN);
            std::cout << "Record removed successfully." << std::endl;
        } else {
            setColor(Color::RED);
            std::cout << "Record not found." << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Error while removing record: " << e.what() << std::endl;
        setColor(Color::RESET);
    }
}


void BibliographyManager::saveToFile(const std::string &filename) const {
    std::ofstream file(filename);  // ofstream = class for writing output to a file

    if (!file.is_open()) {
        setColor(Color::RED);
        std::cerr << "Error opening file: " << filename << std::endl;
        setColor(Color::RESET);
        return;
    }

    try {
        for (const auto &record: records) {
            file << record->lastName << "," << record->firstName << "," << record->title << "," << record->year
                 << std::endl;
        }
    } catch (const std::exception &e) {
        setColor(Color::RED);
        std::cerr << "Error while writing to file: " << e.what() << std::endl;
        setColor(Color::RESET);
    }

    setColor(Color::GREEN);
    std::cout << "Data saved successfully to " << filename << std::endl;
    file.close();
}


void BibliographyManager::clearRecords() {
    records.clear();
}

void BibliographyManager::displayMenu() {
    setColor(Color::BLUE);
    std::cout << "\n===== Bibliography Manager Menu =====\n";
    setColor(Color::GREEN);
    std::cout << "1. Display all records\n";
    std::cout << "2. Sort by last name\n";
    std::cout << "3. Sort by title\n";
    std::cout << "4. Search by title\n";
    std::cout << "5. Search by last name\n";
    std::cout << "6. Search by first name\n";
    std::cout << "7. Search by year\n";
    std::cout << "8. Add a new record\n";
    std::cout << "9. Remove last record\n";
    std::cout << "10. Remove a specific record\n";
    std::cout << "11. Save to file\n";
    std::cout << "12. Clear all records\n";
    std::cout << "0. Exit\n";
    setColor(Color::BLUE);
    std::cout << "=====================================\n";
    setColor(Color::PURPLE);
    std::cout << "Enter your choice: ";
    setColor(Color::RESET);
}