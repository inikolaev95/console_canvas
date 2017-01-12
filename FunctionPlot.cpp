#include "FunctionPlot.h"

FunctionPlot::FunctionPlot(
    std::function<double(double)> f,
    char color) :
    m_f(f),
    m_color(color)
    {}

void FunctionPlot::paint(Canvas& c) const
{
        auto h = c.pixelWidth();
        auto x2 = c.topRight().x + 10;
        for(auto x=c.bottomLeft().x; x<x2; x+=h){
            h = c.pixelWidth();
            while(fabs(m_f(x - h) - m_f(x)) > c.pixelWidth())
                h /= 2;
            c.setColor(x, m_f(x), m_color);
        }
}


