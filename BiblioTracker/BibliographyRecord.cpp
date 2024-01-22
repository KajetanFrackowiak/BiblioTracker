#include "BibliographyRecord.h"
#include "Color.h"  // Correct path relative to the current file
#include <iostream>
#include <cctype>

void BibliographyRecord::display() const {
    setColor(Color::RED);
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

bool BibliographyRecord::operator==(const BibliographyRecord&other) const {
    return lastName == other.lastName &&
           firstName == other.firstName &&
           title == other.title &&
           year == other.year;
}

[[nodiscard]] bool BibliographyRecord::isValidLastName() const {
    for (const char c: lastName) {
        if (!isalpha(c) || (c == ' ')) {
            return false;
        }
    }

    return !lastName.empty() && isupper(lastName.front());
}

[[nodiscard]] bool BibliographyRecord::isValidFirstName() const {
    for (const char c: firstName) {
        if (!isalpha(c) || (c == ' ')) {
            return false;
        }
    }

    return !firstName.empty() && isupper(firstName.front());
}

[[nodiscard]] bool BibliographyRecord::isValidTitle() const {
    for (const char c: title) {
        if (!isalpha(c) || (c == ' ')) {
            return false;
        }
    }

    return !firstName.empty() && isupper(firstName.front());
}
