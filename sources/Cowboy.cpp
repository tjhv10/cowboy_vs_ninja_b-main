#include "Cowboy.hpp"

using namespace ariel;
using namespace std;

//Cowboy::Cowboy(string name, Point& location):Character(name , location , 110){ }

Cowboy::Cowboy(std::string name, Point location):Character(name,Point(location.getX(),location.getY()),110)
{
}
void Cowboy::shoot(Character* enemy){
    if(enemy->isAlive()==false)
        throw runtime_error("You cannot attack dead enemy.");

    if(this->isAlive()==false)
        throw runtime_error("You cannot attack an enemy if you are dead.");

    if (enemy == this)
        throw runtime_error("You cant shoot yourself.");

    if(this->isAlive())
    {   if(this->hasboolets())
        {
            num_of_bullets--;
            enemy->hit(10);
        }
        else reload();
    }
    else throw runtime_error("You are dead.");
}
void Cowboy::reload(){
    if(this->isAlive())
    this->num_of_bullets = 6;
    else throw runtime_error("dead cowboy cannot reload.");
}
void ariel::Cowboy::attack(Character *enemy)
{
    shoot(enemy);
}
bool Cowboy::hasboolets() const
{
    return num_of_bullets>0;
}

std::string ariel::Cowboy::print()
{
    if (this->isAlive())
    {
        return "C Name: "+ getName() + ". Hit points: "+to_string(this->getHealth())+". Location: " +getLocation().print();
    }
    
    return "";
}
