#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <iostream>

namespace ariel {
    class Character {
        private:
            int health;
            Point location;
            std::string name;
            
        public:
            bool isCapten = false,inTeam = false;
            Character(std::string name, Point location, int hit_point);
            ~Character() = default;
            virtual std::string print();
            bool isAlive() const;
            virtual void attack(Character* enemy)=0;
            Point getLocation() const;
            double distance(const Character* other) const;
            void hit(int num);
            std::string getName() const;
            void setX(double x);
            void setY(double y);
            int getHealth();
        };
}

#endif
