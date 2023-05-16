#include "Character.hpp"
#include <iostream>

using namespace ariel;
using namespace std;
Character::Character(string name, Point location, int hit_points):name(name) , location(location), hit_points(hit_points)
{
}

Point Character::getLocation() const{
    return location;
}
void Character::setX(double x) 
{
    this->location.setX(x);
}
void Character::setY(double y)
{
    this->location.setY(y);
}
double Character::distance(const Character* other) const{
    return this->location.distance(other->getLocation());
}
string Character::print(){
    return "Name: "+ this->name + ". Location: " +this->location.print() +". Hit points:"+ to_string(this->hit_points)+"\n";
}         
void Character::hit(int num){
    if(num<0)
    throw invalid_argument("You need to hit a positive number of points.");
    this->hit_points -=num;
}
int Character::getHealth() {
    return this->hit_points;
}
bool Character::isAlive() const{
    if(this->hit_points>0)
        return true;
    return false;
}
string Character::getName() const{
    return this->name;
}

