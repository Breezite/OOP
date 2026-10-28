#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item{
    private:
        std::string name;
        int quantity;
        double price;
    
    protected:
        void persistCommonFields(std::ofstream& out) const;
    
    public:
        Item(std::string n, int q, double p);

        void setName(std::string n);
        void setQuantity(int q);
        void setPrice(double p);
        std::string getName();
        int getQuantity();
        double getPrice();

        virtual void display() const;

        virtual void persist(std::ofstream& out) const;

        virtual ~Item() = default;
};

#endif