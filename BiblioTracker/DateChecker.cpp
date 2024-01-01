#include "DateChecker.h"

bool DateChecker::isValidYear(const int year) {
    const std::time_t currentTime = std::time(nullptr);
    const std::tm* localTime = std::localtime(&currentTime);

    // Extract the current year from the local time
    const int currentYear = localTime->tm_year + 1900;

    // Compare the provided year with the current year
    return year <= currentYear;
}
