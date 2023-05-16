#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <iostream>

namespace ariel {
    class Character {
        private:
            int hit_points;
            Point &location;
            std::string name;
        public:
            Character(std::string name, Point& location, int hit_point);
            Character(std::string name, Point location, int hit_point);
            ~Character() = default;
            virtual std::string print();
            virtual bool isAlive() const;
            Point getLocation() const;
            virtual double distance(const Character& other) const;
            virtual void hit(int num);
            virtual std::string getName() const;
            void setX(double x);
            void setY(double y);
            int getHealth();
        };
}

#endif
