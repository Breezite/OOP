#include "Toy.h"
#include <iostream>
#include <fstream>

using namespace std;

Toy::Toy(string name, int q, double p, bool s) : Item(name, q, p){
    size = s;
};
void Toy::setSize(bool s){
    size = s;
}
bool Toy::getSize(){
    return size;    
}
void Toy::display() const {
    Item::display();
    cout << ", Size: " << size << endl;
    cout << endl;
};

void Toy::persist(ofstream& out) const{
    out << "5 | ";
    persistCommonFields(out);
    out << " | " << size << endl;
}