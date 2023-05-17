#include "Cowboy.hpp"

namespace ariel
{

    // Default constructor
    Cowboy::Cowboy() : Character(), balls(0) {}

    // Constructor with location and name
    Cowboy::Cowboy(string name, Point location) : Character(name, location), balls(0) {}
    
    // Destructor
    Cowboy::~Cowboy()
    {
    }
    // Getter
    int Cowboy::getballs()
    {
        return balls;
    }

    // Setter
    void Cowboy::setballs(int balls)
    {
        this->balls = balls;
    }

    // Member functions
    void Cowboy::shoot(Character *anamy)
    {
    }

    bool Cowboy::hasboolets()
    {
        return true;
    }

    void Cowboy::reload()
    {
    }
    std::string Cowboy::print()
    {
        return ("print");
    }

}
