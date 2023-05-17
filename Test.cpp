#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <math.h>
#include "Point.hpp"
#include "Team.hpp"
#include "Point.hpp"
#include "Character.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Creating new Points")
{
    CHECK_THROWS(Point(2, 2));
    CHECK_THROWS(Point(2.777, 2.46));
    CHECK_THROWS(Point(-2, -2.2));
}
TEST_CASE("Testing the distance function")
{
    Point p1(10, 3.5);
    Point p2(-0.5, -8);

    double expected_d = sqrt(242.5);
    double d = p1.distance(p2);
    CHECK(abs(d - expected_d) < 0.001);
}
TEST_CASE("Testing the moveTowards function")
{
    Point p1(0, 0);   // source point
    Point p2(10, 10); // target point
    double distance = 1.0;

    Point p = p1.moveTowards(p1, p2, distance);
    double expected_d = p1.distance(p);
    CHECK(abs(expected_d - distance) <= 0.001);
}
TEST_CASE("getters & setters")
{
    Point p1(1, 1);
    Point p2;
    p1.setx(2);
    CHECK_EQ(p1.getx(), 2);
    CHECK_EQ(p1.gety(), 1);
    p1.sety(2);
    CHECK_EQ(p1.getx(), 2);
    CHECK_EQ(p1.gety(), 2);
}
TEST_CASE("testing the operator=, ==")
{
    Point p1(4, 0);
    Point p2(4, 0);
    Point p3(2, -2);
    Point p4;
    p4 = p1;
    CHECK_EQ(p1, p4);
    CHECK_EQ(p1, p2);
    CHECK_NE(p2, p3);
    CHECK_NE(p1, p3);
}
//-------------------------------------------------------------------------
TEST_CASE("Creating new Character ")
{
    Point p1(2, 2);
    CHECK_THROWS(Character("Character", p1));
}

TEST_CASE("Testing isAlive function and hit points ")
{
    Point p1(2, 2);
    Character Character1("Character1", p1);
    Point p2(5, 5);
    Character Character2("Character2", p2);
    Character1.hit(0);
    CHECK(Character1.isAlive() == true);
    Character2.hit(1);
    CHECK(Character2.isAlive() == false);
}
TEST_CASE("Testing the distance function")
{
    Point p1(1, 1);
    Character Character1("Character1", p1);
    Point p2(5, 5);
    Character Character2("Character2", p2);
    double d = sqrt(32);
    double actual_d = Character1.distance(Character2);
    CHECK(abs(actual_d - d) <= 0.001);
}
TEST_CASE("Testing name of character")
{
    Point p1(0, 0);
    Point p2(5, 5);
    Character Character1("Character1", p1);
    Character Character2("Character2", p2);
    CHECK(Character1.getName() == "Character1");
    Character2.setName("marian");
    CHECK(Character2.getName() == "marian");
}
TEST_CASE("Testing location of character")
{
    Point p(0, 0);
    Point p1(1, 1);
    Point p2(5, 5);
    Character Character0("Character0", p);
    Character Character1("Character1", p1);
    Character Character2("Character2", p2);
    CHECK(Character0.getLocation() == p);
    Character1.setLocation(p2);
    Point p3;
    p3 = Character1.getLocation();
    CHECK_EQ(p3, p1);
    CHECK_NE(p1, p2);
}


//---------------------------------------------------------------------
TEST_CASE("Creating new Cowboy Character ")
{
    Point p1(7.22, 7.01);
    CHECK_THROWS(Cowboy("Cowboy", p1));
}
TEST_CASE("test for the reload function")
{
    Cowboy Cowboy("Cowboy", Point(22, 7));
    CHECK_EQ(Cowboy.getName(), "Cowboy");
    CHECK(Cowboy.hasboolets() == false);

    Cowboy.reload();
    CHECK(Cowboy.hasboolets() == true);
}
TEST_CASE("test for the shoot function")
{
    Cowboy Cowboy("Cowboy", Point(-2, -0.2));
    Character Enemy("Enemy", Point(1, 1));
    Cowboy.reload();
    CHECK(Cowboy.hasboolets() == true);
    Cowboy.shoot(&Enemy);
    CHECK(Enemy.isAlive() == false);
}
//------------------------------------------------------------------------------------------
TEST_CASE("Creating new Ninja Character ")
{
    Point p3(100, 200);
    CHECK_THROWS(Ninja("Ninja ", p3));
}
TEST_CASE("Test the move function")
{
    Ninja Ninja("Ninja", Point(10, 10));

    CHECK_EQ(Ninja.getName(),  "Ninja");
    CHECK_EQ(Ninja.getLocation(), Point(10, 10));
    Character Enemy("Enemy", Point(1, 1));
    Ninja.move(&Enemy);
    CHECK_EQ(Ninja.getName(),  "Ninja");
    CHECK_EQ(Ninja.getLocation(), Point(11, 11));
}
TEST_CASE("Test the slash function")
{
    Ninja Ninja("Ninja", Point(1, 1));
    Character Enemy("Enemy", Point(1, 1));
    Ninja.slash(&Enemy);
    CHECK_FALSE(Enemy.isAlive());
}
TEST_CASE("Test moving and slashing")
{
    Ninja Ninja("Ninja", Point(3, 3));
    Character Enemy("Enemy", Point(2, 2));
    Ninja.move(&Enemy);
    CHECK_EQ(Ninja.getName(),  "Ninja");
    CHECK_EQ(Ninja.getLocation(), Point(5, 5));
    Ninja.slash(&Enemy);
    CHECK_FALSE(Enemy.isAlive());
}

//------------------------------------------------------------------------------------------
TEST_CASE("Creating new YoungNinja Character ")
{
    Point p4(12, 3.3);
    CHECK_THROWS(YoungNinja("YoungNinja ", p4));
}
//------------------------------------------------------------------------------------------
TEST_CASE("Creating new TrainedNinja Character ")
{
    Point p5(-1.11, -10.2);
    CHECK_THROWS(TrainedNinja("TrainedNinja ", p5));
}
//------------------------------------------------------------------------------------------
TEST_CASE("Creating new OldNinja Character ")
{
    Point p6(0, 0);
    CHECK_THROWS(OldNinja("OldNinja ", p6));
}
//------------------------------------------------------------------------------------------
TEST_CASE("Test creating Team and Adding characters ")
{
    Cowboy* cowboy = new Cowboy("Cowboy", Point(0,0));
    Team team(cowboy);

    CHECK(team.stillAlive() == 1);

    team.add(new Cowboy("Cowboy1", Point(1, 1)));
    team.add(new Cowboy("Cowboy2", Point(2, 2)));
    team.add(new Cowboy("Cowboy3", Point(3, 3)));

    CHECK(team.stillAlive() == 4);
}
TEST_CASE("Test creating Team2 and Adding characters ")
{
    Ninja* ninja = new Ninja("Ninja", Point(0,0));
    Team2 team2(ninja);

    CHECK(team2.stillAlive() == 1);

    team2.add(new TrainedNinja("TrainedNinja", Point(1, 1)));
    team2.add(new OldNinja("OldNinja", Point(2, 2)));
    team2.add(new YoungNinja("YoungNinja", Point(3, 3)));

    CHECK(team2.stillAlive() == 4);
}
TEST_CASE("Test creating SmartTeam and Adding characters ")
{
    TrainedNinja* trainedNinja = new TrainedNinja("TrainedNinja", Point(0,0));
    SmartTeam smartTeam(trainedNinja);

    CHECK(smartTeam.stillAlive() == 1);

    smartTeam.add(new TrainedNinja("TrainedNinja2", Point(1, 1)));

    CHECK(smartTeam.stillAlive() == 2);
}