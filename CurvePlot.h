#ifndef CURVEPLOT_H
#define CURVEPLOT_H
#include "Shapes.h"
#include "Canvas.h"
class CurvePlot : public Paintable
{
public:
    CurvePlot(std::function<double(double)> setX,
              std::function<double(double)> setY,
              double t_left, double t_right,
              char color);
    void paint(Canvas &c) const;
private:
    std::function<double(double)> m_X, m_Y;
    char m_color;
    double m_t_left, m_t_right;
};

#endif // CURVEPLOT_H
