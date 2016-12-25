#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"

class Ellipse : public Shape
{
public:

   Ellipse(
            const PointF& C1,
            const double rad);
    void paint(Canvas& c) const;
private:
    PointF m_C1;
    double m_rad;
};
#endif // ELLIPSE_H

