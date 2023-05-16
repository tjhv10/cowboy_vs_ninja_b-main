#include "OldNinja.hpp"

using namespace ariel;
using namespace std;
OldNinja::OldNinja(std::string name, Point &location):Ninja(name,location,150,8)
{
}
OldNinja::OldNinja(std::string name, Point &&location):Ninja(name,location,150,8)
{
}