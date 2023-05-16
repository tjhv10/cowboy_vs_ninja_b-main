#include "YoungNinja.hpp"

using namespace ariel;
using namespace std;
YoungNinja::YoungNinja(std::string name, Point &location):Ninja(name,location,100,14)
{
}
YoungNinja::YoungNinja(std::string name, Point &&location):Ninja(name,location,100,14)
{
}