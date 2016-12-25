#include "Ellipse.h"


Ellipse::Ellipse(){};

Ellipse::Ellipse(const PointF& C1,
        const PointF rad) :
    m_C1(C1),
    m_rad(rad)
{
}

void Ellipse::paint(Canvas& c) const
{
    double radius=sqrt((m_C1.x-m_rad.x)*(m_C1.x-m_rad.x)+(m_C1.y-m_rad.y)*(m_C1.y-m_rad.y));
    double x=0;
    double y = radius;
    double delta=1-2*radius;
    double error=0;
    while (y>=0) {
        c.setColor(m_C1.x+x,m_C1.y+y);
        c.setColor(m_C1.x+x,m_C1.y-y);
        c.setColor(m_C1.x-x,m_C1.y+y);
        c.setColor(m_C1.x-x,m_C1.y-y);
        error=2*(delta+y)-1;
        if(delta<0 && error<=0) {
            x+=c.pixelWidth();
            delta+=2*x+c.pixelHeight();
            continue;
        }
        error=2*(delta-x)-1;
        if(delta>0 && error>0) {
            y-=c.pixelHeight();
            delta+=1-2*y;
            continue;
        }
        x+=c.pixelWidth();
        delta+=2*(x-y);
        y-=c.pixelHeight();
    }

}

void Ellipse::load(const VariantMap& m)
{
    m_C1.load(m.get<VariantMap>("C1"));
    m_rad.load(m.get<VariantMap>("rad"));
}

VariantMap Ellipse::save() const
{
    return VariantMap()
            << VariantMap::Item("C1", m_C1.save())
            << VariantMap::Item("rad", m_rad.save());
}

DECL_FACTORY_TYPE(Paintable, Ellipse, "ellipse")

