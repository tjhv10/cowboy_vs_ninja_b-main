#ifndef SMART_TEAM_HPP
#define SMART_TEAM_HPP

#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"
#include "Team.hpp"

#include <iostream>
#include <memory>

using namespace std;

namespace ariel {
    class SmartTeam:public Team{
        private:
            array<Character *, 10> fighters = {nullptr}; 
            Character* fighters_leader;
            unsigned long ccount = 0,ncount = 0;
        public:
            SmartTeam(Character* character_leader);
            ~SmartTeam()=default;
            void attack(SmartTeam* enemy);
            // void add(Character* character);
            // bool isNinja(Character *character);
            // bool isCowboy(Character *character);
            // int stillAlive() const;
            // std::string print();
    };
}
#endif
