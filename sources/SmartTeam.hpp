#ifndef SMART_TEAM_HPP
#define SMART_TEAM_HPP

#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Team.hpp"
#include <iostream>

using namespace std;

namespace ariel {
    class SmartTeam : public Team{
        public:
            SmartTeam(Character* leader);
            Point avgLocationNinjas();
            Character* ClosestNinjaToMyCowboy(Team* enemy);
            Character* ClosestNinjaToNinja(Point point,Team *enemy);
            Character* ClosestCowboyToPoint(Point point,Team *enemy);
            Character* FurthestCowboyToPoint(Point point,Team *enemy);
            void attackNinja(Character* enemy);
            void attackCowboy(Character* enemy);
            bool hasCowboy(Team* enemy);
            void attack(Team* other)override;
    };
}
#endif
