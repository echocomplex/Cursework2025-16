#include <List.hxx>
#include <Filer.hxx>
#include <Professor.hxx>
#include <Interface.hxx>
#include <Database.hxx>
#include <iostream>

// int main (void) {
//     Database db("input.txt");
//     std::cout << db << std::endl;
//     Professor prof(
//         "MIT",
//         "Computer Science",
//         "Senior Lecturer",
//         "John Doe",
//         1975,
//         "",
//         "Algorithms, Data Structures"
//  // int main (void) {   std::cout << db << std::endl;

//     std::cout << "-----------" << std::endl << std::endl;

//     db.remove(0);
//     std::cout << db << std::endl;

//     std::cout << "-----------" << std::endl << std::endl;
    
//     List <Professor> l;
//     db.searchProfessorsOver45(l);
//     for (int i = 0; i < l.length(); ++i) std::cout << l[i] << std::endl;
//     l.clear();

//     std::cout << "-----------" << std::endl << std::endl;
    
//     db.searchProfessorsWithAcademicDegree(l);
//     for (int i = 0; i < l.length(); ++i) std::cout << l[i] << std::endl;
//     l.clear();

//     std::cout << "-----------" << std::endl;
    
//     std::cout << db.calculateAverageAge() << std::endl;
//     return 0;
// }

int main (void) {
    Interface interface;
    interface.pool();
    return 0;
}