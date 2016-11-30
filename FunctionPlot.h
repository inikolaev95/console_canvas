#ifndef FUNCTIONPLOT_H
#define FUNCTIONPLOT_H

#include "Paintable.h"

class FunctionPlot : public Paintable
{
public:
    FunctionPlot(
            std::function<double(double)> f,
            char color);
    void paint(Canvas &c) const;
private:
    std::function<double(double)> m_f;
    char m_color;
};

#endif // FUNCTIONPLOT_H
