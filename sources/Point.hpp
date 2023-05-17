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
        Point(double x_coor, double y_coor); 
        double getX();
        double getY();
        void setX(double x_coor);
        void setY(double y_coor);
        std::string print() const;
        static Point moveTowards(const Point& source, const Point& destination, double distance);
        double distance(const Point& other) const;
    };
}

#endif
