#include "Ellipse.h"




Ellipse::Ellipse(const PointF& C1,
        const double rad) :
    m_C1(C1),
    m_rad(rad)
{
}

void Ellipse::paint(Canvas& c) const
{
    double x=0;
    double y = m_rad;
    double delta=1-2*m_rad;
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
