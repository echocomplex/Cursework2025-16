#include <List.hxx>
#include <Filer.hxx>
#include <Professor.hxx>
#include <iostream>

int main (void) {
    Filer unit("input.txt");
    List <Professor> list;
    unit.readToList(list);
    for (unsigned short i = 0; i < list.length(); ++i) {
        std::cout << list[i] << std::endl;
    }
    return 0;
}