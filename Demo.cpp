/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <random>
#include <chrono>
#include <iostream>
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;
auto simulate_battle = [](Team &team, Team &team2) {
    int i = 0;
    while (team.stillAlive() && team2.stillAlive()) {
        if (i % 2 == 0) {
            team.attack(&team2);
        } else {
            team2.attack(&team);
        }
        i++;
    }
      };
    double random_float(double min = -250, double max = 250) {
    std::default_random_engine generator(static_cast<unsigned long>(std::chrono::system_clock::now().time_since_epoch().count()));
    std::uniform_real_distribution<double> distribution(min, max);

    return distribution(generator);
}

auto create_yninja = [](double x = random_float(), double y = random_float()) {
    return new YoungNinja{"Bob", Point{x, y}};
};

auto create_tninja = [](double x = random_float(), double y = random_float()) {
    return new TrainedNinja{"Bob", Point{x, y}};
};

auto create_oninja = [](double x = random_float(), double y = random_float()) {
    return new OldNinja{"Bob", Point{x, y}};
};

auto create_cowboy = [](double x = random_float(), double y = random_float()) {
    return new Cowboy{"Bob", Point{x, y}};
};

int main() {
    Point a(32.3,44),b(1.3,3.5);
    cout<<a.print()<<endl;
    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() <<endl;
    cout <<sushi->print() <<endl;
    sushi->move(tom);
    sushi->slash(tom);

    Team team_A(tom); 
    team_A.add(new YoungNinja("Yogi", Point(64,57)));

    // Team b(tom); should throw tom is already in team a

     Team team_B(sushi);
     team_B.add(new TrainedNinja("Hikari", Point(12,81)));


     while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
        team_A.attack(&team_B);
        team_B.attack(&team_A);
        team_A.print();
        team_B.print();
     }

     if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
     else cout << "winner is team_B" << endl;
     //smart team against dumb team
     int w1=0,w2 =0;
     for (size_t i = 0; i < 5000; i++)
     {
     SmartTeam team1 = SmartTeam(create_cowboy());
     team1.add(create_cowboy());
     team1.add(create_cowboy());
     team1.add(create_yninja());
     team1.add(create_yninja());
     team1.add(create_oninja());
     team1.add(create_oninja());
     team1.add(create_oninja());
     team1.add(create_tninja());
     team1.add(create_tninja());
     Team team2 = Team(create_cowboy());
     team2.add(create_cowboy());
     team2.add(create_cowboy());
     team2.add(create_yninja());
     team2.add(create_yninja());
     team2.add(create_oninja());
     team2.add(create_oninja());
     team2.add(create_oninja());
     team2.add(create_tninja());
     team2.add(create_tninja());
    simulate_battle(team1,team2); 
        if (team2.stillAlive() > 0)
            w2++;
        else w1++;
     }
     for (size_t i = 0; i < 5000; i++)
     {
     SmartTeam team1 = SmartTeam(create_cowboy());
     team1.add(create_cowboy());
     team1.add(create_cowboy());
     team1.add(create_yninja());
     team1.add(create_yninja());
     team1.add(create_oninja());
     team1.add(create_oninja());
     team1.add(create_oninja());
     team1.add(create_tninja());
     team1.add(create_tninja());
     Team team2 = Team(create_cowboy());
     team2.add(create_cowboy());
     team2.add(create_cowboy());
     team2.add(create_yninja());
     team2.add(create_yninja());
     team2.add(create_oninja());
     team2.add(create_oninja());
     team2.add(create_oninja());
     team2.add(create_tninja());
     team2.add(create_tninja());
    simulate_battle(team2,team1); 
        if (team2.stillAlive() > 0)
            w2++;
        else w1++;
     }
     cout<<w1<<" "<<w2<<endl;
    //Dumb team against dumb team
    w1=0,w2 =0;
    for (size_t i = 0; i < 5000; i++)
     {
     Team team1 = Team(create_cowboy());
     team1.add(create_cowboy());
     team1.add(create_cowboy());
     team1.add(create_yninja());
     team1.add(create_yninja());
     team1.add(create_oninja());
     team1.add(create_oninja());
     team1.add(create_oninja());
     team1.add(create_tninja());
     team1.add(create_tninja());
     Team team2 = Team(create_cowboy());
     team2.add(create_cowboy());
     team2.add(create_cowboy());
     team2.add(create_yninja());
     team2.add(create_yninja());
     team2.add(create_oninja());
     team2.add(create_oninja());
     team2.add(create_oninja());
     team2.add(create_tninja());
     team2.add(create_tninja());
     simulate_battle(team1,team2); 
        if (team2.stillAlive() > 0)
            w2++;
        else w1++;
     }
     for (size_t i = 0; i < 5000; i++)
     {
     Team team1 = Team(create_cowboy());
     team1.add(create_cowboy());
     team1.add(create_cowboy());
     team1.add(create_yninja());
     team1.add(create_yninja());
     team1.add(create_oninja());
     team1.add(create_oninja());
     team1.add(create_oninja());
     team1.add(create_tninja());
     team1.add(create_tninja());
     Team team2 = Team(create_cowboy());
     team2.add(create_cowboy());
     team2.add(create_cowboy());
     team2.add(create_yninja());
     team2.add(create_yninja());
     team2.add(create_oninja());
     team2.add(create_oninja());
     team2.add(create_oninja());
     team2.add(create_tninja());
     team2.add(create_tninja());
     simulate_battle(team2,team1); 
        if (team2.stillAlive() > 0)
            w2++;
        else w1++;
     }
     cout<<w1<<" "<<w2<<endl;
    
     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}
