#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
using namespace std;
namespace ariel
{
    class Team
    {
        std::vector<Character *> team;
        Character *leader;

    public:
        Team();
        Team(Character *leader);
        virtual void add(Character *character);
        void attack(Team *enemys);
        int stillAlive();
        virtual string print();
        ~Team();
  
    };

    class Team2 : public Team
    {
        std::vector<Character *> team2;
        Character *leader;

    public:
        Team2();
        Team2(Character *leader);
        void add(Character *character) override;
        ~Team2();
        string print() override;
    };

    class SmartTeam : public Team
    {
        std::vector<Character *> smart_team;
        Character *leader;

    public:
        SmartTeam();
        SmartTeam(Character *leader);
        void add(Character *character) override;
        ~SmartTeam();
        string print() override;
    };

}
