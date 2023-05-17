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
        public:
            Team2(Character* leader);
            void add(Character* character)override;
    };
}
#endif
