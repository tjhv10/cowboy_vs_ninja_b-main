#include "Team.hpp"
using namespace ariel;
using namespace std;
Team::Team(Character* leader): fighters_leader(leader), fighters(){    
    add(leader);
    if (isCowboy(leader))
        ccount++;
    else if(isNinja(leader))
        ncount++;
}
void Team::add(Character* fighter){
    if(ccount+ncount<10)
    {
        if (isNinja(fighter))
        {
            fighters[9-ncount] = fighter;
            ncount++;
        }
        else if (isCowboy(fighter))
        {
            fighters[ccount] = fighter;
            ccount++;
        }
        else
        throw runtime_error("The character you provided is not a cowboy or a ninja");
    }
    else throw overflow_error("You can add up to 10 characters to a team.");
}
bool Team::isNinja(Character *character)
{
    Ninja *ninja = dynamic_cast<Ninja *>(character);
    if(ninja!=NULL)
        return true;
    return false;
}
bool Team::isCowboy(Character *character)
{
    Cowboy *cowboy = dynamic_cast<Cowboy *>(character);
    if(cowboy!=NULL)
        return true;
    return false;
}
void Team::attack(Team *enemyTeam)
{
}
int Team::stillAlive() const{
    return ccount+ncount;
}
string Team::print() const{
    string end = "";
    for (size_t i = 0; i < 10; i++)
    {
        if(fighters[i]!=NULL)
            end += fighters[i]->print();
    }
    return end;
}