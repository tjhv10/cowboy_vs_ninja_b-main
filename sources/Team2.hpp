#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Team.hpp"
#include <iostream>
#include <memory>


using namespace std;

namespace ariel {
    class Team2:public Team{
        private:
            array<Character *, 10> fighters = {nullptr}; 
            Character* fighters_leader;
            unsigned long ccount = 0,ncount = 0;
        public:
            Team2(Character* leader);
            ~Team2()=default;
            void add(Character* character);
            int stillAlive() const;
            std::string print();
    };
}
#endif
