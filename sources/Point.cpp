#include "Point.hpp"
#include <cmath>

using namespace ariel;
using namespace std;
Point::Point() : x(0), y(0) {
}
Point::Point(double x, double y) : x(x), y(y)
{
}
double Point::distance(const Point& other) const{
    double dx = this->x - other.x;
    double dy = this->y - other.y;
    return sqrt(dx*dx + dy*dy);
}
double Point::getX()
{
    return this->x;
}
double Point::getY()
{
    return this->y;
}

void ariel::Point::setX(double x)
{
    this->x = x;
}
void ariel::Point::setY(double y)
{
    this->y = y;
}
string Point::print() const{
    return "x: "+to_string(x)+ " y: "+to_string(y);
}
Point Point::moveTowards(const Point& start,  const Point& end, double dis){
    if (dis<0)
    {
        throw invalid_argument("distance needs to be positive");
    }
    double d = start.distance(end),newx=0,newy=0;
    if (d <= dis) {
        return Point(end.x,end.y);
    }
    // else {
        newx = (1 - dis / d) * start.x + dis / d * end.x;
        newy = (1 - dis / d) * start.y + dis / d * end.y;
    // }
    return Point(newx,newy);
}