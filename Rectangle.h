#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(
            const PointF& bottomLeft,
            const PointF& topRight);
    void paint(Canvas& c) const;
private:
    PointF m_bottomLeft;
    PointF m_topRight;
};

#endif // RECTANGLE_H
