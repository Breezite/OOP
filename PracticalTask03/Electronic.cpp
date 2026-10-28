#include "Electronic.h"
#include <iostream>
#include <fstream>

using namespace std;

Electronic::Electronic(string name, double p, int q, string o, double g) : Item(name, p, q){
    origin = o;
    guarantee = g;
};
void Electronic::setOrigin(string o){
    origin = o;
};
void Electronic::setGuarantee(double g){
    guarantee = g;
}
string Electronic::getOrigin(){
    return origin;
}
double Electronic::getGuarantee(){
    return guarantee;
}
void Electronic::display() const {
    Item::display();
    cout << ", Made in " << origin << ", Guarantee left: " << guarantee << endl;
    cout << endl;
}

void Electronic::persist(ofstream& out) const{
    out << "2 | ";
    persistCommonFields(out);
    out << " | " << origin << " | " << guarantee << endl;
}