#include "Filer.hxx"

Filer::Filer (const std::string& path, const bool createNew) {
    if (createNew) {
        this->file.open(path, std::ios::in);
        if (!this->file.is_open()) {
            this->file.open(path, std::ios::out);
            this->file.close();
            this->file.open(path, std::ios::in);
            if (!this->file.is_open()) throw std::runtime_error("Failed to create the file.");
        }
    }
    else {
        this->file.open(path, std::ios::in);
        if (!this->file.is_open()) throw std::runtime_error("File cannot be opened or does not exists");
    }
    this->path = path;
}

Filer::~Filer (void) noexcept {
    if (this->file.is_open()) this->file.close();
}

void Filer::open (const std::string& path, const bool createNew) {
    if (createNew) {
        this->file.open(path, std::ios::in);
        if (!this->file.is_open()) {
            this->file.open(path, std::ios::out);
            this->file.close();
            this->file.open(path, std::ios::in);
            if (!this->file.is_open()) throw std::runtime_error("Failed to create the file.");
        }
    }
    else {
        this->file.open(path, std::ios::in);
        if (!this->file.is_open()) throw std::runtime_error("File cannot be opened or does not exists");
    }
    this->path = path;
}

void Filer::read (std::string& str) {
    if (!this->file.is_open()) throw std::runtime_error("File does not open now");
    
    this->mutex.lock();

    this->file.close();
    this->file.open(this->path, std::ios::in);

    this->file.seekg(0, std::ios::beg);
    std::string temp;

    this->file.seekp(0, std::ios::beg);
    while (std::getline(this->file, temp)) str += temp + '\n';
    
    this->mutex.unlock();
}

void Filer::readToList (List <Professor>& unit) {
    if (!this->file.is_open()) throw std::runtime_error("File does not open now");
    
    this->mutex.lock();

    this->file.close();
    this->file.open(this->path, std::ios::in);

    this->file.seekg(0, std::ios::beg);
    std::string temp;
    Professor node;
    while (std::getline(this->file, temp)) {
        node = Professor();
        this->stringToProfessor(node, temp);
        unit.append(node);
    }

    this->mutex.unlock();
}

void Filer::writeBack (std::string& string) {
    if (!this->file.is_open()) throw std::runtime_error("File does not open now");
    else if (string.empty()) return;

    this->mutex.lock();

    this->file.close();
    this->file.open(this->path, std::ios::out | std::ios::app);

    this->file << string << '\n';
    this->file.flush();
    this->mutex.unlock();
}

void Filer::writeBackFromProfessor (const Professor& unit) {
    if (!this->file.is_open()) throw std::runtime_error("File does not open now");

    this->mutex.lock();

    this->file.close();
    this->file.open(this->path, std::ios::out | std::ios::app);

    this->file << 
        unit.getUniversity() << "$$" <<
        unit.getDepartment() << "$$" <<
        unit.getPost() << "$$" <<
        unit.getFullName() << "$$" <<
        unit.getBirthYear() << "$$" <<
        unit.getAcademicDegree() << "$$" <<
        unit.getSubjects() << '\n'
    ;
    this->file.flush();
    
    this->mutex.unlock();
}

void Filer::rewrite (std::string& string) {
    if (!this->file.is_open()) throw std::runtime_error("File does not open now");
    else if (string.empty()) return;

    this->mutex.lock();

    this->file.close();
    this->file.open(this->path, std::ios::out | std::ios::trunc);

    this->file << string << '\n';
    this->file.flush();

    this->mutex.unlock();
}

void Filer::rewriteFromList (const List <Professor>& unit) {
    if (!this->file.is_open()) throw std::runtime_error("File does not open now");
    else if (unit.length() == 0) return;

    this->mutex.lock();

    this->file.close();
    this->file.open(this->path, std::ios::out | std::ios::trunc);

    if (this->file.fail()) {
        std::cerr << "Error: File in failed state before operation" << std::endl;
    }

    this->file.seekg(0, std::ios::beg);

    for (unsigned int i = 0; i < unit.length(); ++i) {
        std::string toOut = 
            unit[i].getUniversity() + "$$" +
            unit[i].getDepartment() + "$$" +
            unit[i].getPost() + "$$" +
            unit[i].getFullName() + "$$" +
            std::to_string(unit[i].getBirthYear()) + "$$" +
            unit[i].getAcademicDegree() + "$$" +
            unit[i].getSubjects() + '\n'
        ;
        this->file.write(toOut.c_str(), toOut.size());
        if (this->file.fail()) {
            std::cerr << "Error: Failed to write record " << i << std::endl;
            std::cerr << "Error state: " << this->file.rdstate() << std::endl;
        }
    }
    this->file.flush();

    this->mutex.unlock();
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
    catch (std::exception) {
        unit.setBirthYear(0); 
    }
    unit.setAcademicDegree(arr[5]);
    unit.setSubjects(arr[6]);
}
