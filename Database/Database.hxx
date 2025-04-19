#ifndef DATABASE_HXX
#define DATABASE_HXX

#include <List.hxx>
#include <Professor.hxx>

class Database {
private:
    List <Professor> data;

public:
    Database (void) noexcept = default;
    Database (const List <Professor>& unit) noexcept;
    Database (const Database& unit) noexcept;
    ~Database (void) = default;
    Database& operator= (const Database& unit) noexcept;
    Professor& operator[] (const unsigned int index);
    void append (const Professor& unit) noexcept;
    void remove (const unsigned int index);
    void searchProfessorsWithAcademicDegree (List <Professor>& unit) const noexcept;
    void searchProfessorsOver45 (List <Professor>& unit) const noexcept;
    double calculateAverageAge () const noexcept;
};

#endif // DATABASE_HXX