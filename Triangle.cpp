#include "Triangle.h"

using namespace std;

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

//          Line(PointF(m_v1.x,m_v1.y),PointF(m_v2.x,m_v2.y)).paint(c);
//          Line(PointF(m_v1.x,m_v1.y),PointF(m_v3.x,m_v3.y)).paint(c);
//          Line(PointF(m_v3.x,m_v3.y),PointF(m_v2.x,m_v2.y)).paint(c);
    }

    /*
    double h=c.pixelHeight(),w=c.pixelWidth(),y1,y2,y3,y,x1,x2,x3,x,xa,xb,xc,xmin,xmax,xmin0,xmax0;

    if (m_v1.y < m_v2.y && m_v2.y < m_v3.y) // переобозначение точек (x,y) для удобства
    {
       y3=m_v2.y;
       x3=m_v2.x;
       y1=m_v1.y;
       x1=m_v1.x;
       y2=m_v3.y;
       x2=m_v3.x;
    }
    else if (m_v1.y < m_v3.y && m_v3.y < m_v2.y)
    {
       y3=m_v3.y;
       x3=m_v3.x;
       y1=m_v1.y;
       x1=m_v1.x;
       y2=m_v2.y;
       x2=m_v2.x;
    }
    else if (m_v2.y < m_v1.y && m_v1.y < m_v3.y)
    {
       y3=m_v1.y;
       x3=m_v1.x;
       y1=m_v2.y;
       x1=m_v2.x;
       y2=m_v3.y;
       x2=m_v3.x;
    }
    else if (m_v2.y < m_v3.y && m_v3.y < m_v1.y)
    {
       y3=m_v3.y;
       x3=m_v3.x;
       y1=m_v2.y;
       x1=m_v2.x;
       y2=m_v1.y;
       x2=m_v1.x;
    }
    else if (m_v3.y < m_v1.y && m_v1.y < m_v2.y)
    {
       y3=m_v1.y;
       x3=m_v1.x;
       y1=m_v3.y;
       x1=m_v3.x;
       y2=m_v2.y;
       x2=m_v2.x;
    }
    else if (m_v3.y < m_v2.y && m_v2.y < m_v1.y)
    {
       y3=m_v2.y;
       x3=m_v2.x;
       y1=m_v3.y;
       x1=m_v3.x;
       y2=m_v1.y;
       x2=m_v1.x;
    }

    xmin0=min(min(x1,x2),x3);
    xmax0=max(max(x1,x2),x3);

    double dt1=h/(y2-y1); //шаг по y-кам
    double dt2=w/(xmax0-xmin0); //шаг по x-ам

    for (double t1=0; t1<1; t1+=dt1)
    {
        y=y1*(1-t1)+y2*(t1); // строка y-ков
        xa=(y-y1)/(y3-y1)*(x3-x1)-x1; // функция прямой, идущей примерно до середины поля
        xb=(y-y1)/(y2-y1)*(x2-x1)-x1; // функция прямой, идущей с ymin до ymax
        xc=(y-y2)/(y3-y2)*(x3-x2)-x2; // функция прямой, идущей примерно с середины поля до ymax
        if (xa <= x3) // если точка функции прямой, идущей примерно до середины поля < или = x3, расположенному примерно в центре поля,
                      // то используем функцию xa для нахождения min и max
        {
            xmin=min(xa,xb);
            xmax=max(xa,xb);
        }
        else if (xa > x3) // если точка функции прямой, идущей примерно до середины поля > x3, расположенного примерно в центре поля,
                          // то используем функцию xс для нахождения min и max
        {
            xmin=min(xc,xb);
            xmax=max(xc,xb);
        }
        double t2=0;
        for (x=xmin; x<=xmax; t2+=dt2) // заполняем строку x-ми от xmin до xmax
        {
           x=xmin*(1-t2)+xmax*(t2);
           c.setColor(x,y);
        }

    }
    */
}


