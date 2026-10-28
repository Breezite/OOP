#include "Book.h"
#include <iostream>
#include <fstream>

using namespace std;

Book::Book(string name, double p, int q, int i, string a) : Item(name, q, p){
    isbn = i;
    author = a;
};
void Book::setISBN(int i){
    isbn = i;
}
void Book::setAuthor(string a){
    author = a;
}
int Book::getISBN(){
    return isbn;
}
string Book::getAuthor(){
    return author;
};
void Book::display() const {
    Item::display();
    cout << ", ISBN: " << isbn << ", Author: " << author << endl;
    cout << endl;
}
void Book::persist(ofstream& out) const{
    out << "4 | ";
    persistCommonFields(out);
    out << " | " << isbn << " | " << author << endl;
}