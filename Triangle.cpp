#include "Triangle.h"
#include "line.h"
#include "Variant.h"
#include "VariantMap.h"

using namespace std;

Triangle::Triangle() {}

Triangle::Triangle(
        const PointF& v1,
        const PointF& v2,
        const PointF& v3) :
    m_v1(v1),
    m_v2(v2),
    m_v3(v3)
    {}

void Triangle::paint(Canvas& c) const
{
    double ymin = min(m_v1.y, min(m_v2.y, m_v3.y));
    double ymax = max(m_v1.y, max(m_v2.y, m_v3.y));
    for (double y=ymin; y<ymax; y+=c.pixelHeight())
    {
        bool hasMinMax = false;
        double xmin, xmax;
        auto accumXrange = [&](const PointF& v1, const PointF& v2) {
            auto t = (y - v1.y) / (v2.y - v1.y);
            if (t<0 || t > 1)
                return;
            auto x = v1.x + t*(v2.x - v1.x);
            if (hasMinMax) {
                if (xmin > x)
                    xmin = x;
                else if (xmax < x)
                    xmax = x;
            }
            else {
                xmin = xmax = x;
                hasMinMax = true;
            }
        };
        accumXrange(m_v1, m_v2);
        accumXrange(m_v2, m_v3);
        accumXrange(m_v3, m_v1);
        for (double x=xmin; x<xmax; x+=c.pixelWidth())
        {
            c.setColor(x,y,fillColor());
        }

          Line(PointF(m_v2.x,m_v2.y),PointF(m_v1.x,m_v1.y)).paint(c);
          Line(PointF(m_v3.x,m_v3.y),PointF(m_v1.x,m_v1.y)).paint(c);
          Line(PointF(m_v3.x,m_v3.y),PointF(m_v2.x,m_v2.y)).paint(c);
    }
    }

void Triangle::load(const VariantMap& m)
{
    m_v1.load(m.get<VariantMap>("v1"));
    m_v2.load(m.get<VariantMap>("v2"));
    m_v3.load(m.get<VariantMap>("v3"));
}

VariantMap Triangle::save() const
{
    return VariantMap()
            << VariantMap::Item("v1", m_v1.save())
            << VariantMap::Item("v2", m_v2.save())
            << VariantMap::Item("v3", m_v3.save());
}

DECL_FACTORY_TYPE(Paintable, Triangle, "Triangle")

