// #include "Team.hpp"
// using namespace ariel;
// using namespace std;
// ariel::Team::Team()
// {
// }
// Team::Team(Character* fighters_leader) : fighters_leader(fighters_leader)
// {
//     if (fighters_leader->isCapten)
//     {
//         throw runtime_error("fighters_leader is already a capten.");
//     }
//     fighters_leader->isCapten = true;

//     add(fighters_leader);
// }
// void Team::add(Character* fighter){
//     if (fighter->inTeam == true)
//     {
//         throw runtime_error("The character you provided is already in a fighters.");
//     }
//     if(ccount+ncount<10)
//     {
//         if (isNinja(fighter))
//         {
//             fighters[9-ncount] = fighter;
//             ncount++;
//             fighter->inTeam =true;
//         }
//         else if (isCowboy(fighter))
//         {
//             fighters[ccount] = fighter;
//             ccount++;
//             fighter->inTeam =true;
//         }
//         else
//         throw runtime_error("The character you provided is not a cowboy or a ninja");
//     }
//     else throw runtime_error("You can add up to 10 characters to a fighters.");
// }
// bool Team::isNinja(Character *character)
// {
//     Ninja *ninja = dynamic_cast<Ninja *>(character);
//     if(ninja!=NULL)
//         return true;
//     return false;
// }
// bool Team::isCowboy(Character *character)
// {
//     Cowboy *cowboy = dynamic_cast<Cowboy *>(character);
//     if(cowboy!=NULL)
//         return true;
//     return false;
// }
// Character* Team::closestToLeader(Team * team)
// {
//     Character *closest = nullptr;
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
// void Team::choose_new_leader()
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

// void Team::attack(Team* enemyTeam)
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
//         // target = closestToLeader(enemyTeam); 
//         }  
//     }
    
// }
// int Team::stillAlive(){
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
// string Team::print() const{ 
//     string end = "";
//     for (size_t i = 0; i < fighters.size(); i++) 
//     {
//         if(fighters[i]!=NULL)
//             end += fighters[i]->print();
//     }
//     return end;
// }


#include "Team.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;
namespace ariel
{
    // Constructors and operators
    Team::Team(Character *leader) : leader(leader)
    {
        if(leader->inTeam==true){
            throw runtime_error("Character is already in a team");
        }
        team.push_back(leader);
        leader->inTeam=true;
    }

    Team::Team(Team &other) : leader(other.leader)
    {
        for (auto it = other.team.begin(); it != other.team.end(); it++)
        {
            team.push_back(*it);
        }
    }

    Team::Team(Team &&other) : leader(other.leader)
    {
        for (auto it = other.team.begin(); it != other.team.end(); it++)
        {
            team.push_back(*it);
        }
    }

    //SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

    // Destructors
    Team::~Team()
    {
        for (list<Character *>::iterator it = team.begin(); it != team.end(); it++)
        {
            //delete *it;
        }
    }

    // Functions
    void Team::add(Character *fighter)
    {
        if (team.size() == 10)
        {
            throw runtime_error("Team is full");
        }
        if(fighter->inTeam==true){
            throw runtime_error("Character is already in a team");
        }
        if (isCowboy(fighter))
        {
            team.push_front(fighter);
            fighter->inTeam=true;
        }
        else if (isNinja(fighter))
        {
            team.push_back(fighter);
            fighter->inTeam=true;
        }
    }

    // void SmartTeam::add(Character *fighter)
    // {
    //     if (getTeam().size() == 10)
    //     {
    //         throw runtime_error("Team is full");
    //     }
    //     if (isCowboy(fighter))
    //     {
    //         getTeam().push_front(fighter);
    //         fighter->inTeam=true;
    //     }
    //     else if (isNinja(fighter))
    //     {
    //         getTeam().push_back(fighter);
    //         fighter->inTeam=true;
    //     }
    // }

    bool Team::replaceLeader()
    {
        int minDistance = -1;
        int newLeaderIndex = -1;
        for (auto it = team.begin(); it != team.end(); it++)
        {
            if (!((*it)->isAlive()))
            {
                continue;
            }
            if (minDistance == -1)
            {
                minDistance = leader->distance(*it);
                newLeaderIndex = distance(team.begin(), it);
                continue;
            }
            if (leader->distance(*it) < minDistance)
            {
                minDistance = leader->distance(*it);
                newLeaderIndex = distance(team.begin(), it);
            }
        }
        if (newLeaderIndex == -1)
        {
            return false;
        }
        auto it = team.begin();
        advance(it, newLeaderIndex);
        leader = *it;
        return true;
    }

    void Team::print()
    {
        for (auto it = team.begin(); it != team.end(); it++)
        {
            cout << (*it)->print() << endl;
        }
        cout << endl;
    }

    int Team::stillAlive()
    {
        int counter = 0;
        for (auto it = team.begin(); it != team.end(); it++)
        {
            if ((*it)->isAlive())
            {
                counter++;
            }
        }
        return counter;
    }

    Character* Team::closestToLeader(Team * enemy)
    {
        int minDistance = -1;
        Character *closest = nullptr;
        for (auto it = enemy->team.begin(); it != enemy->team.end(); it++)
        {
            if (!((*it)->isAlive()))
            {
                continue;
            }
            if (minDistance == -1)
            {
                minDistance = leader->distance(*it);
                closest = *it;
                continue;
            }
            if (leader->distance(*it) < minDistance)
            {
                minDistance = leader->distance(*it);
                closest = *it;
            }
        }
        return closest;
    }

    void Team::attack(Team *other)
    {
        if(!other){
            throw invalid_argument("Can't attack a nullptr");
        }
        if (!isLeaderAlive())
        {
            if (!replaceLeader())
            {
                cout << "The team has lost" << endl;
                return;
            }
        }
        if (!other->stillAlive())
        {
            throw runtime_error("Can't attack a dead team");
        }
        
        Character *closest = closestToLeader(other);
        if(closest == nullptr){

            cout << "closest is nullptr" << endl;
        }
        
        for (auto it = team.begin(); it != team.end(); it++)
        {
            if (!((*it)->isAlive()))
            {   
                continue;
            }
            if (!closest->isAlive())
            {
                closest = closestToLeader(other);
            }
            if(!closest)
            {
                return;
            }
            (*it)->attack(closest);
            
        }
    }

    // Getters and Setters

    Character *Team::getLeader() const
    {
        return leader;
    }

    list<Character *>& Team::getTeam()
    {
        return team;
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

bool Team::isLeaderAlive()
{
    return leader->isAlive();
}
}