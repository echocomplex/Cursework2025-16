#ifndef FILER_HXX
#define FILER_HXX


#include <fstream>
#include <string>
#include <stdexcept>
#include <List.hxx>
#include <Professor.hxx>


class Filer {
private:
    std::fstream file;
public:
    Filer (const std::string& path, bool createNew = false);
    ~Filer () noexcept;
    std::string read ();
    void readToList (List <Professor> unit);
    void writeBack (std::string& string) noexcept;
    void writeBackFromUnit (const Professor& unit) noexcept;
    void rewrite (std::string& string) noexcept;
    void rewriteFromList (const List <Professor>& unit) noexcept;
};

#endif // FILER_HXX