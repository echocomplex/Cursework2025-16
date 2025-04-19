#include "Professor.hxx"

Professor::Professor () noexcept {
    this->birth_year = 0;
}

Professor::Professor (const std::string university, const std::string department, const std::string post, const std::string full_name, const unsigned short birth_year, const std::string academic_degree, const std::string subjects) noexcept {
    this->university = university;
    this->department = department;
    this->post = post;
    this->full_name = full_name;
    this->birth_year = birth_year;
    this->academic_degree = academic_degree;
    this->subjects = subjects;
}