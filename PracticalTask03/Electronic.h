#ifndef Electronic_H
#define Electronic_H

#include "item.h"

class Electronic : public Item{
    private:
        std::string origin;
        double guarantee;
    public:
        Electronic(std::string name, double p, int q, std::string o, double g);

        void setOrigin(std::string o);
        void setGuarantee(double g);
        std::string getOrigin();
        double getGuarantee();

        void display() const override;
        
        void persist(std::ofstream& out) const override;
};

#endif