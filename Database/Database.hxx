#ifndef DATABASE_HXX
#define DATABASE_HXX


#include <List.hxx>
#include <Professor.hxx>
#include <Filer.hxx>
#include <ctime>


class Database {
private:
    List <Professor> data;
public:
    Database (void) noexcept = default;
    Database (const List <Professor>& unit) noexcept;
    Database (const Database& unit) noexcept;
    ~Database (void) noexcept = default;
    Database& operator= (const Database& unit) noexcept;
    Professor& operator[] (const unsigned int index) noexcept;
    const Professor& operator[] (const unsigned int index) const noexcept;
    void append (const Professor& unit) noexcept;
    void remove (const unsigned int index) noexcept;
    void searchProfessorsWithAcademicDegree (List <Professor>& unit) const noexcept;
    void searchProfessorsOver45 (List <Professor>& unit) const noexcept;
    double calculateAverageAge (void) const noexcept;
};


#endif // DATABASE_HXX