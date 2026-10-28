#include "item.h"
#include <iostream>
#include <fstream>

using namespace std;

Item::Item(string n, int q, double a){
    name=n;
    quantity=q;
    price=a;
}

void Item::setName(string n){
    name = n;
}
void Item::setQuantity(int q){
    quantity = q;
}
void Item::setPrice(double p){
    price = p;
}

string Item::getName(){
    return name;
}
int Item::getQuantity(){
    return quantity;
}
double Item::getPrice(){
    return price;
};

void Item::display() const {
    cout << "Name: " << name << ", Individual Price: " << price << ", Quantity: " << quantity;
};

void Item::persist(std::ofstream& out) const{
    out << "0 | ";
    persistCommonFields(out);
    out << std::endl;
}
void Item::persistCommonFields(std::ofstream& out) const{
    out << name << " | " << quantity << " | " << price;
}