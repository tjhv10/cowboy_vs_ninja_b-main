#include "doctest.h"
#include <sstream>
#include <iostream>

#include "sources/Team.hpp"

using namespace ariel;

TEST_CASE("Point test")
{
    Point a(1.5,3) ,b(4.75,98);
    CHECK(a.distance(b)==95.0556);
    CHECK(a.distance(b)==b.distance(a));
}
TEST_CASE("Charecter creation and hit test")
{
    Point a(1.5,3) ,b(4.75,98);
    Character c1("c1",a,50);
    Character c2("c2",b,100);
    CHECK(c1.distance(c2)==c2.distance(c1));
    CHECK_EQ(c2.distance(c1),95.0556);
    c1.hit(30);
    CHECK(c1.isAlive());
    c1.hit(20);
    CHECK_FALSE(c1.isAlive());
}
TEST_CASE("Cowboy vs cowboy test")
{
    Point a(1.5,3) ,b(4.75,98);
    Cowboy cowboy_a("Jhon",a);
    Cowboy cowboy_b("Peter",b);
    cowboy_a.shoot(cowboy_b);
    CHECK(cowboy_b.isAlive());
    for (size_t i = 0; i < 5; i++)
    {
        cowboy_a.shoot(cowboy_b);
    }
    CHECK_EQ(cowboy_b.getHealth(),50);
    CHECK_FALSE(cowboy_a.hasboolets());
    cowboy_a.reload();
    CHECK(cowboy_a.hasboolets());
    for (size_t i = 0; i < 4; i++)
    {
        cowboy_a.shoot(cowboy_b);
    }
    CHECK_EQ(cowboy_b.getHealth(),10);
    CHECK(cowboy_b.isAlive());
    cowboy_a.shoot(cowboy_b);
    CHECK_FALSE(cowboy_b.isAlive());
    CHECK_EQ(cowboy_b.getHealth(),0);
}
TEST_CASE("Cowboy vs ninja test")
{
    Point a(1.5,3) ,b(4.75,3);
    Cowboy cowboy("Jhon",a);
    TrainedNinja ninja("Peter",b);
    cout<<"hi: "<<ninja.getHealth()<<endl;
    CHECK(cowboy.distance(ninja)>1);
    for (size_t i = 0; i < 20; i++)
    {
        ninja.slash(&cowboy);
    }
    CHECK(cowboy.isAlive());
    cout<<ninja.getLocation().print()<<endl;
    ninja.move(&cowboy);
    cout<<ninja.getLocation().print()<<endl;
    CHECK(cowboy.distance(ninja)==0);
    for (size_t i = 0; i < 20; i++)
    { 
        ninja.slash(&cowboy);
        cowboy.shoot(ninja);
    }
    CHECK_FALSE(cowboy.isAlive());
    CHECK(ninja.isAlive());
}
TEST_CASE("Team addition check")
{
    Point a(1.5,3) ,b(4.75,3),c(2,3);
    Cowboy cowboy("Jhon",a);
    TrainedNinja tninja("Peter",b);
    YoungNinja yninja("baby", c);
    Team team1(&cowboy);
    cowboy.hit(110);
    CHECK_EQ(team1.stillAlive(),0);
    team1.add(&tninja);
    team1.add(&yninja);
    CHECK_EQ(team1.stillAlive(),2);
}
TEST_CASE("Team attack check")
{
    Point a(1.5,3) ,b(4.75,3),c(2,3),d(1.6,3),e(5,3),f(30,30);
    Cowboy cowboy1("Jhon",a),cowboy2("kobein",d);
    OldNinja oninja1("Peter",b),oninja2("oldy",e);
    YoungNinja yninja1("baby", c),yninja2("jr", f);
    Team team1(&cowboy1),team2(&cowboy2);
    team1.add(&oninja1);
    team1.add(&yninja1);
    team2.add(&oninja2);
    team2.add(&yninja2);
    team1.attack(&team2);//-23 to victim: 87 left
    CHECK_EQ(team2.stillAlive(),3);
    team1.attack(&team2);//-36 to victim : 51 left
    CHECK_EQ(team2.stillAlive(),3);
    team1.attack(&team2);//-36 to victim : 15 left
    CHECK_EQ(team2.stillAlive(),3);
    team1.attack(&team2);//-36 to victim : 0 left
    CHECK_EQ(team2.stillAlive(),2);
    team1.attack(&team2);//-23 to victim: 127 left
    CHECK_EQ(team2.stillAlive(),2);
    team1.attack(&team2);//-36 to victim: 91 left
    CHECK_EQ(team2.stillAlive(),2);
    team1.attack(&team2);//-36 to victim: 55 left
    CHECK_EQ(team2.stillAlive(),2);
    team1.attack(&team2);//-36 to victim: 24 left
    CHECK_EQ(team2.stillAlive(),2);
    team1.attack(&team2);//-36 to victim: 0 left
    CHECK_EQ(team2.stillAlive(),1);
    team1.attack(&team2);//-10 to victim: 90 left
    CHECK_EQ(team2.stillAlive(),1);
    team1.attack(&team2);//-10 to victim: 80 left
    CHECK_EQ(team2.stillAlive(),1);
    team1.attack(&team2);//-10 to victim: 70 left
    CHECK_EQ(team2.stillAlive(),1);
    team1.attack(&team2);//-23 to victim: 47 left
    CHECK_EQ(team2.stillAlive(),1);
    team1.attack(&team2);//-23 to victim: 24 left
    CHECK_EQ(team2.stillAlive(),1);
    team1.attack(&team2);//-36 to victim: 0 left
    CHECK_EQ(team2.stillAlive(),0);
}