#ifndef COWBOY
#define COWBOY

#include "Character.hpp"
#include <iostream>

namespace ariel {
    class Cowboy : public Character{
        private:
            int num_of_bullets = 6;
        public:
            //Cowboy(std::string name, Point& location);
            Cowboy(std::string name, Point location);
            ~Cowboy()= default;
            bool hasboolets();
            void reload();
            void shoot(Character *enemy);
            std::string print() override;
        };
}
#endif
