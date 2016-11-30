#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"

class Ellipse : public Shape
{
public:
    Ellipse(
            const PointF& bottomLeft,
            const PointF& topRight);
    void paint(Canvas& c) const;
private:
    PointF m_bottomLeft;
    PointF m_topRight;
};

#endif // ELLIPSE_H
