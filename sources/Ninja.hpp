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
            ~Ninja() = default; 
            std::string print() override;
            void slash(Character* enemy);
            virtual void move(const Character* enemy);
            };
}

#endif
