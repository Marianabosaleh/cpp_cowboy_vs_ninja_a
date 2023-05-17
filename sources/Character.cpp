#include "Character.hpp"

namespace ariel
{
    // Default constructor
    Character::Character() : location(Point()), hit_point(0), name("") {}
    Character::Character(string name, Point location) : name(name), location(location) {}
    // Destructor
    Character::~Character() {}

    // Getters
    Point Character::getLocation() const
    {
        return location;
    }

    int Character::getHit_point() const
    {
        return hit_point;
    }

    string Character::getName() const
    {
        return name;
    }

    // Setters
    void Character::setLocation(Point location)
    {
        this->location = location;
    }

    void Character::setHit_point(int hit_point)
    {
        this->hit_point = hit_point;
    }

    void Character::setName(string name)
    {
        this->name = name;
    }

    // Member functions
    bool Character::isAlive()
    {
        return false;
    }

    double Character::distance(Character &other)
    {
        return 0.0;
    }

    int Character::hit(int hits)
    {
        return 0;
    }

    std::string Character::print()
    {
        return ("print");
    }

}
