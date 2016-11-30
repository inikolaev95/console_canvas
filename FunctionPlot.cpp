#include "Shapes.h"

FunctionPlot::FunctionPlot(
    std::function<double(double)> f,
    char color) :
    m_f(f),
    m_color(color)
    {}

void FunctionPlot::paint(Canvas &c) const
{
    // TODO
}

