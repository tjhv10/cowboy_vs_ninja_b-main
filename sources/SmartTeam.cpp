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
        if(isNinja(*c))
        {
            count++;
            avgX += (*c)->getLocation().getX();
            avgY += (*c)->getLocation().getY();
        }

    }
    avgX/=count;
    avgY/=count;
    return Point(avgX,avgY);
}
Character *ariel::SmartTeam::ClosestNinjaToMyCowboy(Team *enemy)
{
    double currntClosestNinjaDistance = DBL_MAX;
    Character *closest = nullptr;
    for (auto c = getTeam().begin(); c != getTeam().end(); c++)
    {
        for (auto n = enemy->getTeam().begin(); n != enemy->getTeam().end(); n++)
        {
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
            if(isNinja((*c))){
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
            if(isCowboy((*c))){
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
            if(isCowboy((*c))){
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
        if(isNinja((*c)))
        (*c)->attack(enemy);
    }
}
void ariel::SmartTeam::attackCowboy(Character *enemy)
{
    for (auto c = getTeam().begin(); c != getTeam().end(); c++)
    {
        if(isCowboy((*c)))
        (*c)->attack(enemy);
    }
}
bool ariel::SmartTeam::hasCowboy(Team *enemy)
{
    for (auto c = enemy->getTeam().begin(); c != enemy->getTeam().end(); c++)
    {
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
        attackCowboy(FurthestCowboyToPoint(avgLocationNinjas(),enemy));
    }
    else
    {
        for (auto c = enemy->getTeam().begin(); c != enemy->getTeam().end(); c++)
        {
            if(isNinja((*c)))
            {
                (*c)->attack(ClosestNinjaToNinja((*c)->getLocation(),enemy));
            }
            if (isCowboy((*c)))
            {
                (*c)->attack(ClosestNinjaToMyCowboy(enemy));
            }
        }
    }
}
    