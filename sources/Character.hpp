#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <string>
#include "Point.hpp"
using namespace std;
namespace ariel
{

    class Character
    {
        Point location;
        int hit_point;
        string name;

    public:
        // constructors
        Character();
        Character(string name, Point location);
        // destructor
        virtual ~Character(void); 
        // Getter and Setter
        Point getLocation() const;
        int getHit_point() const;
        string getName() const;
        void setLocation(Point location);
        void setHit_point(int hit_point);
        void setName(string name);
        // functions
        bool isAlive();
        double distance(Character &other);
        int hit(int hits);
        virtual string print();
    };

}
