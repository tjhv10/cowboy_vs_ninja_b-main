#ifndef SMART_TEAM_HPP
#define SMART_TEAM_HPP

#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"

#include <iostream>
#include <memory>

using namespace std;

namespace ariel {
    class SmartTeam{
        private:
            array<Character *, 10> fighters = {nullptr}; 
            Character* fighters_leader;
            int ccount = 0,ncount = 0;
        public:
            SmartTeam(Character* character_leader);
            ~SmartTeam()=default; 
            void add(Character* character);
            void attack(SmartTeam* enemy);
            bool isNinja(Character *character);
            bool isCowboy(Character *character);
            int stillAlive() const;
            std::string print();
    };
}
#endif
