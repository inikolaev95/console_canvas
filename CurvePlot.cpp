#include "CurvePlot.h"

CurvePlot::CurvePlot(std::function<double(double)> setX,
                     std::function<double(double)> setY,
                     double t_left, double t_right,
                     char color):
    m_X(setX),
    m_Y(setY),
    m_t_left(t_left),
    m_t_right(t_right),
    m_color(color)
{}

void CurvePlot::paint(Canvas &c) const
{
    auto h = c.pixelWidth();
    double t = m_t_left;
    double tmp = (c.topRight().x- c.bottomLeft().x);
    while( t < m_t_right){
        while(fabs(m_Y(t) - m_Y(t - h)) < c.pixelHeight() / 2)
            h *= 2;
        while(fabs(m_Y(t) - m_Y(t - h)) > c.pixelHeight())
            h /= 2;
        while(fabs(m_X(t) - m_X(t - h)) < c.pixelWidth() / 2)
            h *= 2;
        while(fabs(m_X(t) - m_X(t - h)) > c.pixelWidth())
            h /= 2;
        c.setColor((c.bottomLeft().x + m_X(t) + tmp)/2, c.bottomLeft().y + m_Y(t), m_color);
        t+=h;
    }
}

