#include "TrainedNinja.hpp"

using namespace ariel;
using namespace std;

TrainedNinja::TrainedNinja(std::string name, Point &location):Ninja(name,location,120,12)
{
}
TrainedNinja::TrainedNinja(std::string name, Point &&location):Ninja(name,location,120,12)
{
}