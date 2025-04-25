#include "Filer.hxx"

Filer::Filer (const std::string& path, const bool createNew) {
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
        if (!this->file.is_open()) throw std::runtime_error("File cannot be opened or does not exists");
    }
}

Filer::~Filer (void) noexcept {
    if (this->file.is_open()) this->file.close();
}

void Filer::open (const std::string& path) {
    this->file.open(path, std::ios::in | std::ios::out | std::ios::ate);
    if (!this->file.is_open()) throw std::runtime_error("File cannot be opened or does not exists");
}

void Filer::read (std::string& str) noexcept {
    if (!this->file.is_open()) throw std::runtime_error("File does not open now");
    
    this->file.seekg(0, std::ios::beg);
    std::string temp;
    while (std::getline(this->file, temp)) str += temp;
}

void Filer::readToList (List <Professor>& unit) {
    if (!this->file.is_open()) throw std::runtime_error("File does not open now");
    
    this->file.seekg(0, std::ios::beg);
    std::string temp;
    Professor node;
    while (std::getline(this->file, temp)) {
        node = Professor();
        this->stringToProfessor(node, temp);
        unit.append(node);
    }
}

void Filer::writeBack (std::string& string) {
    if (!this->file.is_open()) throw std::runtime_error("File does not open now");
    else if (string.empty()) return;

    this->file.seekp(0, std::ios::end);
    this->file << string << '\n';
}

void Filer::stringToProfessor (Professor& unit, const std::string& str) {
    if (str.empty()) return;

    std::string arr[7];
    unsigned short count = 0;
    for (size_t i = 0; i < (str.size() - 1) && count < 7; ++i) {
        if (str[i] == '$' && str[i + 1] == '$') {
            ++count, ++i;
        } 
        else arr[count].push_back(str[i]);
    }
    if (count < 7) arr[count].push_back(str[str.size() - 1]);

    unit.setUniversity(arr[0]);
    unit.setDepartment(arr[1]);
    unit.setPost(arr[2]);
    unit.setFullName(arr[3]);
    try {
        unit.setBirthYear(std::stoul(arr[4]));
    } 
    catch (std::invalid_argument) {
        unit.setBirthYear(0); 
    }
    unit.setAcademicDegree(arr[5]);
    unit.setSubjects(arr[6]);
}
