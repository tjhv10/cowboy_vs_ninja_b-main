#include "Team2.hpp"
using namespace ariel;
using namespace std;

// Team2::Team2(Character* leader){    
//     leader->isCapten = true;
//     if (isNinja( leader))
//     {
//         ncount++;
//     }
//     if (isCowboy(leader))
//     {
//         ccount++;
//     }
//     add(leader);
// }
// void Team2::add(Character* fighter){
//     if (fighter->inTeam == true)
//     {
//         throw runtime_error("The character you provided is already in a team.");
//     }
//     if(ncount+ccount<10)
//     {
//         if (isNinja(fighter))
//         {
//             fighters[ncount+ccount] = fighter;
//             ncount++;
//             fighter->inTeam =true;
//         }
//         else if (isCowboy(fighter))
//         {
//             fighters[ccount+ncount] = fighter;
//             ccount++;
//             fighter->inTeam =true;
//         }
//         else
//         throw runtime_error("The character you provided is not a cowboy or a ninja");
//     }
//     else throw runtime_error("You can add up to 10 characters to a team2.");
// }
// Character* ariel::Team2::closestToLeader(Team *team)
// {
//     Character* closest = nullptr;
//     int minDis = 2147483647;
//     for (unsigned long c = 0; c < fighters.size(); c++)
//     {
//         if(team->fighters[c]!=nullptr){
//             if (team->fighters[c]->isAlive()==false)
//             {
//                 continue;
//             }
//             if (fighters_leader->distance(team->fighters[c]) < minDis)
//             {
//                 minDis = fighters_leader->distance(team->fighters[c]);
//                 closest = team->fighters[c];
//             }
//         }
//     }
    
//     return closest;
// }
// void ariel::Team2::choose_new_leader()
// {
//     Character *closest = nullptr;
//     int minDis = 2147483647;
//     for (unsigned long c = 0; c<fighters.size(); c++)
//     {
//         if(fighters[c]!=nullptr){
//         if (fighters[c]->isAlive()==false)
//         {
//             continue;
//         }
//         if (fighters_leader->distance(fighters[c]) < minDis)
//         {
//             minDis = fighters_leader->distance(fighters[c]);
//             closest = fighters[c];
//         }
//         }
//     }
//     closest->isCapten = true;
//     fighters_leader = closest;
// }
// bool Team2::isNinja(Character *character)
// {
//     Ninja *ninja = dynamic_cast<Ninja *>(character);
//     if(ninja!=NULL)
//         return true;
//     return false;
// }
// bool Team2::isCowboy(Character *character)
// {
//     Cowboy *cowboy = dynamic_cast<Cowboy *>(character);
//     if(cowboy!=NULL)
//         return true;
//     return false;
// }
// void Team2::attack(Team *enemyTeam)
// {
//     if (enemyTeam == nullptr)
//     {
//         throw invalid_argument("Put a valid ptr to a fighters.");
//     }
//     if (this==enemyTeam)
//     {
//         throw runtime_error("you cant attack yourself.");
//     }
//     if (enemyTeam->stillAlive()<=0)
//     {
//         throw runtime_error("you cant attack dead fighters.");
//     }
    
//     if(!fighters_leader->isAlive())
//     {   if (this->stillAlive()>0)
//         {
//             choose_new_leader();
//         }
//         else 
//         {
//             throw runtime_error("This team is dead");
//         }
//     }
    
//     Character* target = closestToLeader(enemyTeam);
//     for (unsigned long c =0; c < fighters.size(); c++)
//     {
//         if(fighters[c]!=nullptr){
//         if (!(fighters[c]->isAlive()))
//         {   
//             continue;
//         }
//         if (target->isAlive())
//         {
//             fighters[c]->attack(target);
//             continue;
//         }
//         if(!enemyTeam->stillAlive())
//         {
//             return;
//         }
//         //target = closestToLeader(enemyTeam); 
//         }  
//     }
// }
// int Team2::stillAlive() const{
//     int count=0;
//     for (unsigned long c =0; c < fighters.size(); c++)
//     {
//         if (fighters[c]!=nullptr&&fighters[c]->isAlive())
//         {
//             count ++;
//         }
//     }
//     return count;
// }
// std::string ariel::Team2::print()
// {
//     string end = "";
//     for (size_t i = 0; i < 10; i++)
//     {
//         if(fighters[i]!=NULL)
//             end += fighters[i]->print();
//     }
//     return end;
// }


Team2::Team2(Character* leader):Team(leader){    
    
}
void Team2::add(Character *fighter)
{
    if (getTeam().size() == 10)
    {
        throw runtime_error("Team is full");
    }
    if(fighter->inTeam==true){
        throw runtime_error("Character is already in a team");
    }
    getTeam().push_back(fighter);
    fighter->inTeam=true;
}
    