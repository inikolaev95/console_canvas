#include "Ellipse.h"




Ellipse::Ellipse(
        const PointF& C1,
        const int rad) :
    m_C1(C1),
    m_rad(rad)
{
}

void Ellipse::paint(Canvas& c) const
{
    int x=0;
    int y = m_rad;
    int delta=1-2*m_rad;
    int error=0;
    while (y>=0) {
        c.setColor(m_C1.x+x,m_C1.y+y);
        c.setColor(m_C1.x+x,m_C1.y-y);
        c.setColor(m_C1.x-x,m_C1.y+y);
        c.setColor(m_C1.x-x,m_C1.y-y);
        error=2*(delta+y)-1;
        if(delta<0 && error<=0) {
            ++x;
            delta+=2*x+1;
            continue;
        }
        error=2*(delta-x)-1;
        if(delta>0 && error>0) {
            --y;
            delta+=1-2*y;
            continue;
        }
        ++x;
        delta+=2*(x-y);
        --y;
    }

}
