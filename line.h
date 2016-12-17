#ifndef LINE_H
#define LINE_H

#include "Shape.h"
#include "VariantMap.h"


class Line: public Shape
{
   public:
    Line();
    Line(
            const PointF& p1,
            const PointF& p2);

    void paint(Canvas &c) const;
    void load(const VariantMap&m);
    VariantMap save() const;

private:
    PointF m_p1;
    PointF m_p2;

};

#endif // LINE_H
