#ifndef CANVAS_H
#define CANVAS_H

#include "ScreenBuffer.h"

class Canvas
{
public:
    Canvas( ScreenBuffer *sb,
            const PointF& bottomLeft,
            const PointF& topRight ) :
        m_sb(sb),
        m_bottomLeft(bottomLeft),
        m_topRight(topRight)
    {
    }

    void setColor(const PointF& p, char color='*')
    {
        m_sb->setColor(tosb(p), color);
    }
    void setColor(double x, double y, char color='*')
    {
        setColor(PointF(x,y), color);
    }
    char color(const PointF& p) const
    {
        return m_sb->color(tosb(p));
    }
    char color(double x, double y) const
    {
        return color(PointF(x, y));
    }
    char operator()(double x, double y) const {
        return color(x, y);
    }

    PointF bottomLeft() const {
        return m_bottomLeft;
    }

    PointF topRight() const {
        return m_topRight;
    }

    double pixelWidth() const {
        return (m_topRight.x - m_bottomLeft.x) / m_sb->width();
    }

    double pixelHeight() const {
        return (m_topRight.y - m_bottomLeft.y) / m_sb->height();
    }

    ScreenBuffer *screenBuffer() const
    {
        return m_sb;
    }

private:
    ScreenBuffer *m_sb;
    PointF m_bottomLeft;
    PointF m_topRight;
    Point tosb(const PointF& p) const
    {
        return Point(
            (p.x - m_bottomLeft.x) *
                    (m_sb->width()-1) /
                    ( m_topRight.x -
                      m_bottomLeft.x ),
            (p.y - m_topRight.y) *
                    (m_sb->height()-1) /
                    ( m_bottomLeft.y -
                      m_topRight.y ));
    }
};

#endif // CANVAS_H
