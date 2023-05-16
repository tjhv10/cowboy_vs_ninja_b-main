#ifndef TEAM_HPP
#define TEAM_HPP

#include "Cowboy.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"

#include <iostream>
#include <memory>
#include <vector>

namespace ariel {
    class Team{
        private:
            array<Character *, 10> fighters = {nullptr}; 
            Character* fighters_leader;
            unsigned long ccount = 0,ncount = 0;
        public:
            Team();
            Team(Character* leader);
            ~Team() = default;
            bool isNinja(Character *character);
            bool isCowboy(Character *character);
            virtual void attack(Team* enemy);
            virtual void add(Character* character);
            std::string print() const;
            int stillAlive();
    };
}

#endif
