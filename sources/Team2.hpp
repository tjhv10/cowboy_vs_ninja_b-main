#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <iostream>
#include <memory>


using namespace std;

namespace ariel {
    class Team2{
        private:
            array<Character *, 10> fighters = {nullptr}; 
            Character* fighters_leader;
            int ccount = 0,ncount = 0;
        public:
            Team2(Character* character_leader);
            ~Team2()=default;
            void add(Character* character);
            void attack(Team2* enemy);
            bool isNinja(Character *character);
            bool isCowboy(Character *character);
            int stillAlive() const;
            std::string print();
    };
}
#endif
