#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point{
    public:
        Point();
        Point(int CartesianX, int CartesianY);

        int getPointXWindow();
        int getPointYWindow();
        int getPointXCartesian();
        int getPointYCartesian();

    private:

        int x;
        int y; 

        int ConvertToWindow();

};

#endif