#ifndef PROFESSOR_HXX
#define PROFESSOR_HXX


#include <string>
#include <iostream>


class Professor {
private:
    std::string university;
    std::string department;
    std::string post;
    std::string full_name;
    unsigned short birth_year;
    std::string academic_degree;
    std::string subjects;

public:
    Professor (void) noexcept;
    Professor (const std::string& university, const std::string& department, const std::string& post, const std::string& full_name, const unsigned short birth_year, const std::string& academic_degree, const std::string& subjects) noexcept;
    ~Professor (void) noexcept = default;
    Professor& operator= (const Professor& unit) noexcept;
    friend std::ostream& operator<< (std::ostream& os, const Professor& unit);
    std::string getUniversity (void) const noexcept;
    std::string getDepartment (void) const noexcept;
    std::string getPost (void) const noexcept;
    std::string getFullName (void) const noexcept;
    unsigned short getBirthYear (void) const noexcept;
    std::string getAcademicDegree (void) const noexcept;
    std::string getSubjects (void) const noexcept;
    void setUniversity (const std::string& university) noexcept;
    void setDepartment (const std::string& department) noexcept;
    void setPost (const std::string& post) noexcept;
    void setFullName (const std::string& full_name) noexcept;
    void setBirthYear (const unsigned short birth_year) noexcept;
    void setAcademicDegree (const std::string& academic_degree) noexcept;
    void setSubjects (const std::string& subjects) noexcept;
};

#endif // PROFESSOR_HXX