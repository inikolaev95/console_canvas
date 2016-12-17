#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"

class Ellipse : public Shape
{
public:

   Ellipse(
            const PointF& C1,
            const int rad);
    void paint(Canvas& c) const;
private:
    PointF m_C1;
    int m_rad;
};
#endif // ELLIPSE_H

