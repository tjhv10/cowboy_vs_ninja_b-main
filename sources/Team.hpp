// #ifndef TEAM_HPP
// #define TEAM_HPP

// #include "Cowboy.hpp"
// #include "TrainedNinja.hpp"
// #include "YoungNinja.hpp"
// #include "OldNinja.hpp"

// #include <iostream>
// #include <memory>
// #include <vector>

// namespace ariel {
//     class Team{
//         private:
//             array<Character *, 10> fighters = {nullptr}; 
//             Character* fighters_leader;
//             unsigned long ccount = 0,ncount = 0;
//         public:
//             Team();
//             Team(Character* leader);
//             Character* closestToLeader(Team * enemy);
//             void choose_new_leader();
//             ~Team() = default;
//             bool isNinja(Character *character);
//             bool isCowboy(Character *character);
//             virtual void attack(Team* enemy);
//             virtual void add(Character* character);
//             std::string print() const;
//             virtual int stillAlive();
//     };
// }

// #endif
#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <sstream>
#include <list>
#include <stdexcept>
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"


using namespace std;

namespace ariel
{
    class Team
    {
    private:
        list<Character *> team;
        Character *leader;

    public:
        Team(Character *leader);
        Team(const std::string& name, int level);
        Team(const Team& other);
        Team& operator=(const Team& other);
        Team(Team&& other) noexcept;
        Team& operator=(Team&& other) noexcept;
        virtual ~Team();
        virtual void add(Character *fighter);
        virtual void attack(Team *other);
        void print();
        int stillAlive();
        bool isNinja(Character *character);
        bool isCowboy(Character *character);
        bool LeaderAlive();
        bool repLeader();
        Character *closestCharacterToLeader(Team *enemy);
        Character* getLeader() const;
        list<Character *>& getTeam();
    };
}
#endif
