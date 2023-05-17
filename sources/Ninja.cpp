#include "Ninja.hpp"

using namespace ariel;
using namespace std;

Ninja::Ninja(string name, Point& location, int hit_points, int speed): Character(name, location, hit_points) , speed(speed){
    
}
void Ninja::slash(Character *enemy)
{
    if (this==enemy)
    {
        throw runtime_error("You cant slash yourself.");
    }
    if(enemy->isAlive()==false)
    throw runtime_error("You cannot attack dead enemy.");
    if(this->isAlive()==false)
    throw runtime_error("You cannot attack an enemy if you are dead.");
    if(this->distance(enemy)<=1)
    {
        if(enemy->isAlive())
            enemy->hit(40);
    }
}
void Ninja::move(Character* enemy){
    if(this->isAlive()&&enemy->isAlive())
    {
        Point enemyPos =enemy->getLocation();
        Point myPos = this->getLocation();
        myPos = Point::moveTowards(myPos,enemyPos, speed);
        this->setX(myPos.getX());
        this->setY(myPos.getY());
    }
}
void Ninja::attack(Character *enemy)
{
    if (!this->isAlive())
        {
            throw runtime_error("Cant attack when you are not alive.");
            return;
        }
        if (!enemy->isAlive())
        {
            throw runtime_error("Cant attack a dead enemy.");
            return;
        }
        if (this->getLocation().distance(enemy->getLocation()) > 1)
        {
            move(enemy);
            return;
        }
        slash(enemy);
}

string Ninja::print() {
    if (this->isAlive())
    {
        return "Ninja name: " + this->getName()+". Location: " + this->getLocation().print() + ". ";
    }
    return "";
}
