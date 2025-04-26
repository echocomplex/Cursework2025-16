#ifndef FILER_HXX
#define FILER_HXX


#include <fstream>
#include <string>
#include <stdexcept>
#include <mutex>
#include <List.hxx>
#include <Professor.hxx>

class Filer {
private:
    std::fstream file;
    std::mutex mutex;
public:
    Filer (void) noexcept = default;
    Filer (const std::string& path, const bool createNew = false);
    ~Filer (void) noexcept;
    void open (const std::string& path);
    void read (std::string& str);
    void readToList (List <Professor>& unit);
    void writeBack (std::string& string);
    void writeBackFromList (const Professor& unit);
    void rewrite (std::string& string);
    void rewriteFromList (const List <Professor>& unit);
    static void stringToProfessor (Professor& unit, const std::string& str);
};

#endif // FILER_HXX