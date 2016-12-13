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

void Rectangle::load(const VariantMap& m)
{
    m_bottomLeft.load(m.get<VariantMap>("bottomLeft"));
    m_topRight.load(m.get<VariantMap>("topRight"));
}

VariantMap Rectangle::save() const
{
    return VariantMap()
            << VariantMap::Item("bottomLeft", m_bottomLeft.save())
            << VariantMap::Item("topRight", m_topRight.save());
}

DECL_FACTORY_TYPE(Paintable, Rectangle, "rectangle")
