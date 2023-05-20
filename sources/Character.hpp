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
            bool isCapten = false,inTeam = false;
        public:
            Character(const std::string& name, int level);
            Character(const Character& other);
            Character& operator=(const Character& other);
            Character(Character&& other) noexcept;
            Character& operator=(Character&& other) noexcept;
            bool isCaption();
            bool isInTeam();
            void setIsCapten(bool capten);
            void setInTeam(bool isInTeam);
            virtual ~Character() = default;    
            Character(std::string name, Point location, int hit_point);
            virtual std::string print();
            bool isAlive();
            bool isAliveS();
            virtual void attack(Character* enemy)=0;
            Point getLocation() const;
            double distance(const Character* other) const;
            void hit(int num);
            std::string getName() const;
            void setX(double x_coor);
            void setY(double y_coor);
            int getHealth();
        };
}

#endif
