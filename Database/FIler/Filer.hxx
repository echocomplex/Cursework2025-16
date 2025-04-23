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
    ~Filer (void) noexcept;
    void read (std::string& str) noexcept;
    void readToList (List <Professor>& unit) noexcept;
    void writeBack (std::string& string) noexcept;
    void writeBackFromList (const Professor& unit) noexcept;
    void rewrite (std::string& string) noexcept;
    void rewriteFromList (const List <Professor>& unit) noexcept;
    static void stringToProfessor (Professor& unit, const std::string& str);
};

#endif // FILER_HXX