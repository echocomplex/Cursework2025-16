#include "Interface.hxx"

void Interface::clearInputBuffer (void) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Interface::getProfessor (Professor& unit) {
    std::string temp;

    std::cout << "Enter the University: ";
    std::getline(std::cin, temp);
    unit.setUniversity(temp);
    std::cout << "Enter the Department: ";
    std::getline(std::cin, temp);
    unit.setDepartment(temp);
    std::cout << "Enter the Post: ";
    std::getline(std::cin, temp);
    unit.setPost(temp);
    std::cout << "Enter the Full Name: ";
    std::getline(std::cin, temp);
    unit.setFullName(temp);
    std::cout << "Enter the Birth Year: ";
    unsigned short year;
    std::cin >> year;
    this->clearInputBuffer();
    unit.setBirthYear(year);
    std::cout << "Enter the Academic Degree: ";
    std::getline(std::cin, temp);
    unit.setAcademicDegree(temp);
    std::cout << "Enter the Subjects: ";
    std::getline(std::cin, temp);
    unit.setSubjects(temp);
}

int Interface::removeProfessor (void) {
    int number;
    while (true) {
        std::cout << "Enter professor number to delete (1-" << this->unit.size() << "): ";
        
        if (!(std::cin >> number)) {
            std::cin.clear();
            this->clearInputBuffer();
            std::cerr << "Error: Please enter a number\n\n";
            continue;
        }

        if (number > 0 && number <= this->unit.size()) {
            return number - 1;
        }
        
        std::cerr << "Error: Number must be between 1 and " << this->unit.size() << "\n\n";
    }
}

void Interface::displayMenu (void) {
    std::cout << "\n\n=== Professor Database Menu ===" << std::endl;
    std::cout << "1. Display all records" << std::endl;
    std::cout << "2. Add new professor" << std::endl;
    std::cout << "3. Remove professor" << std::endl;
    std::cout << "4. Find professors older than 45" << std::endl;
    std::cout << "5. Find professors with academic degree" << std::endl;
    std::cout << "6. Calculate average age" << std::endl;
    std::cout << "7. Exit program" << std::endl;
    std::cout << "Enter your choice (1-7): ";
}

void Interface::pool (void) {
    short choice = 0;
    Professor new_professor;
    List <Professor> collected;
    while (true) {
        this->displayMenu();

        while (!(std::cin >> choice) || choice < 1 || choice > 7) {
            std::cout << "Invalid input. Please enter 1-7: ";
            this->clearInputBuffer();
        }

        this->clearInputBuffer();

        switch (choice) {
            case 1:
                std::cout << "\n[Displaying all records]\n";
                std::cout << this->unit << std::endl;
                break;
            case 2:
                std::cout << "\n[Adding new professor]\n";
                this->getProfessor(new_professor);
                this->unit.append(new_professor);
                break;
            case 3:
                std::cout << "\n[Removing professor]\n";
                this->unit.remove(this->removeProfessor());
                break;
            case 4:
                std::cout << "\n[Finding professors > 45 years]\n";
                this->unit.searchProfessorsOver45(collected);
                for (int i = 0; i < collected.length(); ++i) std::cout << collected[i] << std::endl;
                collected.clear();
                break;
            case 5:
                std::cout << "\n[Searching professors with academic degree]\n";
                this->unit.searchProfessorsWithAcademicDegree(collected);
                for (int i = 0; i < collected.length(); ++i) std::cout << collected[i] << std::endl;
                collected.clear();
                break;
            case 6:
                std::cout << "Average age: " << this->unit.calculateAverageAge() << std::endl;
                break;
            case 7:
                std::cout << "\nExiting program...\n";
                return;
        }

        std::cout << "\nOperation completed. Press Enter to continue...";
        this->clearInputBuffer();
    }
}