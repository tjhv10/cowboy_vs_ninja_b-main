#ifndef OLD_NINJA_HPP
#define OLD_NINJA_HPP

#include "Ninja.hpp"
#include <iostream>

namespace ariel {
    class OldNinja : public Ninja{
        private:
        public:
            OldNinja(std::string name, Point& location);
            OldNinja(std::string name, Point&& location);
    };
}

#endif
