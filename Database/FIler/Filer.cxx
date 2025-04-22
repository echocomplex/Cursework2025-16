#include "Filer.hxx"

Filer::Filer (const std::string& path, bool createNew = false) {
    if (createNew) {
        this->file.open(path, std::ios::in | std::ios::ate);
        if (!this->file.is_open()) {
            this->file.open(path, std::ios::out);
            this->file.close();
            this->file.open(path, std::ios::in | std::ios::ate);
        }
    }
    else {
        this->file.open(path, std::ios::in | std::ios::out);
        if (!file.is_open()) throw std::runtime_error("File is broken or does not exists");
    }
}