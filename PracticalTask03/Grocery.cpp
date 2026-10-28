#include "Grocery.h"
#include <iostream>
#include <fstream>

using namespace std;

Grocery::Grocery(string name, int q, double p, Date d) : Item(name, q, p){
    expiry = d;
}

void Grocery::setExpiry(Date d){
    expiry = d;
}
Date Grocery::getExpiry(){
    return expiry;
}

void Grocery::display() const {
    Item::display();
    cout << ", Expiry Date: " << expiry.day << "/" << expiry.month << "/" << expiry.year << endl;
    cout << endl;
}

void Grocery::persist(ofstream& out) const{
    out << "1 | ";
    persistCommonFields(out);
    out << " | " << expiry.day << " | " << expiry.month << " | " << expiry.year << endl;
}