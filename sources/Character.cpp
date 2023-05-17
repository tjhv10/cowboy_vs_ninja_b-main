#include "Character.hpp"
#include <iostream>

using namespace ariel;
using namespace std;
Character::Character(string name, Point location, int health):name(name) , location(location), health(health)
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
    return "Name: "+ this->name + ". Location: " +this->location.print() +". Hit points:"+ to_string(this->health)+"\n";
}         
void Character::hit(int num){
    if(num<0)
    {
        throw invalid_argument("You need to hit a positive number of points.");
    }
    this->health -=num;
}
int Character::getHealth() {
    return this->health;
}
bool Character::isAlive()const{

    return health>0;
}
string Character::getName() const{
    return this->name;
}

