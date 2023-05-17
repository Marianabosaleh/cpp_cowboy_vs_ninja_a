#include "Team.hpp"

namespace ariel
{

    Team::Team(){}
    

    Team::Team(Character *leader) : leader(leader){}
    Team::~Team(){}
    void Team::add(Character *character)
    {
    }

    void Team::attack(Team *enemys)
    {
    }

    int Team::stillAlive()
    {
        return 0;

    }
    std::string Team::print()
    {
        return ("print");
    }


    // Team2 Constructors
    Team2::Team2() : Team() {}

    Team2::Team2(Character *leader) : Team(leader) {}

    void Team2::add(Character *character) 
    {
    }

    Team2::~Team2()
    {
    }
    std::string Team2::print()
    {
        return ("print");
    }
    // SmartTeam Constructors
    SmartTeam::SmartTeam() : Team() {}

    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

    void SmartTeam::add(Character *character)
    {
    }

    SmartTeam::~SmartTeam()
    {
    }
    std::string SmartTeam::print()
    {
        return ("print");
    }
}
