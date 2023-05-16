#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

namespace ariel { 
    class Point {
    private:
        double x; 
        double y; 
    public:
        Point();
        //Point(Point &other);
        Point(Point *other);
        Point(double x_coor, double y_coor);
        ~Point() = default; 
        double getX();
        double getY();
        void setX(double x);
        void setY(double y);
        std::string print() const;
        static Point moveTowards(Point& source, Point& destination, double distance);
        double distance(const Point& other) const;
    };
}

#endif
