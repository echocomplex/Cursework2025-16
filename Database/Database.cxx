#include "Database.hxx"

Database::Database (void) {
    this->filename = "database.txt";
    this->filename_enc = "database.enc";
    this->crypter.decrypt(this->filename_enc, this->filename);
    this->file.open(this->filename, true);
    this->file.readToList(this->data);
}

Database::Database (const std::string& filename) {
    this->filename = filename + ".txt";
    this->filename_enc = filename + ".enc";
    this->crypter.encrypt(this->filename_enc, this->filename);
    this->file.open(filename);
    this->file.readToList(this->data);
}

Database::Database (const List <Professor>& unit, const std::string& filename) {
    this->data = unit;
    this->filename = filename + ".txt";
    this->filename_enc = filename + ".enc";
    this->file.open(this->filename);
}

Database::Database (const Database& unit) {
    this->data = unit.data;
    this->file.open(unit.filename);
    this->filename = unit.filename;
    this->filename_enc = unit.filename_enc;
}

Database::~Database (void) {
    this->file.rewriteFromList(this->data);
    this->crypter.encrypt(this->filename, this->filename_enc);
}

Database& Database::operator= (const Database& unit) noexcept {
    if (this == &unit) return *this;
    this->data = unit.data;
    this->filename = unit.filename;
    this->filename_enc = unit.filename_enc;
    this->file.open(unit.filename);
    return *this;
}

Professor& Database::operator[] (const unsigned int index) noexcept {
    return this->data[index];
}

std::ostream& operator<< (std::ostream& os, const Database& unit) {
    for (unsigned int i = 0; i < unit.data.length(); ++i) os << i + 1 << ' ' << unit[i] << std::endl;
    return os;
}

const Professor& Database::operator[] (const unsigned int index) const noexcept {
    return this->data[index];
}

void Database::append (const Professor& unit) noexcept {
    this->data.append(unit);
}

void Database::remove (const unsigned int index) noexcept {
    this->data.remove(index);
}

unsigned int Database::size () noexcept {
    return this->data.length();
}

void Database::searchProfessorsWithAcademicDegree (List <Professor>& unit) const noexcept {
    for (unsigned int i = 0; i < this->data.length(); ++i) {
        const Professor& current = this->data[i];
        if (!current.getAcademicDegree().empty() && current.getAcademicDegree() != "-") {
            unit.append(current);
        }
    }
}

void Database::searchProfessorsOver45 (List <Professor>& unit) const noexcept {
    std::time_t now = std::time(nullptr);
    std::tm* local = std::localtime(&now);
    unsigned short current_year = local->tm_year + 1900; 
    for (unsigned int i = 0; i < this->data.length(); ++i) {
        const Professor& current = this->data[i];
        if (current_year - current.getBirthYear() >= 45) {
            unit.append(current);
        }
    }
}

double Database::calculateAverageAge (void) const noexcept {
    std::time_t now = std::time(nullptr);
    std::tm* local = std::localtime(&now);
    unsigned short current_year = local->tm_year + 1900;

    double result = 0.0;
    for (unsigned int i = 0; i < this->data.length(); ++i) {
        result += current_year - this->data[i].getBirthYear();
    }

    return result / this->data.length();
}