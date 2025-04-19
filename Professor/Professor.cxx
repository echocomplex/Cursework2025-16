#include "Professor.hxx"

Professor::Professor () noexcept {
    this->birth_year = 0;
}

Professor::Professor (const std::string& university, const std::string& department, const std::string& post, const std::string& full_name, const unsigned short birth_year, const std::string& academic_degree, const std::string& subjects) noexcept {
    this->university = university;
    this->department = department;
    this->post = post;
    this->full_name = full_name;
    this->birth_year = birth_year;
    this->academic_degree = academic_degree;
    this->subjects = subjects;
}

std::string Professor::getUniversity () const noexcept {
    return this->university;
}

std::string Professor::getDepartment () const noexcept {
    return this->department;
}

std::string Professor::getPost () const noexcept {
    return this->post;
}

std::string Professor::getFullName () const noexcept {
    return this->full_name;
}

unsigned short Professor::getBirthYear () const noexcept {
    return this->birth_year;
}

std::string Professor::getAcademicDegree () const noexcept {
    return this->academic_degree;
}

std::string Professor::getSubjects () const noexcept {
    return this->subjects;
}

void Professor::setUniversity (const std::string& university) noexcept {
    this->university = university;
}

void Professor::setDepartment (const std::string& department) noexcept {
    this->department = department;
}

void Professor::setPost (const std::string& post) noexcept {
    this->post = post;
}

void Professor::setFullName (const std::string& full_name) noexcept {
    this->full_name = full_name;
}

void Professor::setBirthYear (const unsigned short birth_year) noexcept {
    this->birth_year = birth_year;
}

void Professor::setAcademicDegree (const std::string& academic_degree) noexcept {
    this->academic_degree = academic_degree;
}

void Professor::setSubjects (const std::string& subjects) noexcept {
    this->subjects = subjects;
}