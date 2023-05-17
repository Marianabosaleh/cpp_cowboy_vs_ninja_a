#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <string>
#include "Character.hpp"
#include "Point.hpp"
using namespace std;
namespace ariel
{
    class Ninja : public Character
    {
        int speed;

    public:
        // Default constructor
        Ninja();
        // Constructor with location and name
        Ninja(string name, Point location);
        // destructor
        ~Ninja(void);
        // Getter and Setter
        int getspeed();
        void setspeed(int speed);
        // functions
        virtual void move(Character *anamy);
        void slash(Character *anamy);
        string print() override;
    };

    class YoungNinja : public Ninja
    {

    public:
        // constructors:
        YoungNinja(string name, Point location);
        ~YoungNinja(void);
        string print() override;
    };

    class TrainedNinja : public Ninja
    {

    public:
        // constructors:
        TrainedNinja(string name, Point location);
        ~TrainedNinja(void);
        string print() override;
    };

    class OldNinja : public Ninja
    {

    public:
        // constructors:
        OldNinja(string name, Point location);
        ~OldNinja(void);
        string print() override;
    };
}
