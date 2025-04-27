#include "Interface.hxx"

void Interface::clearInputBuffer (void) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Interface::displayMenu (void) {
    std::cout << "\r\n\n=== Professor Database Menu ===\r" << std::endl;
    std::cout << "1. Display all records\r" << std::endl;
    std::cout << "2. Add new professor\r" << std::endl;
    std::cout << "3. Remove professor\r" << std::endl;
    std::cout << "4. Find professors older than 45\r" << std::endl;
    std::cout << "5. Find PhD professors and calculate average age\r" << std::endl;
    std::cout << "6. Exit program\r" << std::endl;
    std::cout << "Enter your choice (1-6): ";
}

void Interface::pool (void) {
    short choice = 0;
    while (true) {
        this->displayMenu();

        while (!(std::cin >> choice) || choice < 1 || choice > 6) {
            std::cout << "\rInvalid input. Please enter 1-6: ";
            this->clearInputBuffer();
        }
        this->clearInputBuffer();

        switch (choice) {
            case 1:
                std::cout << "\r\n[Displaying all records]\r\n";
                // Your display functionality here
                break;
            case 2:
                std::cout << "\r\n[Adding new professor]\r\n";
                // Your add functionality here
                break;
            case 3:
                std::cout << "\r\n[Removing professor]\r\n";
                // Your remove functionality here
                break;
            case 4:
                std::cout << "\r\n[Finding professors > 45 years]\r\n";
                // Your search functionality here
                break;
            case 5:
                std::cout << "\r\n[PhD professors - calculating average age]\r\n";
                // Your PhD calculation here
                break;
            case 6:
                std::cout << "\r\nExiting program...\r\n";
                return;
        }

        std::cout << "\r\nOperation completed. Press Enter to continue...";
        this->clearInputBuffer();
        std::cout << "\r";
    }
}