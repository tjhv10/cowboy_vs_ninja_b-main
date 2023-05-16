#ifndef TRAINED_NINJA_HPP
#define TRAINED_NINJA_HPP

#include "Ninja.hpp"
#include <iostream>
using namespace std;

namespace ariel {
    class TrainedNinja : public Ninja{
        private:
        public:
            TrainedNinja(std::string name, Point& location);
            TrainedNinja(std::string name, Point&& location);
    };
}

#endif
