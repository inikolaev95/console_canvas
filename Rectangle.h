#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle :
    public Shape,
    public Persistent
{
public:
    Rectangle();
    Rectangle(
            const PointF& bottomLeft,
            const PointF& topRight);
    void paint(Canvas& c) const;
    void load(const VariantMap&m);
    VariantMap save() const;
private:
    PointF m_bottomLeft;
    PointF m_topRight;
};

#endif // RECTANGLE_H
