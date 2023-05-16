#include "Team.hpp"
using namespace ariel;
using namespace std;
ariel::Team::Team()
{
}
Team::Team(Character *leader) : fighters_leader(leader), fighters()
{
    if (leader->isCapten)
    {
        throw runtime_error("leader is already a capten.");
    }
    leader->isCapten = true;
    add(leader);
}
void Team::add(Character* fighter){
    if (fighter->inTeam == true)
    {
        throw runtime_error("The character you provided is already in a team.");
    }
    if(ccount+ncount<10)
    {
        
        if (isNinja(fighter))
        {
            fighters[9-ncount] = fighter;
            ncount++;
            fighter->inTeam =true;
        }
        else if (isCowboy(fighter))
        {
            fighters[ccount] = fighter;
            ccount++;
            fighter->inTeam =true;
        }
        else
        throw runtime_error("The character you provided is not a cowboy or a ninja");
    }
    else throw runtime_error("You can add up to 10 characters to a team.");
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
    if (enemyTeam == nullptr)
    {
        throw invalid_argument("Put a valid ptr to a team.");
    }
    if (this==enemyTeam)
    {
        throw runtime_error("you cant attack yourself.");
    }
    if (enemyTeam->stillAlive()==0)
    {
        throw runtime_error("you cant attack dead team.");
    }
    
    
}
int Team::stillAlive(){
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