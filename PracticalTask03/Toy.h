#ifndef Toy_H
#define Toy_H

#include "item.h"

class Toy : public Item{
    private:
        bool size;
    public:
        Toy(std::string name, int q, double p, bool s);

        void setSize(bool s);
        bool getSize();

        void display() const override;

        void persist(std::ofstream& out) const override;
};

#endif