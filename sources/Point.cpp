#include "Point.hpp"
using namespace std;
namespace ariel
{
    Point::Point() : value_x(0), value_y(0) {}
    Point::Point(double value_x, double value_y) : value_x(value_x), value_y(value_y) {}
    Point::~Point(){}
    double Point::getx() const
    {
        return value_x;
    }

    double Point::gety() const
    {
        return value_y;
    }

    void Point::setx(double value_x)
    {
        this->value_x = value_x;
    }

    void Point::sety(double value_y)
    {
        this->value_y = value_y;
    }

    double Point::distance(Point &other)
    {
        return 0.0;
    }

    string Point::print()
    {
        return("print");
    }

    Point Point::moveTowards(Point point_s, Point point_t, double dis)
    {
        return *this;
    }
    Point& Point::operator= (const Point& other){
        return *this;
    }

    bool Point::operator== (const Point& other) const {
        return false;
    }
}
