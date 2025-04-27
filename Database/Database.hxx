#ifndef DATABASE_HXX
#define DATABASE_HXX


#include <List.hxx>
#include <Professor.hxx>
#include <Filer.hxx>
#include <iostream>
#include <Crypter.hxx>
#include <ctime>


class Database {
protected:
    Filer file;
    std::string filename;
    std::string filename_enc;
    List <Professor> data;
    Crypter crypter;
public:
    Database (void);
    Database (const std::string& filename);
    Database (const List <Professor>& unit, const std::string& filename);
    Database (const Database& unit);
    ~Database (void);
    Database& operator= (const Database& unit) noexcept;
    Professor& operator[] (const unsigned int index) noexcept;
    friend std::ostream& operator<< (std::ostream& os, const Database& unit);
    const Professor& operator[] (const unsigned int index) const noexcept;
    void append (const Professor& unit) noexcept;
    void remove (const unsigned int index) noexcept;
    unsigned int size () noexcept;
    void searchProfessorsWithAcademicDegree (List <Professor>& unit) const noexcept;
    void searchProfessorsOver45 (List <Professor>& unit) const noexcept;
    double calculateAverageAge (void) const noexcept;
};


#endif // DATABASE_HXX