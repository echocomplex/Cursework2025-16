#ifndef DATABASE_HXX
#define DATABASE_HXX

#include <List.hxx>
#include <Professor.hxx>

class Database {
private:
    List <Professor> data;

public:
    Database () noexcept = default;
    Database (const List <Professor>& unit) noexcept;
    Database (const Database& unit) noexcept;

};

#endif // DATABASE_HXX