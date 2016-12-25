#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"

class Ellipse : public Shape,
                public Persistent
{
public:

   Ellipse();
   Ellipse(const PointF& C1,
            const PointF rad);
    void paint(Canvas& c) const;
    void load(const VariantMap&m);
    VariantMap save() const;
private:
    PointF m_C1;
    PointF m_rad;
};
#endif // ELLIPSE_H

