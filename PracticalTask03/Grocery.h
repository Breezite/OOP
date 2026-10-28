#ifndef Grocery_H
#define Grocery_H

#include "item.h"
#include <iostream>
#include <ctime>

struct Date{
    int day;
    int month;
    int year;
};

class Grocery : public Item{
    private:
        Date expiry;
    
    public:
        Grocery(std::string name, int q, double p, Date d);

        void setExpiry(Date d);
        Date getExpiry();

        void display() const override;

        void persist(std::ofstream& out) const override;
};

#endif