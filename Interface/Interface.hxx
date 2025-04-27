#ifndef INTERFACE_HXX
#define INTERFACE_HXX


#include <iostream>
#include <Professor.hxx> 
#include <List.hxx>
#include <Database.hxx>


class Interface {
private:
    // Database unit;
    void displayMenu (void);
    void clearInputBuffer (void);
public:
    Interface (void) noexcept = default;
    Interface (const Interface& unit) noexcept = delete;
    ~Interface (void) noexcept = default;
    void pool (void);
};


#endif // INTERFACE_HXX