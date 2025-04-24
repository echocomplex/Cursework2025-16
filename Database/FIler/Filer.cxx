#include "Filer.hxx"

Filer::Filer (const std::string& path, const bool createNew = false) {
    if (createNew) {
        this->file.open(path, std::ios::in | std::ios::out | std::ios::ate);
        if (!this->file.is_open()) {
            this->file.open(path, std::ios::out);
            this->file.close();
            this->file.open(path, std::ios::in | std::ios::out | std::ios::ate);
            if (!this->file.is_open()) throw std::runtime_error("Failed to create the file.");
        }
    }
    else {
        this->file.open(path, std::ios::in | std::ios::out | std::ios::ate);
        if (!file.is_open()) throw std::runtime_error("File cannot be opened or does not exists");
    }
}

Filer::~Filer (void) noexcept {
    this->file.close();
}


void Filer::read (std::string& str) noexcept {
    this->file.seekg(0, std::ios::beg);
    std::string temp;
    while (std::getline(this->file, temp)) str += temp;
}

void Filer::readToList (List <Professor>& unit) noexcept {
    this->file.seekg(0, std::ios::beg);
    std::string temp;
    Professor node;
    while (std::getline(this->file, temp)) {
        this->stringToProfessor(node, temp);
        unit.append(node);
    }
}

void Filer::stringToProfessor (Professor& unit, const std::string& str) noexcept {
    std::string arr[7];
    unsigned short count = 0;
    for (size_t i = 0; i < (str.size() - 1) && count < 7; ++i) {
        if (str[i] == '$' && str[i + 1] == '$') {
            ++count, ++i;
        }
        else arr[count].push_back(str[i]);
    }
    if (count < 7) arr[count].push_back(str[str.size() - 1]);
}
