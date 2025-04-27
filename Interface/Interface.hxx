#ifndef INTERFACE_HXX
#define INTERFACE_HXX


#include <iostream>
#include <Professor.hxx> 
#include <List.hxx>
#include <Database.hxx>
#include <limits>


class Interface {
private:
    Database unit;
    void displayMenu (void);
    void getProfessor (Professor& unit);
    int removeProfessor (void);
    void clearInputBuffer (void);
public:
    Interface (void);
    Interface (const Interface& unit) = delete;
    Interface& operator= (const Interface& unit) = delete;
    ~Interface (void) noexcept = default;
    void pool (void);
};


#endif // INTERFACE_HXX