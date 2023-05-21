#include "Team.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;
namespace ariel
{
    Team::Team(Character *leader) : leader(leader)
    {
        if(leader->isInTeam()==true){
            throw runtime_error("Character is already in a team");
        }
        team.push_back(leader);
        leader->setInTeam(true);
    }
    Team::~Team()
    {
        for (list<Character *>::iterator c = getTeam().begin(); c != getTeam().end(); c++)
        {
            if ((*c)!=nullptr)
            {
                delete *c;
            }
        }
    }
    void Team::add(Character *fighter)
    {
        if(fighter->isInTeam()==true){
            throw runtime_error("Fighter is already in a team");
        }
        if (team.size() >= 10)
        {
            throw runtime_error("Team is full.");
        }
        if (isCowboy(fighter))
        {
            team.push_front(fighter);
            fighter->setInTeam(true);
        }
        else if (isNinja(fighter))
        {
            team.push_back(fighter);
            fighter->setInTeam(true);
        }
    }
    bool Team::repLeader()
    {
        int minDis = -1,i = -1;
        for (auto c = team.begin(); c != team.end(); c++)
        {
            if (!((*c)->isAlive()))
            {
                continue;
            }
            if (minDis == -1)
            {
                minDis = this->leader->distance(*c);
                i = distance(team.begin(), c);
                continue;
            }
            if (this->leader->distance(*c) < minDis)
            {
                minDis = this->leader->distance(*c);
                i = distance(team.begin(), c);
            }
        }
        if (i == -1)
        {
            return false;
        }
        auto c = team.begin();
        advance(c, i);
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
            
            if((*c)==nullptr)
            {
                continue;
            }
            if ((*c)->isAlive())
            {
                counter++;
            }
            
        }
        return counter;
    }

    Character* Team::closestCharacterToLeader(Team * enemy)
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
        if (!LeaderAlive())
        {
            if (!repLeader())
            {
                cout << "The team has lost" << "\n";
                return;
            }
        }
        if (!enemy->stillAlive())
        {
            throw runtime_error("Can't attack a dead team");
        }
        
        Character *closest = closestCharacterToLeader(enemy);
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
                closest = closestCharacterToLeader(enemy);
            }
            if(!closest)
            {
                return;
            }
            (*c)->attack(closest);
        }
    }
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
bool Team::LeaderAlive()
{
    return this->leader->isAlive();
}
}