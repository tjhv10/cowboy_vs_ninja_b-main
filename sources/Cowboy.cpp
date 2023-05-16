#include "Cowboy.hpp"

using namespace ariel;
using namespace std;

Cowboy::Cowboy(string name, Point& location):Character(name , location , 110){ }

Cowboy::Cowboy(std::string name, Point location):Character(name,Point(location.getX(),location.getY()),110)
{
}

void Cowboy::shoot(Character& character){
    if(this->isAlive()&&this->hasboolets())
    {   
        num_of_bullets--;
        character.hit(10);
    }
}
void Cowboy::reload(){
    this->num_of_bullets = 6;
}
bool Cowboy::hasboolets(){
    if (this->num_of_bullets>0)
        return true;
    return false;
}

std::string ariel::Cowboy::print()
{
    return "Cowboy Name: "+ getName() + ". Location: " +getLocation().print() +"\n";
}
