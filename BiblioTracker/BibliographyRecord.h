#ifndef BIBLIOGRAPHY_RECORD_H
#define BIBLIOGRAPHY_RECORD_H

#include <string>
#include "Color.h"  // Correct path relative to the current file

class BibliographyRecord {
public:
    std::string lastName;
    std::string firstName;
    std::string title;
    int year{};

    // Display function using color
    void display() const;

    // Comparison operator
    bool operator==(const BibliographyRecord& other) const;

    // Validation functions
    [[nodiscard]] bool isValidLastName() const;
    [[nodiscard]] bool isValidFirstName() const;
};

#endif // BIBLIOGRAPHY_RECORD_H
