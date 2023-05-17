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
            void attack(Team* other)override;
    };
}
#endif
