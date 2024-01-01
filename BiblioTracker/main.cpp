#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory>
#include <limits>
#include <cctype>  // Dodaj nagłówek dla isalpha i isupper
#include <chrono>

enum class Color {
    RESET = 0,
    RED,
    GREEN,
    YELLOW,
    BLUE
};

// Funkcja do ustawiania koloru
void setColor(const Color color) {
    switch (color) {
        case Color::RESET:
            std::cout << "\033[0m";
            break;
        case Color::RED:
            std::cout << "\033[1;31m";
            break;
        case Color::GREEN:
            std::cout << "\033[1;32m";
            break;
        case Color::YELLOW:
            std::cout << "\033[1;33m";
            break;
        case Color::BLUE:
            std::cout << "\033[1;34m";
            break;
    }
}

class BibliographyRecord {
public:
    std::string lastName;
    std::string firstName;
    std::string title;
    int year{};

    void display() const;

    // Dodaj operator porównania '==' dla klasy BibliographyRecord
    bool operator==(const BibliographyRecord&other) const;

    [[nodiscard]] bool isValidFirstName() const;
    [[nodiscard]] bool isValidLastName() const;
};

class DateChecker {
public:
    static bool isValidYear(const int year) {
        const std::time_t currentTime = std::time(nullptr);
        const std::tm* localTime = std::localtime(&currentTime);

        // Extract the current year from the local time
        const int currentYear = localTime->tm_year + 1900;

        // Compare the provided year with the current year
        return year <= currentYear;
    }
};

void BibliographyRecord::display() const {
    setColor(Color::YELLOW);
    std::cout << lastName;
    setColor(Color::RESET);
    std::cout << ", ";
    setColor(Color::YELLOW);
    std::cout << firstName;
    setColor(Color::RESET);
    std::cout << ", ";
    setColor(Color::BLUE);
    std::cout << title;
    setColor(Color::RESET);
    std::cout << ", ";
    setColor(Color::GREEN);
    std::cout << year;
    setColor(Color::RESET);
    std::cout << std::endl;
}

// Dodaj operator porównania '==' dla klasy BibliographyRecord
bool BibliographyRecord::operator==(const BibliographyRecord&other) const {
    return lastName == other.lastName &&
           firstName == other.firstName &&
           title == other.title &&
           year == other.year;
}

// Dodaj funkcję sprawdzającą, czy last name nie zawiera cyfr i zaczyna się od dużej litery
[[nodiscard]] bool BibliographyRecord::isValidLastName() const {
    for (const char c: lastName) {
        if (!isalpha(c) || (c == ' ')) {
            return false; // Jeżeli znak nie jest literą (lub to spacja), zwróć false
        }
    }

    return !lastName.empty() && isupper(lastName.front());
}

// Dodaj funkcję sprawdzającą, czy first name nie zawiera cyfr i zaczyna się od dużej litery
[[nodiscard]] bool BibliographyRecord::isValidFirstName() const {
    for (const char c: firstName) {
        if (!isalpha(c) || (c == ' ')) {
            return false; // Jeżeli znak nie jest literą (lub to spacja), zwróć false
        }
    }

    return !firstName.empty() && isupper(firstName.front());
}

class BibliographyManager {
private:
    std::vector<std::unique_ptr<BibliographyRecord>> records;

public:
    void loadFromFile(const std::string&filename) {
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

    void displayAllRecords() const {
        for (const auto&record: records) {
            record->display();
        }
    }

    void sortByLastName() {
        std::sort(records.begin(), records.end(), [](const auto&a, const auto&b) {
            return a->lastName < b->lastName;
        });
    }

    void sortByTitle() {
        std::sort(records.begin(), records.end(), [](const auto&a, const auto&b) {
            return a->title < b->title;
        });
    }

    void searchByTitle(const std::string&title) const {
        for (const auto&record: records) {
            if (record->title == title) {
                record->display();
            }
        }
    }

    void searchByLastName(const std::string&lastName) const {
        for (const auto&record: records) {
            if (record->lastName == lastName) {
                record->display();
            }
        }
    }

    void searchByFirstName(const std::string&firstName) const {
        for (const auto&record: records) {
            if (record->firstName == firstName) {
                record->display();
            }
        }
    }

    void searchByYear(int year) const {
        for (const auto&record: records) {
            if (record->year == year) {
                record->display();
            }
        }
    }

    void addRecord(const BibliographyRecord&record) {
        auto newRecord = std::make_unique<BibliographyRecord>(record);
        records.push_back(std::move(newRecord));
    }

    void removeLastRecord() {
        if (!records.empty()) {
            records.pop_back();
        }
    }

    void removeRecord(const BibliographyRecord&record) {
        records.erase(std::remove_if(records.begin(), records.end(),
                                     [&record](const auto&r) { return *r == record; }), records.end());
    }

    void saveToFile(const std::string&filename) const {
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

    void clearRecords() {
        records.clear();
    }
};

void displayMenu() {
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
    setColor(Color::RESET);
    std::cout << "=====================================\n";
    std::cout << "Enter your choice: ";
}

int main() {
    BibliographyManager manager;

    // Przykładowe użycie
    manager.loadFromFile("bibliography.txt");

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        try {
            switch (choice) {
                case 1:
                    manager.displayAllRecords();
                    break;
                case 2:
                    manager.sortByLastName();
                    break;
                case 3:
                    manager.sortByTitle();
                    break;
                case 4: {
                    std::string title;
                    setColor(Color::YELLOW);
                    std::cout << "Enter title to search: ";
                    setColor(Color::RESET);
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, title);
                    manager.searchByTitle(title);
                }
                break;
                case 5: {
                    std::string lastName;
                    setColor(Color::YELLOW);
                    std::cout << "Enter last name to search: ";
                    setColor(Color::RESET);
                    std::cin >> lastName;
                    manager.searchByLastName(lastName);
                }
                break;
                case 6: {
                    std::string firstName;
                    setColor(Color::YELLOW);
                    std::cout << "Enter first name to search: ";
                    setColor(Color::RESET);
                    std::cin >> firstName;
                    manager.searchByFirstName(firstName);
                }
                break;
                case 7: {
                    int year;
                    setColor(Color::YELLOW);
                    std::cout << "Enter year to search: ";
                    setColor(Color::RESET);
                    std::cin >> year;
                    manager.searchByYear(year);
                }
                break;
                case 8: {
                    BibliographyRecord newRecord;
                    std::cout << "Enter last name: ";
                    do {
                        std::cin >> newRecord.lastName;

                        if (!newRecord.isValidLastName()) {
                            std::cerr << "Invalid last name format. Last name must not contain digits and should start "
                                         "with a capital letter.\nWrite again: ";
                            // Clear the input buffer before prompting again
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            continue;  // Continue the loop without executing the remaining code
                        }

                        break;  // Break the loop if last name is valid

                    } while (true);  // Infinite loop, will break when last name is valid

                    std::cout << "Enter first name: ";
                    do {
                        std::cin >> newRecord.firstName;

                        if (!newRecord.isValidFirstName()) {
                            std::cerr <<
                                    "\nInvalid first name format. First name must not contain digits and should start "
                                    "with a capital letter.\nWrite again: ";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            continue;
                        }
                        break;
                    }
                    while (true);


                    std::cout << "Enter title: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, newRecord.title);

                    do {
                    std::cout << "Enter year: ";
                    std::cin >> newRecord.year;
                        if (!DateChecker::isValidYear(newRecord.year)) {
                            std::cerr << "\nInvalid year. Please enter a year not greater than the current year."
                                         "\nWrite again: ";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                        break;
                    } while (true);


                    manager.addRecord(newRecord);
                }
                break;
                case 9:
                    manager.removeLastRecord();
                    break;
                case 10: {
                    BibliographyRecord recordToRemove;
                    setColor(Color::YELLOW);
                    std::cout << "Enter last name of the record to remove: ";
                    setColor(Color::RESET);
                    std::cin >> recordToRemove.lastName;
                    setColor(Color::YELLOW);
                    std::cout << "Enter first name of the record to remove: ";
                    setColor(Color::RESET);
                    std::cin >> recordToRemove.firstName;
                    setColor(Color::YELLOW);
                    std::cout << "Enter title of the record to remove: ";
                    setColor(Color::RESET);
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, recordToRemove.title);

                    manager.removeRecord(recordToRemove);
                }
                break;
                case 11: {
                    std::string filename;
                    setColor(Color::YELLOW);
                    std::cout << "Enter filename to save: ";
                    setColor(Color::RESET);
                    std::cin >> filename;
                    manager.saveToFile(filename);
                }
                break;
                case 12:
                    manager.clearRecords();
                    break;
                case 0:
                    break;
                default:
                    setColor(Color::RED);
                    std::cout << "Invalid choice. Please try again.\n";
                    setColor(Color::RESET);
            }
        }
        catch (const std::exception&e) {
            setColor(Color::RED);
            std::cerr << "Error: " << e.what() << std::endl;
            setColor(Color::RESET);
        }
    }
    while (choice != 0);

    return 0;
}
