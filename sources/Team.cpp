#include "Team.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;
namespace ariel
{
    Team::Team(Character *leader) : leader(leader)
    {
        if(this->leader->inTeam==true){
            throw runtime_error("Character is already in a team");
        }
        team.push_back(this->leader);
        this->leader->inTeam=true;
    }

    Team::Team(Team &enemy) : leader(enemy.leader)
    {
        for (auto c = enemy.team.begin(); c != enemy.team.end(); c++)
        {
            team.push_back(*c);
        }
    }

    Team::Team(Team &&enemy) : leader(enemy.leader)
    {
        for (auto c = enemy.team.begin(); c != enemy.team.end(); c++)
        {
            team.push_back(*c);
        }
    }

    //SmartTeam::SmartTeam(Character *this->leader) : Team(this->leader) {}

    // Destructors
    Team::~Team()
    {
        for (list<Character *>::iterator c = team.begin(); c != team.end(); c++)
        {
            //delete *c;
        }
    }

    // Functions
    void Team::add(Character *fighter)
    {
        if(fighter->inTeam==true){
            throw runtime_error("Fighter is already in a team");
        }
        if (team.size() >= 10)
        {
            throw runtime_error("Team is full.");
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
        int minDis = -1,index = -1;
        for (auto c = team.begin(); c != team.end(); c++)
        {
            if (!((*c)->isAlive()))
            {
                continue;
            }
            if (minDis == -1)
            {
                minDis = this->leader->distance(*c);
                index = distance(team.begin(), c);
                continue;
            }
            if (this->leader->distance(*c) < minDis)
            {
                minDis = this->leader->distance(*c);
                index = distance(team.begin(), c);
            }
        }
        if (index == -1)
        {
            return false;
        }
        auto c = team.begin();
        advance(c, index);
        this->leader = *c;
        return true;
    }

    void Team::print()
    {
        for (auto c = team.begin(); c != team.end(); c++)
        {
            cout << (*c)->print() << "\n";
        }
        cout << "\n";
    }

    int Team::stillAlive()
    {
        int counter = 0;
        for (auto c = team.begin(); c != team.end(); c++)
        {
            if ((*c)->isAlive())
            {
                counter++;
            }
        }
        return counter;
    }

    Character* Team::closestToLeader(Team * enemy)
    {
        int minDis = -1;
        Character *closest = nullptr;
        for (auto c = enemy->team.begin(); c != enemy->team.end(); c++)
        {
            if (!((*c)->isAlive()))
            {
                continue;
            }
            if (minDis == -1)
            {
                minDis = this->leader->distance(*c);
                closest = *c;
                continue;
            }
            if (this->leader->distance(*c) < minDis)
            {
                minDis = this->leader->distance(*c);
                closest = *c;
            }
        }
        return closest;
    }

    void Team::attack(Team *enemy)
    {
        if(!enemy){
            throw invalid_argument("Can't attack a nullptr");
        }
        if (!isLeaderAlive())
        {
            if (!replaceLeader())
            {
                cout << "The team has lost" << "\n";
                return;
            }
        }
        if (!enemy->stillAlive())
        {
            throw runtime_error("Can't attack a dead team");
        }
        
        Character *closest = closestToLeader(enemy);
        if(closest == nullptr){

            throw runtime_error("Closest to leader is null.");
        }
        
        for (auto c = team.begin(); c != team.end(); c++)
        {
            if (!((*c)->isAlive()))
            {   
                continue;
            }
            if (!closest->isAlive())
            {
                closest = closestToLeader(enemy);
            }
            if(!closest)
            {
                return;
            }
            (*c)->attack(closest);
        }
    }

    // Getters and Setters

    Character *Team::getLeader() const
    {
        return this->leader;
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
    return this->leader->isAlive();
}
}