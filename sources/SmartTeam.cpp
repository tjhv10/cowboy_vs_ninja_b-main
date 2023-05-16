#include "SmartTeam.hpp"
using namespace ariel;
using namespace std;
SmartTeam::SmartTeam(Character* leader): fighters_leader(leader), fighters(){    
    add(leader);
    if (isCowboy(leader))
        ccount++;
    else if(isNinja(leader))
        ncount++;
}
void SmartTeam::add(Character* fighter){
    if(ccount+ncount<10)
    {
        if (isNinja(fighter))
        {
            fighters[ncount+ccount] = fighter;
            ncount++;
        }
        else if (isCowboy(fighter))
        {
            fighters[ccount+ncount] = fighter;
            ccount++;
        }
        else
        throw runtime_error("The character you provided is not a cowboy or a ninja");
    }
    else throw overflow_error("You can add up to 10 characters to a SmartTeam.");
}
bool SmartTeam::isNinja(Character *character)
{
    Ninja *ninja = dynamic_cast<Ninja *>(character);
    if(ninja!=NULL)
        return true;
    return false;
}
bool SmartTeam::isCowboy(Character *character)
{
    Cowboy *cowboy = dynamic_cast<Cowboy *>(character);
    if(cowboy!=NULL)
        return true;
    return false;
}
void SmartTeam::attack(SmartTeam *enemySmartTeam)
{
    
}
int SmartTeam::stillAlive() const{
    return ccount+ncount;
}
std::string ariel::SmartTeam::print()
{
    string end = "";
    for (size_t i = 0; i < 10; i++)
    {
        if(fighters[i]!=NULL)
            end += fighters[i]->print();
    }
    return end;
}
