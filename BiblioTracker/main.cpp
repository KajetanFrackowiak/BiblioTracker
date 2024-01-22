#include "BibliographyRecord.h"
#include "DateChecker.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <limits>
#include "BibliographyManager.h"
#include "Color.h"


int main() {
    BibliographyManager manager;

    manager.loadFromFile("bibliography.csv");

    int choice;
    do {
        manager.displayMenu();
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
                            continue; // Continue the loop without executing the remaining code
                        }

                        break; // Break the loop if last name is valid
                    }
                    while (true); // Infinite loop, will break when last name is valid

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
                    do {
                        std::cin >> newRecord.title;

                        if (!newRecord.isValidTitle()) {
                            std::cerr <<
                                      "\nInvalid title format. Title must not contain digits and should start "
                                      "with a capital letter.\nWrite again: ";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            continue;
                        }
                        break;
                    } while (true);

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
                    std::cin >> recordToRemove.lastName;

                    setColor(Color::YELLOW);
                    std::cout << "Enter first name of the record to remove: ";
                    std::cin.ignore();
                    std::getline(std::cin, recordToRemove.firstName);

                    setColor(Color::YELLOW);
                    std::cout << "Enter title of the record to remove: ";
                    std::getline(std::cin, recordToRemove.title);

                    setColor(Color::YELLOW);
                    std::cout << "Enter year of the record to remove: ";
                    std::cin >> recordToRemove.year;

                    while (!BibliographyManager::isNumber(std::to_string(recordToRemove.year))) {
                        setColor(Color::RED);
                        std::cout << "Year must be a number, Write again:" << std::endl;
                        // Clear buffer
                        std::cin.clear();
                        // Ignore any remaining characters in the buffer
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> recordToRemove.year;
                    }

                    // Find and remove the record based on its values
                    manager.removeRecord(recordToRemove);
                    break;
                }

                    break;
                case 11: {
                    std::string filename;
                    setColor(Color::YELLOW);
                    std::cout << "Enter filename to save: ";
                    setColor(Color::RESET);
                    std::cin >> filename;


                    if(filename.empty()) {
                        filename = "bibliography.csv";
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


                    manager.saveToFile(filename);
                    break;
                }

                case 12:
                    manager.clearRecords();
                    break;
                case 0:
                    setColor(Color::PURPLE);
                    std::cout << "BYE BYE :)" << std::endl;
                    break;
                default:
                    setColor(Color::RED);
                    std::cerr << "Invalid choice. Please try again.\n";
                    setColor(Color::RESET);
            }
        }
        catch (const std::exception &e) {
            setColor(Color::RED);
            std::cout << "Error: " << e.what() << std::endl;
            setColor(Color::RESET);
        }
    } while (choice != 0);

    return 0;
}