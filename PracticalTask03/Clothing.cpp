#include "Clothing.h"
#include <iostream>
#include <fstream>

using namespace std;

Clothing::Clothing(string name, double p, int q, string m) : Item(name, p, q){
    material = m;
};
void Clothing::setMaterial(string m){
    material = m;
}
string Clothing::getMaterial(){
    return material;
}
void Clothing::display() const{
    Item::display();
    cout << ", Material: " << material << endl;
    cout << endl;
}
void Clothing::persist(ofstream& out) const{
    out << " 3 | ";
    persistCommonFields(out);
    out << " | " << material << endl;
}