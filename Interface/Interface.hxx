#ifndef INTERFACE_HXX
#define INTERFACE_HXX


#include <iostream>
#include <Professor.hxx> 
#include <List.hxx>
#include <Database.hxx>


class Interface {
private:
    Database unit;
public:
    Interface (void) noexcept = default;
    void execute (void);
};


#endif // INTERFACE_HXX