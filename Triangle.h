#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
public:
    Triangle(
            const PointF& v1,
            const PointF& v2,
            const PointF& v3);
    void paint(Canvas& c) const;
private:
    PointF m_v1;
    PointF m_v2;
    PointF m_v3;
};

#endif // TRIANGLE_H
