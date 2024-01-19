#include "DateChecker.h"
#include <ctime>

bool DateChecker::isValidYear(const int year) {
    // Get the current time in seconds since the epoch (January 1, 1970)
    const std::time_t currentTime = std::time(nullptr);
    // Convert the current time to a local time structure
    const std::tm* localTime = std::localtime(&currentTime);

    // Extract the current year from the local time
    const int currentYear = localTime->tm_year + 1900;

    // Compare the provided year with the current year
    return year <= currentYear;
}
