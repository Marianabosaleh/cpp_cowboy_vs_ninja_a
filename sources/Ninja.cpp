#include "Ninja.hpp"

namespace ariel
{

    // Default constructor
    Ninja::Ninja() : Character(), speed(0) {}

    // Constructor with location and name
    Ninja::Ninja(string name, Point location) : Character(name, location), speed(0) {}


    // Destructor
    Ninja::~Ninja()
    {
    }

    // Getter
    int Ninja::getspeed()
    {
        return speed;
    }

    // Setter
    void Ninja::setspeed(int speed)
    {
        this->speed = speed;
    }

    // Member functions
    void Ninja::move(Character *anamy)
    {
    }

    void Ninja::slash(Character *anamy)
    {
    }
    std::string Ninja::print()
    {
        return ("print");
    }

    // YoungNinja constructor
    YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location) {}
    // Destructor
    YoungNinja::~YoungNinja()
    {
    }
    std::string YoungNinja::print()
    {
        return ("print");
    }

   

    // TrainedNinja constructor
    TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location) {}
    // Destructor
    TrainedNinja::~TrainedNinja()
    {
    }
    std::string TrainedNinja::print()
    {
        return ("print");
    }

    

    // OldNinja constructor
    OldNinja::OldNinja(string name, Point location) : Ninja(name, location) {}
    // Destructor
    OldNinja::~OldNinja()
    {
    }
    std::string OldNinja::print()
    {
        return ("print");
    }

    

}
