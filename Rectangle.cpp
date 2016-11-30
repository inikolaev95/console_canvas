#include "Rectangle.h"

Rectangle::Rectangle() {}

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

DECL_FACTORY_TYPE(Paintable, Rectangle, "rectangle")
