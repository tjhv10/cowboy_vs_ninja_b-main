#include "Point.hpp"
#include <cmath>

using namespace ariel;
using namespace std;
Point::Point() : x(0), y(0) {

}
Point::Point(double x, double y): x(x), y(y){
    
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
void Point::moveTowards(Point& start, Point& end, double dis){
    double d = start.distance(end);
    if (d <= dis) {
        start = end;
    }
    else {
        start.setX((1 - dis / d) * start.x + dis / d * end.x);
        start.setY((1 - dis / d) * start.y + dis / d * end.y);
    }
}