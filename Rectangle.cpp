#include "Rectangle.h"

Rectangle::Rectangle(
        const PointF& bottomLeft,
        const PointF& topRight) :
    m_bottomLeft(bottomLeft),
    m_topRight(topRight)
{
}

void Rectangle::paint(Canvas& c) const
{
    // TODO
}
