#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"
#include <iostream>

namespace ariel {
    class Ninja : public Character{
        private:
            int speed;
        public:
            Ninja(std::string name, Point& location,int speed , int hit_points); 
            std::string print() override;
            void slash(Character* enemy);
            virtual void move(Character* enemy);
            void attack(Character* enemy) override;
            };
}

#endif
