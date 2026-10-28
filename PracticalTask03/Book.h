#ifndef Book_H
#define Book_H

#include "item.h"

class Book : public Item {
    private:
        int isbn;
        std::string author;
    public:
        Book(std::string name, double p, int q, int i, std::string);

        void setISBN(int i);
        void setAuthor(std::string a);
        int getISBN();
        std::string getAuthor();

        void display() const override;

        void persist(std::ofstream& out) const override;
};

#endif