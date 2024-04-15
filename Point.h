//
// Created by matgiedr on 4/15/24.
//

#ifndef PO_P1_POINT_H
#define PO_P1_POINT_H


class Point {
    int x;
    int y;
public:
    Point(int x, int y);
    ~Point() = default;
    void setX(int x);
    void setY(int y);
    int getX() const;
    int getY() const;
    Point& operator=(const Point& other) = default;
};


#endif //PO_P1_POINT_H
