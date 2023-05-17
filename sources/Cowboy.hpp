#ifndef COWBOY
#define COWBOY
constexpr int NOB = 6;
#include "Character.hpp"
#include <iostream>

namespace ariel {
    class Cowboy : public Character{
        private:
            int num_of_bullets = NOB;
        public:
            Cowboy(std::string name, Point location);
            void attack(Character* enemy) override;
            bool hasboolets() const;
            void reload();
            void shoot(Character *enemy);
            std::string print() override;
        };
}
#endif
