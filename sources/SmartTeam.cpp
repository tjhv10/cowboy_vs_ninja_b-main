#include "SmartTeam.hpp"
#include <float.h>
using namespace ariel;
using namespace std;

SmartTeam::SmartTeam(Character* leader):Team(leader){}
Point ariel::SmartTeam::avgLocationNinjas()
{
    double avgX= 0,avgY=0,count = 0;
    for (auto c = getTeam().begin(); c != getTeam().end(); c++)
    {
        if ((*c)==nullptr||!((*c)->isAlive()))
        {
            continue;
        }
        if(isNinja(*c))
        {
            count++;
            avgX += (*c)->getLocation().getX();
            avgY += (*c)->getLocation().getY();
        }

    }
    return Point(avgX/count,avgY/count);
}
Character *ariel::SmartTeam::ClosestNinjaToMyCowboy(Team *enemy)
{
    double currntClosestNinjaDistance = 201;
    Character *closest = nullptr;
    for (auto c = getTeam().begin(); c != getTeam().end(); c++)
    {
        if ((*c)==nullptr)
        {
            continue;
        }
        if (!((*c)->isAlive()))
            {
                continue;
            }
        for (auto n = enemy->getTeam().begin(); n != enemy->getTeam().end(); n++)
        {
            if ((*c)==nullptr||(*n)==nullptr)
            {
                continue;
            }
            if (!((*c)->isAlive()))
            {
                continue;
            }
            if((*c)->distance((*n))<currntClosestNinjaDistance)
            {
                currntClosestNinjaDistance = (*c)->distance((*n));
                closest = (*n);
            }
        }
    }
    return closest;
}
Character *ariel::SmartTeam::ClosestNinjaToNinja(Point p, Team *enemy)
{
    double minDis = -1;
    Character *closest = nullptr;
    for (auto c = enemy->getTeam().begin(); c != enemy->getTeam().end(); c++)
        {
            if ((*c)==nullptr)
            {
                continue;
            }
            if (!((*c)->isAlive()))
            {
                continue;
            }
            if(isNinja((*c))){
                
                if ((*c)==nullptr)
                {
                    continue;
                }
                if (!((*c)->isAlive()))
                {
                    continue;
                }
                if (minDis == -1)
                {
                    minDis = p.distance((*c)->getLocation());
                    closest = *c;
                    continue;
                }
                if (p.distance((*c)->getLocation()) < minDis)
                {
                    minDis = p.distance((*c)->getLocation());
                    closest = *c;
                }
            }
        }
        return closest;
}
Character* ariel::SmartTeam::ClosestCowboyToPoint(Point p,Team *enemy)
{
    double minDis = -1;
    Character *closest = nullptr;
    for (auto c = enemy->getTeam().begin(); c != enemy->getTeam().end(); c++)
        {
            if((*c)!=nullptr&&isCowboy((*c))){
                
            if (!((*c)->isAlive()))
            {
                continue;
            }
            if (minDis == -1)
            {
                minDis = p.distance((*c)->getLocation());
                closest = *c;
                continue;
            }
            if (p.distance((*c)->getLocation()) < minDis)
            {
                minDis = p.distance((*c)->getLocation());
                closest = *c;
            }
            }
        }
        return closest;
}
Character* ariel::SmartTeam::FurthestCowboyToPoint(Point p,Team *enemy)
{
    double minDis = -1;
    Character *closest = nullptr;
    for (auto c = enemy->getTeam().begin(); c != enemy->getTeam().end(); c++)
        {
            if((*c)!=nullptr&&isCowboy((*c))){
                
            if (!((*c)->isAlive()))
            {
                continue;
            }
            if (minDis == -1)
            {
                minDis = p.distance((*c)->getLocation());
                closest = *c;
                continue;
            }
            if (p.distance((*c)->getLocation()) > minDis)
            {
                minDis = p.distance((*c)->getLocation());
                closest = *c;
            }
            }
        }
        return closest;
}
void ariel::SmartTeam::attackNinja(Character *enemy)
{
    for (auto c = getTeam().begin(); c != getTeam().end(); c++)
    {
        if ((*c)==nullptr)
        {
            continue;
        }
        if (!((*c)->isAlive()))
        {
            continue;
        }
        if(isNinja((*c)))
        {
            
            if(enemy->isAlive())
                (*c)->attack(enemy);
        }
    }
}
void ariel::SmartTeam::attackCowboy(Character *enemy)
{
    for (auto c = getTeam().begin(); c != getTeam().end(); c++)
    {
        if ((*c)==nullptr)
        {
            continue;
        }
        if (!((*c)->isAlive()))
        {
            continue;
        }
        if(isCowboy((*c)))
        {
            if(enemy->isAlive())
                (*c)->attack(enemy);
        }
    }
}
bool ariel::SmartTeam::hasCowboy(Team *enemy)
{
    for (auto c = enemy->getTeam().begin(); c != enemy->getTeam().end(); c++)
    {
        if ((*c)==nullptr)
        {
            continue;
        }
        if (!((*c)->isAlive()))
        {
            continue;
        }
        if(isCowboy((*c)))
        return true;
    }
    return false;
}

void ariel::SmartTeam::attack(Team *enemy)
{
    if(!enemy){
        throw invalid_argument("Can't attack a nullptr");
    }
    if (!enemy->stillAlive())
    {
        throw runtime_error("Can't attack a dead team");
    }
    if(hasCowboy(enemy))
    {
        attackNinja(ClosestCowboyToPoint(avgLocationNinjas(),enemy));
        if(hasCowboy(enemy))
        attackCowboy(FurthestCowboyToPoint(avgLocationNinjas(),enemy));
    }
    else
    {
        for (auto c = getTeam().begin(); c != getTeam().end(); c++)
        {
            if ((*c)==nullptr)
            {
                continue;
            }
            if (!((*c)->isAlive()))
            {
                continue;
            }
            if(isNinja((*c)))
            {
                if(enemy!=nullptr&&(*c)!=nullptr)
                {
                    Character *ca =ClosestNinjaToNinja((*c)->getLocation(),enemy);
                    if (ca!=nullptr)
                    {
                        (*c)->attack(ca);
                    }
                    else
                    continue;
                }
                
            }
            else if (isCowboy((*c)))
            {
                if(enemy!=nullptr&&(*c)!=nullptr)
                {
                    Character *cntmc = ClosestNinjaToMyCowboy(enemy);
                    if(cntmc!=nullptr){
                        if(cntmc->isAlive())
                        {
                            (*c)->attack(cntmc);
                        }
                    }
                }
            }
        }
    }
}
    