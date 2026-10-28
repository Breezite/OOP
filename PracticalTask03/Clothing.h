#ifndef Clothing_H
#define Clothing_H

#include "item.h"

class Clothing : public Item{
    private:
        std::string material;
    public:
        Clothing(std::string name, double p, int q, std::string m);

        void setMaterial(std::string m);
        std::string getMaterial();

        void display() const override;

        void persist(std::ofstream& out) const override;
};

#endif