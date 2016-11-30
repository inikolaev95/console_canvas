#include "Shapes.h"

Ellipse::Ellipse(
        const PointF& bottomLeft,
        const PointF& topRight) :
    m_bottomLeft(bottomLeft),
    m_topRight(topRight)
    {}

void Ellipse::paint(Canvas& c) const
{
    // TODO
}
