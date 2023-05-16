#include "Ninja.hpp"

using namespace ariel;
using namespace std;

Ninja::Ninja(string name, Point& location, int hit_points, int speed): Character(name, location, hit_points) , speed(speed){
    
}
void Ninja::slash(Character* enemy){
    if (this==enemy)
    {
        throw runtime_error("You cant slash yourself.");
    }
    if(enemy->isAlive()==false)
    throw runtime_error("You cannot attack dead enemy.");
    if(this->isAlive()==false)
    throw runtime_error("You cannot attack an enemy if you are dead.");
    if(this->distance(enemy)<=1)
        if(enemy->isAlive())
            enemy->hit(40);
}
void Ninja::move(const Character* enemy){
    if(this->isAlive()&&enemy->isAlive())
    {
        Point enemyPos =enemy->getLocation();
        Point myPos = this->getLocation();
        Point::moveTowards(myPos,enemyPos, speed);
        this->setX(myPos.getX());
        this->setY(myPos.getY());
    }
}
string Ninja::print() {
    return "Ninja name: " + this->getName()+". Location: " + this->getLocation().print() + ". ";
}
