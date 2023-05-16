#include "Team2.hpp"
using namespace ariel;
using namespace std;
Team2::Team2(Character* leader): fighters_leader(leader), fighters(){    
    add(leader);
    if (isCowboy(leader))
        ccount++;
    else if(isNinja(leader))
        ncount++;
}
void Team2::add(Character* fighter){
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
    else throw overflow_error("You can add up to 10 characters to a team2.");
}
bool Team2::isNinja(Character *character)
{
    Ninja *ninja = dynamic_cast<Ninja *>(character);
    if(ninja!=NULL)
        return true;
    return false;
}
bool Team2::isCowboy(Character *character)
{
    Cowboy *cowboy = dynamic_cast<Cowboy *>(character);
    if(cowboy!=NULL)
        return true;
    return false;
}
void Team2::attack(Team2 *enemyTeam2)
{
}
int Team2::stillAlive() const{
    return ccount+ncount;
}
std::string ariel::Team2::print()
{
    string end = "";
    for (size_t i = 0; i < 10; i++)
    {
        if(fighters[i]!=NULL)
            end += fighters[i]->print();
    }
    return end;
}
