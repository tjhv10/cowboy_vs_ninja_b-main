#include "Team2.hpp"
using namespace ariel;
using namespace std;
Team2::Team2(Character* leader):Team(leader){}
void Team2::add(Character *fighter)
{   
    if(fighter->inTeam==true){
        throw runtime_error("Fighter is already in a team");
    }
    if (getTeam().size() >= 10)
    {
        throw runtime_error("Team is full.");
    }
    fighter->inTeam=true;
    getTeam().push_back(fighter);
}
    